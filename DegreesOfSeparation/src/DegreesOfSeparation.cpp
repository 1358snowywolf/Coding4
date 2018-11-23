#include <bits/stdc++.h>

using namespace std;

int main() {
	int P, R;
	int times = 1;

	while(true){
		cin >> P >> R;

		if(P == 0 && R == 0){
			break;
		}

		int index = 0;
		map<string, int> names;
		vector<vector<int>> graph (P, vector<int> (P, 2000000));

		for(int i = 0; i < R; i++){
			string str, str1;
			cin >> str >> str1;

			if(names.find(str) == names.end()){
				names.insert(make_pair(str, index++));
			}
			if(names.find(str1) == names.end()){
				names.insert(make_pair(str1, index++));
			}

			graph[names[str]][names[str1]] = 1;
			graph[names[str1]][names[str]] = 1;
		}

		for(int i = 0; i < P; i++){
			graph[i][i] = 0;
		}

		for(int k = 0; k < P; k++){
			for(int i = 0; i < P; i++){
				for(int j = 0; j < P; j++){
					graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
				}
			}
		}

		int maximum = 0;

		for(int i = 0; i < P; i++){
			for(int j = i + 1; j < P; j++){
				maximum = max(maximum, graph[i][j]);
			}
		}

		cout << "Network " << times << ": ";

		if(maximum == 2000000){
			cout << "DISCONNECTED";
		}
		else{
			cout << maximum;
		}

		cout << endl << endl;
		times++;
	}

	return 0;
}
