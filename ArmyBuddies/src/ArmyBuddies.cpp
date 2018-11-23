#include <bits/stdc++.h>

using namespace std;

pair<int, int> connect(set<pair<int, int>>& killed, int left, int right){
	auto itr = lower_bound(killed.begin(), killed.end(), make_pair(left, right));
	pair<int, int> input = make_pair(left, right);
	auto previous = prev(itr);

	bool delete_itr = false;
	bool delete_previous = false;

	if(input.second + 1== itr->first){
		input.second = itr->second;
		delete_itr = true;
	}
	if(input.first - 1 == previous->second){
		input.first = previous->first;
		delete_previous = true;
	}

	if(delete_itr){
		killed.erase(itr);
	}
	if(delete_previous){
		killed.erase(previous);
	}

	killed.insert(input);
	return make_pair(input.first - 1, input.second + 1);
}

int main() {
	int S, B;

	while(true){
		cin >> S >> B;

		if(S == 0 && B == 0){
			break;
		}

		set<pair<int, int>> killed;
		killed.insert(make_pair(0, 0));
		killed.insert(make_pair(S + 1, S + 1));

		for(int i = 0; i < B; i++){
			int left, right;
			cin >> left >> right;

			auto newBuddies = connect(killed, left, right);

			if(killed.size() == 1){
				cout << "* *" << endl;
			}
			else{
				if(newBuddies.first < 1){
					cout << "* ";
				}
				else{
					cout << newBuddies.first << " ";
				}

				if(newBuddies.second > S){
					cout << "*" << endl;
				}
				else{
					cout << newBuddies.second << endl;
				}
			}
		}

		cout << "-" << endl;
	}

	return 0;
}
