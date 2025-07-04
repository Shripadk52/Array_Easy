// RemoveDuplicatesFromSortedArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int removeDuplicates(int* nums, int numsSize);//Prototype
int main()
{
    // Input initialization
    //int nums[] = { 0,0,1,1,1,2,2,3,3,4 };
    int nums[] = { 1,1,2 };
    int numsSize = sizeof(nums) / sizeof(int); 
    int noOfUniqueElements = removeDuplicates(nums, numsSize);

    /*Testing the final output size elements and return value*/
    cout << "The Size of nums Array:" << numsSize << endl;
    cout<<"Number of unique Elements:" << noOfUniqueElements << endl;
    for (int i = 0; i < noOfUniqueElements; i++)
    {
        cout << "nums:" << nums[i] << endl;
    }
}

int removeDuplicates(int* nums, int numsSize)
{
    /*Initialization of variables required Below */

    int* expectedArray = (int*)malloc(numsSize * sizeof(int));// Creating temporary Array

    if (expectedArray != NULL) //if Array is empty avoid storing garbage value
    {
        expectedArray[0] = nums[0];// since nums is sorted in non-decreasing order  
        //(lowest value first) this element is same in both input and expected array
    }

    int numsMarker = 0;//two marker for input and expected
    //array to point their 0th index
    int expectedArrayMarker = 0;

    /* Checking for Unique elements and copying it in 
     the temporary array Below (Step1)*/ 

    while (numsMarker < (numsSize - 1))
    {
        if (nums[numsMarker] == nums[numsMarker + 1])// Current index and the next index
        //element is same no Unique element found 
        {
            numsMarker++;// go to the next index position in the input array
        }
        else if (nums[numsMarker] != nums[numsMarker + 1])// Current index and the next index
        //element is not same Unique element found 
        {
            expectedArrayMarker++; // move to next vacant position available to be used
            expectedArray[expectedArrayMarker] = nums[numsMarker + 1];//copy the unique element
            // in temporary array and also maintain the relative order of the input array
            numsMarker++;// go to the next index position in the input array
        }
    }
    /*Returning the number of unique elements and rearranging the given array to match the expected array (Step 2)*/
    for (int i = 0; i <= expectedArrayMarker; i++)
    {
        nums[i] = expectedArray[i]; //Rearrange the input Array to match expected array and
        //maintain the relative order same as before for all unique elements
    }
    free(expectedArray);//Deallocate Memory temporary array is no longer required

    int numOfUniqueElement = expectedArrayMarker + 1;//Since the expectedArrayMarker starts from 0 the total unique element
    // will always be + 1 also this variable avoid confusion between marker of array and return variable

    return numOfUniqueElement;
}


