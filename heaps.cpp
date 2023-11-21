#ifndef HEAPS_CPP
#define HEAPS_CPP

#include "heaps.h"

void MinHeap::Insert(std::vector<std::string> adjacentVerteces)
{
	heap.push_back(adjacentVerteces);
	DecreaseKey(heap.size() + 1);
}

std::vector<std::string> MinHeap::ExtractMin()
{
	std::vector<std::string> minElement = heap[0];

	heap[0] = heap[heap.size() - 1];
	heap.pop_back();
	Heapify(0);

	return minElement;
}

int MinHeap::GetSize() { return heap.size(); }

std::vector<std::vector<std::string> > MinHeap::GetData() { return heap; }

void MinHeap::DecreaseKey(int index)
{
	int parentIndex = index / 2;

	// If the current element is smaller than its parent, swap them.
	if (stoi(heap[index][2]) < stoi(heap[parentIndex][2]))
	{
		std::swap(heap[index], heap[parentIndex]);
		DecreaseKey(parentIndex);
	}
}

void MinHeap::Heapify(int index)
{
	int leftChildIndex = 2 * index + 1;
	int rightChildIndex = 2 * index + 2;
	int smallestChildIndex = leftChildIndex;
	
	if (rightChildIndex < heap.size() && stoi(heap[rightChildIndex][2]) < stoi(heap[leftChildIndex][2])) { smallestChildIndex = rightChildIndex; }

	// Added to deal with segmentation fault occurring on final pass.
	if(smallestChildIndex >= heap.size()) { smallestChildIndex = (heap.size() - 1); }

	// If the current element is greater than its smallest child, swap them.
	if (stoi(heap[index][2]) > stoi(heap[smallestChildIndex][2]))
	{
		std::swap(heap[index], heap[smallestChildIndex]);
		Heapify(smallestChildIndex);
	}
}

#endif

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