#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> maps;
int N;

int left(int p){
	return p << 1;
}

int right(int p){
	return (p << 1) + 1;
}

void build(int L, int R, int p, int strip, vector<vector<int>>& initialSeg, int type){
	if(L == R){
		initialSeg[strip][p] = maps[strip][L];
		return;
	}

	build(L, (L + R) / 2, left(p), strip, initialSeg, type);
	build(((L + R) / 2) + 1, R, right(p), strip, initialSeg, type);

	if(type == 1){ //max
		initialSeg[strip][p] = max(initialSeg[strip][left(p)], initialSeg[strip][right(p)]);
	}
	else{
		initialSeg[strip][p] = min(initialSeg[strip][left(p)], initialSeg[strip][right(p)]);
	}
}

void fbuild(int L, int R, int p, vector<vector<int>> initialSeg, vector<vector<int>>& finalSeg, int type){
	if(L == R){
		finalSeg[p] = initialSeg[L];
	}
	else{
		fbuild(L, (L + R) / 2, left(p), initialSeg, finalSeg, type);
		fbuild(((L + R) / 2) + 1, R, right(p), initialSeg, finalSeg, type);

		for(int k = 1; k < 4 * N; k++){
			if(type == 1){ //max
				finalSeg[p][k] = max(finalSeg[left(p)][k], finalSeg[right(p)][k]);
			}
			else{
				finalSeg[p][k] = min(finalSeg[left(p)][k], finalSeg[right(p)][k]);
			}
		}
	}
}

int fquerry(int p, int L, int R, int j1, int j2, int i, vector<vector<int>>& finalSeg, int type){

//	cout << p << "  " << j1 << "  " << j2 << "   " << L << "  " << R << endl;

	if(L >= j1 && R <= j2){
		return finalSeg[i][p];
	}
	if(L > j2 || R < j1){
		return (type == 1) ? 0 : 2000000;
	}

	int p1 = fquerry(left(p), L, (L + R) / 2, j1, j2, i, finalSeg, type);
	int p2 = fquerry(right(p), ((L + R) / 2) + 1, R, j1, j2, i, finalSeg, type);

	if(type == 1){
//		cout << p << "  " << j1 << "  " << j2 << "   " << L << "  " << R << "  " << i << endl;
//		cout << "size " << finalSeg[i].size() << endl;
//		for (auto x: finalSeg[i]) {
//			cout << x << "  ";
//		}
//		cout << endl;
//
//		cout << "max : " << max(p1, p2) << endl;
//		cout << " ----  " << endl;
		return max(p1, p2);
	}

	return min(p1, p2);
}

int querry(int p, int i1, int i2, int j1, int j2, int L, int R, vector<vector<int>>& finalSeg, int type){
//	cout << p << "  " << i1 << "  " << i2 << "   " << L << "  " << R << endl;
	if(L >= i1 && R <= i2){
		return fquerry(1, 0, N - 1, j1, j2, p, finalSeg, type);
	}
	if(i1 > R || i2 < L){
		return (type == 1) ? 0 : 2000000;
	}

	int p1 = querry(left(p), i1, i2, j1, j2, L, (L + R) / 2, finalSeg, type);
	int p2 = querry(right(p), i1, i2, j1, j2, ((L + R) / 2) + 1, R, finalSeg, type);

	if(type == 1){
		return max(p1, p2);
	}

	return min(p1, p2);
}

void fupdate(int p, int L, int R, int row, int j, int val, vector<vector<int>>& finalSeg, int type){
	if(L > R) return;
	if(L == R){
//		finalSeg[p][L] = val;
//		cout << row << " " << p << endl;
		finalSeg[row][p] = val;
		return;
	}

	if(L <= j && j <= (L + R) / 2){
		fupdate(left(p), L, (L + R) / 2, row, j, val, finalSeg, type);
	}
	else{
		fupdate(right(p), ((L + R) / 2) + 1, R, row, j, val, finalSeg, type);
	}

	if(type == 1){
		finalSeg[row][p] = max(finalSeg[row][left(p)], finalSeg[row][right(p)]);
	}
	else{
		finalSeg[row][p] = min(finalSeg[row][left(p)], finalSeg[row][right(p)]);
	}
}

void update(int p, int L, int R, int i, int j, int val, vector<vector<int>>& finalSeg, int type){
//	cout << i << " " << j << " " << L << " " << R << endl;
//	cout << "----------------------" << endl;

	if(L == R){
//		cout << L << " " << R << " " << p << " " << i << endl;
		fupdate(1, 0, N - 1, p, j, val, finalSeg, type);
		return;
	}

	if(L <= i && i <= (L + R) / 2){
		update(left(p), L, (L + R) / 2, i, j, val, finalSeg, type);
	}
	else{
		update(right(p), ((L + R) / 2) + 1, R, i, j, val, finalSeg, type);
	}

	for(int k = 0; k < (int) finalSeg[i].size(); k++){
		if(type == 1){
			finalSeg[p][k] = max(finalSeg[left(p)][k], finalSeg[right(p)][k]);
		}
		else{
			finalSeg[p][k] = min(finalSeg[left(p)][k], finalSeg[right(p)][k]);
		}
	}
}

