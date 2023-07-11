#pragma once

#include "support.h"

class Test
{
public:

	int x;
	int y;

	Test();
	Test(int x, int y);

public:

	static void Print() {
		DEBUG("From C++");
	}

	void Info() {
		DEBUG_C(x << " " << y);
	}
};
