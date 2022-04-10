#include "qpoisson.h"

#define SUBWIN_BORDER 8
#define SUBWIN_HEAD 32

#ifdef QT_NO_DEBUG
#define BASE QString(":/")
#else
#define BASE QString("")
#endif

QPoisson::QPoisson(QWidget *parent)
	: QMainWindow(parent)
{
	setupUi(this);
}

QPoisson::~QPoisson()
{
}

void QPoisson::setupUi(QMainWindow *opencv_qt_demoClass)
{
	if (opencv_qt_demoClass->objectName().isEmpty())
		opencv_qt_demoClass->setObjectName(QStringLiteral("opencv_qt_demoClass"));
	opencv_qt_demoClass->resize(700, 600);

	actionOpen = new QAction(opencv_qt_demoClass);
	actionOpen->setObjectName(QStringLiteral("actionOpen"));
	actionOpen->setIcon(QIcon(BASE + "QPoisson/Resources/file_32px_572850_easyicon.net.ico"));

	actionSave = new QAction(opencv_qt_demoClass);
	actionSave->setObjectName(QStringLiteral("actionSave"));
	actionSave->setIcon(QIcon(BASE + "QPoisson/Resources/diskette_32px_572819_easyicon.net.ico"));

	actionMirrorH = new QAction(opencv_qt_demoClass);
	actionMirrorH->setObjectName(QStringLiteral("actionMirrorH"));
	actionMirrorH->setIcon(QIcon(BASE + "QPoisson/Resources/flip_horizontal_32px_572874_easyicon.net.ico"));

	actionMirrorV = new QAction(opencv_qt_demoClass);
	actionMirrorV->setObjectName(QStringLiteral("actionMirrorV"));
	actionMirrorV->setIcon(QIcon(BASE + "QPoisson/Resources/flip_vertical_32px_572875_easyicon.net.ico"));

	actionTurn = new QAction(opencv_qt_demoClass);
	actionTurn->setObjectName(QStringLiteral("actionTurn"));
	actionTurn->setIcon(QIcon(BASE + "QPoisson/Resources/reload_32px_573065_easyicon.net.ico"));

	actionInvert = new QAction(opencv_qt_demoClass);
	actionInvert->setObjectName(QStringLiteral("actionInvert"));
	actionInvert->setIcon(QIcon(BASE + "QPoisson/Resources/protocol_32px_573045_easyicon.net.ico"));

	actionGrey = new QAction(opencv_qt_demoClass);
	actionGrey->setObjectName(QStringLiteral("actionGrey"));
	actionGrey->setCheckable(true);
	actionGrey->setIcon(QIcon(BASE + "QPoisson/Resources/contrast_32px_572784_easyicon.net.ico"));

	actionPolygon = new QAction(opencv_qt_demoClass);
	actionPolygon->setObjectName(QStringLiteral("actionPolygon"));
	actionPolygon->setCheckable(true);
	actionPolygon->setIcon(QIcon(BASE + "QPoisson/Resources/polygon_32px_1169471_easyicon.net.ico"));

	actionRect = new QAction(opencv_qt_demoClass);
	actionRect->setObjectName(QStringLiteral("actionRect"));
	actionRect->setCheckable(true);
	actionRect->setIcon(QIcon(BASE + "QPoisson/Resources/square_32px_1170579_easyicon.net.ico"));

	actionOval = new QAction(opencv_qt_demoClass);
	actionOval->setObjectName(QStringLiteral("actionOval"));
	actionOval->setCheckable(true);
	actionOval->setIcon(QIcon(BASE + "QPoisson/Resources/ellipse_stroked_32px_1168912_easyicon.net.ico"));

	actionImport = new QAction(opencv_qt_demoClass);
	actionImport->setObjectName(QStringLiteral("actionImport"));
	actionImport->setIcon(QIcon(BASE + "QPoisson/Resources/windows_32px_573226_easyicon.net.ico"));

	actionExport = new QAction(opencv_qt_demoClass);
	actionExport->setObjectName(QStringLiteral("actionExport"));
	actionExport->setIcon(QIcon(BASE + "QPoisson/Resources/document_diskette_32px_577567_easyicon.net.ico"));

	actionInsert = new QAction(opencv_qt_demoClass);
	actionInsert->setObjectName(QStringLiteral("actionInsert"));
	actionInsert->setIcon(QIcon(BASE + "QPoisson/Resources/file_transfer_32px_572861_easyicon.net.ico"));

	actionPossion = new QAction(opencv_qt_demoClass);
	actionPossion->setObjectName(QStringLiteral("actionPossion"));
	actionPossion->setCheckable(true);
	actionPossion->setIcon(QIcon(BASE + "QPoisson/Resources/match_width_and_height_32px_572964_easyicon.net.ico"));

	actionErase = new QAction(opencv_qt_demoClass);
	actionErase->setObjectName(QStringLiteral("actionErase"));
	actionErase->setIcon(QIcon(BASE + "QPoisson/Resources/eraser_32px_1197080_easyicon.net.ico"));

	actionEmpty = new QAction(opencv_qt_demoClass);
	actionEmpty->setObjectName(QStringLiteral("actionEmpty"));
	actionEmpty->setIcon(QIcon(BASE + "QPoisson/Resources/empty_32px_1161884_easyicon.net.ico"));

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

	// menuOpen = new QMenu(menuBar);
	// menuOpen->setObjectName(QStringLiteral("menuOpen"));
	//
	// menuTransform = new QMenu(menuBar);
	// menuTransform->setObjectName(QStringLiteral("menuTransform"));
	//
	// menuSelect = new QMenu(menuBar);
	// menuSelect->setObjectName(QStringLiteral("menuSelect"));
	//
	// menuPossion = new QMenu(menuBar);
	// menuPossion->setObjectName(QStringLiteral("menuPossion"));
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

	// menuBar->addAction(menuOpen->menuAction());
	// menuBar->addAction(menuTransform->menuAction());
	// menuBar->addAction(menuSelect->menuAction());
	// menuBar->addAction(menuPossion->menuAction());

	mdiArea = new QMdiArea(centralWidget);
	mdiArea->setGeometry(QRect(0, 0, 610, 610));
	imgBox = new srcImg(centralWidget);
	imgBox->setAttribute(Qt::WA_DeleteOnClose, false);
	subimgBox = new dstImg(centralWidget);
	subimgBox->setAttribute(Qt::WA_DeleteOnClose, false);
	connectWidgets(opencv_qt_demoClass);
	retranslateUi(opencv_qt_demoClass);

} // setupUi

