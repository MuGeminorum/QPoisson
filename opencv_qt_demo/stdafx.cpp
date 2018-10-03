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

uchar itoUCHAR(int x)
{
	if (x < 0)
	{
		return 0x00;
	}
	else if (x >= 0 && x <= 255)
	{
		return (x & 0xFF);
	}
	else
	{
		return 0xFF;
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

void printsln(Mat1f b)
{
	FILE *fp = fopen("f:\\downloads\\x.txt", "w");
	//fprintf_s(fp, "{\n");
	for (int i = 0; i < b.rows; i++)
	{
		//fprintf_s(fp, "{");
		for (int j = 0; j < 4; j++)
		{
			int cp = toINT(itoUCHAR(toINT(b.at<float>(i, j))));
			if (cp >= 0)
			{
				//fprintf_s(fp, (j < 3) ? "+%03d, " : "+%03d ", cp);
				//fprintf_s(fp, " %03d ", cp);
				//int d = digit(cp);
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
				//fprintf_s(fp, (j < 3) ? "-%03d, " : "-%03d ", Abs(cp));
				//fprintf_s(fp, "%03d ", cp);
				//int d = digit(cp);
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
		//fprintf_s(fp, (i < b.rows - 1) ? "},\n" : "}");
		fprintf_s(fp, "\n");
	}
	//fprintf_s(fp, "\n};");
	fclose(fp);
}

void printLap(Mat1f iA)
{
	FILE *fp = fopen("f:\\downloads\\A.txt", "w");
	//fprintf_s(fp, "{\n");
	for (int i = 0; i < iA.rows; i++)
	{
		//fprintf_s(fp, "{");
		for (int j = 0; j < iA.cols; j++)
		{
			int cp = toINT(iA.at<float>(i, j));
			if (cp >= 0)
			{
				//fprintf_s(fp, (j < iA.cols - 1) ? "+%01d, " : "+%01d ", cp);
				fprintf_s(fp, " %01d ", cp);
			}
			else
			{
				//fprintf_s(fp, (j < iA.cols - 1) ? "-%01d, " : "-%01d ", Abs(cp));
				fprintf_s(fp, "%01d ", cp);
			}
		}
		//fprintf_s(fp, (i < iA.rows - 1) ? "},\n" : "}");
		fprintf_s(fp, "\n");
	}
	//fprintf_s(fp, "\n};");
	fclose(fp);
}

#endif