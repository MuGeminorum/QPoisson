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
