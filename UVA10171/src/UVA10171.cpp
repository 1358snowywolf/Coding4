#include <bits/stdc++.h>

using namespace std;

void FloydWarshall(vector<vector<int>>& weights){
	for(int k = 0; k < 26; k++){
		for(int i = 0; i < 26; i++){
			for(int j = 0; j < 26; j++){
				weights[i][j] = min(weights[i][j], weights[i][k] + weights[k][j]);
			}
		}
	}
}

//pair<int, vector<char>> findVisit(vector<vector<int>> Shahriar, vector<vector<int>> Miguel){
//	int minimum = 2000000;
//	vector<char> place;
//
//	for(int i = 0; i < 26; i++){
//		for(int j = 0; j < 26; j++){
//			if(Shahriar[i][j] != 2000000 && Miguel[i][j] != 2000000){
//				minimum = min(minimum, Shahriar[i][j] + Miguel[i][j]);
//
//				if(!place.empty()){
//					place[0] = 'A' + i;
//				}
//				else{
//					place.push_back('A' + i);
//				}
//			}
//		}
//	}
//
//	return make_pair(minimum, place);
//}

pair<int, vector<char>> findPlace(vector<vector<int>> Shahriar, vector<vector<int>> Miguel, int start1, int start2){
	int minimum = 2000000;
	vector<char> place = {'.'};

	for(int i = 0; i < 26; i++){
		if(Shahriar[start1][i] != 2000000 && Miguel[start2][i] != 2000000){
			if(minimum > Shahriar[start1][i] + Miguel[start2][i]){
				minimum = Shahriar[start1][i] + Miguel[start2][i];

				place[0] = (char) (i + 'A');
			}
		}
	}

	for(int i = 0; i < 26; i++){
		if(Shahriar[start1][i] != 2000000 && Miguel[start2][i] != 2000000){
			if(minimum == Shahriar[start1][i] + Miguel[start2][i] && place[0] != (char) (i + 'A')){
				place.push_back((char) (i + 'A'));
			}
		}
	}

	return make_pair(minimum, place);
}

int main(){
	int N;

	while(cin >> N){
		if(N == 0){
			break;
		}

		vector<vector<int>> Shahriar (26, vector<int> (26, 2000000));
		vector<vector<int>> Miguel (26, vector<int> (26, 2000000));

		for(int i = 0; i < N; i++){
			char age, direction, a, b;
			int w;
			cin >> age >> direction >> a >> b >> w;

			if(age == 'Y'){
				Shahriar[a - 'A'][b - 'A'] = w;

				if(direction == 'B'){
					Shahriar[b - 'A'][a- 'A'] = w;
				}
			}
			else{
				Miguel[a - 'A'][b - 'A'] = w;

				if(direction == 'B'){
					Miguel[b - 'A'][a- 'A'] = w;
				}
			}
		}

		char start1, start2;
		cin >> start1 >> start2;

//		cout << start1 << " ";
//		cout << start1 - 'A' << endl;

		Shahriar[start1 - 'A'][start1 - 'A'] = 0;
		Miguel[start2 - 'A'][start2 - 'A'] = 0;


//

		FloydWarshall(Shahriar);
		FloydWarshall(Miguel);
		auto answer = findPlace(Shahriar, Miguel, start1 - 'A', start2 - 'A');

//		for(int i = 0; i < 26; i++){
//			for(int j = 0; j < 26; j++){
//				if(Shahriar[i][j] == 2000000){
//					cout << "X" << " ";
//				}
//				else{
//					cout << Shahriar[i][j] << " ";
//				}
//			}
//
//			cout << endl;
//		}
//
//		cout << "......................." << endl;
//
//		for(int i = 0; i < 26; i++){
//			for(int j = 0; j < 26; j++){
//				if(Miguel[i][j] == 2000000){
//					cout << "X" << " ";
//				}
//				else{
//					cout << Miguel[i][j] << " ";
//				}
//			}
//
//			cout << endl;
//		}

		if(answer.first == 2000000){
			cout << "You will never meet.";
		}
		else{
			cout << answer.first;

			for(char i : answer.second){
				cout << " " << i;
			}
		}

		cout << endl;
	}

	cout << endl;

	return 0;
}
