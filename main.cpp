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

			// getMax() returns 0 when no legal call to computeTo has been made,
			//   which happens here whenever n is 1. Dividing by it is undefined
			//   behaviour: x86 traps and the program dies, ARM quietly yields
			//   zero. Only report a percentage when there is one to report.
			unsigned int maxN = mySieve.getMax();

			if (maxN > 0)
			{
				cout << "% of primes = " << 100 * mySieve.getCount() / maxN
					 << endl << endl;
			}
			else
			{
				cout << endl;
			}
		}
	}

	return 0;
}
