//
// Created by haewonny on 2022-03-13.
//
#include <iostream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    int t;
    cin >> t;

    int n;
    string type, name;

    while(t--){
        map<string, int> m;
        cin >> n; // 의상의 수
        while(n--){
            cin >> name >> type;
            if(m.find(type) == m.end())
                m.insert({type, 1});
            else
                m[type]++; // 빈도수 증가
        }

        int res = 1;
        for(auto i : m){
            res *= (i.second + 1);
        }

        res -= 1; // (의상의 종류 + 1(안 입은 경우)) * (의상의 종류 + 1(안 입은 경우)) - 1(둘 다 안 입은 경우)
        // 출력 - 알몸이 아닌 상태로 의상을 입을 수 있는 경우
        cout << res << "\n";
    }
}
