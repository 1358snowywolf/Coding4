#include <bits/stdc++.h>

using namespace std;
map<string, vector<tuple<string, char, int>>> graph;

map<string, vector<int>> Dijkstra(set<string> words, string start){
	priority_queue<tuple<int, string, char>> pq;
	map<string, vector<int>> distance;

	for(string i : words){
		distance.insert(make_pair(i, vector<int> (26, INT_MAX)));
	}

	pq.push(make_tuple(0, start, start[0]));

	for (int i = 0; i < 26; i++) {
		distance[start][i] = 0;
	}

	while(!pq.empty()){
		tuple<int, string, char> front = pq.top();
		pq.pop();
		int first;
		string second;
		char third;
		tie(first, second, third) = front;
		int minimal = INT_MAX;

		for(int i = 0; i < 26; i++){
			if(i != third - 'a'){
				minimal = min(minimal, distance[second][i]);
			}
		}

		if(first * -1 > minimal){
			continue;
		}

		for(auto n : graph[second]){
			string s;
			char c;
			int i;
			tie(s, c, i) = n;

            if(distance[second][third - 'a'] + i < distance[s][c - 'a'] && third != c){
                distance[s][c - 'a'] = distance[second][third - 'a'] + i;
                pq.push({distance[s][c - 'a'] * -1, s, c});
            }
		}

//		for (auto it : distance) {
//			cout << it.first << "  :  " << it.second << endl;
//		}
//		cout << " ================= " << endl;
	}

	return distance;
}

int main() {
	int N;
	while(cin >> N){
		graph.clear();
		set<string> words;
		string start, end;
		cin >> start >> end;

		for(int i = 0; i < N; i++){
			string u, v, word;
			cin >> u >> v >> word;
			words.insert(u);
			words.insert(v);

			if(graph.find(u) == graph.end()){
				graph.insert(make_pair(u, vector<tuple<string, char, int>> ()));
			}
			if(graph.find(v) == graph.end()){
				graph.insert(make_pair(v, vector<tuple<string, char, int>> ()));
			}

			graph[u].push_back(make_tuple(v, word[0], word.size()));
			graph[v].push_back(make_tuple(u, word[0] , word.size()));
		}

		for(auto i : graph){
			cout << i.first << ": ";

			for(auto j : i.second){
				string s;
				char c;
				int i;
				tie(s, c, i) = j;
				cout << "(" + s << ", " << c << ", " << i << ") ";
			}

			cout << endl;
		}

		auto distance = Dijkstra(words, start);

		int minimum = INT_MAX;

		for(auto i : distance[end]){
			minimum = min(minimum, i);
		}

		cout << minimum << endl;
	}

	int zero;
	cin >> zero;
	cout << endl;

	return 0;
}
