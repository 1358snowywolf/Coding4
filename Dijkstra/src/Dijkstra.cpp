#include <bits/stdc++.h>

using namespace std;
vector<bool> visited;
map<int, vector<pair<int, int>>> graph;

void Dijkstra(){
	priority_queue<pair<int, int>> pq;
	vector<int> distance (4, INT_MAX);
	pq.push(make_pair(0, 0));
	distance[0] = 0;

	while(!pq.empty()){
		pair<int, int> front = pq.top();
		pq.pop();

		if(front.first * -1 > distance[front.second]){
			continue;
		}
//		cout << front.first << " " << front.second << endl;

		for(pair<int, int> n : graph[front.second]){
			if(distance[front.second] + n.second < distance[n.first]){
				distance[n.first] = distance[front.second] + n.second;
			}
			pq.push(make_pair(n.second * -1, n.first));
		}
	}

	for(int i = 0; i < 4; i++){
		cout << distance[i] << " ";
	}
}

int main() {
	visited.assign(4, false);
//	distance.assign(4, INT_MAX);
	vector<pair<int, int>> zero = {{3, 100}, {1, 2}};
	vector<pair<int, int>> one = {{3, 2}, {2, 100}};
	vector<pair<int, int>> two = {};
	vector<pair<int, int>> three = {{2, 1}};

	graph.insert(make_pair(0, zero));
	graph.insert(make_pair(1, one));
	graph.insert(make_pair(2, two));
	graph.insert(make_pair(3, three));

	Dijkstra();

	return 0;
}
