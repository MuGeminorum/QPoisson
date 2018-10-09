#include "stdafx.h"
#include "showImage.h"

showImage::showImage(QWidget *parent)
{
	setupUI(this);

	closed = pressing = false;
	MODE = MODE_RGB;
	figure = FIGURE_NONE;
	
	shape.iNum = 0;
	shape.eMat = Mat1b::zeros(2, 2);
	shape.iMat = Mat4b::zeros(2, 2);

	startPos = curPos = endPos = QPoint(0, 0);
	preArea = QRect(0, 0, 0, 0);
}


showImage::~showImage()
{
	
}

void showImage::setupUI(QWidget *opencv_qt_demoClass)
{
	opencv_qt_demoClass->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
	opencv_qt_demoClass->setAutoFillBackground(true);
}
 

void showImage::setRect(QPixmap *p, QPoint s, QPoint t)
{
	QPen tempen(Qt::red, 1, Qt::SolidLine);
	QPainter painter(&tempix);
	painter.setPen(tempen);
	painter.drawRect(s.x(), s.y(), t.x() - s.x(), t.y() - s.y());
	painter.end();
} 

void showImage::setOval(QPixmap *p, QPoint s, QPoint t)
{
	QPen tempen(Qt::red, 1, Qt::SolidLine);
	QPainter painter(&tempix);
	painter.setPen(tempen);
	painter.drawEllipse(s.x(), s.y(), t.x() - s.x(), t.y() - s.y());
	painter.end();
}

void showImage::setLine(QPixmap *p, QPoint s, QPoint t, Qt::GlobalColor c)
{
	QPen tempen(c, 1, Qt::SolidLine);
	QPainter painter(p);
	painter.setPen(tempen);
	painter.drawLine(s, t);  //curPos
	painter.end();
}

void showImage::fillPoly(QPixmap *p)
{
	QPainter paintemp(p);
	paintemp.setBrush(Qt::red);
	paintemp.setOpacity(0.5);
	paintemp.drawPolygon(polygon);
	paintemp.end();
}

void showImage::fillRect(QPixmap *p)
{
	QPainter paintemp(p);
	paintemp.setBrush(Qt::red);
	paintemp.setOpacity(0.5);

	int x = startPos.x();
	int y = startPos.y();
	int w = endPos.x() - x;
	int h = endPos.y() - y;

	QRect RectBound(x, y, w, h);
	QPainterPath rectPath;
	rectPath.addRect(RectBound);
	
	paintemp.drawPath(rectPath);
	paintemp.end();
}

void showImage::fillOval(QPixmap *p)
{
	QPainter paintemp(p);
	paintemp.setBrush(Qt::red);
	paintemp.setOpacity(0.5);

	int x = startPos.x();
	int y = startPos.y();
	int w = endPos.x() - x;
	int h = endPos.y() - y;

	QRect OvalBound(x, y, w, h);
	QPainterPath ovalPath;
	ovalPath.addEllipse(OvalBound);

	paintemp.drawPath(ovalPath);
	paintemp.end();
}

void showImage::clearPix(QPixmap *p)
{
	(*p) = QPixmap(size());
	(*p).fill(Qt::transparent);
}

void showImage::paintPoly(QPainter *painter)    // paintEvent
{
	(*painter).drawPixmap(QPoint(0, 0), pix);
	if (polygon.count() > 0) (*painter).drawPixmap(QPoint(0, 0), tempix); 
}

void showImage::setPoint(QPixmap *p, QPoint d)
{
	QPen tempen(Qt::red, 1, Qt::SolidLine);
	QPainter painter(p);
	painter.setPen(tempen);
	painter.drawPoint(d);
	painter.end();
}

bool showImage::isColinear(QPoint P1, QPoint P2, QPoint P)
{
	int x1 = P1.x();	
	int y1 = P1.y();

	int x2 = P2.x();
	int y2 = P2.y();

	int x = P.x();
	int y = P.y();

	return ((x - x2)*(y - y1) == (x - x1)*(y - y2));

}

