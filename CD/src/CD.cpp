#include <bits/stdc++.h>

using namespace std;
set<string> used;

void putin(vector<int> visited){
	string str (visited.begin(), visited.end());
	used.insert(str);
}

bool find(vector<int> visited, int j){
	for(int i = 0; i < (int) visited.size(); i++){
		if(visited[i] == j){
			return true;
		}
	}

	return false;
}

bool find2(vector<int> visited){
	string str (visited.begin(), visited.end());
	return (used.find(str) != used.end());
}

pair<int, vector<int>> DFS(vector<int> playlists, vector<int> visited, int maximum, int sum, int i){
	if(find2(visited)){
		return make_pair(sum, visited);
	}

	if(sum + playlists[i] > maximum){
		return make_pair(sum, visited);
	}

	if(i != -1){
		sum += playlists[i];
		visited.push_back(i);
	}

	if(sum == maximum){
		return make_pair(sum, visited);
	}

	int current = sum;
	vector<int> answer = visited;

	for(int j = 0; j < (int) playlists.size(); j++){
		if(find(visited, j)) continue;

		auto dfs = DFS(playlists, visited, maximum, sum, j);

		if(current < dfs.first){
			current = dfs.first;
			answer = dfs.second;
		}
	}

	return make_pair(current, answer);
}

int main() {
	int N, T, input;

	while(cin >> N){
		cin >> T;
		used.clear();
		vector<int> playlists;

		for(int i = 0; i < T; i++){
			cin >> input;
			playlists.push_back(input);
		}

		auto answer = DFS(playlists, vector<int> (), N, 0, -1);

		for(int i : answer.second){
			cout << playlists[i] << " ";
		}

		cout << "sum:" << answer.first << endl;
	}
	return 0;
}
