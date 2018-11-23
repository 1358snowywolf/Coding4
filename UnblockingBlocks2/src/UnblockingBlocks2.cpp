#include <bits/stdc++.h>

using namespace std;
bool answer = false;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int total_x = 0;
int total_y = 0;

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
	set<pair<int, int>> other;

	for(auto i : first){
		other.insert(i);

		for(int j = 0; j < 4; j++){
			other.insert(make_pair(i.first + dx[j], i.second + dy[j]));
		}
	}

	return checkOverlap(first, second);
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

void DFS(vector<set<pair<int, int>>> blocks, pair<pair<int, int>, pair<int, int>> movements, set<pair<pair<int, int>, pair<int, int>>>& visited){
	if(answer) return;
	if (min(movements.first.first, movements.second.first) < total_x) return;
	if (max(movements.first.second, movements.second.second) < total_y) return;

	if(!separated(blocks[0], blocks[1]) && !separated(blocks[2], blocks[1]) && !separated(blocks[0], blocks[2])){
		answer = true;
		return;
	}

	if(visited.find(movements) != visited.end()){
		return;
	}

	visited.insert(movements);

	cout << "(" << movements.first.first << ", " << movements.first.second << ") (" << movements.second.first << ", " << movements.second.second << ")" << endl;

	for(int i = 0; i < 4; i++){
		auto b1 = blocks;
		auto b2 = blocks;
		auto m1 = movements;
		auto m2 = movements;

		change(b1, 1, i);
		change(b2, 2, i);
		m1.first = make_pair(m1.first.first + dx[i], m1.first.second + dy[i]);
		m2.second = make_pair(m2.second.first + dx[i], m2.second.second + dy[i]);

		DFS(b1, m1, visited);
		DFS(b2, m2, visited);
	}
}

void cinEverything(int N, set<pair<int, int>>& pieces){
	int min_x = INT_MAX;
	int min_y = INT_MAX;
	int max_x = INT_MIN;
	int max_y = INT_MIN;
	for(int i = 0; i < N; i++){
		int one, two;
		cin >> one >> two;
		pieces.insert(make_pair(one, two));
		min_x = min(min_x, one);
		min_y = min(min_y, two);
		max_x = max(max_x, one);
		max_y = max(max_y, two);
	}

	total_x += (max_x - min_x + 1);
	total_y += (max_y - min_y + 1);
}

int main() {
//	freopen ("unlock.in", "r", stdin);
//	freopen ("unlovk.out", "w", stdout);
	int N1, N2, N3;
	cin >> N1 >> N2 >> N3;
	set<pair<int, int>> first, second, third;

	cinEverything(N1, first);
	cinEverything(N2, second);
	cinEverything(N3, third);

	pair<pair<int, int>, pair<int, int>> movements;
	set<pair<pair<int, int>, pair<int, int>>> visited;
	vector<set<pair<int, int>>> blocks = {first, second, third};

	DFS(blocks, movements, visited);

	cout << answer << endl;

	return 0;
}
