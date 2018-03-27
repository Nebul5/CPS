// **************************************** //
//              Tests.cpp                   //
//      Unit Tests for Shape language       //
// by Paul Huske, Hal ... , and Jake Conner //
// **************************************** //

#define CATCH_CONFIG_MAIN
#include "Catch2-master\single_include\catch.hpp"

#include "Shape.h"
#include <vector>

TEST_CASE("Circles with varying radii", "[Shape]") {
	Program testProg("");
	std::vector<Program> tests(30, testProg);
	for (auto i = 0; i < tests.size(); i++) {
		tests[i].interpret("Circle(" + std::to_string(i * 5) + ");");
		REQUIRE(tests[i].toString() == "newpath \n 0 0 " + std::to_string((i+1) * 5) + " 0 360 arc closepath stroke showpage");
	}
}

TEST_CASE("Polygons with varying numbers of sides", "[Shape]") {
	Program testProg("");
	std::vector<Program> tests(30, testProg);
	for (auto i = 0; i < tests.size(); i++) {
		tests[i].interpret("Polygon(" + std::to_string(i+3) +", 20);");
		REQUIRE(tests[i].toString() == "newpath \n 0 0 ... stroke showpage");
	}
}

TEST_CASE("Rectangles with varying dimensions", "[Shape]") {
	Program testProg("");
	std::vector<Program> tests(30, testProg);
	for (auto i = 0; i < tests.size(); i++) {
		tests[i].interpret("Rectangle(" + std::to_string(41 - i) + ", " + std::to_string(i + 1) + ");");
		REQUIRE(tests[i].toString() == "newpath \n 0 0 ... stroke showpage");
	}
}