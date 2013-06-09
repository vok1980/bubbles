
#pragma once


typedef unsigned int BoardSize_t;

enum ObjectDimention
{
	OD_WIDTH,
	OD_HEIGHT,
	OD_DEPTH,
};


class IDimension
{
public:
	virtual BoardSize_t GetDimention(ObjectDimention) = 0;
};