#include "stdafx.h"
#include "matrix.h" 

matrix::matrix()
{
}


matrix::~matrix()
{
} 

QImage matrix::MA2QIMG(Mat4b A, bool mode)
{
	int i, j, r, g, b, a;
	int w = A.cols;
	int h = A.rows;

	QImage img(w, h, QImage::Format_ARGB32_Premultiplied); 

	for (i = 0; i < h; i++)
	{
		for (j = 0; j < w; j++)
		{ 
			a = toINT(A.at<Vec4b>(i, j)[0]);
			r = toINT(A.at<Vec4b>(i, j)[1]);
			g = toINT(A.at<Vec4b>(i, j)[2]);
			b = toINT(A.at<Vec4b>(i, j)[3]);

			img.setPixel(j, i, mode ? qRgba((r + g + b) / 3, (r + g + b) / 3, (r + g + b) / 3, a) : qRgba(r, g, b, a)); 
		}
	}

	return img;
}

Mat4b matrix::QIMG2MAT(QImage img)
{
	int i, j;
	int w = img.width();
	int h = img.height();

	Mat4b A = Mat::zeros(h, w, CV_8UC4);

	for (i = 0; i < h; i++)
	{
		QRgb *L = (QRgb *)img.scanLine(i);
		for (j = 0; j < w; j++)
		{
			A.at<Vec4b>(i, j)[0] = itoUCHAR(qAlpha(L[j]));
			A.at<Vec4b>(i, j)[1] = itoUCHAR(qRed(L[j]));
			A.at<Vec4b>(i, j)[2] = itoUCHAR(qGreen(L[j]));
			A.at<Vec4b>(i, j)[3] = itoUCHAR(qBlue(L[j]));

		}
	}

	return A;
}

Mat4b matrix::MirrorH(Mat4b A)
{
	int i, j;
	int w = A.cols;
	int h = A.rows;

	Mat4b B = Mat::zeros(h, w, CV_8UC4);

	for (i = 0; i < h; i++)
	{
		for (j = 0; j < w; j++)
		{ 
			B.at<Vec4b>(i, j) = A.at<Vec4b>(i, w - j - 1);
		}
	}

	return B;
}

Mat4b matrix::MirrorV(Mat4b A)
{
	int i, j;
	int w = A.cols;
	int h = A.rows;

	Mat4b B = Mat::zeros(h, w, CV_8UC4);

	for (i = 0; i < h; i++)
	{
		for (j = 0; j < w; j++)
		{ 
			B.at<Vec4b>(i, j) = A.at<Vec4b>(h - i - 1, j);
		}
	}

	return B;
}

Mat4b matrix::Invert(Mat4b A)
{
	int i, j;
	int w = A.cols;
	int h = A.rows;

	Mat4b B = Mat::zeros(h, w, CV_8UC4);

	for (i = 0; i < h; i++)
	{
		for (j = 0; j < w; j++)
		{ 
			B.at<Vec4b>(i, j)[0] = A.at<Vec4b>(i, j)[0];
			B.at<Vec4b>(i, j)[1] = itoUCHAR(255 - toINT(A.at<Vec4b>(i, j)[1]));
			B.at<Vec4b>(i, j)[2] = itoUCHAR(255 - toINT(A.at<Vec4b>(i, j)[2]));
			B.at<Vec4b>(i, j)[3] = itoUCHAR(255 - toINT(A.at<Vec4b>(i, j)[3]));

		}
	}

	return B;
}

Mat4b matrix::Clockwise90(Mat4b A)
{
	Mat B = Mat::zeros(A.cols, A.rows, CV_8UC4); 
	transpose(A, B);
	return MirrorH(B);
}

Mat1b matrix::newKernal(void)
{
	Mat1b kernal = Mat::zeros(3, 3, CV_8UC1);

	kernal.at<uchar>(0, 1) = itoUCHAR(1);
	kernal.at<uchar>(1, 0) = itoUCHAR(1);
	kernal.at<uchar>(1, 1) = itoUCHAR(1);
	kernal.at<uchar>(1, 2) = itoUCHAR(1);
	kernal.at<uchar>(2, 1) = itoUCHAR(1);

	return kernal;
}

