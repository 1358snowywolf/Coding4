#include <bits/stdc++.h>

using namespace std;
set<int> visited;
vector<int> answer;
vector<int> weights;
map<int, vector<int>> graph;

void topLogical(int u){
	if(visited.find(u) != visited.end()){
		return;
	}

	visited.insert(u);

	for(auto i : graph[u]){
		topLogical(i);
	}

	answer.push_back(u);
}

int findMax(vector<int> results){
	int minimum = INT_MAX;

	for(int i = 0; i < (int) results.size(); i++){
		minimum = min(minimum, results[i]);
	}

	return minimum * -1;
}

int main() {
	int N, M;
	cin >> N >> M;

	for(int i = 0; i < N; i++){
		int input;
		cin >> input;
		weights.push_back(input * -1);
		graph.insert(make_pair(i, vector<int> (0, 0)));
	}

	for(int i = 0; i < M; i++){
		int start, end;
		cin >> start >> end;
		graph[start - 1].push_back(end-1);
	}

	for(int i = 0; i < N; i++){
		if(visited.find(i) != visited.end()){
			continue;
		}

		topLogical(i);
	}

	reverse(answer.begin(), answer.end());
	vector<int> distance (N, 0);

	for(int i = 0; i < (int) answer.size(); i++){
		distance[answer[i]] = min(distance[answer[i]], weights[answer[i]]);

		for(auto j : graph[answer[i]]){
			distance[j] = min(distance[j], distance[answer[i]] + weights[j]);
		}
	}

	cout << findMax(distance) << endl;

	return 0;
}
