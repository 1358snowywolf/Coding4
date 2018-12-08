#include <bits/stdc++.h>

using namespace std;

class NumArray {
public:
    NumArray(vector<int> nums) {
        A = nums;
        segment.assign(nums.size() * 4, 0);
        if(A.empty()) return;

        build(1, 0, (int) nums.size() - 1);
    }

    void update(int i, int val) {
        if(A.empty()) return;
    	updating(1, 0, A.size() - 1, i, val);
    	A[i] = val;
    }

    int sumRange(int i, int j){
        if(A.empty()) return 0;
    	return querry(1, 0, (int) A.size() - 1, i, j);
    }

private:
    vector<int> A;
    vector<int> segment;

    int left(int p){
    	return p << 1;
    }

    int right(int p){
    	return (p << 1) + 1;
    }

    void updating(int p, int L, int R, int i, int val){
    	if(L > i || R < i) return;
    	if(L == R && L == i){
    		segment[p] = val;
    		return;
    	}

    	updating(left(p), L, (L + R) / 2, i, val);
    	updating(right(p), ((L + R) / 2) + 1, R, i, val);

    	segment[p] = segment[left(p)] + segment[right(p)];
    }

//    void updating(int p, int L, int R, int i, int val){
//    	if(L > i || R < i) return;
//    	if(L == R && L == i){
//    		segment[p] = val;
//    		return;
//    	}
//
//    	segment[p] += (val - A[i]);
//    	updating(left(p), L, (L + R) / 2, i, val);
//    	updating(right(p), ((L + R) / 2) + 1, R, i, val);
//    }

    void build(int p, int L, int R){
    	if(L == R){
    		segment[p] = A[L];
    		return;
    	}

    	build(left(p), L, (L + R) / 2);
    	build(right(p), ((L + R) / 2) + 1, R);

    	int p1 = segment[left(p)]; int p2 = segment[right(p)];
    	segment[p] = p1 + p2;
    }

    int querry(int p, int L, int R, int i, int j){
    	if(i > R || j < L) return 0;
    	if(L >= i && R <= j) return segment[p];

    	int p1 = querry(left(p), L, (L + R) / 2, i, j);
    	int p2 = querry(right(p), ((L + R) / 2) + 1, R, i, j);
    	return p1 + p2;
    }
};

int main() {
	NumArray* A = new NumArray({-1});
	cout << A->sumRange(0, 0) << endl;
	A->update(0, 1);
	cout << A->sumRange(0, 0) << endl;;
	return 0;
}
