#include <bits/stdc++.h>

using namespace std;
bool print = false;
set<string> answers;

void DFS(set<int> visited, vector<int> used, vector<int> numbers, int T, int sum, int index){
	if(sum > T) return;

	if(sum == T){
		string input = "";

		for(int i  = 0; i < (int) used.size(); i++){
			input += to_string(used[i]);

			if (i != (int) used.size() - 1) {
				input += "+";
			}
		}

		answers.insert(input);
		return;
	}

	visited.insert(index);

	for(int i = index + 1; i < (int) numbers.size(); i++){
		if(visited.find(i) != visited.end()) continue;

		used.push_back(numbers[i]);
		DFS(visited, used, numbers, T, sum + numbers[i], i);
		used.pop_back();
	}
}

int main() {
	int T, N;

	while(true){
		cin >> T >> N;
		print = false;
		answers.clear();
		if(N == 0 && N == 0) break;

		vector<int> numbers (N, 0);

		for(int i = 0; i < N; i++){
			cin >> numbers[i];
		}

		sort(numbers.rbegin(), numbers.rend());
		cout << "Sums of " << T << ":" << endl;

		DFS(set<int> (), vector<int> (), numbers, T, 0, -1);

		if(answers.empty()){
			cout << "NONE" << endl;
		}
		else{
			vector<string> out;

			for(auto i : answers){
				out.push_back(i);
			}

			reverse(out.begin(), out.end());

			for(auto i : out){
				cout << i << endl;
			}
		}
	}

	return 0;
}
