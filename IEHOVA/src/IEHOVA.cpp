#include <bits/stdc++.h>

using namespace std;
vector<vector<char>> stones;
pair<int, int> start;
set<char> use;
bool clear = false;

void DFS(vector<string> path, set<pair<int, int>> visited, int i, int j){
	if(clear) return;
	if(i < 0 || i >= (int) stones.size()) return;
	if(j < 0 || j >= (int) stones[0].size()) return;

	if(stones[i][j] == '#'){
		clear = true;

		for(int k = 0; k < (int) path.size() - 1; k++){
			cout << path[k] << " ";
		}

		cout << path[(int) path.size() - 1] << endl;
		return;
	}

	if(use.find(stones[i][j]) == use.end()) return;
	if(visited.find(make_pair(i, j)) != visited.end()) return;
	visited.insert(make_pair(i, j));

//	cout << i << " " << j << endl;

	//forth
	path.push_back("forth");
	DFS(path, visited, i - 1, j);
	path.pop_back();

	//left
	path.push_back("left");
	DFS(path, visited, i, j - 1);
	path.pop_back();

	//right
	path.push_back("right");
	DFS(path, visited, i, j + 1);
}

int main() {
	int C;
	cin >> C;
	char input;

	use.insert('I');
	use.insert('E');
	use.insert('H');
	use.insert('O');
	use.insert('V');
	use.insert('A');
	use.insert('#');
	use.insert('@');

	for(int times = 0; times < C; times++){
		int N, M;
		cin >> N >> M;
		clear = false;
		stones.clear();

		for(int i = 0; i < N; i++){
			vector<char> lines;

			for(int j = 0; j < M; j++){
				cin >> input;
				lines.push_back(input);

				if(input == '@'){
					start.first = i;
					start.second = j;
				}
			}

			stones.push_back(lines);
		}

		DFS(vector<string> (), set<pair<int, int>> (), start.first, start.second);
	}

	return 0;
}