bool matrix::Conv(Mat1b A)    // make sure Mat A has 1 channel
{
	int i, j;
	int n = 0;
	int w = A.cols;
	int h = A.rows;

	Mat B = newKernal();

	if (h == B.rows && w == B.cols)
	{
		for (i = 0; i < h; i++)
		{
			for (j = 0; j < w; j++)
			{
				n += toINT(A.at<uchar>(i, j)) * toINT(B.at<uchar>(i, j));  // no need to compute all the block, just deal with the cross.
			}
		}

	}

	return (n == 5);
}

Mat1b matrix::Filter(Mat4b A, QRect r)
{ 
	int i, j, m, n;
	int w = A.cols;
	int h = A.rows;
	
	int xmin = max(r.x(), 0) + 1;
	int ymin = max(r.y(), 0) + 1;
	int xmax = min(r.x() + r.width(), w) - 2;
	int ymax = min(r.y() + r.height(), h) - 2; 

	Mat1b B = Mat::zeros(h, w, CV_8UC1);

	for (i = ymin; i <= ymax; i++)
	{
		for (j = xmin; j <= xmax; j++)
		{

			Mat1b frag = Mat::zeros(3, 3, CV_8UC1);
			for (m = 0; m < 3; m++)
			{
				for (n = 0; n < 3; n++)
				{
					frag.at<uchar>(m, n) = isTRUE(A.at<Vec4b>(i - 1 + m, j - 1 + n)[1]);
				}
			}			
			if (Conv(frag)) B.at<uchar>(i, j) = itoUCHAR(1);

		}
	} 
	return B;
}

Mat1b matrix::Expand(Mat1b A, QRect r)
{ 
	int i, j;

	Mat B = A;
	int w = B.cols;
	int h = B.rows;

	int xmin = max(r.x(), 0) + 1;
	int ymin = max(r.y(), 0) + 1;
	int xmax = min(r.x() + r.width(), w) - 2;
	int ymax = min(r.y() + r.height(), h) - 2;

	for (i = ymin; i <= ymax; i++)
	{
		for (j = xmin; j <= xmax; j++)
		{
			if (toINT(B.at<uchar>(i, j)) == 1)
			{
				if (toINT(B.at<uchar>(i - 1, j)) == 0) B.at<uchar>(i - 1, j) = itoUCHAR(2);
				if (toINT(B.at<uchar>(i + 1, j)) == 0) B.at<uchar>(i + 1, j) = itoUCHAR(2);
				if (toINT(B.at<uchar>(i, j - 1)) == 0) B.at<uchar>(i, j - 1) = itoUCHAR(2);
				if (toINT(B.at<uchar>(i, j + 1)) == 0) B.at<uchar>(i, j + 1) = itoUCHAR(2);
			}
		}
	}
	return B;
}

Mat4b matrix::toPix(Mat1b A, QRect r)
{ 
	int i, j;
	int w = A.cols;
	int h = A.rows;
	
	int xmin = max(r.x(), 0);
	int ymin = max(r.y(), 0);
	int xmax = min(r.x() + r.width(), w) - 1;
	int ymax = min(r.y() + r.height(), h) - 1;

	Mat4b B = Mat::zeros(h, w, CV_8UC4);

	for (i = ymin; i <= ymax; i++)
	{
		for (j = xmin; j <= xmax; j++)
		{
			int p = toINT(A.at<uchar>(i, j));

			switch (p)
			{
			case 1: 
				B.at<Vec4b>(i, j) = { itoUCHAR(127), itoUCHAR(127), itoUCHAR(0), itoUCHAR(0) };  // alpha and red channels of contain
				break;

			case 2: 
				B.at<Vec4b>(i, j) = { itoUCHAR(191), itoUCHAR(64), itoUCHAR(0), itoUCHAR(0) };  // alpha and red channels of bound
				break;

			default: 
				break;
			}

		}
	}

	return B;
} 

