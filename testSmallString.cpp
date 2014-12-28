
#include "SmallString.h"
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
	SmallString<4> ss;
	ss.push_back('1');
	ss.push_back('2');
	ss.push_back('3');
	ss.push_back('4');
	printf("ss = %s\n", ss.str());
	ss += "ABCDE";
	printf("ss = %s\n", ss.str());

	SmallString<8> ss1("PERA");
	SmallString<8> ss2("PERA12");
	check(ss1 < ss2);
	printf("PASSED\n");
	return 0;
}
