#ifndef QPOISSON_H
#define QPOISSON_H

#include <QtWidgets/QMainWindow>

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

#include "srcImg.h"
#include "dstImg.h"

class QPoisson : public QMainWindow
{
	Q_OBJECT

public:
	QPoisson(QWidget *parent = 0);
	~QPoisson();

	QAction *actionOpen;
	QAction *actionSave;
	QAction *actionMirrorH;
	QAction *actionMirrorV;
	QAction *actionTurn;
	QAction *actionInvert;
	QAction *actionGrey;

	QAction *actionImport;
	QAction *actionExport;
	QAction *actionInsert;
	QAction *actionPossion;
	QAction *actionErase;
	QAction *actionEmpty;

	QWidget *centralWidget;
	QStatusBar *statusBar;
	QToolBar *mainToolBar;
	QMenuBar *menuBar;
	QMenu *menuOpen;
	QMenu *menuTransform;
	QMenu *menuPossion;

	QMdiArea *mdiArea;
	QWidget *imgBox;
	QWidget *subimgBox;

	QMenu *menuSelect;
	QAction *actionPolygon;
	QAction *actionRect;
	QAction *actionOval;

private:
	void setupUi(QMainWindow *);
	void retranslateUi(QMainWindow *);
	void connectWidgets(QMainWindow *);

	public slots:
	void openImage(void);
	void saveImage(void);
	void ImgClosed(void);
	void LoadFinished(void);
	void SaveFinished(void);
	void imgResize(void);

	void polychecked(bool);
	void rectchecked(bool);
	void ovalchecked(bool);

	void subload(void);
	void importImg(void);
	void subimgclosed(void);
	void allowinsert(bool);
	void insertFailed(bool);

	void exportImg(void);

signals:
	void loadImg(QString);
	void saveImg(QString);
	void expImg(QString);

	void setpoly(bool);
	void setrect(bool);
	void setoval(bool);

	void loadSubimg(QString);


protected:
	void resizeEvent(QResizeEvent *);
};

#endif // QPOISSON_H