QMat matrix::Filtered(QImage src, QPixmap p, QRect r)
{
	Mat A = QIMG2MAT(p.toImage());
	Mat B = Filter(A, r);
	Mat C = Expand(B, r);

	QRect qr = shrink(C, r);
	
	QMat frag;
	frag.pMat = QPixmap::fromImage(MA2QIMG(toPix(C, qr), false));
	frag.eMat = cutMat(C, qr);
	frag.iMat = cutArea(src, C, qr); 
	frag.iNum = isNULL(C, qr);

	return frag;
}

int matrix::isNULL(Mat1b A, QRect r)
{
	int i, j;
	int count = 0;
	int w = A.cols;
	int h = A.rows;
	int cn = A.channels();

	int xmin = max(r.x(), 0) + 1;
	int ymin = max(r.y(), 0) + 1;
	int xmax = min(r.x() + r.width(), w) - 2;
	int ymax = min(r.y() + r.height(), h) - 2;

	for (i = ymin; i <= ymax; i++)
	{
		for (j = xmin; j <= xmax; j++)
		{
			if (toINT(A.at<uchar>(i, j)) == 1) count++;
		} 
	}

	return count; 
}

Mat4b matrix::cutArea(QImage src, Mat1b A, QRect r)
{
	int i, j;
	int w = A.cols;
	int h = A.rows; 
	
	int xmin = max(r.x(), 0);
	int ymin = max(r.y(), 0);
	int xmax = min(r.x() + r.width(), w) - 1;
	int ymax = min(r.y() + r.height(), h) - 1;

	Mat4b B = QIMG2MAT(src);
	Mat4b C = Mat::zeros(r.height(), r.width(), CV_8UC4);

	for (i = ymin; i <= ymax; i++)
	{
		for (j = xmin; j <= xmax; j++)
		{
			if (toINT(A.at<uchar>(i, j)) != 0) C.at<Vec4b>(i - ymin, j - xmin) = B.at<Vec4b>(i, j);
		}
	}

	return C;
}

QRect matrix::shrink(Mat1b A, QRect r)  // make sure Mat A has 1 channel
{
	int i, j;
	int w = A.cols;
	int h = A.rows;

	int xmin = max(r.x(), 0);
	int ymin = max(r.y(), 0);
	int xmax = min(r.x() + r.width(), w) - 1;
	int ymax = min(r.y() + r.height(), h) - 1;

	int nxmin = xmax;
	int nxmax = xmin;
	int nymin = ymax;
	int nymax = ymin;

	for (i = ymin; i <= ymax; i++)
	{
		for (j = xmin; j <= xmax; j++)
		{
			if (toINT(A.at<uchar>(i, j)) != 0)
			{
				nxmin = min(nxmin, j);
				nxmax = max(nxmax, j);
				nymin = min(nymin, i);
				nymax = max(nymax, i);
			}
		}
	}

	return QRect(nxmin, nymin, nxmax - nxmin + 1, nymax - nymin + 1);
}

Mat1b matrix::cutMat(Mat1b A, QRect r)  // make sure Mat A has 1 channel
{
	int i, j;
	int w = A.cols;
	int h = A.rows;

	int xmin = max(r.x(), 0);
	int ymin = max(r.y(), 0);
	int xmax = min(r.x() + r.width(), w) - 1;
	int ymax = min(r.y() + r.height(), h) - 1;

	Mat1b B = Mat::zeros(r.height(), r.width(), CV_8UC1);

	for (i = ymin; i <= ymax; i++)
	{
		for (j = xmin; j <= xmax; j++)
		{
			B.at<uchar>(i - ymin, j - xmin) = A.at<uchar>(i, j);
		}
	}
	return B;
}

bool matrix::adjacent(QPoint s, QPoint e)
{
	int x1 = s.x();
	int y1 = s.y();
	int x2 = e.x();
	int y2 = e.y();

	return (Abs(x1 - x2) + Abs(y1 - y2) == 1);
}

Mat1f matrix::iLaplace(Mat1b A, int n, QPoint ips[])    // A is eigen matrix
{
	int i, j;
	Mat1f L = Mat::zeros(n, n, CV_32FC1); 

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < i + 1; j++)
		{
			if (i == j){
				L.at<float>(i, j) = -4.0;
			}
			else if (adjacent(ips[i], ips[j]))
			{
				L.at<float>(i, j) = L.at<float>(j, i) = 1.0;
			} 
		}
	}

