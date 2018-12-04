#include <bits/stdc++.h>

using namespace std;

int findParents(int u, vector<int>& parents){
	return ((parents[u] == u) ? u : parents[u] = findParents(parents[u], parents));
}

void connect(int u, int v, vector<int>& parents){
	int x = findParents(u, parents);
	int y = findParents(v, parents);

	parents[x] = y;
}

int main() {
	int C;
	cin >> C;
	string statement;
	int u, v;

	for(int times = 0; times < C; times++){
		int N;

		if(times == 0){
			cin >> N;
		}
		else{
			N = stoi(statement);
		}

//		cout << "N: " << N << endl;

		vector<int> parents;
		pair<int, int> answered = make_pair(0, 0);

		for(int i = 0; i < N; i++){
			parents.push_back(i);
		}

		while(cin >> statement){
			if(isdigit(statement[0])) break;
			cin >> u >> v;
//			cout << u << " " << v << endl;
			u--;
			v--;

			if(statement == "c"){
				connect(u, v, parents);
			}
			else{
				if(findParents(u, parents) == findParents(v, parents)){
					answered.first++;
				}
				else{
					answered.second++;
				}
			}
		}


		cout << answered.first << "," << answered.second << endl << endl;
	}

	return 0;
}
