#include <bits/stdc++.h>

using namespace std;

map<string, int> Dijkstra(map<string, set<string>> words, string start, string end){
	priority_queue<pair<int, string>> pq;
	map<string, int> distance;
	distance.insert(make_pair(start, 2000000));
	distance.insert(make_pair(end, 2000000));
	pq.push(make_pair(0, start));

	for(auto i : words){
		distance.insert(make_pair(i.first, 2000000));
	}

	while(!pq.empty()){
		pair<int, string> front = pq.top();

		if(front.first * -1 > distance[front.second]){
			continue;
		}

		for(auto n : words[front.second]){
			if(distance[front.second] + n.size() < distance[n]){
				distance[n] = distance[front.second] + n.size();
				pq.push(make_pair(distance[n] * -1, n));
			}
		}
	}

	return distance;
}

int main() {
	int N;

	while(cin >> N){
		string start, end;
		cin >> start >> end;
		map<string, vector<string>> languages;

		for(int i = 0; i < N; i++){
			string u, v, w;
			cin >> u >> v >> w;

			if(languages.find(u) == languages.end()){
				languages.insert(make_pair(u, vector<string> ()));
			}

			languages[u].push_back(v);
		}

		map<string, set<string>> words;
		words.insert(make_pair(start, set<string> ()));
		words.insert(make_pair(end, set<string> ()));

		for(auto i : languages){
			for(int j = 0; j < (int) i.second.size(); j++){
				if(words.find(i.second[j]) == words.end()){
					words.insert(make_pair(i.second[j], set<string> ()));
				}

				for(int k = 0; k < (int) i.second.size(); j++){
					if(i.second[j][0] == i.second[k][0]){
						continue;
					}

					words[i.second[j]].insert(i.second[k]);
				}
			}
		}

		for(auto i : languages[start]){
			words[start].insert(i);
		}

		for(auto i : languages[end]){
			words[i].insert(end);
		}

		auto distance = Dijkstra(words, start, end);
		cout << distance[end] << endl;
	}
	return 0;
}
