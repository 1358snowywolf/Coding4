#include <bits/stdc++.h>

using namespace std;
set<int> visited;
vector<int> answer;

set<string> convert(){
	reverse(answer.begin(), answer.end());
	set<string> result;
//	int index = 0;
//
//	for(auto i : answer){
//		if(index == 6){
//			index = 0;
//			result.insert(current);
//			current = "";
//		}
//
//		current += (i + 'A');
//		index++;
//	}
//

	for(int i = 0; i < (int) answer.size(); i += 5){
		string current = "";

		for(int j = i; j < i + 5; j++){
			current += answer[j];
		}

		result.insert(current);
	}

//	string input = "";
//
//	for(auto i : answer){
//		input += (i + 'A');
//	}
//
//	result.insert(input);

	return result;
}

void topLogical(int u, const vector<set<int>> overlap){
	if(visited.find(u) != visited.end()){
		return;
	}

	visited.insert(u);

	for(auto i : overlap[u]){
		topLogical(i, overlap);
	}

	answer.push_back(u);
}


vector<set<int>> makeGraph(vector<vector<char>> graph, vector<vector<int>> vec){
	vector<set<int>> overlap (5, set<int> ());
	char letters[] = {'A', 'B', 'C', 'D', 'E'};

	for(int i = 0; i < 5; i++){
		char character = letters[i];

		//top
		for(int y = vec[i][1]; y <= vec[i][3]; y++){
			if(graph[vec[i][0]][y] != character){
				overlap[i].insert(graph[vec[i][0]][y] - 'A');
			}
		}

		//left
		for(int x = vec[i][0]; x <= vec[i][2]; x++){
			if(graph[x][vec[i][1]] != character){
				overlap[i].insert(graph[x][vec[i][1]] - 'A');
			}
		}

		//bottom
		for(int y = vec[i][1]; y <= vec[i][3]; y++){
			if(graph[vec[i][2]][y] != character){
				overlap[i].insert(graph[vec[i][2]][y] - 'A');
			}
		}

		//right
		for(int x = vec[i][0]; x <= vec[i][2]; x++){
			if(graph[x][vec[i][3]] != character){
				overlap[i].insert(graph[x][vec[i][3]] - 'A');
			}
		}
	}

	return overlap;
}

int main(){
	int H, W;
	cin >> H >> W;
	vector<int> row = {INT_MAX, INT_MAX, INT_MIN, INT_MIN};
	vector<vector<int>> vec (5, row);
	vector<vector<char>> graph;

	for(int i = 0; i < H; i++){
		vector<char> row1;

		for(int j = 0; j < W; j++){
			char input;
			cin >> input;
			row1.push_back(input);
		}

		graph.push_back(row1);
	}

	for(int i = 0; i < (int) graph.size(); i++){
		for(int j = 0; j < (int) graph[i].size(); j++){
			if(graph[i][j] == '.'){
				continue;
			}

			vec[graph[i][j] - 'A'][0] = min(vec[graph[i][j] - 'A'][0], i);
			vec[graph[i][j] - 'A'][1] = min(vec[graph[i][j] - 'A'][1], j);
			vec[graph[i][j] - 'A'][2] = max(vec[graph[i][j] - 'A'][2], i);
			vec[graph[i][j] - 'A'][3] = max(vec[graph[i][j] - 'A'][3], j);
		}
	}

	vector<set<int>> overlap = makeGraph(graph, vec);
	set<string> result;

	for(int i = 0; i < (int) overlap.size(); i++){
		if(visited.find(i) != visited.end()){
			continue;
		}

		topLogical(i, overlap);
	}

	result = convert();

	for(string i : result){
		cout << i << endl;
	}

	return 0;
}
