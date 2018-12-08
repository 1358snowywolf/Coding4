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
	if(L == R){
		segment[p] = A[L];
		return;
	}

	build(segment, left(p), L, (L + R) / 2);
	build(segment, right(p), ((L + R) / 2) + 1, R);

	int p1 = segment[left(p)]; int p2 = segment[right(p)];
	segment[p] = p1 + p2;
}

int querry(vector<int> segment, int p, int L, int R, int i, int j){
	if(i > R || j < L) return 0;
	if(L >= i && R <= j) return segment[p];

	int p1 = querry(segment, left(p), L, (L + R) / 2, i, j);
	int p2 = querry(segment, right(p), ((L + R) / 2) + 1, R, i, j);
	return p1 + p2;
}

int main() {
	return 0;
}
