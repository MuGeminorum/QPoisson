#include <QtWidgets>
#include <Eigen\Eigen>

using namespace Eigen;

typedef Eigen::SparseMatrix<float> SMat1f;
typedef Eigen::Matrix<uchar, Dynamic, Dynamic> MatrixXb;
typedef MatrixXb Mat1b;

#define SUBWIN_BORDER 8
#define SUBWIN_HEAD 32 

#define toINT(x) ((int)(x))
#define toFLT(x) ((float)(1.0 * (x)))

extern QString getFileName(QString);
extern int max(int, int);
extern int min(int, int);
extern int Abs(int);
extern uchar isTRUE(uchar);
extern uchar itoUCHAR(int, int = 255);
extern int toRGB(float, int = 255);

struct Mat4b
{
	MatrixXb ARGB[4];
	int rows;
	int cols;
};

struct QMat
{
	Mat4b iMat;
	Mat1b eMat;
	int iNum;
};
