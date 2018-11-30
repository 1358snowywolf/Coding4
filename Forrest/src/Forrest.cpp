//============================================================================
// Name        : Forrest.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;
set<int> visited;

int DFS(vector<vector<int>> graph, int current){
	int size = 0;

	for(int i = 0; i < (int) graph[current].size(); i++){
		if(visited.find(graph[current][i]) != visited.end()){
			continue;
		}

		visited.insert(graph[current][i]);
		size += DFS(graph, graph[current][i]);
	}

	return size + 1;
}

int main() {
	int C;
	cin >> C;

	for(int times = 0; times < C; times++){
		vector<vector<int>> graph (26, vector<int> ());
		visited.clear();
		string input;

		while(true){
			cin >> input;
			if(input[0] == '*') break;

			graph[input[1] - 'A'].push_back(input[3] - 'A');
			graph[input[3] - 'A'].push_back(input[1] - 'A');
		}

//		for(int i = 0; i < (int) graph.size(); i++){
//			cout << (char) (i + 'A') << ": ";
//
//			for(int j = 0; j < (int) graph[i].size(); j++){
//				cout << (char) (graph[i][j] + 'A') << " ";
//			}
//
//			cout << endl;
//		}

		cin >> input;

		set<int> characters;

		for(int i = 0; i < (int) input.size(); i += 2){
			characters.insert(input[i] - 'A');
		}

		int acorns = 0;
		int trees = 0;

		for(int i : characters){
			if(visited.find(i) != visited.end()) continue;

			visited.insert(i);
			int size = DFS(graph, i);

			if(size <= 1){
				acorns++;
//				cout << "acrs" << acorns << endl;
			}
			else{
				trees++;
//				cout << "trees" << trees << endl;
			}
		}

		cout << "There are " << trees << " tree(s) and " << acorns << " acorn(s)." << endl;
	}

	return 0;
}
