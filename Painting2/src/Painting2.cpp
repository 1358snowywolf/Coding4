#include <bits/stdc++.h>

using namespace std;

int main() {
//	freopen("paint.in", "r", stdin);
//	freopen("paint.out", "w", stdout);
	int N, K;
	cin >> N >> K;
	int index = 0;
	vector<pair<int, int>> intervals;

	for(int i = 0; i < N; i++){
		char direction;
		int begin = index, length;
		cin >> length >> direction;
		index = (direction == 'R') ? index + length : index - length;
		intervals.push_back(make_pair(min(begin, index), max(begin, index)));
	}
//	for(auto i : intervals){
//		cout << i.first << " " << i.second << endl;
//	}

	sort(intervals.begin(), intervals.end());
	int count = 0, start = 0, top;
	int previousSize = 0;
//	priority_queue<int, vector<int>, greater<int>> pq; // stores end values
	multiset<int> pq;

	for(int i = 0; i < (int) intervals.size(); i++){
		if(pq.empty()){
			pq.insert(intervals[i].second);
			previousSize = (int) pq.size();
			continue;
		}

		top = *pq.begin();
//		cout << top << endl;

		while(((int) pq.size() > (K - 1)) && *pq.begin() <= intervals[i].first){
			top = *pq.begin();
			pq.erase(pq.begin());
		}

		if((int) pq.size() < K && previousSize >= K){
			count += (top - start);
			cout << "start " << start << "  top " << top << endl;
			cout << "count   " << count << endl;
//			cout << "---------------------" << endl;
			previousSize = (int) pq.size();
			start = intervals[i].first;
		}

		pq.insert(intervals[i].second);
		if((int) pq.size() == K && previousSize < K){
			start = intervals[i].first;
//			cout << start << endl;
		}

		previousSize = (int) pq.size();

//		for(auto j(pq.begin()), end(pq.end()); j != end;
//			     ++j)
//			    std::cout << *j << "\n";
//
//		cout << endl << count;
//
//		cout << endl << "..................." << endl;

	}

	while((int) pq.size() > K - 1){
		top = *pq.begin();
		pq.erase(pq.begin());
	}
//	cout << "start " << start << endl;
//	cout << "top " << top << endl;
	//	cout << pq.top() << endl;
//	cout << endl;

	count += (top - start);
	cout << count << endl;

	return 0;
}
