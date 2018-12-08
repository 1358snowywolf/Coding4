#include <bits/stdc++.h>

using namespace std;

int left(int p){
	return p << 1;
}

int right(int p){
	return (p << 1) + 1;
}

void build(int p, int L, int R, vector<map<int, int>>& segment, vector<int> A){
	if(L == R){
		segment[p].insert(make_pair(A[L], 1));
//		segment[p].first = A[L];
//		segment[p].second = 1;
		return;
	}

	build(left(p), L, (L + R) / 2, segment, A);
	build(right(p), ((L + R) / 2) + 1, R, segment, A);

	for(auto i : segment[left(p)]){
		segment[p][i.first] += i.second;
	}
	for(auto i : segment[right(p)]){
		segment[p][i.first] += i.second;
	}
}

map<int, int> querry(int p, int L, int R, int i, int j, vector<map<int, int>> segment){
	if(i > R || j < L) return map<int, int> ();
	if(L >= i && R <= j) return segment[p];

	auto p1 = querry(left(p), L, (L + R) / 2, i, j, segment);
	auto p2 = querry(right(p), ((L + R) / 2) + 1, R, i, j, segment);

	for(auto n : p2){
		if(p1.find(n.first) == p1.end()){
			p1.insert(n);
		}
		else{
			p1[n.first] += n.second;
		}
	}
//	cout << p << " " << L << " " << R << ": ";
//
//	for(auto n : p1){
//		cout << "(" << n.first << ", " << n.second << ") ";
//	}
//	cout << endl;

	return p1;
}

int main() {
	while(true){
		int N, Q;
		cin >> N;
		if(N == 0) break;
		cin >> Q;

		vector<map<int, int>> segment (4 * N, map<int, int> ());
		vector<int> A;

		for(int i = 0; i < N; i++){
			int j;
			cin >> j;
			A.push_back(j);
		}

		build(1, 0, A.size() - 1, segment, A);

//		for(int i = 0; i < (int) segment.size(); i++){
//			cout << i<< ": ";
//
//			for(auto j : segment[i]){
//				cout << "(" << j.first << ", " << j.second << ") ";
//			}
//			cout << endl;
//		}

		for(int i = 0; i < Q; i++){
			int u, v;
			cin >> u >> v;

			auto m = querry(1, 0, A.size() - 1, u - 1, v - 1, segment);
			auto count = 0;

			for(auto q : m){
				if(q.second > count){
					count = q.second;
				}
			}

			cout << count << endl;
		}
	}

	return 0;
}
