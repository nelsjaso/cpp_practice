/*  Author: Jason Nelson
 *  Date: 12/19/2013
 *
 *  Small program to demonstrate how I would remove duplicate
 *  entries in an array, preserving the original order the items
 *  were in.
 */

#include <iostream>

const int ARRAY_SIZE = 5;

bool dupe_check(int, int *);
int dupe_count(int *);

int main()
{
	using namespace std;

	int duplicates = 0; // number of duplicates in initial array
	int result_size = 0; // size of results array
	int cur_idx = 0; //current index in results array

	int initial_array[ARRAY_SIZE]; // our initial array, may contain duplicates!
	int * results = NULL; // not sure how big our results array needs to be initally, we'll allocate space for it when we do.

	//Fill up an array with values
	cout << "Enter " << ARRAY_SIZE << " integers\n";

	for(int i=0; i < ARRAY_SIZE; ++i)
	{
		cin >> initial_array[i];
		cin.ignore(100, '\n');
	}

	cout << "Removing duplicates\n";

	//Count the number of duplicates to figure out the size for the results array
	duplicates = dupe_count(initial_array);
	result_size = ARRAY_SIZE - duplicates;
	results = new int[result_size]; //create the results array

	for(int i=0; i < ARRAY_SIZE; ++i)
	{
		if(!dupe_check(initial_array[i], results)) //If this item is not in the results array already, add it.
		{	
			results[cur_idx] = initial_array[i];
			++cur_idx;
		}
	}

	//Display the results!
	for(int i=0; i < result_size; ++i)
		cout << results[i] << " ";
	cout << endl;

delete [] results;

return 0;
}



// This function counts the number of duplicates found in an array of integers
int dupe_count(int * arr)
{
	int result = 0;

	for(int i=0; i < ARRAY_SIZE; ++i)
	{
		for(int j=i+1; j < ARRAY_SIZE; ++j)
		{
			if(arr[i] == arr[j])
			{
				++result;
				break;
			}
		}
	}

	return result;
}



// This function checks whether or not a provided value is in an array of integers
bool dupe_check(int val, int * arr)
{
	for(int i=0; i < ARRAY_SIZE; ++i)
	{
		if(arr[i] == val)
			return true;
	}

	return false;
}