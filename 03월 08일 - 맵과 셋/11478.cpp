//
// Created by haewonny on 2022-03-13.
//
#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    set<string> set;

    string s;
    // 입력 - 소문자로만 이루어진 문자열 s
    cin >> s;

    string str = "";

    for(int i = 0; i < s.size(); i++){
        for(int j = i; j < s.size(); j++){
            str += s[j];
            set.insert(str);
        }
        str = "";
    }
    // 출력 - 서로 다른 부분 문자열의 개수
    cout << set.size();

}
