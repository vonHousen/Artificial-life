/*
 * Main file designed for tests
 */

#include <iostream>
#include "Tests.h"
#include "gtest/gtest.h"

int main(int argc, char *argv[])
{
	std::cout<<"\n"<<"Executing test..."<<std::endl;
	//Tests::runAll();

	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}