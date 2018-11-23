#include <bits/stdc++.h>

using namespace std;

int main() {
	int C;
	cin >> C;
	string line;

//

	for(int times = 0; times < C; times++){
		map<string, int> trees;
		line == "";
		int total_size = 0;

		while(line.length() == 0) {
			getline(cin, line);
		}

		while(line != ""){
			trees[line]++;
			total_size ++;
			getline(cin, line);
		}

		for(auto i : trees){
			cout << i.first << " ";
			cout << fixed << setprecision(4) << 100 * (float) i.second / (float) total_size << endl;
		}

		cout << endl;
	}

	return 0;
}
