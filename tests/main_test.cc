/**
 * Main file designed for running tests along with production code
 */

#include <iostream>
#include "gtest/gtest.h"

int main(int argc, char *argv[])
{
	std::cout << "\nExecuting test..." << std::endl;

	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}