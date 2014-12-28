
#include "SmallVector.h"
#include <stdio.h>
#include <stdlib.h>

void fail()
{
	printf("FAILED\n");
	exit(1);
}

void check(bool x)
{
	if (!x)
		fail();
}

int main()
{
	SmallVector<int, 4> siv;
	siv.push_back(3);
	siv.push_back(4);
	siv.push_back(5);
	siv.push_back(6);
	siv.push_back(7);
	int z = siv[4];
	check(z == 7);
	printf("z = %d\n", z);

	SmallVector<int, 4> v(siv);
	int z2 = v[4];
	check(z2 == 7);
	v.push_back(8);
	check(v[5] == 8);
	v.push_back(9);
	check(v[6] == 9);

	SmallVector<int, 4> v2(3);
	v2[0] = 4;
	v2[1] = 5;
	v2[2] = 6;
	check(v2.size() == 3);
	check(v2[0] == 4);
	check(v2[1] == 5);
	check(v2[2] == 6);

	SmallVector<double, 4> vd(2);
	vd[0] = 1.5;
	vd[1] = 2.5;
	check(vd.size() == 2);
	check(vd[0] == 1.5);
	check(vd[1] == 2.5);

	return 0;
}
