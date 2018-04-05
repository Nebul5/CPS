#include "CpsCompiler.h"
#include <utility>
#include <iostream>

int main() {
	// Example
	Program p("myCPSProg.cps");
	p.compile("PSTest");
	return 0;
}
