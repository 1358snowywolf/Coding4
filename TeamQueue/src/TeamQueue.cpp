#include <bits/stdc++.h>

using namespace std;

int main(){
	int N;
	int scenario = 1;

	while(true){
		cin >> N;
		if(N == 0) break;

		map<int, queue<int>> groups;  //subgroup of line
		map<int, int> teams;        // dictionary
		queue<int> line;     // big queue

		for(int i = 0; i < N; i++){
			int amount;
			cin >> amount;

			for(int j = 0; j < amount; j++){
				int person;
				cin >> person;
				teams.insert(make_pair(person, i));
			}
		}

		string command;
		cin >> command;
		int number;

		cout << "Scenario #" << scenario << endl;

		while(command != "STOP"){
			if(command == "ENQUEUE"){
				cin >> number;
				if(groups.find(teams[number]) == groups.end()){
					queue<int> input;
					input.push(number);
					groups.insert(make_pair(teams[number], input));
					line.push(teams[number]);
				}
				else{
					groups[teams[number]].push(number);
				}
			}
			else{
				int front = line.front();
				int answer = groups[front].front();
				groups[front].pop();

				if(groups[front].empty()){
					groups.erase(front);
					line.pop();
				}

				cout << answer << endl;
			}

			cin >> command;
		}

		cout << endl;
		scenario++;
	}

	return 0;
}
