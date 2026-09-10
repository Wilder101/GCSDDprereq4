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
#include <limits>   // numeric_limits

/**
 main program to exercise the Sieve class
 pre:  None.
 post: Detects the primes between 2 and a user-specified value.
 */
int main()
{
	Sieve mySieve;
	long long number = 1;

	while (number > 0)
	{
		cout << "Maximum n to compute (0 to quit)? ";
		cin >> number;

		// Stop on end of input
		if (cin.eof())
		{
			cout << endl;
			break;
		}

		// A negative read into an unsigned wraps to a huge n, so read signed
		//   and range check before handing it to the sieve
		if (cin.fail() || number < 0 || number > Sieve::MAX_N)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Enter a whole number from 0 to " << Sieve::MAX_N << endl << endl;
			number = 1;
			continue;
		}

		if (number > 0)
		{
			cout << endl << "Primes up to " << number << " are as follows:" << endl;
			mySieve.computeTo((unsigned int)number);
			mySieve.reportResults();

			// getMax() is 0 until a legal call has been made; do not divide by it
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
