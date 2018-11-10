#include <bits/stdc++.h>

using namespace std;

int distance(pair<int, int> first, pair<int, int> second){
	int X = (second.first - first.first) * (second.first - first.first);
	int Y = (second.second - first.second) * (second.second - first.second);

	return X + Y;
}

int findMax(vector<vector<bool>> floydWarshall){
	int maximum = 0;

	for(int i = 0; i < (int) floydWarshall.size(); i++){
		int current = 0;

		for(int j = 0; j < (int) floydWarshall.size(); j++){
			current = (floydWarshall[i][j]) ? current + 1 : current;
		}

		maximum = max(maximum, current);
	}

	return maximum;
}

int main() {
	int N;
	cin >> N;
	map<int, vector<int>> graph;
	vector<pair<pair<int, int>, int>> power;

	for(int i = 0; i < N; i++){
		int first, second, third;
		cin >> first >> second >> third;
		power.push_back(make_pair(make_pair(first, second), third));
	}

	for(int i = 0; i < N; i++){
		graph.insert(make_pair(i, vector<int> (0, 0)));
	}

	for(int i = 0; i < (int) power.size(); i++){
		for(int j = i + 1; j < (int) power.size(); j++){
			int dist = distance(power[i].first, power[j].first);

			if(dist < power[i].second * power[i].second){
				graph[i].push_back(j);
			}

			if(dist < power[j].second * power[j].second){
				graph[j].push_back(i);
			}
		}
	}

	vector<vector<bool>> floydWarshall (graph.size(), vector<bool> (graph.size(), false));

	for(auto i : graph){
		for(auto j : graph[i.first]){
			floydWarshall[i.first][j] = true;
		}
	}

	for(int i = 0; i < (int) floydWarshall.size(); i++){
		floydWarshall[i][i] = true;
	}

	for(int k = 0; k < (int) floydWarshall.size(); k++){
		for(int i = 0; i < (int) floydWarshall.size(); i++){
			for(int j = 0; j < (int) floydWarshall.size(); j++){
				floydWarshall[i][j] = floydWarshall[i][j] || (floydWarshall[i][k] && floydWarshall[k][j]);
			}
		}
	}

	cout << findMax(floydWarshall) << endl;

	return 0;
}
