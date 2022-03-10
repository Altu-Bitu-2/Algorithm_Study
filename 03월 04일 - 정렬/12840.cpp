//
// Created by haewonny on 2022-03-09.
//
#include <iostream>
#define DAY 86400 // 24시간은 86400초

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int h, m, s, q, T, c;
    // 입력
    cin >> h >> m >> s; // 초기 현재 시간 입력
    cin >> q; // 쿼리의 개수 입력 -> q의 숫자만큼 T 입력 받기

    int cur = h * 3600 + m * 60 + s; // 전체 시간 초로 표현

    for (int i = 0; i < q; i++) {
        cin >> T;
        switch (T) {
            case 1: // c를 입력으로 받아서 시계를 앞으로 c초 돌리기
                cin >> c;
                cur = (cur + c) % DAY;
                break;
            case 2: // c를 입력으로 받아서 시계를 뒤로 c초 돌리기
                cin >> c;
                cur = (cur - c) % DAY;
                if(cur < 0) cur += DAY; // 현재 시간이 음수이면 86400 더해서 양수로 만들어야 함
                break;
            case 3: // 창용이가 조작한 시계의 상황 출력
                cout << cur / 3600 << " " << (cur / 60) % 60 << " " << cur % 60 << "\n";
                break;
        }
    }
}

