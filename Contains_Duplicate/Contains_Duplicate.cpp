// Contains_Duplicate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
bool containsDuplicate(int* nums, int numsSize);

int main()
{
    /*Sample input and it's size*/
    int nums[] = { 2,14,18,22,22 };
    int numsSize = sizeof(nums) / sizeof(int);
    /*Testing Sample on Function*/
    bool result = containsDuplicate(nums, numsSize);
    if (result == 1) {
        printf("Contains Duplicate\n");
    }
    else {
        printf("No Duplicate found\n");
    }
}

bool containsDuplicate(int* nums, int numsSize) {

    if(numsSize <=1) /*If the array is empty or has only one element*/
		return 0;   // Early return No duplicate found

	bool DuplicateFound = 0;// Flag to check if duplicate is found
	int* hashPtr = (int*)malloc(numsSize * sizeof(int));// pointer to hash table

    /*Initialize the array with INT_MIN to avoid garbage values(aka Sentry)*/
    for (int i = 0; i < numsSize; i++) {
		hashPtr[i] = INT_MIN;
    }
	
    for (int i = 0; i < numsSize; i++) {
        /*Traverse through Array*/

        int HashIndex = (((nums[i] % numsSize) + numsSize)% numsSize); /*Hash Function which 
        give us Hash Index*/

        if (hashPtr[HashIndex] == nums[i])/*If the Hash Index is already used for the same element*/
        {
            DuplicateFound = 1; /*Duplicate is found*/
            free(hashPtr); /*Free the allocated memory*/
            break; /*Break the loop since no further need to check*/
        }
        else if (hashPtr[HashIndex] != INT_MIN)
        {/*To check if the Current Hash Index is used by another key to avoid collision*/
            
            // To avoid collision  we have to improve the logic to handle collisions
			while(hashPtr[HashIndex] != INT_MIN){
				HashIndex = (HashIndex + 1) % numsSize; // Circular incrementation to find empty available slot
				//Keep incrementing the index until we find the sentinel value which indicates an empty slot

                if (hashPtr[HashIndex] == nums[i])/*If the Hash Index is already used for the same element*/
                {
                    DuplicateFound = 1; /*Duplicate is found*/
                    free(hashPtr); /*Free the allocated memory*/
                    return DuplicateFound; /*Return the result of duplicate found or not*/
                }
            }
			hashPtr[HashIndex] = nums[i]; /*Storing element in Hash table at empty location*/
        }
        else {
            hashPtr[HashIndex] =  nums[i];/*Storing element in Hash table*/
        }
    }
	return DuplicateFound; /*Return the result of duplicate found or not*/
}


