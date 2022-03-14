//
// Created by haewonny on 2022-03-13.
//
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;

    vector<string> file;
    map<string, int> m; // 맵은 key값을 정렬된 상태로 저장

    // 입력 - 바탕화면에 있는 파일의 개수
    cin >> N;
    for (int i = 0; i < N; i++) {
        string name;
        cin >> name; // 바탕화면에 있는 파일의 이름 입력
        name.erase(0, name.find('.') + 1);
        if(m.find(name) == m.end()){
            m[name] = 0;
            file.push_back(name);
        }
        m[name]++;
    }

    // 출력
    for (auto f : m)
        cout << f.first << " " << f.second << "\n";

}

