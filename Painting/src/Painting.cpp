#include <bits/stdc++.h>

using namespace std;

int main() {
	ifstream fin ("paint.in");
	ofstream fout ("paint.out");

	map<int, int> painted;
	int N;
	fin >> N;
	int index = 0;

	for(int i = 0; i < N; i++){
		int length;
		char direction;
		fin >> length >> direction;
//		cout << length << " " << direction << endl;

		if(direction == 'R'){
			for(int j = 0; j < length; j++){
				index++;
				painted[index]++;
				cout << index << " " << painted[index] << endl;
			}

//			index--;
		}
		else{
			for(int j = 0; j < length; j++){
				index--;
				painted[index]++;
			}

//			index++;
		}
	}

	int amount = 0;

	for(auto i : painted){
		if(i.second >= 2){
			amount++;
		}

//		cout << i.first << " " << i.second << endl;
	}

	fout << amount << endl;

	return 0;
}
