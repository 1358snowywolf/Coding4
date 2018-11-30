#include <bits/stdc++.h>

using namespace std;
vector<set<int>> graph;
int V;

void BFS() {
    queue<int> queue;
    vector<int> color (V, 0);

    color[0] = 1; // 1 is center    -1 is outer     0 is TBD
    queue.push(0);

    while(!queue.empty()){
        int s = queue.front();
        queue.pop();

        for (auto v : graph[s]){
        	if(color[v] == 0){
        		color[v] = color[s] * -1;
        		queue.push(v);
        	}
        	else if(color[v] == color[s]){
        		cout << "NO" << endl;
        		return;
        	}
        }
    }

    cout << "YES" << endl;
}

int main() {
	int u, v;

	while(true){
		cin >> V;
		if(V == 0) break;

		vector<set<int>> input (V, set<int> ());
		graph = input;

		while(true){
			cin >> u >> v;
			if(u == 0 && v == 0) break;
			graph[u - 1].insert(v - 1);
			graph[v - 1].insert(u - 1);
		}

		BFS();
	}

	return 0;
}
