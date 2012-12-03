
#include "GraphAlgs.h"

std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G)
{
	int* arr = new int[G -> size()];
	int arr_length = G -> size();
	return Tour(arr, arr_length, 0, G);
}

// mostly taken from the pseudocode we went over in class
std::pair<std::vector<NodeID>, EdgeWeight> Tour(int* arr, int arr_length, int start, Graph* G)
	{
		int* bestTour;
		float bestTourLength;
		if(arr_length - start == 1)
		{
			//check if arr is better than best tour and update
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
				//check length, break if not
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
				int temp = arr[start];
				arr[start] = arr[i];
				arr[i] = temp;
			}
		}
		return std::make_pair(bestTour, bestTourLength);
	}
