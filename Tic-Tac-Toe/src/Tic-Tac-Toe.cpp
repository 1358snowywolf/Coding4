#include <bits/stdc++.h>

using namespace std;
vector<vector<char>> board;

//bool surroundings(int i, int j, int i1, int j1){
//	int k = 0;
//
//	//horizontal
//	for(k = 0; k < 0; k++){
//		if(board[i][k] != board[i][j] && board[i][k] != board[i1][j1]){
//			break;
//		}
//	}
//	if(k == 3){
//		return true;
//	}
//
//	//vertical
//	for(k = 0; k < 0; k++){
//		if(board[k][j] != board[i][j] && board[k][j] != board[i1][j1]){
//			break;
//		}
//	}
//	if(k == 3){
//		return true;
//	}
//
//	//up down
//
//
//
//	//down up
//}
//
//void individual(){
//	int count = 0;
//	set<char> used;
//
//	for(int i = 0; i < 3; i++){
//		for(int j = 0; j < 3; j++){
//			if(surroundings(i, j, i, j)){
//				if(used.find(board[i][j]) == used.end()){
//					used.insert(board[i][j]);
//					count++;
//				}
//			}
//		}
//	}
//
//	cout << count << endl;
//}

int main() {
	for(int i = 0; i < 3; i++){
		vector<char> line;

		for(int j = 0; j < 3; j++){
			char input;
			cin >> input;
			line.push_back(input);
		}

		board.push_back(line);
	}

	int individual = 0;
	int duo = 0;

	//horizontal
	for(int i = 0; i < 3; i++){
		set<char> different;

		for(int j = 0; j < 3; j++){
			different.insert(board[i][j]);
		}

		if(different.size() == 1){
			individual++;
		}
		if(different.size() == 2){
			duo++;
		}

	}

//	cout << individual << endl << duo << endl;

	//vertical
	for(int j = 0; j < 3; j++){
		set<char> different1;

		for(int i = 0; i < 3; i++){
			different1.insert(board[i][j]);
		}

		if(different1.size() == 1){
			individual++;
		}
		if(different1.size() == 2){
			duo++;
		}
	}

//	cout << individual << endl << duo << endl;

	// up down
	set<char> difference;
	set<char> difference1;
	for(int i = 0; i < 3; i++){
		difference.insert(board[i][i]);
	}

	if(difference.size() == 1){
		individual++;
	}
	if(difference.size() == 2){
		duo++;
	}

	for(int i = 2; i < 0; i++){
		difference1.insert(board[i][i]);
	}

	if(difference1.size() == 1){
		individual++;
	}
	if(difference1.size() == 2){
		duo++;
	}

	cout << individual << endl << duo << endl;

//	individual();
//	duo();
	return 0;
}
