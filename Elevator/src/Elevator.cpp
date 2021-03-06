#include <bits/stdc++.h>

using namespace std;

map<int, vector<pair<int, int>>> makeGraph(vector<vector<int>> elevators, vector<int> speed){
	map<int, vector<pair<int, int>>> graph;

//	cout << "size " << elevators.size() << endl;

//	for(int i = 0; i < (int) elevators.size(); i++){
//		graph.insert(make_pair((i * 100) + elevators[i][0], vector<pair<int, int>> ()));
//		int previous = elevators[i][0];
//
//		for(int j = 1; j < (int) elevators[i].size(); j++){
//			int current = elevators[i][j] + (i * 100);
//			graph[(i * 100) + previous].push_back(make_pair(current, (current - previous) * speed[i]));
//			graph.insert(make_pair(current, vector<pair<int, int>> ()));
//
////			for(int k = i - 1; k >= 0; k++){
////				if(graph.find((k * 100) + elevators[i][j]) != graph.end()){
////					graph[(k * 100) + elevators[i][j]].push_back(make_pair(current, 60));
////				}
////			}
//
//			previous = current;
//		}
//	}

	map<int, vector<int>> numbers;

	for(int i = 0; i < 100; i++){
		numbers.insert(make_pair(i, vector<int> ()));
	}

	for(int i = 0; i < (int) elevators.size(); i++){
		for(int j = 0; j < (int) elevators[i].size(); j++){
			graph.insert(make_pair(elevators[i][j] + (i * 100), vector<pair<int, int>> ()));
			numbers[elevators[i][j]].push_back(elevators[i][j] + (i * 100));
		}
	}

	for(int i = 0; i < (int) elevators.size(); i++) {
		for (int j = 0; j < (int) elevators[i].size() - 1; j++){
			graph[elevators[i][j] + (i * 100)].push_back(
					make_pair(elevators[i][j + 1] + (i * 100),
							(elevators[i][j + 1] - elevators[i][j]) * speed[i]));
			graph[elevators[i][j + 1] + (i * 100)].push_back(
					make_pair(elevators[i][j] + (i * 100),
							(elevators[i][j + 1] - elevators[i][j]) * speed[i]));

		}
	}

	for(auto i : numbers){
		if(i.second.size() == 0) continue;

		for(auto j : i.second){
			for(auto k : i.second){
				if(j == k) continue;

				graph[j].push_back(make_pair(k, 60));
			}
		}
	}

//	for(auto i : numbers){
//		cout << i.first << " ";
//
//		for(int j : i.second){
//			cout << j << " ";
//		}
//
//		cout << endl;
//	}

	return graph;
}

vector<int> Dijkstra(map<int, vector<pair<int, int>>> graph, vector<vector<int>> elevators, int start){
	priority_queue<pair<int, int>> pq;
	vector<int> distance (100 * (elevators.size() + 1), 1076000);
	pq.push(make_pair(0, start));
	distance[start] = 0;

	while(!pq.empty()){
		auto front = pq.top();
		pq.pop();

		if(front.first * -1 > distance[front.second]){
			continue;
		}

		for(auto n : graph[front.second]){
            if(distance[front.second] + n.second < distance[n.first]){
                distance[n.first] = distance[front.second] + n.second;
                pq.push({distance[n.first] * -1, n.first});
            }
		}
	}

	return distance;
}

int main() {
	int N, K;

	while(cin >> N){
		cin >> K;
		vector<vector<int>> elevators;
		vector<int> speed;

		for(int i = 0; i < N; i++){
			int s;
			cin >> s;
			speed.push_back(s);
		}

		cin.ignore();

		for(int i = 0; i < N; i++){
			int tmp;
			string line;
			getline(cin, line);
			istringstream iss(line);
			vector<int> input;

			while(iss >> tmp){
				input.push_back(tmp);
			}

			sort(input.begin(), input.end());
			elevators.push_back(input);
		}

		auto graph = makeGraph(elevators, speed);
		int minimum = INT_MAX;

		for(int i = 0; i < (int) elevators.size(); i++){
			if(elevators[i][0] == 0){
				auto distance = Dijkstra(graph, elevators, i * 100);

				for(int i = 0; i < (int) elevators.size(); i++){
					minimum = min(minimum, distance[(i * 100) + K]);
				}
//				cout << i << " :" << minimum << endl;

//				for(int i = 0; i < (int) distance.size(); i++){
//					cout << distance[i] << " ";
//				}
//
//				cout << endl;
//
//				minimum = min(minimum, distance[(i * 100) + K]);
			}
		}

//		auto distance = Dijkstra(graph, elevators, 0);

//
//		for(auto i : graph){
//			cout << i.first << ": ";
//
//			for(auto j : i.second){
//				cout << "(" << j.first << ", " << j.second << ") ";
//			}
//
//			cout << endl;
//		}

//		int minimum = INT_MAX;
//
//		for(int i = 0; i < (int) distance.size() / 100; i++){
//			minimum = min(minimum, distance[K + (i * 100)]);
//		}

//		cout << minimum << endl;

		if(minimum == INT_MAX || minimum == 1076000){
			cout << "IMPOSSIBLE" << endl;
		}
		else{
			cout << minimum << endl;
		}
	}

	cout << endl;

	return 0;
}