void QPoisson::connectWidgets(QMainWindow *opencv_qt_demoClass)
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
	QObject::connect(actionExport, SIGNAL(triggered()), this, SLOT(exportImg()));
	QObject::connect(this, SIGNAL(expImg(QString)), subimgBox, SLOT(save(QString)));
}

void QPoisson::retranslateUi(QMainWindow *opencv_qt_demoClass)
{
	opencv_qt_demoClass->setWindowTitle(QApplication::translate("opencv_qt_demoClass", "QPoisson", 0));
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

	// menuOpen->setTitle(QApplication::translate("opencv_qt_demoClass", "File", 0));
	// menuTransform->setTitle(QApplication::translate("opencv_qt_demoClass", "Transform", 0));
	// menuSelect->setTitle(QApplication::translate("opencv_qt_demoClass", "Select", 0));
	// menuPossion->setTitle(QApplication::translate("opencv_qt_demoClass", "Possion", 0));

	ImgClosed();
} // retranslateUi

void QPoisson::resizeEvent(QResizeEvent *event)
{
	int w = this->width();
	int h = this->height();

	mdiArea->setFixedSize(this->width(), this->height());
}

void QPoisson::allowinsert(bool c)
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

void QPoisson::polychecked(bool c)
{
	if (c)
	{
		actionRect->setChecked(false);
		actionOval->setChecked(false);
	}

	emit setpoly(c);
}

void QPoisson::rectchecked(bool c)
{
	if (c)
	{
		actionPolygon->setChecked(false);
		actionOval->setChecked(false);
	}

	emit setrect(c);
}

void QPoisson::ovalchecked(bool c)
{
	if (c)
	{
		actionPolygon->setChecked(false);
		actionRect->setChecked(false);
	}

	emit setoval(c);
}

