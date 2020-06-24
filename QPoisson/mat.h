#pragma once
class mat
{
public:
	mat();
	~mat();

	QImage MA2QIMG(Mat4b, bool);
	Mat4b QIMG2MAT(QImage);

	Mat4b MirrorV(Mat4b);
	Mat4b MirrorH(Mat4b);
	Mat4b Invert(Mat4b);
	Mat4b Grey(Mat4b);
	Mat4b Clockwise90(Mat4b);

	Mat4b newMat4b(int, int);

	int ipArray(Mat1b, int, QPoint *);
	SMat1f Laplace(int, QPoint *);
	MatrixX4i divGArray(Mat4b, QPoint *, int);

	QPixmap Filtered(QImage, QPixmap, QRect, QMat *);
	QImage toImg(QImage, SMat1f, MatrixX4i, Mat1b, QPoint *, QPoint);

private:

	bool adjacent(QPoint, QPoint);

	int Filter(Mat4b *, QRect *);
	int divG(Mat4b, QPoint, int);
	int Neighbor(Mat4b, Mat1b, QPoint, QPoint, int);

	Mat1b toEig(Mat4b, QRect);
	Mat1b cutMat(Mat1b, QRect);

	Mat4b cutImg(QImage, Mat1b, QRect);
	Mat4b Poisson(QImage, MatrixX4i, QPoint, QPoint *);

	MatrixX4i pSolver(SMat1f, MatrixX4f);
	MatrixX4f Getb(QImage, MatrixX4i, Mat1b, QPoint, QPoint *);

	Mat4b transpose(Mat4b);
};


