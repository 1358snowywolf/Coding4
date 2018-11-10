#include <bits/stdc++.h>

using namespace std;
set<pair<int, int>> location;

void make(string current){
	int i = 0, j = 0;
	string direction = "north";

	for(int index = 0; index < (int) current.size(); index++){
		if(current[index] == 'F'){
			if(direction == "north"){
				i++;
			}
			else if(direction == "left"){
				j--;
			}
			else{
				j++;
			}
		}
		else if(current[index] == 'L'){
			direction = "left";
		}
		else{
			direction = "right";
		}
	}

	if(i == 0 && j == 0){
		return;
	}

	location.insert(make_pair(i, j));
}

void DFS(string current, string directions, int index){
	if(current.size() == directions.size()){
		if(current != directions){
			make(current);
		}
		return;
	}

	string backup = current;
	string backup2 = current;
	current += "R";
	DFS(current, directions, ++index);
	backup += 'L';
	DFS(backup, directions, index);
	backup2 += 'F';
	DFS(backup2, directions, index);
}

int main() {
	string directions;
	cin >> directions;

	DFS("", directions, 0);

	cout << location.size() << endl;

	return 0;
}
