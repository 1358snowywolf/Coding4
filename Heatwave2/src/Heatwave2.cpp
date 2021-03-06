#include <bits/stdc++.h>

using namespace std;
//set<bool> visited;
map<int, vector<pair<int, int>>> graph;

vector<int> Dijkstra(int T, int start){
    priority_queue<pair<int, int>> pq;
    vector<int> distance (T + 1, 1076000);
    pq.push({0, start});
    distance[start] = 0;

//    cout << "start: " << start << endl;

    while(!pq.empty()){
        pair<int, int> front = pq.top();
        pq.pop();
//        visited.insert(front.second);

        if((front.first * -1) > distance[front.second]){
            continue;
        }

//        cout << front.first << front.second << endl;

        for(auto n : graph[front.second]){
//            cout << "n: (" << n.first << ", " << n.second << ")" << endl;
            if(distance[front.second] + n.second < distance[n.first]){
                distance[n.first] = distance[front.second] + n.second;
                pq.push({distance[n.first] * -1, n.first});
            }
        }

//        for(int i = 0; i < (int) distance.size(); i++){
//            cout << distance[i] << "  ";
//        }
//        cout << endl;


    }

    return distance;
}

int main(int argc, const char * argv[]) {
    int T;
    int C;
    int start;
    int end;

    cin >> T >> C >> start >> end;

    for(int i = 1; i <= T; i++){
        graph.insert({i, vector<pair<int, int>> ()});
    }

    for(int i = 0; i < C; i++){
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight});
    }

//    for(auto i : graph){
//        cout << i.first << ": ";
//
//        for(auto u : i.second){
//            cout << "(" << u.first << "," << u.second << ") ";
//        }
//
//        cout << endl;
//    }

    auto distance = Dijkstra(T, start);

    cout << distance[end] << endl;

//    for(int i = 0; i < (int) distance.size(); i++){
//        cout << distance[i] << endl;
//    }

    return 0;
}
