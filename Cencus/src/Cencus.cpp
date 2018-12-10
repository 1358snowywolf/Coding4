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

void segment(int i, int j, int p, int strip, vector<vector<int>>& initialSeg, int type){
	if(i == j){
		initialSeg[strip][p] = maps[strip][i];
		return;
	}

	segment(i, (i + j) / 2, left(p), strip, initialSeg, type);
	segment(((i + j) / 2) + 1, j, right(p), strip, initialSeg, type);

	if(type == 1){ //max
		initialSeg[strip][p] = max(initialSeg[strip][left(p)], initialSeg[strip][right(p)]);
	}
	else{
		initialSeg[strip][p] = min(initialSeg[strip][left(p)], initialSeg[strip][right(p)]);
	}
}

void finalSegment(int i, int j, int p, vector<vector<int>> initialSeg, vector<vector<int>>& finalSeg, int type){
	if(i == j){
//		for(int k = 1; k < 2 * N; k++){
//			finalSeg[p][k] = initialSeg[i][k];
//		}
		finalSeg[p] = initialSeg[i];
	}
	else{
		finalSegment(i, (i + j) / 2, left(p), initialSeg, finalSeg, type);
		finalSegment(((i + j) / 2) + 1, j, right(p), initialSeg, finalSeg, type);

		for(int k = 1; k < 4 * N; k++){
//			finalSeg[p][k] = finalSeg[left(p)][k] + finalSeg[right(p)][k];
			if(type == 1){ //max
				finalSeg[p][k] = max(finalSeg[left(p)][k], finalSeg[right(p)][k]);
			}
			else{
				finalSeg[p][k] = min(finalSeg[left(p)][k], finalSeg[right(p)][k]);
			}
		}
	}
}

int finalQuery(int p, int L, int R, int y1, int y2, int node, vector<vector<int>> finalSeg, int type){
	if(y2 < L || R < y1) return (type == 1) ? 0 : 2000000;
	if(y1 <= L && R <= y2) return finalSeg[node][p];

	int p1 = finalQuery(left(p), L, (L + R) / 2, y1, y2, node, finalSeg, type);
	int p2 = finalQuery(right(p), ((L + R) / 2) + 1, R, y1, y2, node, finalSeg, type);
//	return p1 + p2;

	if(type == 1){
		return max(p1, p2);
	}
	else{
		return min(p1, p2);
	}
}

int query(int p, int L, int R, int x1, int y1, int x2, int y2, vector<vector<int>> finalSeg, int type){
	if(x2 < L || R < x1) return (type == 1) ? 0 : 2000000;
	if(x1 <= L && R <= x2) return finalQuery(1, 1, N - 1, y1, y2, p, finalSeg, type);

	int p1 = query(left(p), L, (L + R) / 2, x1, y1, x2, y2, finalSeg, type);
	int p2 = query(right(p), ((L + R) / 2) + 1, R, x1, y1, x2, y2, finalSeg, type);

	if(type == 1){
		return max(p1, p2);
	}
	else{
		return min(p1, p2);
	}
}

void finalUpdate(int p, int L, int R, int x, int val, int node, vector<vector<int>>& finalSeg, int type){
	if(R == L){
		finalSeg[node][p] = val;
	}
	else{
		if(L <= x && x <= (L + R) / 2){
			finalUpdate(left(p), L, (L + R) / 2, x, val, node, finalSeg, type);
		}
		else{
			finalUpdate(right(p), ((L + R) / 2) + 1, R, x, val, node, finalSeg, type);
		}

//		finalSeg[node][p] = finalSeg[node][left(p)] + finalSeg[node][right(p)];
		if(type == 1){
			finalSeg[node][p] = max(finalSeg[node][left(p)], finalSeg[node][right(p)]);
		}
		else{
			finalSeg[node][p] = min(finalSeg[node][left(p)], finalSeg[node][right(p)]);
		}
	}
}

void update(int p, int L, int R, int x, int y, int val, vector<vector<int>>& finalSeg, int type){
	if(L == R){
		finalUpdate(1, 1, 4, y, val, p, finalSeg, type);
	}
	else{
		if(L <= y && y <= (L + R) / 2){
			update(left(p), L, (L + R) / 2, x, y, val, finalSeg, type);
		}
		else{
			update(right(p), ((L + R) / 2) + 1, R, x, y, val, finalSeg, type);
		}

		for(int i = 1; i < N; i++){
			if(type == 1){
				finalSeg[p][i] = max(finalSeg[left(p)][i], finalSeg[right(p)][i]);
			}
			else{
				finalSeg[p][i] = min(finalSeg[left(p)][i], finalSeg[right(p)][i]);
			}
		}
	}
}

int main() {
	cin >> N;

	for(int i = 0; i < N; i++){
		vector<int> line;

		for(int j = 0; j < N; j++){
			int input;
			cin >> input;
			line.push_back(input);
		}

		maps.push_back(line);
	}

//	for(int i = 0; i < N; i++){
//		for(int j = 0; j < N; j++){
//			cout << maps[i][j] << " ";
//		}
//
//		cout << endl;
//	}

	int Q;
	cin >> Q;

	vector<vector<int>> maxInitialSeg (N * 2, vector<int> (N * 2, 0));
	vector<vector<int>> maxFinalSeg (N * 4, vector<int> (N * 4, 0));

	vector<vector<int>> minInitialSeg (N * 2, vector<int> (N * 2, 2000000));
	vector<vector<int>> minFinalSeg (N * 4, vector<int> (N * 4, 2000000));

	for(int i = 0; i < N; i++){
		segment(0, N - 1, 1, i, maxInitialSeg, 1);
	}
	for(int i = 0; i < N; i++){
		segment(0, N - 1, 1, i, minInitialSeg, 2);
	}

	finalSegment(0, N - 1, 1, maxInitialSeg, maxFinalSeg, 1);
	finalSegment(0, N - 1, 1, minInitialSeg, minFinalSeg, 2);

	cout << endl;

	for(int i = 0; i < 5; i++){
//		cout << maxFinalSeg[0][i] << " "
		for(int j = 0; j < 10; j++){
			cout << maxInitialSeg[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;

//	for(int i = 0; i < 5; i++){
////		cout << maxFinalSeg[0][i] << " ";
//		for(int j = 0; j < 10; j++){
//			if(minInitialSeg[i][j] == 2000000) cout << "X" << " ";
//			else cout << minInitialSeg[i][j] << " ";
//		}
//		cout << endl;
//	}

	for(int i = 0; i < 12; i++){
		for(int j = 0; j < 12; j++){
			cout << maxFinalSeg[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;

	for(int i = 0; i < Q; i++){
		char function;
		cin >> function;

		if(function == 'q'){
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			x1--; x2--; y1--; y2--;
			cout << query(1, 0, N, x1, y1, x2, y2, maxFinalSeg, 1) << " " << query(1, 0, N, x1, y1, x2, y2, minFinalSeg, 2) << endl;
		}
		else{
			int x, y, val;
			cin >> x >> y >> val;
			x--; y--;

//			update(1, 1, N, x, y, val, maxFinalSeg, 1);
//			update(1, 1, N, x, y, val, minFinalSeg, 2);
		}

	}

	return 0;
}
