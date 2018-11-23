#include <bits/stdc++.h>

using namespace std;
map<char, vector<char>> graph;
map<char, int> indegrees;
bool print = false;

void all(vector<char> answer, set<char> visited){
	if(answer.size() == graph.size()){
		for(char i : answer){
			cout << i << " ";
		}

		cout << endl;
		print = true;
		return;
	}

	for(auto i : graph){
		if(indegrees[i.first] == 0 && visited.find(i.first) == visited.end()){
			for(auto j : i.second){
				indegrees[j]--;
			}

			answer.push_back(i.first);
			visited.insert(i.first);
			all(answer, visited);
			visited.erase(i.first);
			answer.pop_back();

			for(auto j : i.second){
				indegrees[j]++;
			}
		}
	}
}

int main(){
	int C;
	cin >> C;
	string spaces;
	string letters, path;

	for(int times = 0; times < C; times++){
		cin >> spaces;
		print = false;
		graph.clear();
		indegrees.clear();
		getline(cin, letters);
		getline(cin, path);

		for(char i : letters){
			if(i == ' ') continue;

			indegrees.insert(make_pair(i, 0));
			graph.insert(make_pair(i, vector<char> ()));
		}

		for(int i = 0; i < (int) path.size(); i += 4){
			if(path[i] == ' ') continue;

			graph[path[i]].push_back(path[i + 2]);
			indegrees[path[i + 2]]++;
		}

		all(vector<char> (), set<char> ());


		if(!print){
			cout << "NO" << endl;
		}

		cout << endl;
	}

	return 0;
}
