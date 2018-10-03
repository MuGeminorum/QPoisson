#include "stdafx.h"
#include "opencv_qt_demo.h"

opencv_qt_demo::opencv_qt_demo(QWidget *parent) : QMainWindow(parent)
{

	setupUi(this); 
}

opencv_qt_demo::~opencv_qt_demo()
{

}

void opencv_qt_demo::setupUi(QMainWindow *opencv_qt_demoClass)
{
	if (opencv_qt_demoClass->objectName().isEmpty()) opencv_qt_demoClass->setObjectName(QStringLiteral("opencv_qt_demoClass"));
	opencv_qt_demoClass->resize(700, 600);

	actionOpen = new QAction(opencv_qt_demoClass);
	actionOpen->setObjectName(QStringLiteral("actionOpen"));
	QIcon icon;
	icon.addFile(QStringLiteral("Resources/file_32px_572850_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
	actionOpen->setIcon(icon);

	actionSave = new QAction(opencv_qt_demoClass);
	actionSave->setObjectName(QStringLiteral("actionSave"));
	QIcon icon1;
	icon1.addFile(QStringLiteral("Resources/diskette_32px_572819_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
	actionSave->setIcon(icon1);

	actionMirrorH = new QAction(opencv_qt_demoClass);
	actionMirrorH->setObjectName(QStringLiteral("actionMirrorH"));
	QIcon icon2;
	icon2.addFile(QStringLiteral("Resources/flip_horizontal_32px_572874_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
	actionMirrorH->setIcon(icon2);

	actionMirrorV = new QAction(opencv_qt_demoClass);
	actionMirrorV->setObjectName(QStringLiteral("actionMirrorV"));
	QIcon icon3;
	icon3.addFile(QStringLiteral("Resources/flip_vertical_32px_572875_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
	actionMirrorV->setIcon(icon3);

	actionTurn = new QAction(opencv_qt_demoClass);
	actionTurn->setObjectName(QStringLiteral("actionTurn"));
	QIcon icon4;
	icon4.addFile(QStringLiteral("Resources/reload_32px_573065_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
	actionTurn->setIcon(icon4);

	actionInvert = new QAction(opencv_qt_demoClass);
	actionInvert->setObjectName(QStringLiteral("actionInvert"));
	QIcon icon5;
	icon5.addFile(QStringLiteral("Resources/protocol_32px_573045_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
	actionInvert->setIcon(icon5);

	actionGrey = new QAction(opencv_qt_demoClass);
	actionGrey->setObjectName(QStringLiteral("actionGrey"));
	actionGrey->setCheckable(true);
	QIcon icon6;
	icon6.addFile(QStringLiteral("Resources/contrast_32px_572784_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
	actionGrey->setIcon(icon6);

	actionPolygon = new QAction(opencv_qt_demoClass);
	actionPolygon->setObjectName(QStringLiteral("actionPolygon"));
	actionPolygon->setCheckable(true);
	QIcon icon7;
	icon7.addFile(QStringLiteral("Resources/polygon_32px_1169471_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
	actionPolygon->setIcon(icon7);

	actionRect = new QAction(opencv_qt_demoClass);
	actionRect->setObjectName(QStringLiteral("actionRect"));
	actionRect->setCheckable(true);
	QIcon icon8;
	icon8.addFile(QStringLiteral("Resources/square_32px_1170579_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
	actionRect->setIcon(icon8);

	actionOval = new QAction(opencv_qt_demoClass);
	actionOval->setObjectName(QStringLiteral("actionOval"));
	actionOval->setCheckable(true);
	QIcon icon9;
	icon9.addFile(QStringLiteral("Resources/ellipse_stroked_32px_1168912_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
	actionOval->setIcon(icon9);

	actionImport = new QAction(opencv_qt_demoClass);
	actionImport->setObjectName(QStringLiteral("actionImport"));
	QIcon icon10;
	icon10.addFile(QStringLiteral("Resources/windows_32px_573226_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
	actionImport->setIcon(icon10);

	actionExport = new QAction(opencv_qt_demoClass);
	actionExport->setObjectName(QStringLiteral("actionExport"));
	QIcon icon11;
	icon11.addFile(QStringLiteral("Resources/document_diskette_32px_577567_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
	actionExport->setIcon(icon11);

	actionInsert = new QAction(opencv_qt_demoClass);
	actionInsert->setObjectName(QStringLiteral("actionInsert"));
	QIcon icon12;
	icon12.addFile(QStringLiteral("Resources/file_transfer_32px_572861_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
	actionInsert->setIcon(icon12);

	actionPossion = new QAction(opencv_qt_demoClass);
	actionPossion->setObjectName(QStringLiteral("actionPossion"));
	actionPossion->setCheckable(true);
	QIcon icon13;
	icon13.addFile(QStringLiteral("Resources/match_width_and_height_32px_572964_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
	actionPossion->setIcon(icon13);

	actionErase = new QAction(opencv_qt_demoClass);
	actionErase->setObjectName(QStringLiteral("actionErase"));
	QIcon icon14;
	icon14.addFile(QStringLiteral("Resources/eraser_32px_1197080_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
	actionErase->setIcon(icon14);

	actionEmpty = new QAction(opencv_qt_demoClass);
	actionEmpty->setObjectName(QStringLiteral("actionEmpty"));
	QIcon icon15;
	icon15.addFile(QStringLiteral("Resources/empty_32px_1161884_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
	actionEmpty->setIcon(icon15);

	centralWidget = new QWidget(opencv_qt_demoClass);
	centralWidget->setObjectName(QStringLiteral("centralWidget"));
	opencv_qt_demoClass->setCentralWidget(centralWidget);

	statusBar = new QStatusBar(opencv_qt_demoClass);
	statusBar->setObjectName(QStringLiteral("statusBar"));
	opencv_qt_demoClass->setStatusBar(statusBar);

	mainToolBar = new QToolBar(opencv_qt_demoClass);
	mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
	opencv_qt_demoClass->addToolBar(Qt::TopToolBarArea, mainToolBar);

	menuBar = new QMenuBar(opencv_qt_demoClass);
	menuBar->setObjectName(QStringLiteral("menuBar"));
	menuBar->setGeometry(QRect(0, 0, 600, 26));

	menuOpen = new QMenu(menuBar);
	menuOpen->setObjectName(QStringLiteral("menuOpen"));

	menuTransform = new QMenu(menuBar);
	menuTransform->setObjectName(QStringLiteral("menuTransform"));

	menuSelect = new QMenu(menuBar);
	menuSelect->setObjectName(QStringLiteral("menuSelect"));

	menuPossion = new QMenu(menuBar);
	menuPossion->setObjectName(QStringLiteral("menuPossion"));
	opencv_qt_demoClass->setMenuBar(menuBar);

	mainToolBar->addAction(actionOpen);
	mainToolBar->addAction(actionSave);

	mainToolBar->addSeparator();
	mainToolBar->addAction(actionMirrorH);
	mainToolBar->addAction(actionMirrorV);
	mainToolBar->addAction(actionTurn);
	mainToolBar->addAction(actionInvert);
	mainToolBar->addAction(actionGrey);

	mainToolBar->addSeparator();
	mainToolBar->addAction(actionRect);
	mainToolBar->addAction(actionPolygon);
	mainToolBar->addAction(actionOval);
	mainToolBar->addAction(actionEmpty);

	mainToolBar->addSeparator();
	mainToolBar->addAction(actionImport);
	mainToolBar->addAction(actionExport);
	mainToolBar->addAction(actionInsert);
	mainToolBar->addAction(actionPossion);
	mainToolBar->addAction(actionErase);

	menuBar->addAction(menuOpen->menuAction());
	menuBar->addAction(menuTransform->menuAction());
	menuBar->addAction(menuSelect->menuAction());
	menuBar->addAction(menuPossion->menuAction());

	mdiArea = new QMdiArea(centralWidget);
	mdiArea->setGeometry(QRect(0, 0, 610, 610));
	imgBox = new showImage(centralWidget);
	imgBox->setAttribute(Qt::WA_DeleteOnClose, false);
	subimgBox = new subImg(centralWidget);
	subimgBox->setAttribute(Qt::WA_DeleteOnClose, false);
	connectWidgets(opencv_qt_demoClass);
	retranslateUi(opencv_qt_demoClass);

} // setupUi

void opencv_qt_demo::connectWidgets(QMainWindow *opencv_qt_demoClass)
{
	QMetaObject::connectSlotsByName(opencv_qt_demoClass);

	QObject::connect(actionTurn, SIGNAL(triggered()), imgBox, SLOT(turn()));
	QObject::connect(actionMirrorV, SIGNAL(triggered()), imgBox, SLOT(reflect()));
	QObject::connect(actionMirrorH, SIGNAL(triggered()), imgBox, SLOT(rever()));
	QObject::connect(actionInvert, SIGNAL(triggered()), imgBox, SLOT(anticolor()));
	QObject::connect(actionGrey, SIGNAL(toggled(bool)), imgBox, SLOT(grey(bool)));

	QObject::connect(actionPolygon, SIGNAL(toggled(bool)), this, SLOT(polychecked(bool)));
	QObject::connect(actionRect, SIGNAL(toggled(bool)), this, SLOT(rectchecked(bool)));
	QObject::connect(actionOval, SIGNAL(toggled(bool)), this, SLOT(ovalchecked(bool)));

	QObject::connect(actionOpen, SIGNAL(triggered()), this, SLOT(openImage()));
	QObject::connect(actionSave, SIGNAL(triggered()), this, SLOT(saveImage()));
	QObject::connect(this, SIGNAL(loadImg(QString)), imgBox, SLOT(load(QString)));
	QObject::connect(this, SIGNAL(saveImg(QString)), imgBox, SLOT(save(QString)));

	QObject::connect(imgBox, SIGNAL(LoadComplete()), this, SLOT(LoadFinished()));
	QObject::connect(imgBox, SIGNAL(SaveComplete()), this, SLOT(SaveFinished()));
	QObject::connect(imgBox, SIGNAL(QuitImg()), this, SLOT(ImgClosed()));
	QObject::connect(imgBox, SIGNAL(turnImg()), this, SLOT(imgResize()));

	QObject::connect(imgBox, SIGNAL(selectcomplete(bool)), this, SLOT(allowinsert(bool)));

	QObject::connect(this, SIGNAL(setpoly(bool)), imgBox, SLOT(poly(bool)));
	QObject::connect(this, SIGNAL(setrect(bool)), imgBox, SLOT(rect(bool)));
	QObject::connect(this, SIGNAL(setoval(bool)), imgBox, SLOT(oval(bool)));

	QObject::connect(actionImport, SIGNAL(triggered()), this, SLOT(importImg()));
	QObject::connect(this, SIGNAL(loadSubimg(QString)), subimgBox, SLOT(load(QString)));
	QObject::connect(subimgBox, SIGNAL(LoadComplete()), this, SLOT(subload()));
	QObject::connect(subimgBox, SIGNAL(quitsubimg()), this, SLOT(subimgclosed()));

	QObject::connect(actionEmpty, SIGNAL(triggered()), imgBox, SLOT(empty()));
	QObject::connect(actionInsert, SIGNAL(triggered()), imgBox, SLOT(insertImg()));
	QObject::connect(imgBox, SIGNAL(inserting(QMat)), subimgBox, SLOT(insert(QMat)));

	QObject::connect(actionErase, SIGNAL(triggered()), subimgBox, SLOT(erase()));	
	QObject::connect(subimgBox, SIGNAL(inserted(bool)), actionPossion, SLOT(setEnabled(bool)));
	QObject::connect(subimgBox, SIGNAL(inserted(bool)), actionErase, SLOT(setEnabled(bool)));
	QObject::connect(subimgBox, SIGNAL(inserted(bool)), actionExport, SLOT(setEnabled(bool)));

	QObject::connect(subimgBox, SIGNAL(erased(bool)), actionPossion, SLOT(setChecked(bool)));
	QObject::connect(subimgBox, SIGNAL(erased(bool)), actionPossion, SLOT(setEnabled(bool)));
	QObject::connect(subimgBox, SIGNAL(erased(bool)), actionErase, SLOT(setEnabled(bool)));
	QObject::connect(subimgBox, SIGNAL(erased(bool)), actionExport, SLOT(setEnabled(bool)));

	QObject::connect(imgBox, SIGNAL(cleaned(bool)), actionInsert, SLOT(setEnabled(bool)));
	QObject::connect(subimgBox, SIGNAL(fainsert(bool)), this, SLOT(insertFailed(bool)));

	QObject::connect(actionPossion, SIGNAL(toggled(bool)), subimgBox, SLOT(possion(bool)));
}

void opencv_qt_demo::retranslateUi(QMainWindow *opencv_qt_demoClass)
{
	opencv_qt_demoClass->setWindowTitle(QApplication::translate("opencv_qt_demoClass", "opencv_qt_demo", 0));
	actionOpen->setText(QApplication::translate("opencv_qt_demoClass", "Open", 0));
	actionSave->setText(QApplication::translate("opencv_qt_demoClass", "Save", 0));
	actionSave->setToolTip(QApplication::translate("opencv_qt_demoClass", "Save", 0));
	actionMirrorH->setText(QApplication::translate("opencv_qt_demoClass", "MirrorH", 0));
	actionMirrorV->setText(QApplication::translate("opencv_qt_demoClass", "MirrorV", 0));
	actionTurn->setText(QApplication::translate("opencv_qt_demoClass", "Turn", 0));
	actionInvert->setText(QApplication::translate("opencv_qt_demoClass", "Invert", 0));
	actionGrey->setText(QApplication::translate("opencv_qt_demoClass", "Grey", 0));
	actionPolygon->setText(QApplication::translate("opencv_qt_demoClass", "Polygon", 0));
	actionRect->setText(QApplication::translate("opencv_qt_demoClass", "Rect", 0));
	actionOval->setText(QApplication::translate("opencv_qt_demoClass", "Oval", 0));
	actionEmpty->setText(QApplication::translate("opencv_qt_demoClass", "Empty", 0));

	actionImport->setText(QApplication::translate("opencv_qt_demoClass", "Import", 0));
	actionExport->setText(QApplication::translate("opencv_qt_demoClass", "Export", 0));
	actionInsert->setText(QApplication::translate("opencv_qt_demoClass", "Insert", 0));
	actionPossion->setText(QApplication::translate("opencv_qt_demoClass", "Possion", 0));
	actionErase->setText(QApplication::translate("opencv_qt_demoClass", "Erase", 0));

	menuOpen->setTitle(QApplication::translate("opencv_qt_demoClass", "File", 0));
	menuTransform->setTitle(QApplication::translate("opencv_qt_demoClass", "Transform", 0));
	menuSelect->setTitle(QApplication::translate("opencv_qt_demoClass", "Select", 0));
	menuPossion->setTitle(QApplication::translate("opencv_qt_demoClass", "Possion", 0));

	ImgClosed();
} // retranslateUi

void opencv_qt_demo::resizeEvent(QResizeEvent *event)
{
	int w = this->width();
	int h = this->height();

	mdiArea->setFixedSize(this->width(), this->height());

}

void opencv_qt_demo::allowinsert(bool c)
{
	if (mdiArea->subWindowList(QMdiArea::CreationOrder).count() == 2)
	{
		actionInsert->setEnabled(c);
	}
	else
	{
		actionInsert->setEnabled(false);
	}
}

void opencv_qt_demo::polychecked(bool c)
{
	if (c)
	{
		actionRect->setChecked(false);
		actionOval->setChecked(false);
	}

	emit setpoly(c);
}

void opencv_qt_demo::rectchecked(bool c)
{
	if (c)
	{
		actionPolygon->setChecked(false);
		actionOval->setChecked(false);
	}

	emit setrect(c);
}

void opencv_qt_demo::ovalchecked(bool c)
{
	if (c)
	{
		actionPolygon->setChecked(false);
		actionRect->setChecked(false);
	}

	emit setoval(c);
}

void opencv_qt_demo::openImage(void)
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open image file"), "./", tr("Image files(*.bmp *.gif *.jpg *.jpeg *.png *.pbm *.pgm *.ppm *.xbm *.xpm)"));
	if (!fileName.isEmpty())
	{

		int SUBWinCount = mdiArea->subWindowList(QMdiArea::CreationOrder).count();

		if (SUBWinCount > 0)
		{
			if (SUBWinCount == 2) mdiArea->removeSubWindow(subimgBox);
			mdiArea->removeSubWindow(imgBox);
			mdiArea->closeAllSubWindows();
		}

		mainToolBar->setEnabled(false);
		emit loadImg(fileName);
	}
}

void opencv_qt_demo::importImg(void)
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open image file"), "./", tr("Image files(*.bmp *.gif *.jpg *.jpeg *.png *.pbm *.pgm *.ppm *.xbm *.xpm)"));
	if (!fileName.isEmpty())
	{
		if (mdiArea->subWindowList(QMdiArea::CreationOrder).count() == 2) mdiArea->subWindowList(QMdiArea::CreationOrder).at(1)->close(); 
		mainToolBar->setEnabled(false);
		emit loadSubimg(fileName);
	}
}

void opencv_qt_demo::subload(void)  // subimg load complete
{

	mdiArea->addSubWindow(subimgBox, windowFlags()&~Qt::WindowMinMaxButtonsHint);
	
	QMdiSubWindow *csw = mdiArea->subWindowList(QMdiArea::CreationOrder).at(1);
	int h = subimgBox->height();
	int w = subimgBox->width();
	int mw = w + 2 * SUBWIN_BORDER;
	int mh = h + SUBWIN_BORDER + SUBWIN_HEAD;
	csw->setFixedSize(mw, mh);

	subimgBox->show();
	mdiArea->tileSubWindows();
	mainToolBar->setEnabled(true);

	actionPolygon->setEnabled(true);
	actionRect->setEnabled(true);
	actionOval->setEnabled(true);
	actionEmpty->setEnabled(true);
	actionPolygon->setChecked(false);
	actionRect->setChecked(false);
	actionOval->setChecked(false);
	actionPossion->setChecked(false);
}

void opencv_qt_demo::saveImage(void)
{
	QString file_path = QFileDialog::getSaveFileName(this, tr("Save File"), "./", tr("BMP (*.bmp);;JPG (*.jpg);;JPEG (*.jpeg);;PNG(*.png);;PPM(*.ppm);;XBM(*.xbm);;XPM(*.xpm)"));
	if (!file_path.isEmpty())
	{		
		mainToolBar->setEnabled(false);
		if (QFileInfo(file_path).suffix().isEmpty()) file_path.append(".png");
		emit saveImg(file_path);
	}	

}

void opencv_qt_demo::exportImg(void)
{
	QString file_path = QFileDialog::getSaveFileName(this, tr("Save File"), "./", tr("BMP (*.bmp);;JPG (*.jpg);;JPEG (*.jpeg);;PNG(*.png);;PPM(*.ppm);;XBM(*.xbm);;XPM(*.xpm)"));
	if (!file_path.isEmpty())
	{
		mainToolBar->setEnabled(false);
		if (QFileInfo(file_path).suffix().isEmpty()) file_path.append(".png");
		emit expImg(file_path);
	}

}

void opencv_qt_demo::ImgClosed(void)
{
	mainToolBar->setEnabled(true);
	actionOpen->setEnabled(true);
	actionSave->setEnabled(false);
	actionMirrorH->setEnabled(false);
	actionMirrorV->setEnabled(false);
	actionTurn->setEnabled(false);
	actionGrey->setEnabled(false);
	actionInvert->setEnabled(false);
	actionPolygon->setEnabled(false);
	actionRect->setEnabled(false);
	actionOval->setEnabled(false);
	actionEmpty->setEnabled(false);
	actionImport->setEnabled(false);
	subimgclosed();

	mdiArea->removeSubWindow(imgBox);
	mdiArea->closeAllSubWindows();
}

void opencv_qt_demo::subimgclosed(void)
{
	if (mdiArea->subWindowList(QMdiArea::CreationOrder).count() == 2) {
		mdiArea->removeSubWindow(subimgBox);
		mdiArea->subWindowList(QMdiArea::CreationOrder).at(1)->close();
	}

	actionExport->setEnabled(false);
	actionInsert->setEnabled(false);
	actionPossion->setEnabled(false);
	actionErase->setEnabled(false);
}

void opencv_qt_demo::LoadFinished(void)
{
	mdiArea->addSubWindow(imgBox, windowFlags()&~Qt::WindowMinMaxButtonsHint);
	imgResize(); 
	SaveFinished();

	actionGrey->setChecked(false);
	actionPolygon->setEnabled(false);
	actionRect->setEnabled(false);
	actionOval->setEnabled(false);
	actionPolygon->setChecked(false);
	actionRect->setChecked(false);
	actionOval->setChecked(false);
	actionImport->setEnabled(true);
	actionPossion->setChecked(false);
	actionPossion->setEnabled(false);
	actionErase->setEnabled(false);
	actionExport->setEnabled(false);
	 
}

void opencv_qt_demo::imgResize(void)
{
	QMdiSubWindow *csw = mdiArea->subWindowList(QMdiArea::CreationOrder).at(0);
	int h = imgBox->height();
	int w = imgBox->width();
	int mw = w + 2 * SUBWIN_BORDER;
	int mh = h + SUBWIN_BORDER + SUBWIN_HEAD;
	csw->setFixedSize(mw, mh);
	imgBox->show();
}

void opencv_qt_demo::SaveFinished(void)
{

	mainToolBar->setEnabled(true);
	actionOpen->setEnabled(true);
	actionSave->setEnabled(true);
	actionMirrorH->setEnabled(true);
	actionMirrorV->setEnabled(true);
	actionTurn->setEnabled(true);
	actionGrey->setEnabled(true);
	actionInvert->setEnabled(true);
}

void opencv_qt_demo::insertFailed(bool f)
{
	if (f)
	{
		QMessageBox::about(NULL, "Failed", "Oversized fragment!");
	}
	else
	{
		actionPossion->setChecked(f);
	}
}


