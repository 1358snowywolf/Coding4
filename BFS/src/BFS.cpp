#include <bits/stdc++.h>

using namespace std;
vector<set<int>> adj;
vector<bool> color;
int V;

void BFS(int s, int end) {
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;

//    Create a queue for BFS
    queue<int> queue;

//    Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push(s);
//    queue.push(-1);
//    int count = 0;

//    'i' will be used to get all adjacent
//    vertices of a vertex

    while(!queue.empty()){
//    Dequeue a vertex from queue and print it
        s = queue.front();
//        cout << s << " " << count << endl;
        queue.pop();

//        if(s == -1){
//        	count++;
//          queue.push(-1);
//        	continue;
//        }
//
//        if(s == end){
//        	cout << count << endl;
//        	return;
//        }

//        Get all adjacent vertices of the dequeued
//        vertex s. If a adjacent has not been visited,
//        then mark it visited and enqueue it
        for (auto v : adj[s]){
        	if(color[v] == color[s]){
        		cout << "Not Bipartite" << endl;
        		return;
        	}

            if (!visited[v]){
                visited[v] = true;
                queue.push(v);
            }
        }
    }

    cout << "Bipartite" << endl;
}

int main() {
	set<int> zero;
	set<int> one;
	set<int> two;
	set<int> three;
	set<int> four;
	set<int> five;

	zero.insert(1);
	zero.insert(2);
	zero.insert(3);

	one.insert(0);
	one.insert(2);
	one.insert(4);

	two.insert(0);
	two.insert(1);
	two.insert(3);
	two.insert(4);

	three.insert(0);
	three.insert(2);

	four.insert(1);
	four.insert(2);
	four.insert(5);

	five.insert(4);

	adj.push_back(zero);
	adj.push_back(one);
	adj.push_back(two);
	adj.push_back(three);
	adj.push_back(four);
	adj.push_back(five);

	color.push_back(true);
	color.push_back(false);
	color.push_back(false);
	color.push_back(false);
	color.push_back(true);
	color.push_back(false);

	BFS(0, 4);

	return 0;
}
