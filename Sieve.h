#pragma once

/*  Wilder Molyneux
*   University of Washington | Bothell (UWB)
*   Graduate Certificate in Software Design and Development (GCSDD)
*   Prerequisite Sample Coursework
*   June 21, 2023
*
*   Dr. Emily M. Bender Rule: C++
*
*   From UWB Computing & Software Systems (CSS) 143
*   Programming Competency Self-Assessment: Second Assessment (four of four)
*   "Sieve of Eratosthenes"
*
*   Sieve.h
*/

#include <iostream>
#include <list>

using namespace std;

class Sieve
{
  public:
	Sieve();
	~Sieve();

	// Member functions
	void computeTo(unsigned int n);
	void reportResults();
	unsigned int getMax();
	unsigned int getCount();

  private:
	// Using a <list> as a <queue> due to the C++ STL queue's 
	//   lack of offset & iterator support
	list<unsigned int> primes;

	// Internal consistency checks
	bool computeToCalled;
	unsigned int lastValueOfN;
};
