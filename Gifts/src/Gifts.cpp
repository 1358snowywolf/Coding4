#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, B;
	cin >> N >> B;
	vector<pair<int, int>> prices;

	for(int i = 0; i < N; i++){
		int cost, ship;
		cin >> cost >> ship;
		prices.push_back(make_pair(cost, ship));
	}

	sort(prices.begin(), prices.end());
	int total = 0;
	int bought = 0;

	for(int i = 0; i < (int) prices.size(); i++){
		if(total + prices[i].first + prices[i].second <= B){
			total += (prices[i].first + prices[i].second);
			bought++;
		}
		else if(total + (prices[i].first / 2) + prices[i].second <= B){
			bought++;
			break;
		}
		else{
			break;
		}
	}

	cout << bought << endl;

	return 0;
}
