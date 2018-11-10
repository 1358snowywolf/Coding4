#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<int> assembly1 = {3, 5, 1};
	vector<int> assembly2 = {4, 6, 10};
	vector<int> weight1 = {3, 5};
	vector<int> weight2 = {2, 1};
	vector<int> answer1;
	vector<int> answer2;

	answer1.push_back(assembly1[0]);
	answer2.push_back(assembly2[0]);

	for(int i = 1; i < (int) assembly1.size(); i++){
		answer1.push_back(min(answer1[i - 1], answer2[i - 1] + weight2[i - 1]) + assembly1[i]);
		answer2.push_back(min(answer2[i - 1], answer1[i - 1] + weight1[i - 1]) + assembly2[i]);
	}

	cout << min(answer1[answer1.size() - 1], answer2[answer2.size() - 1]) << endl;

	return 0;
}
