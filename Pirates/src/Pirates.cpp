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
		segment[p] = A[L] - 1;
		return;
	}

	build(segment, left(p), L, (L + R) / 2);
	build(segment, right(p), ((L + R) / 2) + 1, R);

	int p1 = segment[left(p)]; int p2 = segment[right(p)];
	segment[p] = p1 + p2;
}

int querry(vector<int>& segment, vector<int>& lazy, int p, int L, int R, int i, int j){
	if(lazy[p] != 0){
		if(lazy[p] == -1){
			segment[p] = (R - L + 1) - segment[p];
		}
		else{
			segment[p] = (lazy[p] == 2) ? (R - L + 1) : 0;
		}

		if(L != R){
			if(lazy[p] == -1){
				if(lazy[left(p)] == 0){
					lazy[left(p)] = -1;
				}
				else if(lazy[left(p)] == -1){
					lazy[left(p)] = 0;
				}
				else{
					lazy[left(p)] = (lazy[left(p)] == 2) ? 1 : 2;
				}

				if(lazy[right(p)] == 0){
					lazy[right(p)] = -1;
				}
				else if(lazy[right(p)] == -1){
					lazy[right(p)] = 0;
				}
				else{
					lazy[right(p)] = (lazy[right(p)] == 2) ? 1 : 2;
				}
			}
			else{
				lazy[left(p)] = lazy[p];
				lazy[right(p)] = lazy[p];
			}
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

void update(vector<int>& segment, vector<int>& lazy, int p, int L, int R, int i, int j, int diff){
	if(lazy[p] != 0){
		if(lazy[p] == -1){
			segment[p] = (R - L + 1) - segment[p];
		}
		else{
			segment[p] = (lazy[p] == 2) ? (R - L + 1) : 0;
		}

		if(L != R){
//			lazy[left(p)] = lazy[p];
//			lazy[right(p)] = lazy[p];
			if(lazy[p] == -1){
				if(lazy[left(p)] == 0){
					lazy[left(p)] = -1;
				}
				else if(lazy[left(p)] == -1){
					lazy[left(p)] = 0;
				}
				else{
					lazy[left(p)] = (lazy[left(p)] == 2) ? 1 : 2;
				}

				if(lazy[right(p)] == 0){
					lazy[right(p)] = -1;
				}
				else if(lazy[right(p)] == -1){
					lazy[right(p)] = 0;
				}
				else{
					lazy[right(p)] = (lazy[right(p)] == 2) ? 1 : 2;
				}
			}
			else{
				lazy[left(p)] = lazy[p];
				lazy[right(p)] = lazy[p];
			}
		}

		lazy[p] = 0;
	}

	if(L > R || L > j || R < i){
		return;
	}

	if(L >= i && R <= j){
		if(diff == -1){
			segment[p] = (R - L + 1) - segment[p];
		}
		else{
			segment[p] = (diff == 2) ? (R - L + 1) : 0;
		}

		if(L != R){
			if(diff == -1){
				if(lazy[left(p)] == 0){
					lazy[left(p)] = -1;
				}
				else if(lazy[left(p)] == -1){
					lazy[left(p)] = 0;
				}
				else{
					lazy[left(p)] = (lazy[left(p)] == 2) ? 1 : 2;
				}

				if(lazy[right(p)] == 0){
					lazy[right(p)] = -1;
				}
				else if(lazy[right(p)] == -1){
					lazy[right(p)] = 0;
				}
				else{
					lazy[right(p)] = (lazy[right(p)] == 2) ? 1 : 2;
				}
			}
			else{
				lazy[left(p)] = diff;
				lazy[right(p)] = diff;
			}
		}

		return;
	}

	update(segment, lazy, left(p), L, (L + R) / 2, i, j, diff);
	update(segment, lazy, right(p), ((L + R) / 2) + 1, R, i, j, diff);

	segment[p] = segment[left(p)] + segment[right(p)];
}

int main() {
	int C;
	cin >> C;

	for(int times = 0; times < C; times++){
		cout << "Case " << times + 1 << ":" << endl;
		int cases = 1;
		int M;
		cin >> M;
		A.clear();

		for(int i = 0; i < M; i++){
			int T;
			string input;
			cin >> T >> input;

			for(int j = 0; j < T; j++){
				for(int k = 0; k < (int) input.size(); k++){
					A.push_back((input[k] - '0') + 1);
				}
			}
		}

		vector<int> lazy (A.size() * 4, 0);
		vector<int> segment (A.size() * 4, 0);
		build(segment, 1, 0, A.size() - 1);

		int Q;
		cin >> Q;

		for(int i = 0; i < Q; i++){
			int a, b;
			char operation;
			cin >> operation >> a >> b;

			if(operation == 'F'){
				update(segment, lazy, 1, 0, A.size() - 1, a, b, 2);
			}
			else if(operation == 'E'){
				update(segment, lazy, 1, 0, A.size() - 1, a, b, 1);

			}
			else if(operation == 'I'){
				update(segment, lazy, 1, 0, A.size() - 1, a, b, -1);
			}
			else{
				cout << "Q" << cases << ": " << querry(segment, lazy, 1, 0, A.size() - 1, a, b) << endl;
				cases++;
			}
		}
	}

	return 0;
}
