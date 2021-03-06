#include <bits/stdc++.h>

using namespace std;
map<int, vector<pair<int, int>>> graph;

vector<int> Dijkstra(int N, int end){
	priority_queue<pair<int, int>> pq;
	vector<int> distance (N, 10760000);
	pq.push(make_pair(0, end));
	distance[end] = 0;

	while(!pq.empty()){
		pair<int, int> front = pq.top();
		pq.pop();

		if(front.first * -1 > distance[front.second]){
			continue;
		}

		for(auto n : graph[front.second]){
			if(distance[front.second] + n.second < distance[n.first]){
				distance[n.first] = distance[front.second] + n.second;
				pq.push(make_pair(distance[n.first] * -1, n.first));
			}
		}
	}

	return distance;
}

int findCount(vector<int> distance, int T){
	int count = 0;

	for(int i = 0; i < (int) distance.size(); i++){
		if(distance[i] <= T){
			count++;
		}
	}

	return count;
}

int main(){
	int C;
	cin >> C;

	for(int i = 0; i < C; i++){
		graph.clear();
		int N, E, T, M;
		cin >> N >> E >> T >> M;

		for(int i = 0; i < N; i++){
			graph.insert(make_pair(i, vector<pair<int, int>> ()));
		}

		for(int i = 0; i < M; i++){
			int u, v, weight;
			cin >> u >> v >> weight;
			graph[v - 1].push_back(make_pair(u - 1, weight));
		}

		vector<int> distance = Dijkstra(N, E - 1);
		int count = findCount(distance, T);

		cout << count << endl << endl;
	}


	return 0;
}
