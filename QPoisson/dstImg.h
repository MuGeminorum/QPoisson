#ifdef QT_DEBUG
#pragma comment (lib,"qtmaind.lib")
#pragma comment (lib,"Qt5Cored.lib")
#pragma comment (lib,"Qt5Guid.lib")
#pragma comment (lib,"Qt5Widgetsd.lib")
#endif

#pragma once 
#include "mat.h"

class dstImg : public QWidget
{
	Q_OBJECT

public:
	dstImg(QWidget *parent = 0);
	~dstImg();

private:
	Mat4b M;
	QImage img;
	QImage pimg;
	mat *mf;
	QPixmap pix;
	QRect movePos;
	QMat QM;
	SMat1f iA;
	MatrixX4i divG;
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

