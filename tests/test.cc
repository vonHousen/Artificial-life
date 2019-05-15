/*
 * Main file designed for tests
 */

#include <iostream>
#include "Tests.h"

int main(int argc, char *argv[])
{
	std::cout<<"\n"<<"Executing test..."<<std::endl;
	Tests::runAll();

	return 0;
}