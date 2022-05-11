#ifdef QT_DEBUG
#pragma comment (lib,"qtmaind.lib")
#pragma comment (lib,"Qt5Cored.lib")
#pragma comment (lib,"Qt5Guid.lib")
#pragma comment (lib,"Qt5Widgetsd.lib")
#endif

#pragma once
#include "mat.h"

class srcImg : public QWidget
{
	Q_OBJECT

public:
	srcImg(QWidget *parent = 0);
	~srcImg();

private:
	Mat4b M;
	QMat shape;
	bool MODE;
	QImage img;
	mat *mf;

	QPoint startPos;
	QPoint endPos;
	QPoint curPos;

	QPixmap pix;
	QPixmap tempix;

	QPolygon polygon;
	QRect preArea;

	bool closed;
	bool pressing;
	int figure;

	void setupUI(QWidget *);
	void clearMask(QImage);

	void paintPoly(QPainter *);
	void paintRect(QPainter *);
	void paintOval(QPainter *);

	void drawPoly(QMouseEvent *);
	void drawRect(QMouseEvent *);
	void drawOval(QMouseEvent *);

	void updPoly(QMouseEvent *);
	void updRect(QMouseEvent *);
	void updOval(QMouseEvent *);

	void fillPoly(QPixmap *);
	void fillRect(QPixmap *);
	void fillOval(QPixmap *);

	void setPoint(QPixmap *, QPoint);
	void setLine(QPixmap *, QPoint, QPoint, Qt::GlobalColor);
	void setRect(QPixmap *, QPoint, QPoint);
	void setOval(QPixmap *, QPoint, QPoint);

	void confirmPoly(QMouseEvent *);
	void confirmRect(QMouseEvent *);
	void confirmOval(QMouseEvent *);

	void clearPix(QPixmap *);

	QPoint confine(QPoint);
	bool isColinear(QPoint, QPoint, QPoint);
	bool Neighbor(QPoint, QPoint);
	bool leastPix(QPoint, QPoint);
	bool leastRect(QRect);

	QRect Range(QPolygon);
	QRect Positive(QPoint, QPoint);

protected:
	void paintEvent(QPaintEvent *);
	void closeEvent(QCloseEvent *);
	void mousePressEvent(QMouseEvent *);
	void mouseMoveEvent(QMouseEvent *);
	void mouseReleaseEvent(QMouseEvent *);

public slots:
	void turn(void);
	void rever(void);
	void reflect(void);
	void anticolor(void);

	void load(QString);
	void save(QString);
	void grey(bool);
	void poly(bool);
	void rect(bool);
	void oval(bool);
	void empty(void);

	void insertImg(void);

signals:
	void LoadComplete(void);
	void SaveComplete(void);
	void QuitImg(void);
	void turnImg(void);
	void selectcomplete(bool);
	void inserting(QMat);
	void cleaned(bool);
};
