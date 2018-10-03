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

	QMat Filtered(QImage, QPixmap, QRect);

	Mat1f iLaplace(Mat1b, int, QPoint *);
	Mat1f Getb(QImage, Mat1f, Mat1b, QPoint, QPoint *);

	Mat4b Possion(QImage, Mat1f, QPoint, QPoint *);
	QImage toImg(QImage, Mat1f, Mat1f, Mat1b, QPoint *, QPoint);

	Mat1f divGArray(Mat4b, QPoint *, int);

private:

	Mat1b newKernal(void); 
	Mat4b toPix(Mat1b, QRect);
	Mat1b Filter(Mat4b, QRect);
	Mat1b Expand(Mat1b , QRect);
	Mat1b cutMat(Mat1b, QRect);
	Mat4b cutArea(QImage, Mat1b, QRect);
	QRect shrink(Mat1b, QRect); 

	double divG(Mat4b, QPoint, int);
	double Neighbor(Mat4b, Mat1b, QPoint, QPoint, int);

	int isNULL(Mat1b, QRect);
	bool Conv(Mat1b); 
	bool adjacent(QPoint, QPoint);
};

