#include <bits/stdc++.h>

using namespace std;
set<pair<int, int>> works;

//bool check(int first, int N){
//	set<int> numbers;
//	int
//	int index = 0;
//
//	while(first != 0){
//		int remainder = first % 10;
//		numbers.insert(remainder);
//		remainder /= 10;
//		index++;
//	}
//
//	if(index < 5){
//		numbers.insert(0);
//	}
//	index = 0;
//
//	while(second != 0){
//		int remainder = second % 10;
//		numbers.insert(remainder);
//		remainder /= 10;
//	}
//
//	if(index < 5){
//		numbers.insert(0);
//	}
//
//	if(numbers.size() == 10){
//		return true;
//	}
//	else{
//		return false;
//	}
//}
//
//void recursion(int first, int second, int size, int N){
//	if(size == 10){
//		if(check(first, second)){
//			works.push_back(make_pair(first, second));
//		}
//		return;
//	}
//
//	if(size < 5){
//		for(int i = 0; i < 10; i++){
//			int backup = first;
//			backup = (backup * 10) + i;
//			recursion(backup, second, size + 1, N);
//		}
//	}
//	else{
//		for(int i = 0; i < 10; i++){
//			int backup = second;
//			backup = (backup * 10) + i;
//			recursion(first, backup, size + 1, N);
//		}
//	}
//}
//
//pair<bool, int> check(int second, int N){
//	int first = N * second;
//	pair<bool, int> answer = make_pair(false, 0);
//
//	if(first / second != N){
//		return answer;
//	}
//
//	answer.first = true;
//	answer.second = second;
//
//	return answer;
//}
//
//void recursion(int second, int size, int N){
//	if(size == 5){
//		pair<bool, int> c = check(second, N);
//
//		if(c.first){
//			works.insert(make_pair(c.second, second));
//		}
//
//		return;
//	}
//}

void check(int denominator, int N){
	int numerator = N * denominator;
	set<int> numbers;

	if(numerator >= 100000){
		return;
	}

	if(numerator < 10000 || denominator < 10000){
		numbers.insert(0);
	}

	int tmp = denominator;

	while(tmp != 0){
		int remainder = tmp % 10;
		numbers.insert(remainder);
		tmp /= 10;
	}

	tmp = numerator;

	while(tmp != 0){
		int remainder = tmp % 10;
		numbers.insert(remainder);
		tmp /= 10;
	}

	if(numbers.size() == 10){
		works.insert(make_pair(numerator, denominator));
	}
}

int main() {
	int N;
	while(cin >> N){
		works.clear();
		if(N == 0){
			break;
		}

		for(int denominator = 1234; denominator <= 98765; denominator++){
			check(denominator, N);
		}

		if(works.size() == 0){
			cout << "There are no solutions for " << N << "." << endl;
		}
		else{
			for(auto i : works){
//				cout << i.first << " / " << i.second << " = " << N << endl;
				string f = to_string(i.first);
				string s = to_string(i.second);

				if(f.size() == 5 && s.size() == 5){
					cout << f << " / " << s << " = " << N << endl;
				}
				else{
					if(f.size() <= 4){
						f = "0" + f;
					}
					if(s.size() <= 4){
						s = "0" + s;
					}

					cout << f << " / " << s << " = " << N << endl;
				}
			}
		}

		cout << endl;
	}

	return 0;
}
