#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<string> names;
	vector<pair<int, int>> maximum;
	vector<pair<int, int>> minimum;

	for(int i = 0; i < N; i++){
		string a;
		cin >> a;
		names.push_back(a);

		int ma = INT_MIN;
		int mi = INT_MAX;

		for(int j = 0; j < (int) a.size(); j++){
			ma = max(ma, a[j] - 'a');
			mi = min(ma, a[j] - 'a');
		}

		maximum.push_back(make_pair(ma, i));
		minimum.push_back(make_pair(mi, i));
	}

	sort(maximum.rbegin(), maximum.rend());
	sort(minimum.begin(), minimum.end());
	vector<pair<int, int>> answers (N, make_pair(0, 0));

//	for(int i = 0; i < N; i++){
//		answers[maximum[i].second].second = maximum[i].second;
//		answers[minimum[i].second].first = minimum[i].second;
//	}
//
//	for(int i = 0; i < N; i++){
//		cout << answers[i].first << " " << answers[i].second << endl;
//	}

	return 0;
}
