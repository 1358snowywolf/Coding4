#include <bits/stdc++.h>

using namespace std;

int main() {
	string cargo;
	int index = 1;

	while(true){
		cin >> cargo;
		if(cargo == "end") break;

		vector<char> stacks;

		for(int i = 0; i < (int) cargo.size(); i++){
			bool found = false;

			for(int j = 0; j < (int) stacks.size(); j++){
				if(stacks[j] >= cargo[i]){
					stacks[j] = cargo[i];
					found = true;
					break;
				}
			}

			if(!found){
				stacks.push_back(cargo[i]);
			}
		}

		cout << "Case " << index << ": " << stacks.size() << endl;
		index++;
	}

	return 0;
}
