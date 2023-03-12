#include "mat.h"

using namespace std;

#define INT(x) ((int)(x))
#define FLT(x) ((float)(1.0 * (x)))
#define BOL(x) ((x != 0x00) ? 0x01 : 0x00)

mat::mat()
{
}

mat::~mat()
{
}

uchar mat::itoUCHAR(int x, int ta)
{
	if (x < 0)
	{
		return 0x00;
	}
	else if (x >= 0 && x <= ta)
	{
		return (x & 0xFF);
	}
	else
	{
		return (ta & 0xFF);
	}
}

int mat::toRGB(float x, int t)
{
	int n = INT(x);

	if (n < 0)
	{
		return 0;
	}
	else if (n >= 0 && n <= t)
	{
		return n;
	}
	else
	{
		return t;
	}
}

QImage mat::MA2QIMG(Mat4b A, bool mode)
{
	int i, j, r, g, b, a;
	int w = A.cols;
	int h = A.rows;

	QImage img(w, h, QImage::Format_ARGB32_Premultiplied);

	for (i = 0; i < h; i++)
	{
		for (j = 0; j < w; j++)
		{
			a = INT(A.ARGB[0](i, j));
			r = INT(A.ARGB[1](i, j));
			g = INT(A.ARGB[2](i, j));
			b = INT(A.ARGB[3](i, j));

			img.setPixel(j, i, mode ? qRgba((r + g + b) / 3, (r + g + b) / 3, (r + g + b) / 3, a) : qRgba(r, g, b, a));
		}
	}

	return img;
}

Mat4b mat::newMat4b(int h, int w)
{
	int i;
	Mat4b A;

	A.rows = h;
	A.cols = w;

	for (i = 0; i < 4; i++)
	{
		A.ARGB[i] = MatrixXb::Zero(h, w);
	}

	return A;
}

Mat4b mat::QIMG2MAT(QImage img)
{
	int i, j;
	int w = img.width();
	int h = img.height();
	Mat4b A = newMat4b(h, w);

	for (i = 0; i < h; i++)
	{
		QRgb *L = (QRgb *)img.scanLine(i);
		for (j = 0; j < w; j++)
		{
			A.ARGB[0](i, j) = itoUCHAR(qAlpha(L[j]));
			A.ARGB[1](i, j) = itoUCHAR(qRed(L[j]));
			A.ARGB[2](i, j) = itoUCHAR(qGreen(L[j]));
			A.ARGB[3](i, j) = itoUCHAR(qBlue(L[j]));
		}
	}

	return A;
}

Mat4b mat::MirrorH(Mat4b A)
{
	int i, j, k;
	int w = A.cols;
	int h = A.rows;
	Mat4b B = newMat4b(h, w);

	for (i = 0; i < h; i++)
	{
		for (j = 0; j < w; j++)
		{
			for (k = 0; k < 4; k++)
			{
				B.ARGB[k](i, j) = A.ARGB[k](i, w - j - 1);
			}
		}
	}

	return B;
}

Mat4b mat::MirrorV(Mat4b A)
{
	int i, j, k;
	int w = A.cols;
	int h = A.rows;
	Mat4b B = newMat4b(h, w);

	for (i = 0; i < h; i++)
	{
		for (j = 0; j < w; j++)
		{
			for (k = 0; k < 4; k++)
			{
				B.ARGB[k](i, j) = A.ARGB[k](h - i - 1, j);
			}
		}
	}

	return B;
}

Mat4b mat::Invert(Mat4b A)
{
	int i, j, k;
	int w = A.cols;
	int h = A.rows;
	Mat4b B = newMat4b(h, w);

	B.ARGB[0] = A.ARGB[0];

	for (i = 0; i < h; i++)
	{
		for (j = 0; j < w; j++)
		{
			for (k = 1; k < 4; k++)
			{
				B.ARGB[k](i, j) = ~(A.ARGB[k](i, j));
			}
		}
	}

	return B;
}

Mat4b mat::transpose(Mat4b A)
{
	int i;
	int h = A.cols;
	int w = A.rows;
	Mat4b B = newMat4b(h, w);

	for (i = 0; i < 4; i++)
	{
		B.ARGB[i] = A.ARGB[i].transpose();
	}

	return B;
}

