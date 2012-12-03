//GraphAlgs.cpp
//All code written by Jordan Komnick for CSE274
//Solves the travelling salesperson problem

#include "GraphAlgs.h"

//The original method that is called in the tests
//Documentation is found in GraphAlgs.h
std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G)
{
	int* arr = new int[G -> size()];
	int arr_length = G -> size();
	return Tour(arr, arr_length, 0, G);
}

//A helper method I wrote for my implementation of the travelling salesperson problem
//Returns: A pair with the first being a list of nodes in the order they are visited and the second being the length of the trip
//Preconditions: Same as the preconditions for TSP(Graph* G)
//This implementation is mostly taken from the pseudocode we went over in class
std::pair<std::vector<NodeID>, EdgeWeight> Tour(int* arr, int arr_length, int start, Graph* G)
	{
		int* bestTour;
		float bestTourLength;
		if(arr_length - start == 1)
		{
			//check if arr is better than best tour and update as necessary
			int currentTour = 0;
			for(int i = 0; i < arr_length - 1; i++)
			{
				currentTour += G -> weight(arr[i], arr[i+1]);
			}
			if(currentTour < bestTourLength)
			{
				bestTourLength = currentTour;
				bestTour = arr;
			}
		}
		else
		{
			for(int i = start; i < arr_length; i++)
			{
				//check length, break if current tour is already longer than the best tour to save time
				int currentTour = 0;
				for(int j = 0; j < arr_length - j; i++)
				{
					currentTour += G -> weight(arr[i], arr[i+1]);
				}
				if(currentTour >= bestTourLength)
				{
					break;
				}
				int temp = arr[start];
				arr[start] = arr[i];
				arr[i] = temp;
				Tour(arr, arr_length , start+1, G);
				int temp2 = arr[start];
				arr[start] = arr[i];
				arr[i] = temp2;
			}
		}
		return std::make_pair(*bestTour, bestTourLength);
	}
