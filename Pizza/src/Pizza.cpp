#include <bits/stdc++.h>

using namespace std;
vector<string> toppings;
string answer;

bool works(set<char> current){
	for(int i = 0; i < (int) toppings.size(); i++){
		bool fits = false;
//		int fits = 0;

		for(int j = 0; j <= (int) toppings[i].size() - 2; j += 2){
			bool contains = (toppings[i][j] == '+');
			char food = toppings[i][j + 1];

			if(contains){
				if(current.find(food) != current.end()){
//					fits++;
					fits = true;
					break;
				}
			}
			else{
				if(current.find(food) == current.end()){
//					fits ++;
					fits = true;
					break;
				}
			}
		}


//		if(fits == (int) toppings[i].size()){
//			return true;
//		}
		if(!fits){
//			cout << i << endl;
			return false;
		}
	}

	return true;
}

void DFS(set<char> current, string actual, int index){
//	cout << actual << endl;

	if(index == 16){
//		cout << actual << endl;
//		if(actual == "CELP"){
//			cout << actual << endl;
//		}
		if(works(current)){
//			cout << answer << endl;
			if(actual.size() < answer.size() || (actual.size() == answer.size() && actual[0] < answer[0])){
				answer = actual;
			}
		}

		return;
	}

	DFS(current, actual, index + 1);
	current.insert((char) 'A' + index);
//	actual += ('0' + ('A' + index));
	actual += ((char) 'A' + index);
	DFS(current, actual, index + 1);
}

int main() {
	string input;

	while(cin >> input){
		toppings.clear();
		answer = "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP";

		while(input != "."){
			input.erase(input.begin() + input.size() - 1);
			toppings.push_back(input);
			cin >> input;
		}

		set<char> current;
//		current.insert('C');
//		current.insert('E');
//		current.insert('L');
//		current.insert('P');

		DFS(current, "", 0);

		if(answer != "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP"){
			sort(answer.begin(), answer.end());
			cout << "Toppings: " << answer << endl;
		}
		else{
			cout << "No pizza can satisfy these requests." << endl;
		}
	}

	return 0;
}
