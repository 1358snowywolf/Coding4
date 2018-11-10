#include <bits/stdc++.h>

using namespace std;
set<pair<int, int>> visited;
int max1 = 5;
int max2 = 2;
int aim = 4;

pair<int, int> pour(int amount1, int amount2){
	if(amount1 + amount2 <= max1){
		return make_pair(amount1 + amount2, 0);
	}

	int pouring = (amount1 + amount2) % max1;

	return make_pair(max1, pouring);
}

bool waterJugSolver(int amount1, int amount2){
	if(amount1 == aim || amount2 == aim){
		return true;
	}

	if(visited.find(make_pair(amount1, amount2)) != visited.end()){
		return false;
	}

	visited.insert(make_pair(amount1, amount2));

	bool answer = waterJugSolver(0, amount2); // dump first
	answer |= waterJugSolver(amount1, 0); // dump second
	answer |= waterJugSolver(max1, amount2);
	answer |= waterJugSolver(amount1, max2);

	pair<int, int> first = pour(amount1, amount2);
	pair<int, int> second = pour(amount2, amount1);

	answer |= waterJugSolver(first.first, first.second);
	answer |= waterJugSolver(second.first, second.second);

	return answer;
}

int main() {
	cout << ((waterJugSolver(0, 0)) ? "true" : "false") << endl;
	return 0;
}
