//============================================================================
// Name        : Mother_Vertex.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;

void motherVertex(map<int, vector<int>> graph, int u, set<int> visited){
	if(visited.find(u) != visited.end()){
		return;
	}

	visited.insert(u);

	for(int v : graph[u]){
		motherVertex(graph, v, visited);
	}
}

int main() {
	map<int, vector<int>> graph;

	for(int u : graph){
		set<int> visited;
		motherVertex(graph, u, visited);
		if(visited.size() == graph.size()){
			cout << u << endl;
		}
	}
	return 0;
}
