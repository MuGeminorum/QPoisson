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
	Mat4b B = Mat::zeros(A.cols, A.rows, CV_8UC4);
	transpose(A, B);
	return MirrorH(B);
}

int matrix::Filter(Mat4b *C, QRect *qr)
{
	int i, j;
	int n = 0;
	Mat4b A = *C;
	QRect r = *qr;

	int w = A.cols;
	int h = A.rows;

	int xmin = max(r.x(), 0) + 1;
	int ymin = max(r.y(), 0) + 1;
	int xmax = min(r.x() + r.width(), w) - 2;
	int ymax = min(r.y() + r.height(), h) - 2;

	Mat4b B = Mat::zeros(h, w, CV_8UC4); 

	for (i = ymin; i <= ymax; i++)
	{
		for (j = xmin; j <= xmax; j++)
		{

			uchar cf = isTRUE(A.at<Vec4b>(i, j)[0]);
			cf &= isTRUE(A.at<Vec4b>(i - 1, j)[0]);
			cf &= isTRUE(A.at<Vec4b>(i, j - 1)[0]);
			cf &= isTRUE(A.at<Vec4b>(i + 1, j)[0]);
			cf &= isTRUE(A.at<Vec4b>(i, j + 1)[0]);

			if (cf == 0x01)
			{
				B.at<Vec4b>(i, j)[0] = itoUCHAR(127);
				B.at<Vec4b>(i, j)[1] = itoUCHAR(127); 
				n++;
			}

		}
	}
	
	if (n > 0)
	{

		int nxmin = xmax;
		int nxmax = xmin;
		int nymin = ymax;
		int nymax = ymin;

		for (i = ymin; i <= ymax; i++)
		{
			for (j = xmin; j <= xmax; j++)
			{
				if (toINT(B.at<Vec4b>(i, j)[0]) == 127)
				{
					if (toINT(B.at<Vec4b>(i - 1, j)[0]) == 0)
					{
						B.at<Vec4b>(i - 1, j)[0] = itoUCHAR(191);
						B.at<Vec4b>(i - 1, j)[1] = itoUCHAR(64);
					}
					if (toINT(B.at<Vec4b>(i + 1, j)[0]) == 0)
					{
						B.at<Vec4b>(i + 1, j)[0] = itoUCHAR(191);
						B.at<Vec4b>(i + 1, j)[1] = itoUCHAR(64);
					}
					if (toINT(B.at<Vec4b>(i, j - 1)[0]) == 0)
					{
						B.at<Vec4b>(i, j - 1)[0] = itoUCHAR(191);
						B.at<Vec4b>(i, j - 1)[1] = itoUCHAR(64);
					}
					if (toINT(B.at<Vec4b>(i, j + 1)[0]) == 0)
					{
						B.at<Vec4b>(i, j + 1)[0] = itoUCHAR(191);
						B.at<Vec4b>(i, j + 1)[1] = itoUCHAR(64);
					}

					nxmin = min(nxmin, j);
					nxmax = max(nxmax, j);
					nymin = min(nymin, i);
					nymax = max(nymax, i);

				}
			}
		}

		(*C) = B;
		(*qr) = QRect(nxmin - 1, nymin - 1, nxmax - nxmin + 3, nymax - nymin + 3);
	}

	return n;

}
 
QPixmap matrix::Filtered(QImage src, QPixmap p, QRect r, QMat *fg)
{
	QRect qr = r;
	Mat4b A = QIMG2MAT(p.toImage());
	int n = Filter(&A, &qr);

	if (n > 0)
	{ 
		Mat1b E = toEig(A, qr);
		(*fg).eMat = cutMat(E, qr);
		(*fg).iMat = cutImg(src, E, qr);
		(*fg).iNum = n; 
		return QPixmap::fromImage(MA2QIMG(A, false));
	}
	else
	{
		(*fg).iNum = 0;
		return p;
	}
}

Mat1b matrix::toEig(Mat4b A, QRect r)
{
	int i, j;
	int w = A.cols;
	int h = A.rows;

	Mat1b E = Mat::zeros(h, w, CV_8UC1);

	int xmin = max(r.x(), 0);
	int ymin = max(r.y(), 0);
	int xmax = min(r.x() + r.width(), w) - 1;
	int ymax = min(r.y() + r.height(), h) - 1;

	for (i = ymin; i <= ymax; i++)
	{
		for (j = xmin; j <= xmax; j++)
		{
			if (toINT(A.at<Vec4b>(i, j)[0]) == 127) E.at<uchar>(i, j) = itoUCHAR(1);
			if (toINT(A.at<Vec4b>(i, j)[0]) == 191) E.at<uchar>(i, j) = itoUCHAR(2);
		}
	}

	return E;
}

Mat4b matrix::cutImg(QImage src, Mat1b A, QRect r)
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


Mat1b matrix::cutMat(Mat1b A, QRect r)  // make sure Mat A has only 1 channel
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

