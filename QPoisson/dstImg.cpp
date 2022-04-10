#include "dstImg.h"


dstImg::dstImg(QWidget *parent)
{
	pressing = isPossion = false;
	startPos = curPos = QPoint(0, 0);
	movePos.setRect(0, 0, 0, 0);

	setMouseTracking(true);
	this->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
	this->setAutoFillBackground(true);
}


dstImg::~dstImg()
{
}

void dstImg::load(QString imgPath)
{
	img.load(imgPath);
	setWindowTitle("Target - " + QFileInfo(imgPath).fileName());
	M = mf->QIMG2MAT(img);
	clearMask(img);
	emit LoadComplete();
}

void dstImg::clearMask(QImage img)
{
	int w = img.width();
	int h = img.height();
	setFixedSize(w, h);
	pix.fill(Qt::transparent);
	update();
}

void dstImg::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);

	if (isPossion)
	{
		painter.drawImage(QRect(0, 0, pimg.width(), pimg.height()), pimg);
	}
	else
	{
		painter.drawImage(QRect(0, 0, img.width(), img.height()), img);
		if (!pix.isNull()) painter.drawPixmap(movePos.topLeft(), pix);
	}
}

void dstImg::closeEvent(QCloseEvent *event)
{
	emit quitsubimg();
}

void dstImg::mousePressEvent(QMouseEvent *event)
{
	if (inRect(movePos, event->pos()))
	{
		pressing = true;
		startPos = event->pos() - movePos.topLeft();
	}
}

void dstImg::mouseReleaseEvent(QMouseEvent *event)
{
	pressing = false;
}

void dstImg::mouseMoveEvent(QMouseEvent *event)
{
	if (pressing)
	{
		curPos = confine(event->pos());
		movePos.moveTopLeft(curPos - startPos);

		if (isPossion) pimg = mf->toImg(img, iA, divG, QM.eMat, innerPos, movePos.topLeft());

		update();
	}

	setCursor(inRect(movePos, event->pos()) ? Qt::SizeAllCursor : Qt::ArrowCursor);
}

bool dstImg::inRect(QRect r, QPoint p)
{
	int left = r.x();
	int top = r.y();
	int right = left + r.width() - 1;
	int bottom = top + r.height() - 1;

	return (p.x() >= left) && (p.x() <= right) && (p.y() >= top) && (p.y() <= bottom);

}

QPoint dstImg::confine(QPoint p)
{
	int x = p.x();
	int y = p.y();

	int dLeft = startPos.x();
	int dTop = startPos.y();
	int dRight = movePos.width() - 1 - dLeft;
	int dBottom = movePos.height() - 1 - dTop;

	if (p.x() < dLeft) x = dLeft;
	if (p.x() > img.width() - 1 - dRight) x = img.width() - 1 - dRight;
	if (p.y() < dTop) y = dTop;
	if (p.y() > img.height() - 1 - dBottom) y = img.height() - 1 - dBottom;

	return QPoint(x, y);
}

void dstImg::insert(QMat A)
{
	QM = A;
	innerPos = (QPoint *)malloc((QM.iNum) * sizeof(QPoint));
	int k = mf->ipArray(QM.eMat, QM.iNum, &innerPos[0]);
	iA = mf->Laplace(k, innerPos);
	divG = mf->divGArray(QM.iMat, innerPos, k);

	Mat4b B = QM.iMat;
	int w = B.cols;
	int h = B.rows;

	if (w <= img.width() && h <= img.height())
	{
		int x = (img.width() - w) / 2;
		int y = (img.height() - h) / 2;

		pix = QPixmap::fromImage(mf->MA2QIMG(B, false));
		movePos = QRect(x, y, w, h);
		update();
		emit inserted(true);
		emit fainsert(false);
	}
	else
	{
		emit fainsert(true);
	}
}

void dstImg::erase(void)
{
	pix.fill(Qt::transparent);
	update();
	emit erased(false);
}

void dstImg::possion(bool p)
{
	isPossion = p;
	if (isPossion) pimg = mf->toImg(img, iA, divG, QM.eMat, innerPos, movePos.topLeft());
	update();
}

void dstImg::save(QString fp)
{
	isPossion ? pimg.save(fp) : img.save(fp);
	emit savecomplete();
}