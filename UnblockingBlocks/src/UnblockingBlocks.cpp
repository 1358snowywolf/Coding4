#include <bits/stdc++.h>

using namespace std;
bool answer = false;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

// if not overlap, return true
bool checkOverlap(set<pair<int, int>> first, set<pair<int, int>> second){
	for(auto i : second){
		if(first.find(i) != first.end()){
			return false;
		}
	}

	return true;
}

// if not seperated, return true
bool separated(set<pair<int, int>> first, set<pair<int, int>> second){
	int dx[] = {0, 0, 1, -1};
	int dy[] = {1, -1, 0, 0};
	set<pair<int, int>> other;

	for(auto i : first){
		other.insert(i);

		for(int j = 0; j < 4; j++){
			other.insert(make_pair(i.first + dx[j], i.second + dy[j]));
		}
	}

	return checkOverlap(first, second);
}

void cinEverything(int N, set<pair<int, int>>& pieces){
	for(int i = 0; i < N; i++){
		int one, two;
		cin >> one >> two;
		pieces.insert(make_pair(one, two));
	}
}

void change(vector<set<pair<int, int>>>& blocks, int index, int i){
	set<pair<int, int>> add;

	for(auto itr = blocks[index].begin(); itr != blocks[index].end(); ++itr){
		int first = itr->first + dx[i];
		int second = itr->second + dy[i];
		add.insert(make_pair(first, second));
	}

	blocks[index].clear();

	for(auto j : add){
		blocks[index].insert(j);
	}
}

void DFS(vector<set<pair<int, int>>> blocks, set<pair<int, int>> visited, pair<int, int> degree, const int index, const int other){
	if(answer) return;

	if(separated(blocks[0], blocks[index])){
		if(other == -1 || separated(blocks[other], blocks[index])){
			answer = true;
		}

		return;
	}

	if(visited.find(degree) != visited.end()) return;
	visited.insert(degree);

	for(int i = 0; i < 4; i++){
		change(blocks, index, i);
		DFS(blocks, visited, make_pair(degree.first + dx[i], degree.second + dy[i]), index, other);
	}
}

int main() {
	int N1, N2, N3;
	cin >> N1 >> N2 >> N3;
	set<pair<int, int>> first, second, third;

	cinEverything(N1, first);
	cinEverything(N2, second);
	cinEverything(N3, third);
	vector<set<pair<int, int>>> blocks = {first, second, third};

//	cout << checkOverlap(third, second);  // 1 = true
//	cout << separated(first, second) << endl;


	DFS(blocks, set<pair<int, int>> (), make_pair(0, 0), 1, 2);

	if(answer){
		answer = false;

		DFS(blocks, set<pair<int, int>> (), make_pair(0, 0), 2, -1);
		if(answer){
			cout << true << endl;
			return 0;
		}
	}

	answer = false;

	DFS(blocks, set<pair<int, int>> (), make_pair(0, 0), 2, 1);

	if(answer){
		answer = false;

		DFS(blocks, set<pair<int, int>> (), make_pair(0, 0), 1, -1);
		if(answer){
			cout << true << endl;
			return 0;
		}
	}

	cout << false << endl;

	return 0;
}
