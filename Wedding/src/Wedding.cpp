#include <bits/stdc++.h>

using namespace std;
int C, budget;
vector<vector<int>> price (20, vector<int> (20, 0));
vector<vector<int>> memory (250, vector<int> (20, -1));

int shop(int money, int g){
	if(money < 0) return INT_MIN;
	if(g == C) return budget - money;
	if(memory[money][g] != -1) return memory[money][g];
	int answer = -1;

	for(int i = 1; i <= price[g][0]; i++){
		answer = max(answer, shop(money - price[g][i], g + 1));
	}

	return memory[money][g] = answer;
}

int main() {
	int i, j, TC, score;
	cin >> TC;

	while(TC--){
		cin >> budget >> C;

		for(i = 0; i < C; i++){
			cin >> price[i][0];
			for(j = 0; j < price[i][0]; j++){
				cin >> price[i][j + 1];
			}
		}

		for(i = 0; i < 250; i++){
			for(j = 0; j < 20; j++){
				memory[i][j] = -1;
			}
		}

		score = shop(budget, 0);
		if(score < 0) cout << "no solution" << endl;
		else cout << score << endl;
	}


	return 0;
}
