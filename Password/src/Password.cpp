#include <bits/stdc++.h>

using namespace std;

void DFS(string current, int index, string rule, vector<string> dict){
	if(index == (int) rule.size()){
		cout << current << endl;
		return;
	}

	if(rule[index] == '#'){
		for(int i = 0; i < (int) dict.size(); i++){
			DFS(current + dict[i], index + 1, rule, dict);
		}
	}
	else{
		for(int i = 0; i <= 9; i++){
			DFS(current + to_string(i), index + 1, rule, dict);
		}
	}
}

int main() {
	int N, M;
	string input;

	while(cin >> N){
		cout << "--" << endl;
		vector<string> dict;

		for(int i = 0; i < N; i++){
			cin >> input;
			dict.push_back(input);
		}

		cin >> M;
		vector<string> rules;

		for(int i = 0; i < M; i++){
			cin >> input;
			rules.push_back(input);
		}

		for(int i = 0; i < M; i++){
			DFS("", 0, rules[i], dict);
		}
	}
	return 0;
}
