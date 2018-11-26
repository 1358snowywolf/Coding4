#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> maze;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
//pair<string, pair<pair<int, int>, pair<int, int>>> answer;
set<pair<string, pair<pair<int, int>, pair<int, int>>>> answer;

void DFS(pair<int, int> beginning, int i, int j, string str, set<pair<int, int>> visited){
//	cout << i << " " << j << ": " << maze[i][j] << endl;

	if(i < 0 || i >= (int) maze.size()){
		return;
	}
	if(j < 0 || j >= (int) maze[i].size()){
		return;
	}
	if(visited.find(make_pair(i, j)) != visited.end()) return;

	if(i == (int) maze.size() - 1){
		string s = to_string(str[0]) + to_string(str[(int) str.size() - 1]);
		answer.insert(make_pair(s, make_pair(beginning, make_pair(i, j))));
		cout << str << ": " << beginning.first << " " << beginning.second << " " << i << " " << j << endl;
//		if(answer.first > str){
//			answer.first = str;
//			answer.second = make_pair(beginning, make_pair(i, j));
//		}
		return;
	}

	visited.insert(make_pair(i, j));
	str += to_string(maze[i][j]);

	for(int k = 0; k < 4; k++){
		if(i + dx[k] < 0 || i + dx[k] >= (int) maze.size()){
			return;
		}
		if(j + dy[k] < 0 || j + dy[k] >= (int) maze[i].size()){
			return;
		}

		if(maze[i][j] + 1 == maze[i + dx[k]][j + dy[k]]){
			DFS(beginning, i + dx[k], j + dy[k], str, visited);
		}
		else if(maze[i + dx[k]][j + dy[k]] == 1){
			DFS(beginning, i + dx[k], j + dy[k], str, visited);
		}
	}
}

int main() {
	int C;
	cin >> C;

	for(int times = 0; times < C; times++){
		int N, M;
		cin >> N >> M;
		maze.clear();
		answer.clear();

		for(int i = 0; i < N; i++){
			vector<int> line;
			for(int j = 0; j < M; j++){
				int input;
				cin >> input;
				line.push_back(input);
			}
			maze.push_back(line);
		}

		for(int i = 0; i < M; i++){
			if(maze[0][i] != 1) continue;
			DFS(make_pair(0, i), 0, i, "", set<pair<int, int>> ());
//			cout << endl << endl;
		}

//		auto a = *answer.begin();
		cout << answer.begin()->second.first.first + 1 << " " << answer.begin()->second.first.second + 1 << endl;
		cout << answer.begin()->second.second.first + 1 << " " << answer.begin()->second.second.second + 1 << endl;
		cout << endl;

//		cout << answer.first << endl;
//		cout << answer.second.first.first + 1 << " " << answer.second.first.second + 1 << endl;
//		cout << answer.second.second.first + 1 << " " << answer.second.second.second + 1 << endl;
		cout << endl;
	}


	return 0;
}
