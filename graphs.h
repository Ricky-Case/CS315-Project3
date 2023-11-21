#ifndef GRAPHS_H
#define GRAPHS_H

#include <map>
#include <queue>
#include <iostream>

const int NO_PATH = -1;
const int INVALID_VERTEX = -2;

template <typename T>
class Graph
{
public:
	void BuildGraph(std::vector<std::vector<T> >&);
	void PrintData();

	// Check to see if an edge exists between two points.
    bool HasEdge(T T1, T T2) const;

    // Add an edge between two points.
    void AddEdge(T T1, T T2);

    // Apply BFS to find the shortest path from the starting point to the destination.
    // Return the distnace from the start to the finish.
    // If either doesn't exist, return INVALID_VERTEX (-2)
    // If noth path exists, return NO_PATH (-1)
    // store the shortest path distance from the given source s  to vertex w in distance map<w, distance>
    // store which next vertex to go through on the shortest path to the given source s in go_through map<w, v>.
    // Here a pair <w, v> in go_through map represents on the shortest path from w to the given source s, it needs to take the path: w-->v...-->s
    int BFS(T& T1, T& T2, std::map<T, int>& T3, std::map<T, T>& T4);

private:
    //represent the mapping from a Vertex, say u (key) to a set of vertices (value) which directly connect to u
    std::vector<std::vector<T> > adjacentPoints;
};

#endif
#include "graphs.cpp"


//**********************//
//******PSEUDOCODE******//
//**********************//

/*
************BFS************

BFS(graph, node)
	for each vertex u which is an element of graph, excluding node
		u.color = WHITE
		u.d = infinity
		u.pi = NIL
	node.color = GRAY
	node.d = 0
	node.pi = NIL
	Q = EmptySet

	Enqueue(Q, node)

	while Q != node
		u = Dequeue(Q)
		for each v which is an element of graph.adj[u]
			if v.color == WHITE
				v.color = GRAY
				v.d = u.d + 1
				v.pi = u
				Enqueue(q, v)
		
		u.color = BLACK

Print-Path(graph, s, v)
	if v == s
		print(s)
	else if v.pi == NIL
		print("no path from s to v exists")
	else
		Print-Path(graph, s, v.pi)
		print(v)



**********DIJKSTRA********

Dijkstra(graph, w, s)
	Initialize-Single-Source(g, s)
	S = EmptySet
	Q = G.V

	while (Q != EmptySet)
		u = Extract-Mini(Q)
		S = S UNION {u}

		for each vertex v in G.adj[u]
			Relax(u, v, w)

Relax(u, v, w)
	if v.d > (u.d + w(u, v))
		v.d = (u.d + w(u, v))
		v.pi = u

Initialize-Single-Source(G, s)
	for each vertex v in G.V
		v.d = infinity
		v.pi = NIL
	
	s.d = 0
*/