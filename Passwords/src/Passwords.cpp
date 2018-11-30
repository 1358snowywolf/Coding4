#include <bits/stdc++.h>

using namespace std;
set<string> answers;

void DFS(vector<vector<char>> grid, vector<unordered_set<char>> columns, string password, int i, int j){
	if(j == 5){
		answers.insert(password);
		return;
	}

	for(int i = 0; i < 6; i++){
		if(columns[j].find(grid[i][j]) == columns[j].end()){
			continue;
		}

		string sacrafice = password;
		sacrafice += grid[i][j];
		DFS(grid, columns, sacrafice, i, j + 1);
	}
}

int main() {
	int C;
	cin >> C;

	for(int times = 0; times < C; times++){
		int K;
		cin >> K;
		answers.clear();

		vector<vector<char>> first;
		vector<vector<char>> second;

		for(int i = 0; i < 6; i++){
			vector<char> line;
			for(int j = 0; j < 5; j++){
				char input;
				cin >> input;
				line.push_back(input);
			}
			first.push_back(line);
		}

		for(int i = 0; i < 6; i++){
			vector<char> line;
			for(int j = 0; j < 5; j++){
				char input;
				cin >> input;
				line.push_back(input);
			}
			second.push_back(line);
		}

		vector<unordered_set<char>> columns;

		for(int j = 0; j < 5; j++){
			unordered_set<char> input;
			for(int i = 0; i < 6; i++){
				input.insert(second[i][j]);
			}
			columns.push_back(input);
		}

		DFS(first, columns, "", 0, 0);

		if((int) answers.size() < K){
			cout << "NO" << endl;
		}
		else{
			int index = 1;

			for(auto i : answers){
				if(index == K){
					cout << i << endl;
					break;
				}

				index++;
			}
		}
	}

	return 0;
}