#ifdef PRINT_DEBUG
	printLap(L);
#endif

	//invert(L, L, DECOMP_EIG);
	return L; 
}

double matrix::divG(Mat4b src, QPoint inp, int k)
{
	int x = inp.x();
	int y = inp.y();

	double s = -4.0 * toINT(src.at<Vec4b>(x, y)[k]);

	s += 1.0 * toINT(src.at<Vec4b>(x - 1, y)[k]);
	s += 1.0 * toINT(src.at<Vec4b>(x + 1, y)[k]);
	s += 1.0 * toINT(src.at<Vec4b>(x, y - 1)[k]);
	s += 1.0 * toINT(src.at<Vec4b>(x, y + 1)[k]);

	return s;
}

double matrix::Neighbor(Mat4b dst, Mat1b eig, QPoint tlp, QPoint inp, int k)
{
	int m = inp.x();
	int n = inp.y();
	int i = m + tlp.y();
	int j = n + tlp.x();

	double s = 0.0;

	if (toINT(eig.at<uchar>(m - 1, n)) == 2) s += 1.0 * toINT(dst.at<Vec4b>(i - 1, j)[k]);
	if (toINT(eig.at<uchar>(m + 1, n)) == 2) s += 1.0 * toINT(dst.at<Vec4b>(i + 1, j)[k]);
	if (toINT(eig.at<uchar>(m, n - 1)) == 2) s += 1.0 * toINT(dst.at<Vec4b>(i, j - 1)[k]);
	if (toINT(eig.at<uchar>(m, n + 1)) == 2) s += 1.0 * toINT(dst.at<Vec4b>(i, j + 1)[k]);

	return s;
}

int matrix::ipArray(Mat1b A, int n, QPoint *ips)  // can add fail message of malloc
{
	int i, j;
	int k = 0;
	int w = A.cols;
	int h = A.rows; 

	for (i = 0; i < h; i++)
	{
		for (j = 0; j < w; j++)
		{
			if (toINT(A.at<uchar>(i, j)) == 1){
				*(ips + k) = QPoint(i, j);
				k++;
			}
		}
	}
	return k;
}

Mat1f matrix::Getb(QImage dst, Mat1f dgs, Mat1b eig, QPoint tlp, QPoint ips[])
{
	int i, j;
	int n = dgs.rows;
	Mat4d D = QIMG2MAT(dst);
	Mat1f b = Mat::zeros(n, 4, CV_32FC1);

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 4; j++)
		{
			b.at<float>(i, j) = dgs.at<float>(i, j) - Neighbor(D, eig, tlp, ips[i], j);
		}
	}
	return b;
}

Mat1f matrix::divGArray(Mat4b src, QPoint ips[], int n)
{
	int i, j;
	Mat1f g = Mat::zeros(n, 4, CV_32FC1);

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 4; j++)
		{
			g.at<float>(i, j) = divG(src, ips[i], j);
		}
	}
	return g;
}
  
Mat4b matrix::Possion(QImage dst, Mat1f sln, QPoint tlp, QPoint ips[])
{
	int i, j, k, m;
	int x = tlp.y();
	int y = tlp.x();
	int n = sln.rows;
	Mat A = QIMG2MAT(dst);

	for (k = 0; k < n; k++)
	{
		i = ips[k].x() + x;
		j = ips[k].y() + y;
		for (m = 0; m < 4; m++)
		{
			A.at<Vec4b>(i, j)[m] = itoUCHAR(toINT(sln.at<float>(k, m)));
		}

	}
	return A;
}

QImage matrix::toImg(QImage dst, Mat1f iA, Mat1f divG, Mat1b Eigen, QPoint ips[], QPoint tlp)
{
	Mat1f b = Getb(dst, divG, Eigen, tlp, ips);
	Mat1f x = Mat::zeros(b.rows, 4, CV_32FC1);
	//x = iA * b;
	cv::solve(iA, b, x, DECOMP_EIG);

#ifdef PRINT_DEBUG
	printsln(x);
#endif

	Mat4b p = Possion(dst, x, tlp, ips);

	return MA2QIMG(p, false);
}