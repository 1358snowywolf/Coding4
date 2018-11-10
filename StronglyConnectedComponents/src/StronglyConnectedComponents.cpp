#include <bits/stdc++.h>

using namespace std;
map<int, vector<int>> graph;
vector<int> numbers (7, INT_MAX);
set<int> visited (7, INT_MAX);
vector<int> low;
int depth = 0;

void SCC(int u){
	numbers[u] = depth;
	low[u] = depth;
	depth++;
	stack<int> s;
	s.push(u);

	for(int v : graph[u]){
		if(visited.find(v) == visited.end()){
			SCC(v);
		}
		else{
			low[u] = min(low[u], low[v]);
		}

		if(low[u] == low[v]){
			while(true){
				int tmp = s.top();
				s.pop();

				cout << tmp << " ";

				if(tmp == u){
					break;
				}
			}
		}
	}
}

int main() {

	return 0;
}
