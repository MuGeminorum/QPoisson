#pragma once
#include <QtWidgets/QWidget>
#include"matrix.h"

class subImg : public QWidget
{
	Q_OBJECT

public:
	subImg(QWidget *parent = 0);
	~subImg();

private:
	Mat M;
	QImage img;
	QImage pimg;
	matrix *mf; 
	QPixmap pix;
	QRect movePos;
	QMat QM;
	Mat1f iA;
	Mat1f divG;
	QPoint *innerPos;

	QPoint startPos;
	QPoint curPos;
	bool pressing;
	bool isPossion;

	void clearMask(QImage);
	bool inRect(QRect, QPoint);
	QPoint confine(QPoint);

signals:
	void LoadComplete(void);
	void quitsubimg(void);
	void inserted(bool);
	void erased(bool);
	void fainsert(bool);
	void savecomplete(void);

protected:
	void paintEvent(QPaintEvent *);
	void closeEvent(QCloseEvent *);
	void mousePressEvent(QMouseEvent *);
	void mouseMoveEvent(QMouseEvent *);
	void mouseReleaseEvent(QMouseEvent *);

public slots:
	void load(QString);
	void insert(QMat);
	void erase(void);
	void possion(bool);
	void save(QString);

};