Mat4b mat::Clockwise90(Mat4b A)
{
	return MirrorH(transpose(A));
}

int mat::Filter(Mat4b *C, QRect *qr)
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
	Mat4b B = newMat4b(h, w);

	for (i = ymin; i <= ymax; i++)
	{
		for (j = xmin; j <= xmax; j++)
		{
			uchar cf = BOL(A.ARGB[0](i, j));

			cf &= BOL(A.ARGB[0](i - 1, j));
			cf &= BOL(A.ARGB[0](i, j - 1));
			cf &= BOL(A.ARGB[0](i + 1, j));
			cf &= BOL(A.ARGB[0](i, j + 1));

			if (cf == 0x01)
			{
				B.ARGB[0](i, j) = itoUCHAR(127);
				B.ARGB[1](i, j) = itoUCHAR(127);
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
				if (INT(B.ARGB[0](i, j)) == 127)
				{
					if (INT(B.ARGB[0](i - 1, j)) == 0)
					{
						B.ARGB[0](i - 1, j) = itoUCHAR(191);
						B.ARGB[1](i - 1, j) = itoUCHAR(64);
					}
					if (INT(B.ARGB[0](i + 1, j)) == 0)
					{
						B.ARGB[0](i + 1, j) = itoUCHAR(191);
						B.ARGB[1](i + 1, j) = itoUCHAR(64);
					}
					if (INT(B.ARGB[0](i, j - 1)) == 0)
					{
						B.ARGB[0](i, j - 1) = itoUCHAR(191);
						B.ARGB[1](i, j - 1) = itoUCHAR(64);
					}
					if (INT(B.ARGB[0](i, j + 1)) == 0)
					{
						B.ARGB[0](i, j + 1) = itoUCHAR(191);
						B.ARGB[1](i, j + 1) = itoUCHAR(64);
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

QPixmap mat::Filtered(QImage src, QPixmap p, QRect r, QMat *fg)
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

Mat1b mat::toEig(Mat4b A, QRect r)
{
	int i, j;
	int w = A.cols;
	int h = A.rows;
	Mat1b E = Mat1b::Zero(h, w); // Mat::zeros(h, w, CV_8UC1);
	int xmin = max(r.x(), 0);
	int ymin = max(r.y(), 0);
	int xmax = min(r.x() + r.width(), w) - 1;
	int ymax = min(r.y() + r.height(), h) - 1;

	for (i = ymin; i <= ymax; i++)
	{
		for (j = xmin; j <= xmax; j++)
		{
			if (INT(A.ARGB[0](i, j)) == 127) // is content
			{
				E(i, j) = itoUCHAR(1);
			}
			else if (INT(A.ARGB[0](i, j)) == 191) // is border
			{
				E(i, j) = itoUCHAR(2);
			}
		}
	}

	return E;
}

Mat4b mat::cutImg(QImage src, Mat1b A, QRect r)
{
	int i, j, k;
	int w = A.cols();
	int h = A.rows();
	int xmin = max(r.x(), 0);
	int ymin = max(r.y(), 0);
	int xmax = min(r.x() + r.width(), w) - 1;
	int ymax = min(r.y() + r.height(), h) - 1;
	Mat4b B = QIMG2MAT(src);
	Mat4b C = newMat4b(r.height(), r.width());

	for (i = ymin; i <= ymax; i++)
	{
		for (j = xmin; j <= xmax; j++)
		{
			if (INT(A(i, j)) != 0)
			{
				for (k = 0; k < 4; k++)
				{
					C.ARGB[k](i - ymin, j - xmin) = B.ARGB[k](i, j);
				}
			}
		}
	}

	return C;
}

Mat1b mat::cutMat(Mat1b A, QRect r) // make sure Mat A has only 1 channel
{
	int i, j;
	int w = A.cols();
	int h = A.rows();
	int xmin = max(r.x(), 0);
	int ymin = max(r.y(), 0);
	int xmax = min(r.x() + r.width(), w) - 1;
	int ymax = min(r.y() + r.height(), h) - 1;
	Mat1b B = Mat1b::Zero(r.height(), r.width());

	for (i = ymin; i <= ymax; i++)
	{
		for (j = xmin; j <= xmax; j++)
		{
			B(i - ymin, j - xmin) = A(i, j);
		}
	}
	return B;
}

bool mat::adjacent(QPoint s, QPoint e)
{
	int x1 = s.x();
	int y1 = s.y();
	int x2 = e.x();
	int y2 = e.y();

	return (abs(x1 - x2) + abs(y1 - y2) == 1);
}

SMat1f mat::Laplace(int n, QPoint ips[])
{
	int i, j;
	SMat1f L(n, n);

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < i + 1; j++)
		{
			if (i == j)
			{
				L.insert(i, j) = -4.0;
			}
			else if (adjacent(ips[i], ips[j]))
			{
				L.insert(i, j) = L.insert(j, i) = 1.0;
			}
		}
	}

	L.makeCompressed();

	return L;
}

int mat::divG(Mat4b src, QPoint inp, int k)
{
	int x = inp.x();
	int y = inp.y();
	int s = -4 * INT(src.ARGB[k](x, y));

	s += INT(src.ARGB[k](x - 1, y));
	s += INT(src.ARGB[k](x + 1, y));
	s += INT(src.ARGB[k](x, y - 1));
	s += INT(src.ARGB[k](x, y + 1));

	return s;
}

int mat::Neighbor(Mat4b dst, Mat1b eig, QPoint tlp, QPoint inp, int k)
{
	int m = inp.x();
	int n = inp.y();
	int i = m + tlp.y();
	int j = n + tlp.x();
	int s = 0;

	if (INT(eig(m - 1, n)) == 2)
		s += INT(dst.ARGB[k](i - 1, j));
	if (INT(eig(m + 1, n)) == 2)
		s += INT(dst.ARGB[k](i + 1, j));
	if (INT(eig(m, n - 1)) == 2)
		s += INT(dst.ARGB[k](i, j - 1));
	if (INT(eig(m, n + 1)) == 2)
		s += INT(dst.ARGB[k](i, j + 1));

	return s;
}

int mat::ipArray(Mat1b A, int n, QPoint *ips) // can add fail message of malloc
{
	int i, j;
	int k = 0;
	int w = A.cols();
	int h = A.rows();

	for (i = 0; i < h; i++)
	{
		for (j = 0; j < w; j++)
		{
			if (INT(A(i, j)) == 1)
			{
				*(ips + k) = QPoint(i, j);
				k++;
			}
		}
	}
	return k;
}

MatrixX4f mat::Getb(QImage dst, MatrixX4i dgs, Mat1b eig, QPoint tlp, QPoint ips[])
{
	int i, j;
	int n = dgs.rows();
	Mat4b D = QIMG2MAT(dst);
	MatrixX4f b = MatrixX4f::Zero(n, 4);

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 4; j++)
		{
			b(i, j) = FLT(dgs(i, j) - Neighbor(D, eig, tlp, ips[i], j));
		}
	}

	return b;
}

MatrixX4i mat::divGArray(Mat4b src, QPoint ips[], int n)
{
	int i, j;
	MatrixX4i g = MatrixX4i::Zero(n, 4);

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 4; j++)
		{
			g(i, j) = divG(src, ips[i], j);
		}
	}

	return g;
}

Mat4b mat::Poisson(QImage dst, MatrixX4i sln, QPoint tlp, QPoint ips[])
{
	int i, j, k, m;
	int x = tlp.y();
	int y = tlp.x();
	int n = sln.rows();
	Mat4b A = QIMG2MAT(dst);

	for (k = 0; k < n; k++)
	{
		i = ips[k].x() + x;
		j = ips[k].y() + y;

		for (m = 0; m < 4; m++)
		{
			A.ARGB[m](i, j) = itoUCHAR(sln(k, m));
		}
	}

	return A;
}

MatrixX4i mat::pSolver(SMat1f A, MatrixX4f b) // Solve Ax = b
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

QImage mat::toImg(QImage dst, SMat1f A, MatrixX4i divG, Mat1b Eigen, QPoint ips[], QPoint tlp)
{
	MatrixX4f b = Getb(dst, divG, Eigen, tlp, ips);
	MatrixX4i x = pSolver(A, b);
	Mat4b p = Poisson(dst, x, tlp, ips);

	return MA2QIMG(p, false);
}