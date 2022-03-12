//
// Created by haewonny on 2022-03-12.
//
#include <iostream>
#include <map>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, N, M;
    // 입력 1 - 테스트 케이스의 개수 T
    cin >> T;
    while (T--) {
        // 입력 2 - '수첩 1'에 적어 놓은 정수의 개수
        cin >> N;
        map<int, int> m; // Map : 다양한 자료형의 형태를 key-value 값으로 저장

        for (int i = 0; i < N; i++) {
            int a;
            // 입력 2-1 - '수첩 1'에 적혀 있는 정수 N개
            cin >> a;
            m[a] = 1;
        }
        // 입력 3 - '수첩 2'에 적어 놓은 정수의 개수
        cin >> M;
        for (int i = 0; i < M; i++) {
            int b;
            // 입력 3-1 - '수첩 2'에 적혀 있는 정수 M개
            cin >> b;

            // 출력 - '수첩 2'에 적혀있는 M개의 순서대로, '수첩 1'에 있으면 1, 없으면 0
            if (m[b] == 1) // '수첩 2'에 존재할 때
                cout << "1\n";
            else // '수첩 2'에 존재하지 않을 때
                cout << "0\n";
        }
    }
}