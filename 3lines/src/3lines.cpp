#include <bits/stdc++.h>

using namespace std;

bool check(vector<pair<int, int>> one, vector<pair<int, int>> two, vector<pair<int, int>> three, set<pair<int, int>> coordinates){
	set<pair<int, int>> cows;

	for(int i = 0; i < (int) one.size(); i++){
		cows.insert(one[i]);
	}
	for(int i = 0; i < (int) two.size(); i++){
		cows.insert(two[i]);
	}
	for(int i = 0; i < (int) three.size(); i++){
		cows.insert(three[i]);
	}

	if(cows.size() == coordinates.size()){
		return true;
	}
	return false;
}

int main() {
	int N;
	cin >> N;
	map<int, vector<pair<int, int>>> vertical;
	map<int, vector<pair<int, int>>> horizontal;
	set<pair<int, int>> coordinates;

	for(int i = 0; i < N; i++){
		int X, Y;
		cin >> X >> Y;
		if(horizontal.find(Y) != horizontal.end()){
			horizontal[Y].push_back(make_pair(X, Y));
		}
		else{
			horizontal.insert((make_pair(Y, vector<pair<int, int>> (1, make_pair(X, Y)))));
		}
		if(vertical.find(X) != vertical.end()){
			vertical[X].push_back(make_pair(X, Y));
		}
		else{
			vertical.insert((make_pair(X, vector<pair<int, int>> (1, make_pair(X, Y)))));
		}

		coordinates.insert(make_pair(X, Y));
	}

	for(auto i : horizontal){
		for(auto j : vertical){
			for(auto k : horizontal){
				if(i == k){
					continue;
				}

				if(check(i.second, j.second, k.second, coordinates)){
					cout << 1 << endl;
					return 0;
				}
			}


			for(auto k : horizontal){
				if(j == k){
					continue;
				}

				if(check(i.second, j.second, k.second, coordinates)){
					cout << 1 << endl;
					return 0;
				}
			}
		}
	}

	cout << 0 << endl;

	return 0;
}
