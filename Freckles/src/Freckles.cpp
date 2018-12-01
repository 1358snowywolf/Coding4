#include <bits/stdc++.h>

using namespace std;
vector<vector<pair<int, float>>> neighbors;

void process(int v, priority_queue<pair<float, int>>& pq, vector<bool>& visited){
	visited[v] = true;

	for(auto u : neighbors[v]){
		if(visited[u.first]) continue;
		pq.push({u.second * -1, u.first});
	}
}

float Prim(){
	priority_queue<pair<float, int>> pq;
	vector<bool> visited (neighbors.size(), false);
	process(0, pq, visited);
	float cost = 0;

	while(!pq.empty()){
		auto u = pq.top();
		pq.pop();

//		cout << u.first * -1 << " " << u.second << endl;

		if(visited[u.second]) continue;

		cost += (u.first * -1);
		process(u.second, pq, visited);
	}

	return cost;
}

int main(){
	int C;
	cin >> C;

	for(int times = 0; times < C; times++){
		int N;
		cin >> N;

		vector<pair<float, float>> freckles;
		vector<vector<pair<int, float>>> input (N, vector<pair<int, float>> ());
		neighbors = input;
		input.clear();

		for(int i = 0; i < N; i++){
			float x, y;
			cin >> x >> y;
			freckles.push_back(make_pair(x, y));
		}


		for(int i = 0; i < N; i++){
			for(int j = i + 1; j < N; j++){
				if(i == j) continue;

				float X = (freckles[i].first - freckles[j].first) * (freckles[i].first - freckles[j].first);
				float Y = (freckles[i].second - freckles[j].second) * (freckles[i].second - freckles[j].second);
				float distance = (float) sqrt(X + Y);

				neighbors[i].push_back(make_pair(j, distance));
				neighbors[j].push_back(make_pair(i, distance));
			}
		}

		float answer = Prim();
		cout << fixed << setprecision(2) << answer << endl << endl;
	}

	return 0;
}
