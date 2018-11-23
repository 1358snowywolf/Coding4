#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int>> side = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

pair<int, int> spiral(int size, int position){
	int move = 1;
	int index = 1;
	int direction = 0;
	int i = size / 2;
	int j = i;
	int times = 0;

	while(index < position){
		for(int k = 0; k < move; k++){
			i += side[direction % 4].first;
			j += side[direction % 4].second;
			index++;

			if(index == position){
				return make_pair(i + 1, j + 1);
			}
		}

		direction++;
		times++;

		if(times == 2){
			times = 0;
			move++;
		}
	}

	return make_pair(i + 1, j + 1);
}

int main() {
	int size, position;

	while(true){
		cin >> size >> position;

		if(size == 0 && position == 0){
			continue;
		}

		auto answer = spiral(size, position);

		cout << "Line = " << answer.first << ", column = " << answer.second << "." << endl;
	}

	return 0;
}
