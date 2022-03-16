//
// Created by haewonny on 2022-03-16.
//
#include <iostream>
#include <stack>
/*
 ** 만약, 어떤 줄의 프렛을 여러 개 누르고 있다면, 가장 높은 프렛의 음이 발생한다.
  ==> 낮은 프렛을 연주하고 싶으면, 앞에 눌러져있는 모든 프렛을 떼어야 함
 */
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력 - 멜로디에 포함되어 있는 음의 수 N, 한 줄에 있는 프렛의 수 P
    int N, P, cnt = 0;
    cin >> N >> P;
    stack<int> s[P];
    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b; // a는 줄의 번호, b는 그 줄에서 눌러야 하는 프렛 번호

        while(!s[a].empty()){
            if(s[a].top() > b){ // 이미 눌린 것이 눌러야 하는 프렛 번호보다 큰 경우
                cnt++;
                s[a].pop(); // 가장 위 프렛 제거
            }
            else
                break;
        }

        if(!s[a].empty()){
            if(s[a].top() == b) // 이미 누른 상태
                continue;
        }

        s[a].push(b); // 안 누른 경우
        cnt++;
    }

    // 출력 - 첫째 줄에 멜로디를 연주하는데 필요한 최소 손가락 움직임
    cout << cnt;
}
