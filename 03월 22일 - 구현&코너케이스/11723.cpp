//
// Created by haewonny on 2022-03-28.
//
#include <iostream>
#include <set>
#include <string>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    set<int> s;
    set<int> all = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

    // 입력 - 수행해야 하는 연산의 수
    int M;
    cin >> M;

    while(M--){
        string op;
        int n;

        cin >> op;

        if(op != "all" && op != "empty"){ // all, empty가 아닐 때만 n 입력 받기
            cin >> n;
        }

        if(op == "add"){ // add : s에 n 추가
                s.insert(n);
        }
        else if(op == "remove"){ // remove : s에서 n 제거
                s.erase(n);
        }
        else if(op == "check"){
            if(s.find(n) != s.end()){ // s에 n이 있으면 1 출력
                cout << 1 << '\n';
            }
            else // 없으면 0 출력
                cout << 0 << '\n';
        }
        else if(op == "toggle"){
            if(s.find(n) != s.end()){ // s에 n 있으면 n 제거
                s.erase(n);
            }
            else // 없으면 n 추가
                s.insert(n);
        }
        else if(op == "all"){
            s = all;
        }
        else if(op == "empty"){
            s.clear(); // 다 비우기
        }
    }

}
