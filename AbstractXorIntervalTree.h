#pragma once

#include "Interval.h"

class AbstractXorIntervalTree
{
public:
	virtual void Insert (int where, int val) = 0;
	virtual int Query (const Interval& interval) const = 0;
};

