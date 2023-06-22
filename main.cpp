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
*   main.cpp
*/

/**
 Driver file exercise the Sieve class

 @author Clark Olson
 @translation from Java to C++ Wilder Molyneux
 */

#include "Sieve.h"

/**
 main program to exercise the Sieve class
 pre:  None.
 post: Detects the primes between 2 and a user-specified value.
 */
int main()
{
	Sieve mySieve;
	unsigned int number = 1;

	while (number > 0)
	{
		cout << "Maximum n to compute (0 to quit)? ";
		cin >> number;

		if (number > 0)
		{
			cout << endl << "Primes up to " << number << " are as follows:" << endl;
			mySieve.computeTo(number);
			mySieve.reportResults();
			cout << "% of primes = " << 100 * mySieve.getCount() / mySieve.getMax() 
				 << endl << endl;
		}
	}

	return 0;
}
