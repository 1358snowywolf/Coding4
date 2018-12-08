#include <bits/stdc++.h>

using namespace std;
vector<int> A;

int left(int p){
	return p << 1;
}

int right(int p){
	return (p << 1) + 1;
}

void build(vector<int>& segment, int p, int L, int R){
	if(L > R) return;
	if(L == R){
		segment[p] = A[L];
		return;
	}

	build(segment, left(p), L, (L + R) / 2);
	build(segment, right(p), ((L + R) / 2) + 1, R);

	int p1 = segment[left(p)]; int p2 = segment[right(p)];
	segment[p] = p1 + p2;
}

int querry(vector<int> segment, vector<int>& lazy, int p, int L, int R, int i, int j){
//	if(i > R || j < L) return 0;
//	if(L >= i && R <= j) return segment[p];
//
//	int p1 = querry(segment, left(p), L, (L + R) / 2, i, j);
//	int p2 = querry(segment, right(p), ((L + R) / 2) + 1, R, i, j);
//	return p1 + p2;

	if(lazy[p] != 0){
		segment[p] += (R - L + 1) * lazy[p];

		if(L != R){
			lazy[left(p)] += lazy[p];
			lazy[right(p)] += lazy[p];
		}

		lazy[p] = 0;
	}

	if(L > R || L > j || R < i){
		return 0;
	}

	if(L >= i && R <= j){
		return segment[p];
	}

	int p1 = querry(segment, lazy, left(p), L, (L + R) / 2, i, j);
	int p2 = querry(segment, lazy, right(p), ((L + R) / 2) + 1, R, i, j);
	return p1 + p2;
}

void update(int p, int L, int R, int i, int j, int diff, vector<int>& lazy, vector<int>& segment){
	if(lazy[p] != 0){
		segment[p] += (R - L + 1) * lazy[p];

		if(L != R){
			lazy[left(p)] = lazy[p];
			lazy[right(p)] = lazy[p];
		}

		lazy[p] = 0;
	}

	if(L > R || L > j || R < i){
		return;
	}

	if(L >= i && R <= j){
		segment[p] += (R - L + 1) * diff;

		if(L != R){
			lazy[left(p)] += diff;
			lazy[right(p)] += diff;
		}

		return;
	}

	update(left(p), L, (L + R) / 2, i, j, diff, lazy, segment);
	update(right(p), ((L + R) / 2) + 1, R, i, j, diff, lazy, segment);

	segment[p] = segment[left(p)] + segment[right(p)];
}

int main() {
	A = {1, 3, 5, 7, 9, 11};
	vector<int> lazy (4 * A.size(), 0);
	vector<int> segment (4 * A.size(), 0);

	build(segment, 1, 0, A.size() - 1);

//	for(int i = 0; i < (int) segment.size(); i++){
//		cout << segment[i] << " ";
//	}
//	cout << endl;

	cout << querry(segment, lazy, 1, 0, A.size() - 1, 1, 3) << endl;
	update(1, 0, A.size() - 1, 1, 5, 10, lazy, segment);
	cout << querry(segment, lazy, 1, 0, A.size() - 1, 1, 3);
	return 0;
}
