#include <bits/stdc++.h>

using namespace std;

bool prime(int number){
	for(int i = 2; i <= sqrt(number); i++){
		if(number % i == 0) return false;
	}

	return true;
}

void DFS(vector<int> ring, vector<bool> visited, int current, int index, int N){
	if(index == N - 1){
		if(prime(ring[0] + ring[N - 1] + 2)){
			for(int i = 0; i < N - 1; i++){
				cout << ring[i] + 1 << " ";
			}

			cout << ring[N - 1] + 1 << endl;
//			reverse(ring.begin(), ring.end());
//
//			for(int i = 0; i < N - 1; i++){
//				cout << ring[i] + 1 << " ";
//			}
//
//			cout << ring[N - 1] + 1 << endl;
		}

		return;
	}

	visited[current] = true;
	index++;

//	for(int i = 0; i < (int) ring.size(); i++){
//		cout << ring[i] + 1 << " ";
//	}
//	cout << endl;

//	cout << current << " ";

	for(int i = 0; i < N; i++){
		if(visited[i]) continue;
		if(!prime(current + i + 2)) continue;

//		cout << current << "->" << i << endl;

		ring.push_back(i);
		DFS(ring, visited, i, index, N);
		ring.pop_back();
	}
}

int main() {
	int N;
	int index = 1;

	while(cin >> N){
		cout << "Case " << index << ":" << endl;

		vector<bool> visited (N, false);
		vector<int> ring;
		ring.push_back(0);

		DFS(ring, visited, 0, 0, N);

		cout << endl;
		index++;
	}

	return 0;
}
