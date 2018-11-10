#include <bits/stdc++.h>

using namespace std;

string make(int i){
	string answer = "m";

	for(int j = 0; j < i; j++){
		answer += "o";
	}

	return answer;
}

int main() {
	int N;
	cin >> N;
	string use = "moo";
	string actual = use;
	int i = 1;

	while(actual.size() < N){
		use = make(i + 2);
//		actual += use;

		actual = actual + use + actual;
		i++;
	}

	cout << actual[N - 1] << endl;
	return 0;
}
