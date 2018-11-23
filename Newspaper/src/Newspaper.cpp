#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, K, M;
	cin >> N;

	for(int times = 0; times < N; times++){
		map<char, int> costs;
		cin >> K;

		for(int i = 0; i < K; i++){
			char a;
			int c;
			cin >> a >> c;
//			c = ((float) c) / ((float) 100);

			costs.insert(make_pair(a, c));
		}

		cin >> M;
		int total = 0;

//		for(auto i : costs){
//			cout << i.first << ": " << i.second << endl;
//		}

//		string str;
//		string lines;
//
//		for(int i = 1; i < M; i++){
//			lines += ("line" + to_string(i) + "\n");
//		}
//
//		lines += ("line" + to_string(M));
//		istringstream f(lines);

		string str;
		getline(cin, str);

		for(int i = 0; i < M; i++){
//
//			while(getline(f, str)){
//				cout << str << endl;
//			}
			string str;
			getline(cin, str);

//			cout << str << endl << "............................." << endl;

//			while(getline(cin, str)){
//				cout << str << endl;
//			}
//			cout << str << endl;

			for(int j = 0; j < (int) str.size(); j++){
				if(costs.find(str[j]) != costs.end()){
					total += costs[str[j]];
//					cout << total << endl;
				}
			}
//			cout << total << endl;
		}

		float answer = (float) total / (float) 100;

		cout << fixed << setprecision(2) << answer << "$" << endl;
	}

//	cout << endl;

	return 0;
}
