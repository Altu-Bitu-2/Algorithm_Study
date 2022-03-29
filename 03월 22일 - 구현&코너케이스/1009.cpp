//
// Created by haewonny on 2022-03-28.
//
#include <iostream>
#include <cmath>

#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력 - 테스트 케이스의 개수 T
    int T;
    cin >> T;

    while (T--) {
        ll a, b, res;
        // 입력 - 총 데이터의 개수는 a^(b) 형태
        cin >> a >> b;

        res = a;

        // 계산 + 출력 - 각 테스트 케이스에 대해 마지막 데이터가 처리되는 컴퓨터의 번호 출력
        if (b % 4 == 0)
            b = 4;
        else
            b %= 4;

        res = pow(a, b);

        if (res % 10 == 0) // 끝이 0이면 항상 10번 컴퓨터
            cout << 10 << '\n';
        else
            cout << res % 10 << '\n'; // 일의자리가 컴퓨터
    }
}

