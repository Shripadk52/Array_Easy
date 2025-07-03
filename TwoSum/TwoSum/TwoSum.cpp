// TwoSum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int* twoSum(int* nums, int numsSize, int target, int* returnSize);
int main()
{
	// Intialize all the input variables 
	int nums[] = { 3,2,4 };
	int numsSize = sizeof(nums) / sizeof(int);
	int target = 6;
	int returnSize = 2;
	int * resultIndices = twoSum(nums, numsSize, target, &returnSize);

	// add condition to avoid access of unintialized memory
	if (resultIndices != NULL) {
		cout << "resultIndices[0]:" << resultIndices[0] << endl;
		cout << "resultIndices[1]:" << resultIndices[1] << endl;
		free(resultIndices);// deallocate once done to avoid memory leak
	}
}

// User defined Function
int * twoSum(int* nums, int numsSize, int target, int* returnSize)
{
	// Intialize the result array pointer and front and rare markers 
	int front = 0;
	int rare = 0;
	int* result = NULL;

	if ((*returnSize) != 2)
	{
		*returnSize = 2;// Only to be used when submitting on LeetCode cause it does not passes int * returnSize when calling
	}

	while (rare < numsSize)
	{
		for (int i = 0; i < numsSize; i++)
		{
			if (front != rare)
			{
				// if both front and rare markers are in within given array size and are not the same look for target
				if ((nums[front] + nums[rare]) == target)
				{
					result = (int*)malloc(*returnSize * sizeof(int)); // Only allocate memory when need avoid memory allocation in case of no match is found
					result[0] = rare;
					result[1] = front;
					return result;//Early return of function to avoid unwanted processing if job is done
				}
			}
			front++;//Front marker Traversing
		}
		rare++;//rare marker Increment after each complete traversal of front marker
		front = 0;
	}
	return NULL;// avoid returning garbage value inside result if no match is found instead return NULL
}
