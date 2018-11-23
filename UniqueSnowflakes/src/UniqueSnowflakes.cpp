#include <bits/stdc++.h>

using namespace std;

int main() {
	int C;
	cin >> C;

	for(int times = 0; times < C; times++){
		int N;
		cin >> N;
		vector<int> snowflakes;

		for(int i = 0; i < N; i++){
			int s;
			cin >> s;
			snowflakes.push_back(s);
		}

		int maximum = 0;

		for(int i = 0; i < N; i++){
			int j = i;
			set<int> unique;

			while(j < N && unique.find(snowflakes[j]) == unique.end()){
				unique.insert(snowflakes[j]);
				j++;
			}

			maximum = max(maximum, (int) unique.size());
		}

		cout << maximum << endl;

//		set<int> uniqueness;
//		int answer = INT_MAX;
//
//		for(int i = 0; i < N; i++){
//			int snowflake;
//			cin >> snowflake;
//
//			if(uniqueness.find(snowflake) != uniqueness.end()){
//				answer = min(answer, i);
//			}
//
//			uniqueness.insert(snowflake);
//		}
//
//		if(answer == INT_MAX){
//			cout << uniqueness.size() << endl;
//		}
//		else{
//			cout << answer << endl;
//		}
	}

	return 0;
}
