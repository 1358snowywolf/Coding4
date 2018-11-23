#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, M;

	while(cin >> N){
		if(N == 0){
			break;
		}

		cin >> M;
		vector<int> front;
		vector<int> back;

		for(int i = 0; i < N; i++){
			int teeth;
			cin >> teeth;
			front.push_back(teeth);
		}

		for(int i = 0; i < M; i++){
			int teeth;
			cin >> teeth;
			back.push_back(teeth);
		}

		vector<float> answers;

		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				answers.push_back((float) back[j] / front[i]);
			}
		}

		sort(answers.begin(), answers.end());
		float maximum = 0.00;

		for(int i = 0; i < (int) answers.size() - 1; i++){
			maximum = max(maximum, (float) answers[i + 1] / answers[i]);
//			cout << (float) answers[i + 1] / answers[i] << endl;
//			cout << answers[i] << endl;
		}

//		cout << answers[answers.size() - 1] << endl;

		cout << fixed << setprecision(2) << maximum << endl;
	}

	return 0;
}
