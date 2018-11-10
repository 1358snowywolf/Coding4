#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, C;
  cin >> N >> C;
  vector<pair<int, int>> A(N);

  for (int i = 0; i < N; i++) {
	  int X, Y;
	  cin >> X >> Y;
	  A[i] = make_pair(X, Y);
  }

  long long result = 0;
  vector<bool> used(N, false);
  vector<int> D(N, INT_MAX);
  D[0] = 0;

  for (int i = 0; i < N; i++) {
    int j = -1;
    for (int k = 0; k < N; k++) {
      if (used[k]) continue;
      if (j == -1 || D[k] < D[j]) {
        j = k;
      }
    }


	result += D[j];
    used[j] = true;

    for (int k = 0; k < N; k++) {
    	if(j == k){
    		continue;
    	}

    	int distance = (A[k].first - A[j].first) * (A[k].first - A[j].first) + (A[k].second - A[j].second) * (A[k].second - A[j].second);

    	if(distance < C){
    		distance = INT_MAX;
    	}

    	D[k] = min(D[k], distance);
    }
  }

  for(int i = 0; i < (int) D.size(); i++){
	  if(D[i] == INT_MAX){
		  cout << -1 << endl;
		  return 0;
	  }
  }

  cout << result << endl;

  return 0;
}
