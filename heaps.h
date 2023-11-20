#ifndef HEAPS_H
#define HEAPS_H

#include <map>
#include <set>
#include <queue>
#include <vector>
#include <iostream>


class MinHeap
{
public:
	// Inserts a new element into the heap.
	void Insert(std::vector<std::string>);

	// Extracts the smallest element from the heap.
	std::vector<std::string> ExtractMin();

	// Returns the size of the heap.
	int GetSize();

private:
	// A vector to store the elements in the heap.
	std::vector<std::vector<std::string> > heap;

	// Heapify the heap upwards from the given index.
	void DecreaseKey(int);

	// Heapify the heap downwards from the given index.
	void Heapify(int);
};

#endif
#include "heaps.cpp"