#include <bits/stdc++.h>

using namespace std;
vector<int> indegrees;
map<int, vector<int>> graph;
unordered_map<string, int> names;
unordered_map<int, string> otherWay;

void makeIndegrees(){
	for(auto v : graph){
		for(int going : v.second){
			indegrees[going]++;
		}
	}
}

void enqueue(set<int>& q){
	for(int i = 0; i < (int) indegrees.size(); i++){
		if(indegrees[i] == 0){
			q.insert(i);
		}
	}
}

void remove(int u){
	for(int x : graph[u]){
		indegrees[x]--;
	}
}

vector<int> Khan(){
	vector<int> answers;
	set<int> q;
	enqueue(q);

	while(!q.empty()){
		int u = *q.begin();
		q.erase(q.begin());
		remove(u);
		answers.push_back(u);

		for(int x : graph[u]){
			if(indegrees[x] <= 0){
				q.insert(x);
			}
		}
	}

	return answers;
}

int main() {
	int times = 1, N;

	while(cin >> N){
		int M;
		indegrees.assign(N, 0);
		graph.clear();
		names.clear();
		otherWay.clear();

		for(int i = 0; i < N; i++){
			string drink;
			cin >> drink;
			names.insert(make_pair(drink, i));
			otherWay.insert(make_pair(i, drink));
			graph.insert(make_pair(i, vector<int> ()));
		}

		cin >> M;

		for(int i = 0; i < M; i++){
			string weaker, stronger;
			cin >> weaker >> stronger;

			graph[names[weaker]].push_back(names[stronger]);
		}

		makeIndegrees();
		vector<int> answers = Khan();

		cout << "Case #" << times << ": Dilbert should drink beverages in this order:";
		for(int i : answers){
			cout << " " << otherWay[i];
		}

		cout << "." << endl << endl;

		times++;
	}

	return 0;
}
