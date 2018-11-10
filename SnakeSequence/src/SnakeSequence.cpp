#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<vector<int>> snakes;
	snakes.push_back({9, 6, 5, 2});
	snakes.push_back({8, 7, 6, 5});
	snakes.push_back({7, 3, 1, 6});
	snakes.push_back({1, 1, 1, 7});
	vector<vector<int>> answer (snakes.size(), vector<int> (snakes[0].size(), 1));

	for(int i = 0; i < (int) answer.size(); i++){
		for(int j = 0; j < (int) answer[0].size(); j++){
			if(j - 1 >= 0){
				if(snakes[i][j] - 1 == snakes[i][j - 1] || snakes[i][j] + 1 == snakes[i][j - 1])
					answer[i][j] = answer[i][j - 1] + 1;
			}
			if(i - 1 >= 0){
				if((snakes[i][j] - 1 == snakes[i - 1][j] || snakes[i][j] + 1 == snakes[i - 1][j]))
					answer[i][j] = max(answer[i][j], answer[i][j - 1]) + 1;
			}
		}
	}

	int maximum = 0;

	for(int i = 0; i < (int) answer.size(); i++){
		for(int j = 0; j < (int) answer[0].size(); j++){
			maximum = max(maximum, answer[i][j]);
		}
	}

	cout << maximum << endl;

	return 0;
}
