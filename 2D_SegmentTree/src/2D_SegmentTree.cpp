//============================================================================
// Name        : 2D_SegmentTree.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> initialSeg;
vector<vector<int>> finalSeg;
vector<vector<int>> maps;
int N;

int left(int p){
	return p << 1;
}

int right(int p){
	return (p << 1) + 1;
}

void segment(int i, int j, int p, int strip){
	if(i == j){
		initialSeg[strip][p] = maps[strip][i];
		return;
	}

	segment(i, (i + j) / 2, left(p), strip);
	segment(((i + j) / 2) + 1, j, right(p), strip);
	initialSeg[strip][p] = initialSeg[strip][left(p)] + initialSeg[strip][right(p)];
}

void finalSegment(int i, int j, int p){
	if(i == j){
		for(int k = 1; k < 2 * N; k++){
			finalSeg[p][k] = initialSeg[i][k];
		}
	}
	else{
		finalSegment(i, (i + j) / 2, left(p));
		finalSegment(((i + j) / 2) + 1, j, right(p));

		for(int k = 1; k < 2 * N; k++){
			finalSeg[p][k] = finalSeg[left(p)][k] + finalSeg[right(p)][k];
		}
	}
}

int finalQuery(int p, int L, int R, int x1, int x2, int node){
	if(x2 < L || R < x1) return 0;
	if(x1 <= L && R <= x2) return finalSeg[node][p];

	int p1 = finalQuery(left(p), L, (L + R) / 2, x1, x2, node);
	int p2 = finalQuery(right(p), ((L + R) / 2) + 1, R, x1, x2, node);
	return p1 + p2;
}

int query(int p, int L, int R, int y1, int y2, int x1, int x2){
	if(y2 < L || R < y1) return 0;
	if(y1 <= L && R <= y2) return finalQuery(1, 1, 4, x1, x2, p);

	int p1 = query(left(p), L, (L + R) / 2, y1, y2, x1, x2);
	int p2 = query(right(p), ((L + R) / 2) + 1, R, y1, y2, x1, x2);
	return p1 + p2;
}

void finalUpdate(int p, int L, int R, int x, int val, int node){
	if(R == L){
		finalSeg[node][p] += val;
	}
	else{
		if(L <= x && x <= (L + R) / 2){
			finalUpdate(left(p), L, (L + R) / 2, x, val, node);
		}
		else{
			finalUpdate(right(p), ((L + R) / 2) + 1, R, x, val, node);
		}

		finalSeg[node][p] = finalSeg[node][left(p)] + finalSeg[node][right(p)];
	}
}

void update(int p, int L, int R, int x, int y, int val){
	if(L == R){
		finalUpdate(1, 1, 4, x, val, p);
	}
	else{
		if(L <= y && y <= (L + R) / 2){
			update(left(p), L, (L + R) / 2, x, y, val);
		}
		else{
			update(right(p), ((L + R) / 2) + 1, R, x, y, val);
		}

		for(int i = 1; i < N; i++){
			finalSeg[p][i] = finalSeg[left(p)][i] + finalSeg[right(p)][i];
		}
	}
}

int main() {
	initialSeg.assign(1000, vector<int> (1000, 0));
	finalSeg.assign(1000, vector<int> (1000, 0));
	vector<int> first = {1, 2, 3, 4};
	vector<int> second = {5, 6, 7, 8};
	vector<int> third = {1, 7, 5, 9};
	vector<int> four = {3, 0, 6, 2};

	maps.push_back(first);
	maps.push_back(second);
	maps.push_back(third);
	maps.push_back(four);
	N = 4;

	for(int i = 0; i < N; i++){
		segment(0, N - 1, 1, i);
	}

	finalSegment(0, N - 1, 1);

	cout << query(1, 1, 4, 2, 3, 2, 3) << endl;
	update(1, 1, 4, 2, 3, 100);
	cout << query(1, 1, 4, 2, 3, 2, 3) << endl;

	return 0;
}