int main() {
	cin >> N;

	for(int i = 0; i < N; i++){
		vector<int> lines;

		for(int j = 0; j < N; j++){
			int input;
			cin >> input;
			lines.push_back(input);
		}

		maps.push_back(lines);
	}

//	for(int i = 0; i < N; i++){
//		for(int j = 0; j < N; j++){
//			cout << maps[i][j] << " ";
//		}
//
//		cout << endl;
//	}

	vector<vector<int>> maxInitialSeg (N * 4, vector<int> (N * 4, 0));
	vector<vector<int>> maxFinalSeg (N * 4, vector<int> (N * 4, 0));

	vector<vector<int>> minInitialSeg (N * 4, vector<int> (N * 4, 2000000));
	vector<vector<int>> minFinalSeg (N * 4, vector<int> (N * 4, 2000000));

	for(int i = 0; i < N; i++){
		build(0, N - 1, 1, i, minInitialSeg, 2);
		build(0, N - 1, 1, i, maxInitialSeg, 1);
	}

	fbuild(0, N - 1, 1, minInitialSeg, minFinalSeg, 2);
	fbuild(0, N - 1, 1, maxInitialSeg, maxFinalSeg, 1);

	int Q;
	cin >> Q;

//	cout << endl;
////
////	for(int i = 0; i < 7; i++){
////		for(int j = 0; j < 7; j++){
////			if(minFinalSeg[i][j] == 2000000){
////				cout << "X ";
////			}
////			else{
////				cout << minFinalSeg[i][j] << " ";
////			}
////		}
////		cout << endl;
////	}
////
////	cout << endl << endl;
////
////	for(int i = 0; i < 7; i++){
////		for(int j = 0; j < 7; j++){
////			if(maxFinalSeg[i][j] == 2000000){
////				cout << "X ";
////			}
////			else{
////				cout << maxFinalSeg[i][j] << " ";
////			}
////		}
////		cout << endl;
////	}
////
////	cout << endl;
//
//
//	for(int i = 0; i < N * 3; i++){
//		for(int j = 0; j < N * 3; j++){
//			if(minFinalSeg[i][j] == 2000000){
//				cout << "X ";
//			}
//			else{
//				cout << minFinalSeg[i][j] << " ";
//			}
//		}
//		cout << endl;
//	}
//
//	cout << endl;
//	cout << endl;

//	for(int i = 0; i < 12; i++){
//		for(int j = 0; j < 20; j++){
//			if(minFinalSeg[i][j] == 2000000){
//				cout << "X ";
//			}
//			else{
//				cout << minFinalSeg[i][j] << " ";
//			}
//		}
//		cout << endl;
//	}
//
//	cout << endl << endl;
//
//	for(int i = 0; i < 12; i++){
//		for(int j = 0; j < 20; j++){
//			if(maxFinalSeg[i][j] == 2000000){
//				cout << "X ";
//			}
//			else{
//				cout << maxFinalSeg[i][j] << " ";
//			}
//		}
//		cout << endl;
//	}
//
//	cout << endl;

	for(int a = 0; a < Q; a++){
		char command;
		cin >> command;

		if(command == 'q'){
			int i1, i2, j1, j2;
			cin >> i1 >> j1 >> i2 >> j2;
			i1--; i2--; j1--; j2--;

			cout << querry(1, i1, i2, j1, j2, 0, N - 1, maxFinalSeg, 1) << " " <<
					querry(1, i1, i2, j1, j2, 0, N - 1, minFinalSeg, 2) << endl;
		}
		else{
			int i, j, val;
			cin >> i >> j >> val;
			i--; j--;

			//update(int p, int L, int R, int i, int j, int val, vector<vector<int>>& finalSeg, int type)

			update(1, 0, N - 1, i, j, val, maxFinalSeg, 1);
			update(1, 0, N - 1, i, j, val, minFinalSeg, 2);

//			maps[i][j] = val;
//
//			for(int k = 0; k < N; k++){
//				build(0, N - 1, 1, k, minInitialSeg, 2);
//				build(0, N - 1, 1, k, maxInitialSeg, 1);
//			}
//
//			fbuild(0, N - 1, 1, minInitialSeg, minFinalSeg, 2);
//			fbuild(0, N - 1, 1, maxInitialSeg, maxFinalSeg, 1);

//			cout << endl;
//
//			for(int i = 0; i < N * 3; i++){
//				for(int j = 0; j < N * 3; j++){
//					if(minFinalSeg[i][j] == 2000000){
//						cout << "X ";
//					}
//					else{
//						cout << minFinalSeg[i][j] << " ";
//					}
//				}
//				cout << endl;
//			}
////
//			cout << endl;


//			cout << endl;
//
//			for(int i = 0; i < 7; i++){
//				for(int j = 0; j < 7; j++){
//					if(minFinalSeg[i][j] == 2000000){
//						cout << "X ";
//					}
//					else{
//						cout << minFinalSeg[i][j] << " ";
//					}
//				}
//				cout << endl;
//			}
//
//			cout << endl << endl;
//
//			for(int i = 0; i < 7; i++){
//				for(int j = 0; j < 7; j++){
//					if(maxFinalSeg[i][j] == 2000000){
//						cout << "X ";
//					}
//					else{
//						cout << maxFinalSeg[i][j] << " ";
//					}
//				}
//				cout << endl;
//			}
//
//			cout << endl;
		}
	}

	return 0;
}
