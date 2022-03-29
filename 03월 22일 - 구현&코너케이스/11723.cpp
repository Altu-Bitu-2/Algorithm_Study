//
// Created by haewonny on 2022-03-28.
//
#include <iostream>
#include <set> // set을 사용하면 O(logN)의 시간복잡도
#include <vector> // 벡터를 사용하는 것이 좋음
#include <string>

using namespace std;
const int SIZE = 21;
/**
 * [집합] - 단순 구현 문제
 *
 * ver1. 배열 사용 풀이
 * set()을 사용해서 매번 연산을 하면 시간이 굉장히 오래 걸려요.
 * 입력되는 x의 값이 1~20으로 범위가 매우 작기 때문에, 각 숫자가 집합에 들어있는 여부를 저장하는 배열을 이용합니다.
 *
 * 1. 집합에는 1~20의 숫자만 입력 or 제거됨 (=true or false)
 * 2. 크기 21의 bool 배열을 선언
 * 3. 입력은 true 처리, 제거는 false 처리
 */
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

//    set<int> s;
//    set<int> all = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    vector<bool> s(SIZE, false);

    // 입력 - 수행해야 하는 연산의 수
    int M;
    cin >> M;

    while(M--){
        string op;
        int num;

        cin >> op;

        // num을 입력받지 않아도 되는 경우들
        if (op == "all") {
            s.assign(SIZE, true);
            continue;
        }
        if (op == "empty") {
            s.assign(SIZE, false);
            continue;
        }

        // num을 입력받아야 하는 경우들
        cin >> num;

        if (op == "add") { // add : num 추가
            s[num] = true; // 입력은 true 처리
            continue;
        }
        if (op == "remove") { // remove : num 제거
            s[num] = false; // 제거는 false 처리
            continue;
        }
        if (op == "check") {
            cout << s[num] << '\n'; // bool 형을 출력하면 true: 1, false: 0으로 출력
            continue;
        }
        if (op == "toggle") {
            s[num] = !s[num];
            continue;
        }
//        if(op != "all" && op != "empty"){ // all, empty가 아닐 때만 n 입력 받기
//            cin >> n;
//        }
//
//        if(op == "add"){ // add : s에 n 추가
//                s.insert(n);
//        }
//        else if(op == "remove"){ // remove : s에서 n 제거
//                s.erase(n);
//        }
//        else if(op == "check"){
//            if(s.find(n) != s.end()){ // s에 n이 있으면 1 출력
//                cout << 1 << '\n';
//            }
//            else // 없으면 0 출력
//                cout << 0 << '\n';
//        }
//        else if(op == "toggle"){
//            if(s.find(n) != s.end()){ // s에 n 있으면 n 제거
//                s.erase(n);
//            }
//            else // 없으면 n 추가
//                s.insert(n);
//        }
//        else if(op == "all"){
//            s = all;
//        }
//        else if(op == "empty"){
//            s.clear(); // 다 비우기
//        }
    }

}