void showImage::drawPoly(QMouseEvent *event)    // mousePressEvent
{
	if (event->button() == Qt::LeftButton)
	{
		emit selectcomplete(false);
		endPos = event->pos();
		int vertex = Abs(polygon.count());

		switch (vertex)
		{
		case 0:
			clearPix(&pix);
			polygon << QPoint(endPos);
			setPoint(&pix, endPos);
			update();
			startPos = endPos;
			break;

		case 1:
			if (!Neighbor(endPos, polygon.at(0)))
			{
				polygon << QPoint(endPos);
				setLine(&pix, startPos, endPos, Qt::red);
				update();
				startPos = endPos;
			}
			break;

		case 2:
			if (!Neighbor(endPos, polygon.at(0)) && !Neighbor(endPos , polygon.at(1)))
			{
				polygon << QPoint(endPos);
				setLine(&pix, startPos, endPos, Qt::red);
				update();
				startPos = endPos;
			}
			break;

		default:
			if (isColinear(polygon.at(vertex - 2), polygon.at(vertex - 1), endPos))
			{
				if (!Neighbor(endPos, polygon.at(vertex - 2)) && !Neighbor(endPos, polygon.at(vertex - 1)))
				{
					setLine(&pix, polygon.at(vertex - 2), polygon.at(vertex - 1), Qt::transparent);
					polygon.remove(vertex - 1);
					polygon << QPoint(endPos);
					setLine(&pix, startPos, endPos, Qt::red);
					update();
					startPos = endPos;
				}
			}
			else
			{
				if (Neighbor(endPos, polygon.at(0)))
				{
					closed = true;
				}
				else
				{
					polygon << QPoint(endPos);
				}
				setLine(&pix, startPos, endPos, Qt::red);
				update();
				startPos = endPos;
			}
			break;


		}

	}
}

bool showImage::Neighbor(QPoint src, QPoint dst)
{
	return (Abs(src.x() - dst.x()) <= 1) && (Abs(src.y() - dst.y()) <= 1);
}

bool showImage::leastPix(QPoint src, QPoint dst)
{
	return (Abs(dst.x() - src.x()) >= 2) && (Abs(dst.y() - src.y()) >= 2);
}

bool showImage::leastRect(QRect r)
{
	QPoint LeftUp(r.x(), r.y());
	QPoint RightDown(r.x() + r.width() - 1, r.y() + r.height() - 1);
	return leastPix(LeftUp, RightDown);
}

QRect showImage::Range(QPolygon p)
{
	QRect r(0, 0, 0, 0);

	if (p.count() > 2)
	{
		int xmax = p.at(0).x();
		int ymax = p.at(0).y();
		int xmin = p.at(0).x();
		int ymin = p.at(0).y();

		for (int i = 1; i < p.count(); i++)
		{
			xmax = max(xmax, p.at(i).x());
			ymax = max(ymax, p.at(i).y());
			xmin = min(xmin, p.at(i).x());
			ymin = min(ymin, p.at(i).y());
		}

		r.setRect(xmin, ymin, xmax - xmin, ymax - ymin);
	}

	return r;
}

void showImage::updPoly(QMouseEvent *event)    // mouseMoveEvent
{
	if (polygon.count() > 0)
	{
		if (polygon.count() > 2) setCursor(Neighbor(event->pos(), polygon.at(0)) ? Qt::CrossCursor : Qt::ArrowCursor);
		clearPix(&tempix);
		curPos = event->pos();
		setLine(&tempix, startPos, curPos, Qt::yellow);
		update();
	}
	else
	{
		setCursor(Qt::ArrowCursor);
	}
}



void showImage::paintRect(QPainter *painter)    // paintEvent
{
	(*painter).drawPixmap(QPoint(0, 0), pressing ? tempix : pix);
}

