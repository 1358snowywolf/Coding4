#include <bits/stdc++.h>

using namespace std;

map<string, int> Dijkstra(map<string, set<string>> words, string start, string end){
	priority_queue<pair<int, string>> pq;
	map<string, int> distance;

	for(auto i : words){
		distance.insert(make_pair(i.first, 2000000));
	}

	distance[start] = 0;
	distance[end] = 2000000;

	pq.push(make_pair(0, start));

	while(!pq.empty()){
		pair<int, string> front = pq.top();
		pq.pop();

		if(front.first * -1 > distance[front.second]){
			continue;
		}

		for(auto n : words[front.second]){
			if(distance[front.second] + n.length() < distance[n]){
				distance[n] = distance[front.second] + n.length();
				pq.push(make_pair(distance[n] * -1, n));
			}
		}
	}

	return distance;
}

int main() {
	int N;

	while(cin >> N){
		if(N == 0) return 0;
		string start, end;
		cin >> start >> end;
		map<string, vector<string>> languages;

		for(int i = 0; i < N; i++){
			string u, v, w;
			cin >> u >> v >> w;
			languages[u].push_back(w);
			languages[v].push_back(w);
		}

		map<string, set<string>> words;

		for(auto i : languages){
			for(int j = 0; j < (int) i.second.size(); j++){
				for(int k = j + 1; k < (int) i.second.size(); k++){
					if(i.second[j][0] == i.second[k][0]){    //error
						continue;
					}

					words[i.second[j]].insert(i.second[k]);
					words[i.second[k]].insert(i.second[j]);
				}
			}
		}

		for(auto i : languages[start]){
			words["start"].insert(i);
		}

		for(auto i : languages[end]){
			words[i].insert("end");
		}

		auto distance = Dijkstra(words, "start", "end");

		if(distance["end"] == 2000000){
			cout << "impossivel" << endl;
		}
		else{
			cout << distance["end"] - 3 << endl;
		}

//		cout << distance["end"] - 3 << endl;
	}
	return 0;
}
