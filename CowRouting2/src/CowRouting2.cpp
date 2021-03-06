#include <bits/stdc++.h>

using namespace std;
set<int> visited;
vector<int> parents;
map<int, vector<tuple<int, int, int>>> graph;

vector<long long> Dijkstra(int start){
	priority_queue<tuple<int, int, int>> pq;
	vector<long long> distance (graph.size() + 1, INT_MAX);
	pq.push(make_tuple(0, start, -1));
	distance[start] = 0;

	while(!pq.empty()){
		long long weight;
		int u, airline;
		auto front = pq.top();
		pq.pop();
		tie(weight, u, airline) = front;

		visited.insert(u);

		if(weight * -1 > distance[u]) continue;

		for(auto n : graph[u]){
			int v, w, a;
			tie(v, w, a) = n;

			if(a == airline) w = 0;

			if(distance[u] + w < distance[v]){
				distance[v] = distance[u] + w;
				pq.push(make_tuple(distance[v] * -1, v, a));
				parents[v] = u;
			}
		}
//
//		for(int i = 0; i < (int) distance.size(); i++){
//			cout << distance[i] << " ";
//		}
//
//		cout << endl;
//
//		for(int i = 0; i < (int) parents.size(); i++){
//			cout << parents[i] << " ";
//		}
//
//		cout << endl << "............................." << endl;
	}

	return distance;
}

int transfer(int start, int end){
	int count = 0;

	while(parents[end] != end){
		count++;
		end = parents[end];
	}

	return count;
}

int main() {
	int start, end, N;
	cin >> start >> end >> N;
	int maximum = 0;

	for(int i = 0; i < N; i++){
		int cost, trips;
		cin >> cost >> trips;
		int previous;
		cin >> previous;
		maximum = previous;

		for(int j = 1; j < trips; j++){
			int current;
			cin >> current;
			maximum = max(maximum, current);

			if(graph.find(previous - 1) != graph.end()){
				graph[previous - 1].push_back(make_tuple(current - 1, cost, i));
			}
			else{
				graph.insert(make_pair(previous - 1, vector<tuple<int, int, int>> ()));
				graph[previous - 1].push_back(make_tuple(current - 1, cost, i));
			}

			previous = current;
		}
	}

	for(int i = 0; i < maximum; i++){
		parents.push_back(i);
	}

	auto distance = Dijkstra(start - 1);

	if(visited.find(end - 1) == visited.end()){
		cout << "-1 -1" << endl;
		return 0;
	}

	cout << distance[end - 1] << " " << transfer(start - 1, end - 1) << endl;

	return 0;
}