void showImage::drawRect(QMouseEvent *event)    // mousePressEvent
{
	if (event->button() == Qt::LeftButton)
	{
		emit selectcomplete(false);
		clearPix(&pix);
		pressing = true;
		startPos = event->pos();
	}
}

QPoint showImage::confine(QPoint p)
{
	int x = (p.x() > 0) ? min(p.x(), img.width() - 1) : max(p.x(), 0);
	int y = (p.y() > 0) ? min(p.y(), img.height() - 1) : max(p.y(), 0);
	return QPoint(x, y);
}

QRect showImage::Positive(QPoint s, QPoint e)
{
	int x = min(s.x(), e.x());
	int y = min(s.y(), e.y());
	int w = max(s.x(), e.x()) - x + 1;
	int h = max(s.y(), e.y()) - y + 1;

	return QRect(x, y, w, h);
}

void showImage::updRect(QMouseEvent *event)    // mouseMoveEvent
{
	if (pressing)
	{
		clearPix(&tempix);
		curPos = confine(event->pos());
		setRect(&tempix, startPos, curPos);
		update();
	} 
}

void showImage::confirmRect(QMouseEvent *event)    // mouseReleaseEvent
{
	if (!hasMouseTracking() && pressing)
	{
		pressing = false;
		endPos = confine(event->pos());

		fillRect(&pix);

		if (leastPix(startPos, endPos))
		{

			preArea = Positive(startPos, endPos);
			pix = mf->Filtered(img, pix, preArea, &shape);

			if (shape.iNum > 0)
			{
				clearPix(&tempix);
				update();
				startPos = curPos = endPos = QPoint(0, 0);
				emit selectcomplete(true);
			}
			else
			{
				clearPix(&pix);
				clearPix(&tempix);
				update();
				startPos = curPos = endPos = QPoint(0, 0);
			}

		}
		else
		{
			clearPix(&pix);
			clearPix(&tempix);
			update();
			startPos = curPos = endPos = QPoint(0, 0);
		}
	}
}

void showImage::confirmOval(QMouseEvent *event)    // mouseReleaseEvent
{
	if (!hasMouseTracking() && pressing)
	{
		pressing = false;
		endPos = confine(event->pos());

		fillOval(&pix);

		if (leastPix(startPos, endPos))
		{

			preArea = Positive(startPos, endPos);
			pix = mf->Filtered(img, pix, preArea, &shape);

			if (shape.iNum > 0)
			{
				clearPix(&tempix);
				update();
				startPos = curPos = endPos = QPoint(0, 0);
				emit selectcomplete(true);
			}
			else
			{
				clearPix(&pix);
				clearPix(&tempix);
				update();
				startPos = curPos = endPos = QPoint(0, 0);
			}

		}
		else
		{
			clearPix(&pix);
			clearPix(&tempix);
			update();
			startPos = curPos = endPos = QPoint(0, 0);
		}

	}
}

void showImage::confirmPoly(QMouseEvent *event)    // mouseReleaseEvent
{
	if (hasMouseTracking() && closed)
	{
		fillPoly(&pix);

		preArea = Range(polygon);
		pix = mf->Filtered(img, pix, preArea, &shape);

		if (leastRect(preArea) && shape.iNum > 0)
		{
			clearPix(&tempix);
			polygon.clear();
			closed = false;
			update();
			startPos = curPos = endPos = QPoint(0, 0);
			emit selectcomplete(true);
		}
		else
		{
			clearPix(&pix);
			clearPix(&tempix);
			polygon.clear();
			closed = false;
			update();
			startPos = curPos = endPos = QPoint(0, 0);
		} 

	}
}

void showImage::paintOval(QPainter *painter)    // paintEvent
{
	(*painter).drawPixmap(QPoint(0, 0), pressing ? tempix : pix);
}

void showImage::drawOval(QMouseEvent *event)    // mousePressEvent
{
	if (event->button() == Qt::LeftButton)
	{
		emit selectcomplete(false);
		clearPix(&pix);
		pressing = true;
		startPos = event->pos();
	}

}

