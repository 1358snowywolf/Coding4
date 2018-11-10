#include <bits/stdc++.h>

using namespace std;
//
//int findMin(vector<pair<string, int>> descending, string str){
//	for(int i = 0; i < (int) descending.size(); i++){
//		if(str[0] < descending[i].first[0]){
//			return i;
//		}
//		else if(str[0] == descending[i].first[0]){
//			int index = 0;
//
//			while(str[index] == descending[i].first[index]){
//				index++;
//			}
//
//			if(str[index] < descending[i].first[index]){
//				return i;
//			}
//		}
//	}
//
//	return (int) descending.size() - 1;
//}
//
//int findMax(vector<pair<string, int>> ascending, string str){
//	for(int i = 0; i < (int) ascending.size(); i++){
//		if(str[0] > ascending[i].first[0]){
//			return i;
//		}
//		else if(str[0] == ascending[i].first[0]){
//			int index = 0;
//
//			while(str[index] == ascending[i].first[index]){
//				index++;
//			}
//
//			if(str[index] > ascending[i].first[index]){
//				return i;
//			}
//		}
//	}
//
//	return (int) ascending.size() - 1;
//}

int main() {
	ifstream fin ("scramble.in");
	ofstream fout ("scramble.out");

	int N;
	fin >> N;
	vector<string> original;
	vector<string> ascending;
	vector<string> descending;

	for(int i = 0; i < N; i++){
		string str;
		fin >> str;
		auto str2 = str;
		original.push_back(str);
		sort(str.begin(), str.end());
		sort(str2.rbegin(), str2.rend());

		ascending.push_back(str);
		descending.push_back(str2);
	}


	sort(ascending.begin(), ascending.end());
	sort(descending. begin(), descending.end());

	vector<pair<int, int>> answers (N, make_pair(0, 0));

//
//	for(int i = 0; i < N; i++){
//		cout << ascending[i].first << " ";
//	}
//
//	cout << endl;
//
//	for(int i = 0; i < N; i++){
//		cout << descending[i].first << " ";
//	}
//
//	cout << endl;
//
//	for(int i = 0; i < N; i++){
//		int index = findMin(descending, ascending[i].first);
//		answers[ascending[i].second].first = index;
//
//		index = findMax(ascending, descending[i].first);
//		answers[descending[i].second].second = index;
//	}
//
//	for(int i = 0; i < (int) answers.size(); i++){
//		cout << answers[i].first + 1 << " " << answers[i].second + 1 << endl;
//	}

	for(int i = 0; i < N; i++){
		string l = original[i];
		string h = original[i];
		sort(l.begin(), l.end());
		sort(h.rbegin(), h.rend());

		auto lower = lower_bound(descending.begin(), descending.end(), l) - descending.begin() + 1;
		auto higher = upper_bound(ascending.begin(), ascending.end(), h) - ascending.begin();

//		cout << original[i] << " " << lower << " " << higher << endl;

		answers[i].first = lower;
		answers[i].second = higher;
//		int lower = lower_bound(descending.begin(), descending.end(), ascending[i]);
//		int upper = upper_bound(ascending.begin(), ascending.end(), descending[i]);
	}

	for(int i = 0; i < (int) answers.size(); i++){
		fout << answers[i].first << " " << answers[i].second << endl;
	}

	return 0;
}
