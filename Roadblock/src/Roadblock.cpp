#include <bits/stdc++.h>

using namespace std;
vector<int> parent;
map<int, vector<pair<int, int>>> graph;
map<pair<int, int>, int> weights;

vector<int> Dijkstra(int T){
	priority_queue<pair<int, int>> pq;
	vector<int> distance (T, 2000000);

	for(int i = 0; i < T; i++){
		parent.push_back(i);
	}

	pq.push(make_pair(0, 0));
	distance[0] = 0;

	while(!pq.empty()){
		pair<int, int> front = pq.top();
		pq.pop();

		if(front.first * -1 > distance[front.second]) continue;

		for(auto n : graph[front.second]){
			if(distance[front.second] + n.second < distance[n.first]){
				distance[n.first] = distance[front.second] + n.second;
				pq.push(make_pair(distance[n.first] * -1, n.first));
				parent[n.first] = front.second;

//				for(int i = 0; i < (int) parent.size(); i++){
//					cout << parent[i] << " ";
//				}
//
//				cout << endl;
			}
		}
	}

	return distance;
}

//vector<pair<int, int>> make_vector(int N){
//	int index = N - 1;
//	vector<pair<int, int>> answer;
//
//	while(parent[index] != index){
//		answer.push_back(make_pair(parent[index], index));
//		index = parent[index];
//	}
//
//	return answer;
//}
//
//vector<int> make_weights(vector<pair<int, int>> connections){
//	vector<int> paths;
//
//	for(int i = 0; i < (int) connections.size(); i++){
//		paths.push_back(weights[connections[i]]);
//	}
//
//	return paths;
//}

int findIndex(int u, int v){
	int weight;

	for(int i = 0; i < (int) graph[u].size(); i++){
		if(graph[u][i].first == v){
			weight = i;
		}
	}

	return weight;
}

pair<int, int> thing(int N){
	int maximum = 0;
	int i = N - 1;
	int u, v;

	while(i != parent[i]){
		int weight = findIndex(i, parent[i]);

		if(weight > maximum){
			maximum = weight;
			u = parent[i];
			v = i;
		}

		i = parent[i];
	}

	return make_pair(u, v);
}

void changeWeight(pair<int, int> ii){
	for(int i = 0; i < (int) graph[ii.first].size(); i++){
		if(graph[ii.first][i].first == ii.second){
			graph[ii.first][i].second *= 2;
			cout << ii.first << " " << ii.second << " " << graph[ii.first][i].second << endl;
			return;
		}
	}
}

int main() {
	int N, M;
	cin >> N >> M;

	for(int i = 0; i < N;  i++){
		graph.insert(make_pair(i, vector<pair<int, int>> ()));
	}

	for(int i = 0; i < M; i++){
		int start, end, weight;
		cin >> start >> end >> weight;
		graph[start - 1].push_back(make_pair(end - 1, weight));
		graph[end - 1].push_back(make_pair(start - 1, weight));
		weights.insert(make_pair(make_pair(start - 1, end - 1), weight));
	}

	auto first = Dijkstra(N);
	auto ii = thing(N);
	changeWeight(ii);
	auto second = Dijkstra(N);

	cout << second[N - 1] - first[N - 1] << endl;

	for(int i = 0; i < (int) first.size(); i++){
		cout << first[i] << " ";
	}

	cout << endl;

	for(int i = 0; i < (int) second.size(); i++){
		cout << second[i] << " ";
	}

	cout << endl;

//	auto connections = make_vector(N);
//	auto paths = make_weights(connections);
//	int maximum = 0;
//
//	for(int i = 1; i < (int) paths.size(); i++){
//		if(paths[maximum] < paths[i]){
//			maximum = i;
//		}
//	}
//	auto secondDistance = Dijkstra(N, connections[maximum]);
//	cout << secondDistance[N - 1] - distance[N - 1] << endl;

	return 0;
}
