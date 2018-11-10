#include <bits/stdc++.h>

using namespace std;
map<int, vector<int>> graph;
vector<int> answer;
set<int> visited;

void topLogical(int u){
	if(visited.find(u) != visited.end()){
		return;
	}

	visited.insert(u);

	for(auto i : graph[u]){
		topLogical(i);
	}

	answer.push_back(u);
}

int main() {
	vector<int> one = {2, 3, 6};
	vector<int> two = {5};
	vector<int> three = {2};
	vector<int> five = {6};
	vector<int> six = {};

	graph.insert(make_pair(1, one));
	graph.insert(make_pair(2, two));
	graph.insert(make_pair(3, three));
	graph.insert(make_pair(5, five));
	graph.insert(make_pair(6, six));

//	for(auto i : graph){
//		if(visited.find(i.first) == visited.end()){
//			topLogical(i.first);
//		}
//	}

	topLogical(2); //does not always have to start with one
	topLogical(1);

	reverse(answer.begin(), answer.end());

	for(int i = 0; i < (int) answer.size(); i++){
		cout << answer[i] << " ";
	}

	cout << endl;

	return 0;
}
