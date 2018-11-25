#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;

	while(true){
		cin >> N;
		if(N == 0) break;
		map<string, int> courses;

		for(int i = 0; i < N; i++){
			vector<int> input (5, 0);
			for(int j = 0; j < 5; j++){
				cin >> input[j];
			}

			sort(input.begin(), input.end());
			string sta = "";

			for(int i = 0; i < 5; i++){
				sta += to_string(input[i]);
			}

			courses[sta]++;
		}

		int maximum = 0, count = 0;

		for(auto i : courses){
			maximum = max(maximum, i.second);
		}

		for(auto i : courses){
			if(maximum == i.second){
				count += i.second;
			}
		}

		cout << count << endl;
	}
	return 0;
}
