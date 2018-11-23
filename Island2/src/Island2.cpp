#include <bits/stdc++.h>

using namespace std;

void connect(set<pair<int, int>>& water, int i){
	auto itr = lower_bound(water.begin(), water.end(), make_pair(i, i));
	pair<int, int> input = make_pair(i, i);
	auto previous = prev(itr);

	bool delete_itr = false;
	bool delete_previous = false;

	if(input.second + 1== itr->first){
		input.second = itr->second;
		delete_itr = true;
	}
	if(input.first - 1 == previous->second){
		input.first = previous->first;
		delete_previous = true;
	}

	if(delete_itr){
		water.erase(itr);
	}
	if(delete_previous){
		water.erase(previous);
	}

	water.insert(input);
}

int main() {
	int N;
	cin >> N;
	map<int, vector<int>> heights;

	for(int i = 0; i < N; i++){
		int input;
		cin >> input;
		heights[input].push_back(i);
	}

	int maximum = 1;
	set<pair<int, int>> water;
	water.insert(make_pair(-1, -1));
	water.insert(make_pair(N, N));

	for(auto i : heights){
		for(auto j : i.second){
			connect(water, j);
		}

		maximum = max(maximum, (int) water.size() - 1);
	}

	cout << maximum << endl;

	return 0;
}
