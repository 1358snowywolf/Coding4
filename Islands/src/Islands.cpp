#include <bits/stdc++.h>

using namespace std;

int count(vector<int> heights, int current){
	bool part = false;
	int total = 0;

	for(int i = 0; i < (int) heights.size(); i++){
		if(heights[i] > current){
			if(part == false){
				part = true;
				total++;
			}
		}
		else{
			part = false;
		}
	}

	return total;
}

int main() {
	int N;
	cin >> N;
	vector<int> heights;

	for(int i = 0; i < N; i++){
		int input;
		cin >> input;
		heights.push_back(input);
	}

	int maximum = 0;

	for(int i = 0; i < N; i++){
		maximum = max(maximum, count(heights, i));
	}

	cout << maximum << endl;

	return 0;
}
