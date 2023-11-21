#ifndef GRAPHS_CPP
#define GRAPHS_CPP

#include "graphs.h"

template<typename T>
void Graph<T>::BuildGraph(std::vector<std::vector<T> >& adjacentVerteces)
{
	std::cout << "Building Graph!" << std::endl;
	
	for (int outerIndex = 0; outerIndex < adjacentVerteces.size(); outerIndex++)
	{
		adjacentPoints.push_back(adjacentVerteces[outerIndex]);

		std::cout << "Element " << outerIndex << "..." << std::endl
				  << "Position 1: " << adjacentPoints[outerIndex][0] << std::endl
				  << "Position 2: " << adjacentPoints[outerIndex][1] << std::endl
				  << "Position 3: " << adjacentPoints[outerIndex][2] << std::endl;

		// for (int innerIndex = 0; innerIndex < adjacentVerteces[outerIndex].size(); innerIndex++)
		// {
		// 	std::cout << "Position " << innerIndex << ": " << adjacentVerteces[outerIndex][innerIndex];

		// 	adjacentPoints[outerIndex][innerIndex] = adjacentVerteces[outerIndex][innerIndex];
		// }
	}

	std::cout << std::endl << std::endl;
}

template<typename T>
void Graph<T>::PrintData()
{
	std::cout << "Printing Graph Data!" << std::endl << std::endl;
	
	for (int outerIndex = 0; outerIndex < adjacentPoints.size(); outerIndex++)
	{
		for (int innerIndex = 0; innerIndex < adjacentPoints[outerIndex].size(); innerIndex++)
		{
			std::cout << adjacentPoints[outerIndex][innerIndex] << " ";
		}
		std::cout << std::endl;
	}
}

// Check to see if an edge exists between two points.
template <typename T>
bool Graph<T>::HasEdge(T T1, T T2) const
{
	bool hasEdge = false;
	std::vector<T> TSet = adjacentPoints.at(T1);
	for(auto index = TSet.begin(); index != TSet.end(); index++)
	{
		if (T2 == *index)
		{
			hasEdge = true;
		}
	}

	return hasEdge;
}

// Add an edge between two points.
template <typename T>
void Graph<T>::AddEdge(T T1, T T2)
{
	adjacentPoints[T1].insert(T2);
	adjacentPoints[T2].insert(T1);
}


template <typename T>
int Graph<T>::BFS(T& T1, T& T2, std::map<T, int>& T3, std::map<T, T>& T4)
{
	// For each vertex in the graph...
	for (auto index = adjacentPoints.begin(); index != adjacentPoints.end(); index++)
	{
		T3[index->first] = -1;
	}

	if(T3.find(T1) == T3.end())
	{
		return INVALID_VERTEX;
	}

	// Create an empty QUEUE.
	std::queue<T> pointQueue;

	// Set the T3 at 'T1' equal to 0.
	T3.at(T1) = 0;

	// Set "T4" at 'T1' equal to 'T1'.
	T4[T1] = T1;

	// Insert T1 into the QUEUE.
	pointQueue.push(T1);

	// Set "current" equal to 'T1'.
	T current = T1;

	// While QUEUE is not empty AND "current" is not equal to 'T2'...
	while (!pointQueue.empty() && current != T2)
	{
		current = pointQueue.front();
		pointQueue.pop();

		// For each vertex that is adjacent to "current"...
		for (auto index : adjacentPoints.at(current))
		{
			// If T3 at given index is equal to -1...
			if (T3.at(index) == -1)
			{
				// Set T3 at given index equal to T3 at "current" plus 1.
				T3.at(index) = (T3.at(current) + 1);

				// Set "T4" at given index equal to current.
				T4[index] = current;

				// Add given index to QUEUE.
				pointQueue.push(index);
			}
		}
	}

	if (T3.find(T2) != T3.end())
	{
		return T3[T2];
	}
	else if(!HasEdge(T1,T2))
	{
		return NO_PATH;
	}
	else
	{
		return INVALID_VERTEX;
	}
}

#endif