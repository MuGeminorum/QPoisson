#pragma once

class matrix
{
public:
	matrix();
	~matrix();

	QImage MA2QIMG(Mat4b, bool);
	Mat4b QIMG2MAT(QImage);

	Mat4b MirrorV(Mat4b);
	Mat4b MirrorH(Mat4b);
	Mat4b Invert(Mat4b);
	Mat4b Grey(Mat4b);
	Mat4b Clockwise90(Mat4b);

	int ipArray(Mat1b, int, QPoint *);
	
	SMat1f Laplace(int, QPoint *);  
	MatrixX4f Getb(QImage, Mat1i, Mat1b, QPoint, QPoint *);
	Mat1i divGArray(Mat4b, QPoint *, int);
	Mat4b Poisson(QImage, MatrixX4f, QPoint, QPoint *);

	QPixmap Filtered(QImage, QPixmap, QRect, QMat *);
	QImage toImg(QImage, SMat1f, Mat1i, Mat1b, QPoint *, QPoint);

private:
	
	int Filter(Mat4b *, QRect *);

	Mat1b toEig(Mat4b, QRect);
	Mat1b cutMat(Mat1b, QRect);
	Mat4b cutImg(QImage, Mat1b, QRect);
	MatrixX4f pSolver(SMat1f, MatrixX4f);

	int divG(Mat4b, QPoint, int);
	int Neighbor(Mat4b, Mat1b, QPoint, QPoint, int);
	bool adjacent(QPoint, QPoint);
};

