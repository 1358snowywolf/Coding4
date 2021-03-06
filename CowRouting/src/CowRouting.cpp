#include <bits/stdc++.h>

using namespace std;
map<int, vector<pair<int, int>>> graph;
map<int, set<int>> flights;

vector<int> Dijkstra(int N, int start){
	priority_queue<pair<int, int>> pq;
	vector<int> distance (N, 176000);
	pq.push(make_pair(0, start));
	distance[start] = 0;

	while(!pq.empty()){
		pair<int, int> front = pq.top();
		pq.pop();

		if(front.first * -1 > distance[front.second]) continue;

		for(auto n : graph[front.second]){
			if(n.second < distance[n.first]){
				distance[n.first] = n.second;
				pq.push(make_pair(distance[n.first] * -1, n.first));
			}
		}
	}

	return distance;
}

int main() {
	int start, end, N;
	cin >> start >> end >> N;

	for(int i = 0; i < N; i++){
		int cost, size;
		cin >> cost >> size;
		int previous;
		cin >> previous;
		flights.insert(make_pair(i, set<int> ()));
		flights[i].insert(previous);

		for(int i = 0; i < size - 1; i++){
			int current;
			cin >> current;
			if(graph.find(previous) != graph.end()){
				graph[previous].push_back(make_pair(current - 1, cost))];
			}
			else{
				graph.insert(make_pair(previous, vector<pair<int, int>> (1, make_pair(current - 1, cost))));
			}

			flights[i].insert(current);
			previous = current;
		}
	}

	auto distance = Dijkstra(N, start);

	return 0;
}
