#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	int index = 1;

	while(cin >> N){
		if(N == -1){
			break;
		}

		vector<pair<float, tuple<int, int, int>>> times;

		for(int i = 0; i < N; i++){
			float miles;
			int G, Y, R;
			cin >> miles >> G >> Y >> R;

			times.push_back(make_pair(miles, make_tuple(G, Y, R)));
		}

		vector<int> work;

		for(int speed = 30; speed <= 60; speed++){
			int i;

			for(i = 0; i < (int) times.size(); i++){
				float current = (times[i].first / speed) * 3600;
				int G, Y, R;
				tie (G, Y, R) = times[i].second;
//				int remainder = ((int) current) / (G + Y + R);
//				float remainder2 = current - ((int) current) + remainder;
				float remainder = fmod(current, G + Y + R);

				if(remainder > (float) (G + Y)){
					break;
				}
			}

			if(i == (int) times.size()){
				work.push_back(speed);
			}
		}

		cout << "Case " << index << ": ";

		if(work.empty()){
			cout << "No acceptable speeds." << endl;
		}
		else{
			for(int i = 0; i < (int) work.size(); i++){
				int start = work[i];
				int end = start;

				while(i + 1 < (int) work.size() && work[i] + 1 == work[i + 1]){
					end = work[i + 1];
					i++;
				}

				if(start == end){
					cout << start;
				}
				else{
					cout << start << "-" << end;
				}

				if(i + 1 < (int) work.size()){
					cout << ", ";
				}
			}

			cout << endl;
		}

		index++;
	}
	return 0;
}
