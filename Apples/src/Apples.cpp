#include <bits/stdc++.h>
#define INF 200000001

using namespace std;
vector<vector<pair<int, int>>> graph;

vector<int> Dijkstra(int start){
	priority_queue<pair<int, int>> pq;
	vector<int> distance (graph.size(), INF);
	pq.push(make_pair(0, start));
	distance[start] = 0;

	while(!pq.empty()){
		pair<int, int> u = pq.top(); pq.pop();


		if(u.first * -1 > distance[u.second]){
			continue;
		}

		for(auto v : graph[u.second]){
			if(distance[u.second] + v.second < distance[v.first]){
				distance[v.first] = distance[u.second] + v.second;
				pq.push(make_pair(distance[v.first] * -1, v.first));
			}
		}
	}
//	for(int i = 0; i < (int) distance.size(); i++){
//		cout << distance[i] << " ";
//	}
//	cout << endl;

	return distance;
}

int main() {
	int C, P, PB, PA1, PA2;
	cin >> C >> P >> PB >> PA1 >> PA2;
	graph.assign(P, vector<pair<int, int>> ());

	for(int i = 0; i < C; i++){
		int u, v, w;
		cin >> u >> v >> w;
		graph[u - 1].push_back(make_pair(v - 1, w));
		graph[v - 1].push_back(make_pair(u - 1, w));
	}

	auto distance1 = Dijkstra(PA2 - 1);
	auto distance2 = Dijkstra(PA1 - 1);


	int answer = min(distance1[PB - 1], distance2[PB - 1]) + distance2[PA2 - 1];

//	cout << distance1[PA1 - 1] << " " << distance2[PA2 - 1] << endl;

//	for(int i = 0; i < P; i++){
//		cout << distance1[i] << " ";
//	}


	cout << answer << endl;


	return 0;
}
#include <bits/stdc++.h>
#define INF 200000001

using namespace std;
vector<vector<pair<int, int>>> graph;

vector<int> Dijkstra(int start){
	priority_queue<pair<int, int>> pq;
	vector<int> distance (graph.size(), INF);
	pq.push(make_pair(0, start));
	distance[start] = 0;

	while(!pq.empty()){
		pair<int, int> u = pq.top(); pq.pop();


		if(u.first * -1 > distance[u.second]){
			continue;
		}

		for(auto v : graph[u.second]){
			if(distance[u.second] + v.second < distance[v.first]){
				distance[v.first] = distance[u.second] + v.second;
				pq.push(make_pair(distance[v.first] * -1, v.first));
			}
		}
	}
//	for(int i = 0; i < (int) distance.size(); i++){
//		cout << distance[i] << " ";
//	}
//	cout << endl;

	return distance;
}

int main() {
	int C, P, PB, PA1, PA2;
	cin >> C >> P >> PB >> PA1 >> PA2;
	graph.assign(P, vector<pair<int, int>> ());

	for(int i = 0; i < C; i++){
		int u, v, w;
		cin >> u >> v >> w;
		graph[u - 1].push_back(make_pair(v - 1, w));
		graph[v - 1].push_back(make_pair(u - 1, w));
	}

	auto distance1 = Dijkstra(PA2 - 1);
	auto distance2 = Dijkstra(PA1 - 1);


	int answer = min(distance1[PB - 1], distance2[PB - 1]) + distance2[PA2 - 1];

//	cout << distance1[PA1 - 1] << " " << distance2[PA2 - 1] << endl;

//	for(int i = 0; i < P; i++){
//		cout << distance1[i] << " ";
//	}


	cout << answer << endl;


	return 0;
}
