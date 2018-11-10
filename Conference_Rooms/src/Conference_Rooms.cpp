#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;
	multiset<int> ending;
	vector<pair<int, int>> times;
	int maximum = 0, current = 0;

	for(int i = 0; i < N; i++){
		int start, end;
		cin >> start >> end;
		times.push_back(make_pair(start, end));
	}

	sort(times.begin(), times.end());

	for(int i = 0; i < (int) times.size(); i++){
		int start = times[i].first;
		int end = times[i].second;

		while(!ending.empty() && start > *ending.begin()){
			current--;
			ending.erase(ending.begin());
		}

		ending.insert(end);
		maximum = max(maximum, ++current);
	}

	cout << maximum << endl;

	return 0;
}
