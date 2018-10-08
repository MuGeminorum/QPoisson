#include <QtWidgets>
#include<opencv2\opencv.hpp>
#include<Eigen\Eigen>

using namespace cv;
using namespace Eigen;

typedef Eigen::SparseMatrix<float> SMat1f;
//typedef Matrix<uchar, Dynamic, Dynamic > MatrixXb;

#define SUBWIN_BORDER 8
#define SUBWIN_HEAD 32
//#define PRINT_DEBUG 1

#define toINT(x) ((int)(x))
#define toFLT(x) ((float)(1.0 * (x)))

extern QString getFileName(QString);
extern int max(int, int);
extern int min(int, int);
extern int Abs(int);
extern uchar isTRUE(uchar);
extern uchar itoUCHAR(int);

#ifdef PRINT_DEBUG
extern void printsln(Mat4b);
extern void printLap(SMat1f);
#endif

struct QMat
{ 
	Mat4b iMat;
	Mat1b eMat; 
	int iNum;
};