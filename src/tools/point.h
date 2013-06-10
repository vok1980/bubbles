
#pragma once



struct SPoint
{
	bool operator==(SPoint &refExt)
	{
		return ((m_iX == refExt.m_iX) && (m_iY == refExt.m_iY));
	}

	long m_iX;
	long m_iY;
};