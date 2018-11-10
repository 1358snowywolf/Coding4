#include <bits/stdc++.h>

using namespace std;
set<int> starting;
unordered_set<int> finished;
vector<int> pastures (1010, 0);

void DFS(map<int, vector<int>> graph, set<int>& visited, int u, int count){
	if(visited.find(u) != visited.end()){
		return;
	}

	visited.insert(u);

	//        in starting                           not in finished - your helpful daughter
	if(starting.find(u) != starting.end() && finished.find(u) == finished.end()){
		count++;
		finished.insert(u);
	}

	pastures[u] += count;

	for(auto i : graph[u]){
		DFS(graph, visited, i, count);
	}
}

//void adding(set<int> visited, vector<int>& pastures){
//	for(int i : visited){
//		pastures[i]++;
//	}
//}

int findMax(vector<int> pastures, int N, int K){
	int amount = 0;

	for(int i = 1; i <= N; i++){
		if(pastures[i] == K){
			amount++;
		}
	}

	return amount;
}

bool works(int index, vector<vector<bool>> floydWarshall){
	for(int i = 1; i < (int) floydWarshall[index].size(); i++){
		if(!floydWarshall[i][index]){
			return false;
		}
	}

	return true;
}

bool worksTwo(int index, vector<vector<bool>> floydWarshall){
	for(auto i : starting){
		if(!floydWarshall[i][index]){
			return false;
		}
	}

	return true;
}

int main() {
	int K, N, M;
	cin >> K >> N >> M;

	for(int i = 0; i < K; i++){
		int position;
		cin >> position;
		starting.insert(position);
	}

	map<int, vector<int>> graph;

	for(int i = 1; i <= N; i++){
		graph.insert(make_pair(i, vector<int> (0, 0)));
	}

	for(int i = 1; i <= M; i++){
		int start, end;
		cin >> start >> end;
		graph[start].push_back(end);
	}

	vector<vector<bool>> floydWarshall (graph.size() + 1, vector<bool> (graph.size() + 1, false));

	for(auto i : graph){
		for(auto j : graph[i.first]){
			floydWarshall[i.first][j] = true;
		}
	}

	for(int i = 0; i < (int) floydWarshall.size(); i++){
		floydWarshall[i][i] = true;
	}

	for(int k = 0; k < (int) floydWarshall.size(); k++){
		for(int i = 0; i < (int) floydWarshall.size(); i++){
			for(int j = 0; j < (int) floydWarshall.size(); j++){
				floydWarshall[i][j] = floydWarshall[i][j] || (floydWarshall[i][k] && floydWarshall[k][j]);
			}
		}
	}

	int count = 0;

//	for(int i = 0; i < (int) floydWarshall.size(); i++){
//		if(works(i, floydWarshall)){
//			count++;
//		}
//	}

	for(int i = 0; i < (int) floydWarshall.size(); i++){
		if(worksTwo(i, floydWarshall)){
			count++;
		}
	}

	cout << count<< endl;

//	for(auto i : graph){
//		cout << i.first << ": ";
//
//		for(auto j : graph[i.first]){
//			cout << j << " ";
//		}
//
//		cout << endl;
//	}

//	for(int i : starting){
//		if(finished.find(i) == finished.end()){
//			set<int> visited;
//			DFS(graph, visited, i, 0);
//		}
//
////		 for(int i = 0; i <= N; i++){
////			 cout << pastures[i] << " ";
////		 }
////		 cout << endl;
//
////		 adding(visited, pastures);
//
////		 for(int i = 0; i < (int) pastures.size(); i++){
////			 cout << pastures[i] << " ";
////		 }
////		 cout << endl;
//	}



//	cout << findMax(pastures, N, K) << endl;

	return 0;
}
