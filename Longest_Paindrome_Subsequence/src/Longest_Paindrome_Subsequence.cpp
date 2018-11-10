#include <bits/stdc++.h>

using namespace std;

int main() {
	string str = "GEEKSFORGEEKS";
	vector<vector<int>> dp (str.size(), vector<int> (str.size(), 0));

	for(int i = 0; i < (int) dp.size(); i++){
		dp[i][i] = 1;
	}

//	for(int i = 2; i < (int) dp.size(); i++){
//		for(int j = 0; j < (int) dp.size() - i - 1; j++){
//			int k = j + i - 1;
//
//			if(str[j] == str[k] && i == 2){
//				dp[j][k] = 2;
//			}
//			else if(str[j] == str[k]){
//				dp[j][k] = dp[j + 1][k - 1] + 2;
//			}
//			else{
//				dp[j][k] = max(dp[j][k - 1], dp[j + 1][k]);
//			}
//		}
//	}

	for(int length = 2; length <= (int) str.size(); length++){
		for(int i = 0; i < (int) str.size() - length + 1; i++){
			int j = i + length - 1;

			if(str[i] == str[j] && length == 2){
				dp[i][j] = 2;
			}
			else if(str[i] == str[j]){
				dp[i][j] = dp[i + 1][j - 1] + 2;
			}
			else{
				if(j - 1 >= 0 && i + 1 < (int) dp.size()){
					dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
				}
				else if(j - 1 < 0){
					dp[i][j] = dp[i + 1][j];
				}
				else{
					dp[i][j] = dp[i][j - 1];
				}
			}
		}
	}

	for(int i = 0; i < (int) dp.size(); i++){
		for(int j = 0; j < (int) dp.size(); j++){
			cout << dp[i][j] << " ";
		}

		cout << endl;
	}

	cout << dp[0][dp.size() - 1] << endl;

	return 0;
}
