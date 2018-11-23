#include <bits/stdc++.h>

using namespace std;

int main() {
	int books, length;
	cin >> books >> length;
	vector<int> heights, widths;

	for(int i = 0; i < books; i++){
		int h, w;
		cin >> h >> w;
		heights.push_back(h);
		widths.push_back(w);
	}

	vector<int> DP (books, 2000000);
	DP[0] = heights[0];

	for(int i = 1; i < books; i++){
		int prev = i -1;
		DP[i] = DP[prev] + heights[i];

		int last_height = heights[i];
		int width = widths[i];

		while(prev >= 0) {
			width += widths[prev];
			if (width > length) break;

			last_height = max(last_height, heights[prev]);
			DP[i] = min (DP[i], last_height + (prev == 0 ? 0 : DP[prev -1]));
			prev--;
		}

//		for(int i = 0; i < books; i++){
//			cout << DP[i] << " ";
//		}
//
//		cout << endl;
//
////		int minimum = DP[i - 1] + heights[i];
//		DP[i] = DP[i - 1] + heights[i];
//		int totalWidth = widths[i];
//		int maxHeight = heights[i];
//		int backtrack = i - 1;
//
//		while(totalWidth + widths[backtrack] <= length){
////			int tmpHight = (backtrack >= 0 ? DP[backtrack] : 0);
////
////			int current = max(maxHeight, tmpHight) + tmpHight;
////			int add = 0;
////
////			if(backtrack = 0){
////
////			}
////			else if(backtrack )
//
//
//			int current = max(maxHeight, heights[backtrack]) + (backtrack >= 1 ? DP[backtrack - 1] : 0);
//
//
////			int current = 0;
////
////			if(maxHeight > heights[backtrack]){
////				current = maxHeight;
////			}
////			else{
////				current = heights[backtrack] + DP[backtrack];
////			}
//
//			if(DP[i] > current){
//				DP[i] = min(DP[i], current);
////				maxHeight = max(maxHeight, tmpHight);
//				maxHeight = max(maxHeight, heights[backtrack]);
//				totalWidth += widths[backtrack];
//			}
//			backtrack--;
////			else{
////				break;
////			}
////			for(int i = 0; i < books; i++){
////				cout << DP[i] << " ";
////			}
////
////			cout << endl;
//		}
//
//
//
//		DP[i] = minimum;
	}

//	cout << endl;
//
//	for(int i = 0; i < books; i++){
//		cout << DP[i] << " ";
//	}
//
//	cout << endl;

	cout << DP[books - 1] << endl;

	return 0;
}
