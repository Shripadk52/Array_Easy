// Best_Time_to_Buy_and_Sell_Stock.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int maxmaximumProfit(int* prices, int pricesSize);

int main()
{
    // Initialization of variables to be passed to function
    int prices[] = { 7,6,4,3,1 };
    int pricesSize = sizeof(prices) / sizeof(int);

	// Calling the function and testing the result
    int maximumProfit = maxmaximumProfit(prices, pricesSize);
    printf("The maximum maximumProfit we made from this stock is:%d",maximumProfit );
}

int maxmaximumProfit(int* prices, int pricesSize)
{
    // Initialization of required variables
    int runningProfit = 0, maximumProfit = 0;
    int minSoFar;
   

    for (int i = 0; i < pricesSize; i++)
    /*the outer loop is to track minimum stock price so far*/
    { 
        if (i == 0)
        /*If it's the first Day*/
        {
			minSoFar = prices[i]; // Set the minimum stock price to the first day's price
        }
        else {
            /*If it's not the First Day*/
            if (prices[i] < minSoFar)
            /*If the current Day price is less than our previous Days
            Stock price then Update the minSoFar*/
            {
                minSoFar = prices[i];
            }
            else {
                /*if The current Day price is greater than our mininum
                stock price so far then we calculate the profit we will
                gain by selling today*/
				
                /*Formula: Profit = selling cost - buying Day cost (minimum stock price So Far)*/
				runningProfit = prices[i] - minSoFar;

                if (runningProfit > maximumProfit)
                {
					maximumProfit = runningProfit; // Update maximumProfit if runningProfit is greater
                }
            }
        }
    }
	return maximumProfit; // Return the maximum maximumProfit earned
}
