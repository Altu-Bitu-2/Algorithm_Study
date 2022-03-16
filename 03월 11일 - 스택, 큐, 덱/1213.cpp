//
// Created by haewonny on 2022-03-16.
//
// 팰린드롬 : 역순으로 읽어도 같은 말이 되는 말
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    string name;
    cin >> name;

    vector<int> a(26, 0); // 알파벳의 등장횟수 저장

    for (int i = 0; i < name.size(); i++) {
        a[name[i] - 'A']++;
    }

    string m; // 팰린드롬 가운데 부분
    for (int i = 0; i < 26; i++) {
        if (a[i] % 2 == 1) { // 알파벳 등장횟수가 홀수일 때
            m.push_back('A' + i);
        }
    }

    string A; // 완성된 팰린드롬

    if (m.length() <= 1) { // 가운데 부분이 1 이하여야 팰린드롬을 만들 수 있음
        string f;
        for (int i = 0; i < 26; i++) {
            f += string(a[i] / 2, 'A' + i);
        }
        string b(f.rbegin(), f.rend());
        A = f + m + b;
    }

    // 출력
    if (m.length() > 1)
        cout << "I'm Sorry Hansoo\n";
    else
        cout << A << "\n";
}
