#include <bits/stdc++.h>

using namespace std;
int maximum = 0;
vector<tuple<int, int, int>> stations;

void DFS(multiset<pair<int, int>> passengers, int size, int money, int index, int N, vector<int> used){
//	for(auto i : passengers){
//		cout << "(" << i.first << ", " << i.second << ") ";
//	}
//	cout << endl;

	if(index == (int) stations.size()){
		maximum = max(maximum, money);

//		if(maximum == money){
//			for(int i : used){
//				cout << i << " ";
//			}
//			cout << ": " << money << endl;
//		}
//		cout << size << " " << money << endl;
		return;
	}

	int s, d, n;
	tie(s, d, n) = stations[index];
//	cout << s << endl << endl;

	while(true){
		if(passengers.empty()) break;
		auto group = passengers.begin();
		if(group->first > s) break;

		size -= group->second;
		passengers.erase(passengers.begin());
	}

	DFS(passengers, size, money, index + 1, N, used);

	if(n + size > N) return;
	passengers.insert(make_pair(d, n));
	money += ((d - s) * n);
	size += n;
	used.push_back(index);

	DFS(passengers, size, money, index + 1, N, used);
}

int main() {
	int N, B, C;

	while(true){
		cin >> N >> B >> C;
		if(N == 0 && B == 0 && C == 0) break;

		maximum = 0;
		stations.clear();

		for(int i = 0; i < C; i++){
			int s, d, n;
			cin >> s >> d >> n;
			stations.push_back(make_tuple(s, d, n));
		}

		sort(stations.begin(), stations.end());

		DFS(multiset<pair<int, int>> (), 0, 0, 0, N, vector<int> ());

		cout << maximum << endl;
	}

	return 0;
}
