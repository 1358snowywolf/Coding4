#include <bits/stdc++.h>

using namespace std;
bool printed = false;

void DFS(vector<vector<int>> graph, set<int> visited, int index, int L, vector<int> path){
//	cout << path.size() << "   " << index <<  " (";
//
//	for(int i = 0; i < L + 1; i++){
//		cout << path[i] << ",";
//	}
//	cout << " ---------------------- " << endl;


	if((int) path.size() == L + 1){
		printed = true;

		cout << "(";

		for(int i = 0; i < (int) path.size() - 1; i++){
			cout << path[i] << ",";
		}

		cout << path[(int) path.size() - 1] << ")" << endl;
		return;
	}

	for(int i = 0; i < (int) graph[index].size(); i++){
		if(graph[index][i] == 0){
			continue;
		}
		if(visited.find(i) != visited.end()){
			continue;
		}

//		cout << i << " ";
		path.push_back(i + 1);
		visited.insert(i);
		DFS(graph, visited, i, L, path);
		visited.erase(i);
		path.pop_back();
	}
}

int main() {
	int N, L;

	while(cin >> N >> L){
//		cout << N << L;
		vector<vector<int>> graph;

		for(int i = 0; i < N; i++){
			vector<int> line;

			for(int j = 0; j < N; j++){
				int input;
				cin >> input;
				line.push_back(input);
			}

			graph.push_back(line);
		}

		set<int> visited;
		vector<int> path;
		visited.insert(0);
		path.push_back(1);

		DFS(graph, visited, 0, L, path);

		if(!printed){
			cout << "no walk of length " << L << endl;
		}

		printed = false;

		int nines;
		if (!(cin >> nines)) {
			return 0;
		}

		cout << endl;
	}

	return 0;
}
