#include "stdafx.h"

QString getFileName(QString fullPath)
{
	QFileInfo fileinfo = QFileInfo(fullPath);
	return fileinfo.fileName();
}

int max(int x, int y)
{
	return (x > y) ? x : y;
}

int min(int x, int y)
{
	return (x < y) ? x : y;
}

int Abs(int x)
{
	return (x >= 0) ? x : (-x);
}

uchar isTRUE(uchar x)
{
	return (x != 0x00) ? 0x01 : 0x00;
}

uchar itoUCHAR(int x, int ta)
{
	if (x < 0)
	{
		return 0x00;
	}
	else if (x >= 0 && x <= ta)
	{
		return (x & 0xFF);
	}
	else
	{
		return (ta & 0xFF);
	}
}

int toRGB(float x, int t)
{
	int n = toINT(x);

	if (n < 0)
	{
		return 0;
	}
	else if (n >= 0 && n <= t)
	{
		return n;
	}
	else
	{
		return t;
	}

}

#ifdef PRINT_DEBUG

int digit(int y)
{
	int x = Abs(y);
	if (x == 0)
	{
		return 1;
	}
	else
	{
		int i = 0;
		while (toINT(x / pow(10.0, i)) > 0)
		{
			i++;
		}
		return i;
	}
}

void printsln(MatrixX4f b)
{
	FILE *fp = fopen("f:\\downloads\\x.txt", "w"); 
	for (int i = 0; i < b.rows(); i++)
	{ 
		for (int j = 0; j < 4; j++)
		{
			int cp = toINT(itoUCHAR(toINT(b(i, j)), toINT(b(i, 0))));
			if (cp >= 0)
			{ 
				switch (digit(Abs(cp)))
				{
				case 1: fprintf_s(fp, "   %01d ", cp); break;
				case 2: fprintf_s(fp, "  %02d ", cp); break;
				case 3: fprintf_s(fp, " %03d ", cp); break;
				default:
					break;
				}
			}
			else
			{ 
				switch (digit(Abs(cp)))
				{
				case 1: fprintf_s(fp, "  %01d ", cp); break;
				case 2: fprintf_s(fp, " %02d ", cp); break;
				case 3: fprintf_s(fp, "%03d ", cp); break;
				default:
					break;
				}
			}
		} 
		fprintf_s(fp, "\n");
	} 
	fclose(fp);
}

void printLap(SMat1f iA)
{
	FILE *fp = fopen("f:\\downloads\\A.txt", "w"); 
	for (int i = 0; i < iA.rows(); i++)
	{ 
		for (int j = 0; j < iA.cols(); j++)
		{
			int cp = toINT(iA.coeffRef(i, j)); 
			if (cp >= 0)
			{ 
				fprintf_s(fp, " %01d ", cp);
			}
			else
			{ 
				fprintf_s(fp, "%01d ", cp);
			}
		} 
		fprintf_s(fp, "\n");
	} 
	fclose(fp);
}

#endif