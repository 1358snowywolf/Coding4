#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	vector<int> height (N, 0);

	for(int i = 0; i < K; i++){
		int start, end;
		cin >> start >> end;
		start--;
		end--;

		for(int i = start; i <= end; i++){
			height[i]++;
		}
	}

	sort(height.begin(), height.end());

	cout << height[height.size() / 2] << endl;

	return 0;
}
