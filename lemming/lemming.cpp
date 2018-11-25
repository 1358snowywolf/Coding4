#include <iostream>
#include <utility>
#include <vector>
#include <set>

using namespace std;

int main(int argc, const char * argv[]) {
    int C;
    cin >> C;
    
    for(int times = 0; times < C; times++){
        int B, SG, SB;
        cin >> B >> SG >> SB;
        multiset<int> green, blue;
        
        for(int i = 0; i < SG; i++){
            int input;
            cin >> input;
            green.insert(input * -1);
        }
        for(int i = 0; i < SB; i++){
            int input;
            cin >> input;
            blue.insert(input * -1);
        }
        
        while(!blue.empty() && !green.empty()){
            vector<pair<int, int>> battlefield;
            
            for(int i = 0; i < B; i++){
                if(green.empty() && blue.empty()){
                    break;
                }
                
                if(green.empty() && !blue.empty()){
                    battlefield.push_back({*blue.begin() * -1, 0});
                    blue.erase(blue.begin());
                }
                else if(blue.empty() && !green.empty()){
                    battlefield.push_back({0, *green.begin() * -1});
                    green.erase(green.begin());
                }
                else{
                    battlefield.push_back({*blue.begin() * -1, *green.begin() * -1});
                    blue.erase(blue.begin());
                    green.erase(green.begin());
                }
            }
            
            for(int i = 0; i < (int) battlefield.size(); i++){
//                cout << battlefield[i].first << " VS " << battlefield[i].second << endl;
                
                if(battlefield[i].first > battlefield[i].second){  // blue > green
                    blue.insert((battlefield[i].first - battlefield[i].second) * -1);
                }
                else if(battlefield[i].first < battlefield[i].second){
                    green.insert((battlefield[i].second - battlefield[i].first) * -1);
                }
            }
            
//            for(int i : blue){
//                cout << i * -1 << " ";
//            }
//            cout << endl;
//            for(int i : green){
//                cout << i * -1 << " ";
//            }
//            cout << endl << ".................................." << endl;
        }
        
        if(blue.empty() && green.empty()){
            cout << "green and blue died" << endl;
        }
        else if(blue.empty()){
            cout << "green wins" << endl;
            
            for(int i : green){
                cout << i * -1 << endl;
            }
        }
        else{
            cout << "blue wins" << endl;
            
            for(int i : blue){
                cout << i * -1 << endl;
            }
        }
        
        cout << endl;
    }
    
    return 0;
}

