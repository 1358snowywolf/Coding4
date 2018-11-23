//============================================================================
// Name          : PaintingSilver.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("paint.in", "r", stdin);
	freopen("paint.out", "w", stdout);
	int N, K;
	cin >> N >> K;
	int current = 0;
	vector<pair<int, int>> intervals;

	for(int i = 0; i < N; i++){
		int length;
		char direction;
		cin >> length >> direction;

		int end = (direction == 'R') ? current + length : current - length;
		intervals.push_back(make_pair(min(current, end), max(current, end)));
		current = end;
	}

	sort(intervals.begin(), intervals.end());
	multiset<int> backlog;
	int start, top, count = 0;

	for(auto i : intervals){
		if(backlog.empty()){
			backlog.insert(i.second);

			if((int) backlog.size() == K){
				start = i.first;
			}

			continue;
		}

		while(*backlog.begin() < i.first){
			int top = *backlog.begin();
			backlog.erase(backlog.begin());

			if((int) backlog.size() == K - 1){
				count += (top - start);
			}
		}

		backlog.insert(i.second);

		if((int) backlog.size() == K){
			start = i.first;
		}
	}

	while((int) backlog.size() >= K){
		top = *backlog.begin();
		backlog.erase(backlog.begin());

		if((int) backlog.size() == K - 1){
			count += (top - start);
		}
	}

	cout << count << endl;

	return 0;
}

