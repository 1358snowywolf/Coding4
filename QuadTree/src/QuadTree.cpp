#include <bits/stdc++.h>

using namespace std;

int cur;

struct node {
    int size;
    char color;
    node* child[4];
};

node* parse(string s) {
    node* res = new node();

    if (s[cur] == 'f') {
        res->color = 'f';
        cur++;
    }
    else if (s[cur] == 'e') {
        res->color = 'e';
        cur++;
    }
    else{
        res->color = 'p';
        cur++;
        res->child[0] = parse(s);
        res->child[1] = parse(s);
        res->child[2] = parse(s);
        res->child[3] = parse(s);
    }

    return res;
}

node* combine(node* first, node* second){
	node* answer = new node();

	if(first->color == 'f' || second->color == 'f'){
		answer->color = 'f';
	}
	else{
		if(first->color == 'e'){
			answer = second;
		}
		else if(second->color == 'e'){
			answer = first;
		}
		else{
			auto one = combine(first->child[0], second->child[0]);
			auto two = combine(first->child[1], second->child[1]);
			auto three = combine(first->child[2], second->child[2]);
			auto four = combine(first->child[3], second->child[3]);

			if(one->color == 'f' && two->color == 'f' && three->color == 'f'&& four->color == 'f'){
				answer->color = 'f';
			}
			else{
				answer->color = 'p';
				answer->child[0] = one;
				answer->child[1] = two;
				answer->child[2] = three;
				answer->child[3] = four;
			}
		}
	}

	return answer;
}

int count(node* result, int width){
	int black = 0;

	if(result->color == 'f'){
		return width * width;
	}
	else if(result->color == 'p'){
		black += count(result->child[0], width >> 1);
		black += count(result->child[1], width >> 1);
		black += count(result->child[2], width >> 1);
		black += count(result->child[3], width >> 1);
	}

	return black;
}

int main() {
	int C;
	cin >> C;

	for(int times = 0; times < C; times++){
		cur = 0;
		string o, t;
		cin >> o >> t;

		auto first = parse(o);
		cur = 0;
		auto second = parse(t);

		auto result = combine(first, second);

		int black = count(result, 32);
		cout << "There are " << black << " black pixels." << endl;
	}

	return 0;
}