SMat1f matrix::Laplace(int n, QPoint ips[])    // A is eigen matrix
{
	int i, j;

	SMat1f L(n, n);
	//Mat1f L = Mat::zeros(n, n, CV_32FC1);  // upper is only about 10000 x 10000, which is not large enough

	for (i = 0; i < n; i++)
	{ 
		for (j = 0; j < i + 1; j++)
		{
			if (i == j){
				L.insert(i, j) = -4.0;
				//L.at<float>(i, j) = -4.0; 
			}
			else if (adjacent(ips[i], ips[j]))
			{
				L.insert(i, j) = L.insert(j, i) = 1.0;
				//L.at<float>(i, j) = L.at<float>(j, i) = 1.0;
			}

		}
	}
	L.makeCompressed();

#ifdef PRINT_DEBUG
	printLap(L);
#endif

	return L;
}

int matrix::divG(Mat4b src, QPoint inp, int k)
{
	int x = inp.x();
	int y = inp.y();

	int s = -4 * toINT(src.at<Vec4b>(x, y)[k]);

	s += toINT(src.at<Vec4b>(x - 1, y)[k]);
	s += toINT(src.at<Vec4b>(x + 1, y)[k]);
	s += toINT(src.at<Vec4b>(x, y - 1)[k]);
	s += toINT(src.at<Vec4b>(x, y + 1)[k]);

	return s;
}

int matrix::Neighbor(Mat4b dst, Mat1b eig, QPoint tlp, QPoint inp, int k)
{
	int m = inp.x();
	int n = inp.y();
	int i = m + tlp.y();
	int j = n + tlp.x();

	int s = 0;

	if (toINT(eig.at<uchar>(m - 1, n)) == 2) s += toINT(dst.at<Vec4b>(i - 1, j)[k]);
	if (toINT(eig.at<uchar>(m + 1, n)) == 2) s += toINT(dst.at<Vec4b>(i + 1, j)[k]);
	if (toINT(eig.at<uchar>(m, n - 1)) == 2) s += toINT(dst.at<Vec4b>(i, j - 1)[k]);
	if (toINT(eig.at<uchar>(m, n + 1)) == 2) s += toINT(dst.at<Vec4b>(i, j + 1)[k]);

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

MatrixX4f matrix::Getb(QImage dst, Mat1i dgs, Mat1b eig, QPoint tlp, QPoint ips[])
{
	int i, j;
	int n = dgs.rows;
	Mat4d D = QIMG2MAT(dst);

	MatrixX4f b = MatrixX4f::Zero(n, 4);
	//Mat1f b = Mat::zeros(n, 4, CV_32FC1); 

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 4; j++)
		{
			b(i, j) = toFLT(dgs.at<int>(i, j) - Neighbor(D, eig, tlp, ips[i], j));
			//b.at<float>(i, j) = dgs.at<float>(i, j) - Neighbor(D, eig, tlp, ips[i], j);
		}
	}
	return b;
}

Mat1i matrix::divGArray(Mat4b src, QPoint ips[], int n)
{
	int i, j;
	Mat1i g = Mat::zeros(n, 4, CV_32SC1);

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 4; j++)
		{
			g.at<int>(i, j) = divG(src, ips[i], j);
		}
	}
	return g;
}
  
Mat4b matrix::Poisson(QImage dst, MatrixX4i sln, QPoint tlp, QPoint ips[])
{
	int i, j, k, m;
	int x = tlp.y();
	int y = tlp.x();
	int n = sln.rows();
	Mat A = QIMG2MAT(dst);

	for (k = 0; k < n; k++)
	{
		i = ips[k].x() + x;
		j = ips[k].y() + y;

		for (m = 0; m < 4; m++)
		{
			A.at<Vec4b>(i, j)[m] = itoUCHAR(sln(k, m));
		}

	}
	return A;
}

MatrixX4i matrix::pSolver(SMat1f A, MatrixX4f b)
{
	int i, j;
	int n = b.rows();
	BiCGSTAB<SMat1f> pSolve(A);
	MatrixX4f x = pSolve.solve(b);
	MatrixX4i p = MatrixX4i::Zero(n, 4);

	for (i = 0; i < n; i++)
	{

		p(i, 0) = toRGB(x(i, 0));

		for (j = 1; j < 4; j++)
		{
			p(i, j) = toRGB(x(i, j), p(i, 0));
		}

	}

	return p;
}

QImage matrix::toImg(QImage dst, SMat1f A, Mat1i divG, Mat1b Eigen, QPoint ips[], QPoint tlp)
{
	MatrixX4f b = Getb(dst, divG, Eigen, tlp, ips);
	MatrixX4i x = pSolver(A, b);

#ifdef PRINT_DEBUG
	printsln(x);
#endif

	Mat4b p = Poisson(dst, x, tlp, ips);

	return MA2QIMG(p, false);
}