void QPoisson::openImage(void)
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open image file"), "./", tr("Image files(*.bmp *.gif *.jpg *.jpeg *.png *.pbm *.pgm *.ppm *.xbm *.xpm)"));
	if (!fileName.isEmpty())
	{

		int SUBWinCount = mdiArea->subWindowList(QMdiArea::CreationOrder).count();

		if (SUBWinCount > 0)
		{
			if (SUBWinCount == 2)
				mdiArea->removeSubWindow(subimgBox);
			mdiArea->removeSubWindow(imgBox);
			mdiArea->closeAllSubWindows();
		}

		mainToolBar->setEnabled(false);
		emit loadImg(fileName);
	}
}

void QPoisson::importImg(void)
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open image file"), "./", tr("Image files(*.bmp *.gif *.jpg *.jpeg *.png *.pbm *.pgm *.ppm *.xbm *.xpm)"));
	if (!fileName.isEmpty())
	{
		if (mdiArea->subWindowList(QMdiArea::CreationOrder).count() == 2)
			mdiArea->subWindowList(QMdiArea::CreationOrder).at(1)->close();
		mainToolBar->setEnabled(false);
		emit loadSubimg(fileName);
	}
}

void QPoisson::subload(void) // subimg load complete
{

	mdiArea->addSubWindow(subimgBox, windowFlags() & ~Qt::WindowMinMaxButtonsHint);

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

void QPoisson::saveImage(void)
{
	QString file_path = QFileDialog::getSaveFileName(this, tr("Save File"), "./", tr("BMP (*.bmp);;JPG (*.jpg);;JPEG (*.jpeg);;PNG(*.png);;PPM(*.ppm);;XBM(*.xbm);;XPM(*.xpm)"));
	if (!file_path.isEmpty())
	{
		mainToolBar->setEnabled(false);
		if (QFileInfo(file_path).suffix().isEmpty())
			file_path.append(".png");
		emit saveImg(file_path);
	}
}

void QPoisson::exportImg(void)
{
	QString file_path = QFileDialog::getSaveFileName(this, tr("Save File"), "./", tr("BMP (*.bmp);;JPG (*.jpg);;JPEG (*.jpeg);;PNG(*.png);;PPM(*.ppm);;XBM(*.xbm);;XPM(*.xpm)"));
	if (!file_path.isEmpty())
	{
		mainToolBar->setEnabled(false);
		if (QFileInfo(file_path).suffix().isEmpty())
			file_path.append(".png");
		emit expImg(file_path);
	}
}

void QPoisson::ImgClosed(void)
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

void QPoisson::subimgclosed(void)
{
	if (mdiArea->subWindowList(QMdiArea::CreationOrder).count() == 2)
	{
		mdiArea->removeSubWindow(subimgBox);
		mdiArea->subWindowList(QMdiArea::CreationOrder).at(1)->close();
	}

	actionExport->setEnabled(false);
	actionInsert->setEnabled(false);
	actionPossion->setEnabled(false);
	actionErase->setEnabled(false);
}

void QPoisson::LoadFinished(void)
{
	mdiArea->addSubWindow(imgBox, windowFlags() & ~Qt::WindowMinMaxButtonsHint);
	imgResize();
	SaveFinished();

	actionGrey->setChecked(false);
	actionPolygon->setEnabled(false);
	actionRect->setEnabled(false);
	actionOval->setEnabled(false);
	actionEmpty->setEnabled(false);
	actionPolygon->setChecked(false);
	actionRect->setChecked(false);
	actionOval->setChecked(false);
	actionImport->setEnabled(true);
	actionPossion->setChecked(false);
	actionPossion->setEnabled(false);
	actionErase->setEnabled(false);
	actionExport->setEnabled(false);
}

void QPoisson::imgResize(void)
{
	QMdiSubWindow *csw = mdiArea->subWindowList(QMdiArea::CreationOrder).at(0);
	int h = imgBox->height();
	int w = imgBox->width();
	int mw = w + 2 * SUBWIN_BORDER;
	int mh = h + SUBWIN_BORDER + SUBWIN_HEAD;
	csw->setFixedSize(mw, mh);
	imgBox->show();
}

void QPoisson::SaveFinished(void)
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

void QPoisson::insertFailed(bool f)
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
