//
// Created by haewonny on 2022-03-19.
//
#include <iostream>
#include <string>

using namespace std;

// 유클리드 호제법 - 최대공약수 빠르게 찾기
int GCD(int a, int b){
    if(a % b == 0)
        return b;

    return GCD(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력 - n:m 형태
    string s;
    cin >> s;

    int a = 0, b = 0, temp = 1;

    while(1){
        if(s[temp] == ':'){
            // substr(a, b) : a번째 문자부터 b길이 만큼의 문자열 리턴
            a = stoi(s.substr(0, temp)); // stoi() : string to int
            b = stoi(s.substr(temp + 1, s.length()));
            break;
        }
        temp++;
    }

    int res = GCD(a, b);

    // 출력
    cout << a / res << ":" << b / res;
}