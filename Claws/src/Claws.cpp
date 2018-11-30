#include <bits/stdc++.h>

using namespace std;
map<int, vector<int>> graph;

bool DFS(vector<int> claw, int index, int prev, int size){
	if(prev != -1){
		if(size < 3){
			if(claw[index] != 0) return false;
			claw[index] = claw[prev];
		}
		else{
			claw[index] = claw[prev] + 1;
		}
	}

	int degrees = 0;
	size = (size + 1) % 3;

	for(int v : graph[index]){
		if(claw[v] == claw[index]) continue;
		if(claw[v] != 0) continue;
		bool work = DFS(claw, v, index, size);
		degrees++;
		if(degrees == 3) break;
		if(!work) return false;
	}

	return true;
}

int main() {
	int V;
	int u, v;

	while(true){
		cin >> V;
		if(V == 0) break;
		graph.clear();

		while(true){
			cin >> u >> v;
			if(u == 0 && v == 0) break;
			graph[u - 1].push_back(v - 1);
			graph[v - 1].push_back(u - 1);
		}

		vector<int> claw (V, 0);
		claw[0] = 1;

	    if(DFS(claw, 0, -1, 0)){
	    	cout << "YES" << endl;
	    }
	    else{
	    	cout << "NO" << endl;
	    }
	}

	return 0;
}
