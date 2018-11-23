#include <bits/stdc++.h>

using namespace std;
string input, answer;

void DFS(stack<char> sta, int inputIndex, int answerIndex, string current){
	if(inputIndex >= (int) input.size() && answerIndex >= (int) answer.size()){
		cout << current << endl;
		return;
	}

	auto backup = sta;

	//push in
	if(inputIndex < (int) input.size()){
		sta.push(input[inputIndex]);
		DFS(sta, inputIndex + 1, answerIndex, current + "i");
	}

	//pop out
	if(backup.empty()){
		return;
	}

	auto top = backup.top(); backup.pop();

	if(top != answer[answerIndex]){
		return;
	}

	DFS(backup, inputIndex, answerIndex + 1, current + "o");
}

int main() {
	while(cin >> input){
		cin >> answer;

		cout << "[" << endl;
		DFS(stack<char> (), 0, 0, "");
		cout << "]" << endl;
	}

	cout << endl;

	return 0;
}
