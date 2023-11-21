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

	std::vector<std::vector<std::string> > GetData();

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


//**********************//
//******PSEUDOCODE******//
//**********************//

/*
************HEAPS************
Max-Heapify(heap, index)
{
	left = Left(index)
	right = Right(index)

	if (left <= heap.size && heap[left] > heap[right]) { largest = left; }
	else { laregest = right; }
	
	if (right <= heap.size && heap[right] > heap[left]) { largest = right; }
	
	if (largest != index)
	{
		swap(heap[index], heap[largest]);
		Max-Heapify(heap, largest);
	}
}

Build-Max-Heap(heap)
{
	heap.size = heap.length();

	for (index = floor(heap.length()/2); index > 0; index--) { Max-Heapify(heap, index); }
}

Heapsort(heap)
{
	Build-Max-Heap(heap);

	for (index = heap.length(); index > 1; index--)
	{
		swap(heap[1], heap[index]);
		heap.size = (heap.size -1);
		Max-Heapify(heap, 1);
	}
}

Heap-Extract-Max(heap)
{
	if (heap.size < 1) { error "heap underflow"; }

	max = heap[1];
	heap[1] = heap[heap.size];
}

Heap-Increase-Key(heap, index, key)
{
	if (key < heap[index]) { error "new key is smaller than current key." }

	heap[index] = key;

	while (index > 1 && heap[parent(index)])
	{
		swap(heap[index], heap[parent(index)]);
		index = parent(index);
	}
}

Max-Heap-Insert(heap, key)
{
	heap.size = heap.size + 1;
	heap[heap.size] = -infinity; // remove.
	Heap-Increase-Key(heap, heap.size, key);
}
*/