void showImage::updOval(QMouseEvent *event)    // mouseMoveEvent
{
	if (pressing)
	{
		clearPix(&tempix);
		curPos = confine(event->pos());
		setOval(&tempix, startPos, curPos);
		update();
	} 

}


void showImage::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	painter.drawImage(QRect(0, 0, img.width(), img.height()), img);

	switch (figure)
	{
	case FIGURE_POLY: paintPoly(&painter); break;
	case FIGURE_RECT: paintRect(&painter); break;
	case FIGURE_OVAL: paintOval(&painter); break;

	default:
		break;
	}
}

void showImage::closeEvent(QCloseEvent *event)
{
	emit QuitImg();
}

void showImage::mousePressEvent(QMouseEvent *event)
{
	switch (figure)
	{
	case FIGURE_POLY: drawPoly(event); break;
	case FIGURE_RECT: drawRect(event); break;
	case FIGURE_OVAL: drawOval(event); break;

	default:
		break;
	}
}

void showImage::mouseReleaseEvent(QMouseEvent *event)
{
	switch (figure)
	{
	case FIGURE_POLY: confirmPoly(event); break;
	case FIGURE_RECT: confirmRect(event); break;
	case FIGURE_OVAL: confirmOval(event); break;

	default:
		break;
	}
}

void showImage::mouseMoveEvent(QMouseEvent *event)
{
	switch (figure)
	{
	case FIGURE_POLY: updPoly(event); break;
	case FIGURE_RECT: updRect(event); break;
	case FIGURE_OVAL: updOval(event); break;

	default:
		break;
	}
}
 
void showImage::clearMask(QImage img)
{
	int w = img.width();
	int h = img.height();

	setFixedSize(w, h);
	clearPix(&pix);
	clearPix(&tempix);
	if (polygon.count() > 0) polygon.clear();
	update();
	startPos = curPos = endPos = QPoint(0, 0);
	emit cleaned(false);
}

void showImage::load(QString imgPath)
{
	img.load(imgPath);    // here we can add a messagebox to hint wether loading is successful
	setWindowTitle("Source - " + getFileName(imgPath));
	M = mf->QIMG2MAT(img);
	clearMask(img);
	emit LoadComplete();
}

void showImage::turn(void)
{
	M = mf->Clockwise90(M);
	img = mf->MA2QIMG(M, MODE);
	clearMask(img);
	emit turnImg();
}

void showImage::rever(void)
{
	M = mf->MirrorH(M);
	img = mf->MA2QIMG(M, MODE);
	clearMask(img);
}

void showImage::reflect(void)
{
	M = mf->MirrorV(M);
	img = mf->MA2QIMG(M, MODE);
	clearMask(img);
}

void showImage::anticolor(void)
{
	M = mf->Invert(M);
	img = mf->MA2QIMG(M, MODE); 
	clearMask(img);
}

void showImage::grey(bool mode)
{
	MODE = mode;
	img = mf->MA2QIMG(M, MODE); 
	clearMask(img);
}

void showImage::save(QString fp)
{
	img.save(fp);
	emit SaveComplete();
}

void showImage::poly(bool p)
{
	emit selectcomplete(false);
	setMouseTracking(true); 
	figure = p ? FIGURE_POLY : FIGURE_NONE;
	clearMask(img); 
}

void showImage::rect(bool p)
{
	emit selectcomplete(false);
	setMouseTracking(false); 
	figure = p ? FIGURE_RECT : FIGURE_NONE;
	clearMask(img); 
}

void showImage::oval(bool p)
{
	emit selectcomplete(false);
	setMouseTracking(false); 
	figure = p ? FIGURE_OVAL : FIGURE_NONE;
	clearMask(img); 
}

void showImage::insertImg(void)
{
	emit inserting(shape);
}

void showImage::empty(void)
{
	clearMask(img);
	emit cleaned(false);
}