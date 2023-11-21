#include <fstream>
#include <iostream>
#include <sstream>
#include <stack>
#include <algorithm>

#include "heaps.h"
#include "graphs.h"

MinHeap BuildMinHeap(std::ifstream&);

std::vector<std::string> DetermineVertices(std::ifstream&);

int main()
{
	std::ifstream userData;

	// Implement a Priority Queue using a Binary Heap...
	MinHeap minHeap = BuildMinHeap(userData);
	std::vector<std::string> vertices = DetermineVertices(userData);

	minHeap.PrintMinimumElement();
	
	// Extract the smallest element from the heap.
	// std::vector<std::string> minElement = minHeap.ExtractMin();

	std::cout << std::endl << "Vertices: " << std::endl;
	for (int index = 0; index < vertices.size(); index++) { std::cout << vertices[index] << std::endl; }

	


	
	// Breadth First Search (20 points)
		// Represent the graph using an adjacency list.
			// You can use any basic data structure to implement the adjacency list, as long as it is not a specialized one designed for graph computation (such as you might get from the network library).
			// You WILL NOT be using edge weights.
			// You are allowed to use any data structure you'd like for these auxiliary structures, within reason (nothing that can just solve the problem with a single method call, but I don't think that will be an issue). This means that you can use pre-existing queue implementations if you'd like!

		// Implement the PRINT-PATH method outlined in the book. This will allow you to print out the shortest path from some starting vertex, s, to any other vertex, v.
			// Using this method combined with your BFS implementation, print out the shortest path...
			// 1) from Arad to Sibiu
			// 2) from Arad to Craiova
			// 3) from Arad to Bucharest
	
	// Dijkstra's Algorithm (40 points)
		// Calculates the single-source shortest path on a weighted graph.
		// Use edge weights for this part of the assignment.
		// Make use of the Priority Queue data structure, implemented in Part 1
		// Find the shortest path from Arad to Bucharest.
			// You should be able to print out this path using a method similar to (possibly identical to, depending on your implementation) the PRINT-PATH method used in part 2.
			// Is this path divergent from the path from Arad to Bucharest you found in part 2?
				// Why or why not?

		// DO NOT use methods that can essentially answer the question in one method call.

	return 0;
}


MinHeap BuildMinHeap(std::ifstream& userFile)
{
	MinHeap minHeap;
	std::string line;
	char whiteSpace;
	bool isWord = false;

	std::cout << std::endl << std::endl << "Adjacency List: " << std::endl;

	userFile.open("Data/RomaniaEdges.txt");

	// Keep reading words or if that fails clear the error state and read a white space character
	while ((isWord = static_cast<bool>(userFile >> line)) || (userFile.clear(), userFile >> whiteSpace))
	{
		int wordNum = 1;
		std::string vertex1 = "";
		std::string vertex2 = "";
		std::string weight = "";
		std::vector<std::string> adjacentVerteces;

		for (int index = 0; index < line.size(); index++)
		{
			if(wordNum == 1)
			{
				if (line[index] == ',')
				{
					adjacentVerteces.push_back(vertex1);
					wordNum++;
				}
				else
				{
					vertex1 += line[index];
				}
			}
			else if (wordNum == 2)
			{
				if (line[index] == ',')
				{
					adjacentVerteces.push_back(vertex2);
					wordNum++;
				}
				else
				{
					vertex2 += line[index];
				}
			}
			else
			{
				weight += line[index];
			}
		}
		adjacentVerteces.push_back(weight);

		std::cout << adjacentVerteces[0] << ", " << adjacentVerteces[1] << ", " << adjacentVerteces[2] << std::endl;
		minHeap.Insert(adjacentVerteces);
	}

	userFile.close();

	return minHeap;
}


std::vector<std::string> DetermineVertices(std::ifstream& userFile)
{
	std::string vertex;

	userFile.open("Data/RomaniaVertices.txt");

	std::vector<std::string> vertices;

	while (userFile >> vertex)
	{
		// Convert every word to lower-case letters.
		// for (int letterIndex = 0; letterIndex < vertex.size(); letterIndex++) { vertex[letterIndex] = tolower(vertex[letterIndex]); }
		vertices.push_back(vertex);
	}

	userFile.close();

	return vertices;
}





//*******************************************************************************************