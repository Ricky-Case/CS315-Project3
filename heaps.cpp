#ifndef HEAPS_CPP
#define HEAPS_CPP

#include "heaps.h"

void MinHeap::Insert(std::vector<std::string> adjacentVerteces)
{
	heap.push_back(adjacentVerteces);
	DecreaseKey(heap.size() - 1);
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

void MinHeap::PrintMinimumElement() { std::cout << "Minimum Element: " << heap[0][0] << " and " << heap[0][1] << ", at " << heap[0][2] << std::endl; }

void MinHeap::DecreaseKey(int index)
{
	int parentIndex = (index - 1) / 2;

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