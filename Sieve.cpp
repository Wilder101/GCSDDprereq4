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
*   Sieve.cpp
*/

#include "Sieve.h"
#include <cmath>    // sqrt()
#include <vector>   

// Constructor constructs a Sieve object
Sieve::Sieve()
{
	lastValueOfN = 0;
	computeToCalled = false;

	primes.clear();
}

// Destructor
Sieve::~Sieve()
{
	primes.clear();
}

// This is the method that should implement the sieve algorithm. All prime
//   computations must be implemented using this algorithm.The method should 
//   compute all primes up to and including n. It should throw an 
//   IllegalArgumentException if n is less than 2.
void Sieve::computeTo(unsigned int n)
{
	// Local variables
	list<unsigned int> consecutiveInts;
	lastValueOfN = n;

	// Check for illegal argument
	if (n < 2)
	{
		cout << "IllegalStateException: no legal call has been made yet to the "
			<< "computeTo method." << endl;
	}
	else    // n >= 2; valid input
	{
		// Valid call to method
		computeToCalled = true;
		 
		// Clear primes queue
		primes.clear(); 

		// Fill consecutiveInts queue with consecutive integers from 2 through n inclusive
		for (unsigned int i = 2; i <= n; i++)
		{
			consecutiveInts.push_back(i);
		}

		// Set-up Sieve of Eratosthenes
		vector<bool> isPrime(n + 1, true);
		isPrime[0] = false;
		isPrime[1] = false;

		// Sieve of Eratosthenes
		for (unsigned int p = 2; p <= sqrt(n); p++) 
		{
			if (isPrime[p]) 
			{
				for (unsigned int i = p * p; i <= n; i += p) 
				{
					isPrime[i] = false;
				}
			}
		}

		// Save primes to primes queue
		for (unsigned int num : consecutiveInts)
		{
			if (isPrime[num]) 
			{
				primes.push_back(num);
			}
		}
	}

	consecutiveInts.clear();
}

// This method should report the primes to System.out. It should throw an
//   IllegalStateException if no legal call has been made yet to the computeTo
//   method. It is okay for it to have an extra space at the end of each line.
void Sieve::reportResults()
{
	if (computeToCalled)
	{
		unsigned int returnNow = 0;

		for (const int& element : primes) 
		{
			cout << element << " ";
			returnNow++;

			if (returnNow == 12)
			{
				cout << endl;
				returnNow = 0;
			}
		}
		cout << endl;
	}
	else
	{
		cout << "IllegalStateException: no legal call has been made yet to the "
			 << "computeTo method." << endl;
	}
}

// This is a convenience method that will let the client find out the value of 
//   n that was used the last time computeTo was called. It should throw an 
//   IllegalStateException if no legal call has been made yet to the 
//   computeTo method.
unsigned int Sieve::getMax()
{
	if (computeToCalled)
	{
		return lastValueOfN;
	}
	else
	{
		cout << "IllegalStateException: no legal call has been made yet to the "
			 << "computeTo method."  << endl;
	}
	
	return 0;
}

// This method should return the number of primes that were found on the last 
//   call to computeTo. It should throw an IllegalStateException if no legal call
//   has been made yet to the computeTo method.
unsigned int Sieve::getCount()
{
	if (computeToCalled)
	{
		return unsigned int(primes.size());
	}
	else
	{
		cout << "IllegalStateException: no legal call has been made yet to the "
			 << "computeTo method." << endl;
	}

	return 0;
}
