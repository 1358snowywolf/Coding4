#include <bits/stdc++.h>

using namespace std;

int main() {
	ifstream fin ("scramble.in");
	ofstream fout ("scramble.out");

	int N;
	fin >> N;
	vector<string> original;
	vector<string> ascending;
	vector<string> descending;

	for(int i = 0; i < N; i++){
		string str;
		fin >> str;
		auto str2 = str;
		original.push_back(str);
		sort(str.begin(), str.end());
		sort(str2.rbegin(), str2.rend());

		ascending.push_back(str);
		descending.push_back(str2);
	}


	sort(ascending.begin(), ascending.end());
	sort(descending. begin(), descending.end());

	vector<pair<int, int>> answers (N, make_pair(0, 0));

	for(int i = 0; i < N; i++){
		string l = original[i];
		string h = original[i];
		sort(l.begin(), l.end());
		sort(h.rbegin(), h.rend());

		auto lower = lower_bound(descending.begin(), descending.end(), l) - descending.begin() + 1;
		auto higher = upper_bound(ascending.begin(), ascending.end(), h) - ascending.begin();

//		cout << original[i] << " " << lower << " " << higher << endl;

		answers[i].first = lower;
		answers[i].second = higher;
//		int lower = lower_bound(descending.begin(), descending.end(), ascending[i]);
//		int upper = upper_bound(ascending.begin(), ascending.end(), descending[i]);
	}

	for(int i = 0; i < (int) answers.size(); i++){
		fout << answers[i].first << " " << answers[i].second << endl;
	}

	return 0;
}
