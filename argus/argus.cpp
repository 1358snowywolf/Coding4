#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int main(int argc, const char * argv[]) {
    string str;
//    vector<pair<int, int>> queries;  // period, number
    map<int, int> queries; //number, period
    
    while(true){
        cin >> str;
        if(str == "#") break;
        
        int number, period;
        cin >> number >> period;
        queries.insert({number, period});
    }
    
    int K;
    cin >> K;
    priority_queue<pair<int, int>> pq;  //make negative!
    
    for(auto i : queries){
        pq.push(make_pair(i.second * -1, i.first * -1));
    }
    
    int count = 0;
    
    while(count < K){
        auto top = pq.top(); pq.pop();
        pq.push(make_pair(((top.first * -1) + queries[top.second * -1]) * -1, top.second));
        cout << top.second * -1 << endl;
        count++;
    }
    
    cout << endl;
    
    return 0;
