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

    string S, E, Q; // HH:MM 형식이라 int가 아니라 string

    set<string> s;
    set<string> attend;
    // 입력 1 - 개총 시작 시간, 개총 끝난 시간, 개총 스트리밍 시간
    cin >> S >> E >> Q;

    while(true){
        // 입력 2 - 채팅 기록들
        string time, name;
        cin >> time >> name;

        if(time == "" && name == "")
            break;
        if(time <= S){ // 개강총회 시작 전에 입장
            s.insert(name); // 학생 이름 기록
            continue;
        }
        if(time <= Q && time >= E) { // 개강총회 끝과 스트리밍 끝 사이
            if (s.find(name) != s.end()) { // 개강총회 시작 전에 입장한 사람 이름이 있다면
                attend.insert(name); // 출석으로 기록
                continue;
            }
        }
    }
    // 출력 - 출석이 확인된 인원 수
    cout << attend.size() << "\n";
}
