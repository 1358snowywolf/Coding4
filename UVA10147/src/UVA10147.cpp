#include <bits/stdc++.h>

using namespace std;
int N, M;
vector<int> parents;
vector<pair<int, int>> total;

int distance(int i, int j, vector<pair<int, int>> coordinates){
	int X = (coordinates[i].first - coordinates[j].first) *
			(coordinates[i].first - coordinates[j].first);
	int Y = (coordinates[i].second - coordinates[j].second) *
			(coordinates[i].second - coordinates[j].second);

	return X + Y;
}

bool included(vector<pair<int, int>> alreadyhas, int i, int j){
	for(int index = 0; index < (int) alreadyhas.size(); index++){
		if(alreadyhas[index].first == i && alreadyhas[index].second == j){
			return true;
		}
		if(alreadyhas[index].first == j && alreadyhas[index].second == i){
			return true;
		}
	}

	return true;
}

int findParents(int u){
	while(parents[u] != u){
		u = parents[u];
	}

	return u;
}

void connect(int u, int v){
	int x = findParents(u);
	int y = findParents(v);

	parents[y] = x;
}

void KrushalAlgorithm(vector<tuple<int, int, int>> edges){
	for(tuple<int, int, int> edge : edges){
		int weight, u, v;
		tie(weight, u, v) = edge;
//		cout << weight << ' ' << u << " " << v << endl;

		if(findParents(u) != findParents(v)){
			connect(u, v);
//
//			if(weight == 0){
//				continue;
//			}

			total.push_back(make_pair(u, v));
			if(total.size() == N - 1 - M){
				return;
			}
		}
	}
}

int main() {
	int C;
	cin >> C;

	for(int times = 0; times < C; times++){
		total.clear();
		parents.clear();
		cin >> N;
//		vector<pair<int, int>> alreadyhas;
		vector<pair<int, int>> coordinates;
		vector<tuple<int, int, int>> edges;

		for(int i = 0; i < N; i++){
			int X, Y;
			cin >> X >> Y;
			parents.push_back(i);
			coordinates.push_back(make_pair(X, Y));
		}

		cin >> M;
//		cout << "here" << endl;

		for(int i = 0; i < M; i++){
			int start, end;
			cin >> start >> end;
//			alreadyhas.push_back(make_pair(start - 1, end - 1));
			connect(start - 1, end - 1);
		}

//		cout << "hi" << endl;

		for(int i = 0; i < (int) coordinates.size(); i++){  //error
			for(int j = 0; j < (int) coordinates.size(); j++){
				if(i == j){
					continue;
				}
//				if(!included(alreadyhas, i, j)){
//					edges.push_back(make_tuple(0, i, j));
//					continue;
//				}

				edges.push_back(make_tuple(distance(i, j, coordinates), i, j));
			}
		}

		sort(edges.begin(), edges.end());

//		cout << "call" << endl;

		KrushalAlgorithm(edges);

		if((int) total.size() == 0){
			cout << "No new highways need" << endl;
		}
		else{
//			sort(total.begin(), total.end());
			for(int i = 0; i < (int) total.size(); i++){
				cout << total[i].first + 1 << " " << total[i].second + 1 << endl;
			}
		}

//		cout << endl;
	}

	cout << endl;

	return 0;
}
