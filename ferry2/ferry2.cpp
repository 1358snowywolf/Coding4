//
//  main.cpp
//  FerryLoadingIV
//
//  Created by Isabella Duan on 11/24/18.
//  Copyright © 2018 Isabella Duan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(int argc, const char * argv[]) {
    int C;
    cin >> C;
    
    for(int times = 0; times < C; times++){
        int length, N;
        cin >> length >> N;
        length *= 100;
        queue<int> left, right;
        
        for(int i = 0; i < N; i++){
            int l;
            string position;
            cin >> l >> position;
            
            if(position == "left"){
                left.push(l);
            }
            else{
                right.push(l);
            }
        }
        
        vector<queue<int>> banks = {left, right};
        int place = 0, count = 0;
        
//        auto one = banks[0];
//        auto two = banks[1];
//
//        while(!one.empty()){
//            cout << one.front() << " ";
//            one.pop();
//        }
//        cout << endl;
//        while(!two.empty()){
//            cout << two.front() << " ";
//            two.pop();
//        }
//        cout << endl << ".........................." << endl;

        
        while(!banks[0].empty() || !banks[1].empty()){
            int size = 0;
//            cout << place << ": " << banks[place].size() << endl;

            while(!banks[place].empty() && (size + banks[place].front()) <= length){
                size += banks[place].front();
                banks[place].pop();
//                cout << place << ": " << banks[place].size() << endl;
//                cout << "size : " << size << endl;
            }
            
            count++;
            place = (place + 1) % 2;
        }
        
        cout << count << endl;
    }
    
    return 0;
}

