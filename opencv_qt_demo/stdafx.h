#include <QtWidgets>
#include<opencv2\opencv.hpp>
using namespace cv;

#define SUBWIN_BORDER 8
#define SUBWIN_HEAD 32
//#define PRINT_DEBUG 1

#define toINT(x) ((int)(x))

extern QString getFileName(QString);
extern int max(int, int);
extern int min(int, int);
extern int Abs(int);
extern uchar isTRUE(uchar);
extern uchar itoUCHAR(int);

#ifdef PRINT_DEBUG
extern void printsln(Mat1f);
extern void printLap(Mat1f);
#endif

struct QMat
{
	QPixmap pMat;
	Mat4b iMat;
	Mat1b eMat; 
	int iNum;
};