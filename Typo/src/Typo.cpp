#include <bits/stdc++.h>

using namespace std;

int main() {
	string parenthesis;
	cin >> parenthesis;

	int middle = (parenthesis.size() / 2) - 1;
	vector<int> answers;

	for(int i = 0; i <= middle; i++){
		if(parenthesis[i] == ')'){
			answers.push_back(i + 1);
		}
	}

	for(int i = middle + 1; i < (int) parenthesis.size(); i++){
		if(parenthesis[i] == '('){
			answers.push_back(i + 1);
		}
	}

	for(int i = 0; i < (int) answers.size(); i++){
		cout << answers[i] << " ";
	}


	return 0;
}
