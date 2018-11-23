#include <bits/stdc++.h>

using namespace std;

int main() {
	int C;
	cin >> C;

	for(int times = 0; times < C; times++){
		int N, T, M;
		cin >> N >> T >> M;
//		vector<tuple<int, int, string>> cars;
		queue<pair<int, int>> left, right;

		for(int i = 0; i < M; i++){
			int time;
			string direction;
			cin >> time >> direction;

			if(direction == "left"){
				left.push(make_pair(time, i));
			}
			else{
				right.push(make_pair(time, i));
			}
		}

		vector<int> answer (M, 0);
		vector<pair<int, int>> ferry;
		vector<queue<pair<int, int>>> banks = {left, right};
		int current = 0;
		int place = 0;

		while(!banks[0].empty() || !banks[1].empty()){
			int lefttime = (banks[0].empty()) ? 2000000 : banks[0].front().first;
			int righttime = (banks[1].empty()) ? 2000000 : banks[1].front().first;
			vector<int> time = {lefttime, righttime};

			if(current < time[0] && current < time[1]){
				current = min(time[0], time[1]);
			}
			else{
				int size = 0;

				while(!banks[place].empty() && banks[place].front().first <= current && size < N){
					answer[banks[place].front().second] = current + T;
					banks[place].pop();
					size++;
				}

				current += T;
				place = (place + 1) % 2;
			}
		}

		for(int i = 0; i < M; i++){
			cout << answer[i] << endl;
		}

		cout << endl;
	}

	return 0;
}
