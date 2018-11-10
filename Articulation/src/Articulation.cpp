#include <bits/stdc++.h>

using namespace std;
vector<int> numbers (6, INT_MAX);
vector<int> low (6, INT_MAX);
vector<int> parent (6, INT_MAX);
set<int> visited;
vector<bool> articulationPoint (6, false);
set<pair<int, int>> articulationBridge;
map<int, vector<int>> graph;
int rootChild;
int rootNode;
int depth;

void articulation(int u){
	numbers[u] = depth;
	low[u] = depth++;
	visited.insert(u);

	for(auto v : graph[u]){
		if(visited.find(v) == visited.end()){
			parent[v] = u;

			if(u == rootNode){
				rootChild++;
			}

			articulation(v);

			if(numbers[u] <= low[v]){
				articulationPoint[u] = true;
			}
			if(numbers[u] < low[v]){
				articulationBridge.insert(make_pair(u, v));
			}

			low[u] = min(low[u], low[v]);
		}
		else if(parent[u] != v){
			low[u] = min(low[u], numbers[v]);
		}
	}
}

int main() {
	vector<int> zero = {1};
	vector<int> one = {0, 2, 3, 4, 5};
	vector<int> two = {1};
	vector<int> three = {1};
	vector<int> four = {1, 5};
	vector<int> five = {1, 4};

	graph.insert(make_pair(0, zero));
	graph.insert(make_pair(1, one));
	graph.insert(make_pair(2, two));
	graph.insert(make_pair(3, three));
	graph.insert(make_pair(4, four));
	graph.insert(make_pair(5, five));

	rootNode = 5;
	rootChild = 0;
	depth = 0;

	articulation(rootNode);
	articulationPoint[rootNode] = (rootChild > 1);

	for(int i = 0; i < 6; i++){
		cout << i << ": " << articulationPoint[i] << endl;
	}

	cout << "Articulation Bridges:" << endl;

	for(auto bridge : articulationBridge){
		cout << bridge.first << "  " << bridge.second << endl;
	}

	return 0;
}
