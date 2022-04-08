//
// Created by haewonny on 2022-04-08.
//
#include <iostream>
#include <set>

using namespace std;

/**
 * set 풀이
 *
 * set은 중복값이 제거되기 때문에 multiset을 이용하여 저장해야 함
 * multiset 또한 값을 넣으면 정렬이 바로 되기 때문에 이후의 정렬 과정이 따로 필요 없음
 */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t, k, n; // t(테스트 데이터 개수), k(연산의 개수), n(정수 n)
    char cmd; // 연산을 나타내는 문자 - D 또는 I

    cin >> t; // 테스트 데이터 개수 입력
    while (t--) { // 테스트 데이터 개수만큼 반복
        multiset<int> ms; // 중복 저장
        cin >> k; // 연산의 개수 입력 받기
        while (k--) { // 연산의 개수만큼 반복
            // 입력
            cin >> cmd >> n;

            // 연산
            switch (cmd) { // cmd값에 따라 연산하기(switch-case문)
                case 'I': // I 연산 - 정수 n을 Q에 삽입
                    ms.insert(n); // ms에 n 삽입
                    break;
                case 'D': // D 연산 - Q에서 최댓값 삭제(D 1), Q에서 최솟값 삭제(D -1)
                    if (ms.empty()) { // ms가 비어있다면 연산 무시
                        break;
                    }
                    if (n == 1) { // n이 1이면
                        ms.erase(--ms.end()); // 최댓값 삭제
                    }
                    if (n == -1) { // n이 -1이면
                        ms.erase(ms.begin()); // 최솟값 삭제
                    }
                    break;
            }
        }

        // 출력
        if (ms.empty()) // ms가 비어있으면
            cout << "EMPTY\n";
        else // ms가 비어있지 않으면
            cout << *(--ms.end()) << ' ' << *ms.begin() << '\n'; // Q에 남아있는 값 중 최댓값과 최솟값 출력
    }
}
