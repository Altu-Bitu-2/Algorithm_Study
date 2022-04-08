//
// Created by haewonny on 2022-04-08.
//
#include <iostream>
#include <queue>

using namespace std;

/**
 * [크리스마스 선물] - 단순 구현 문제
 *
 * - 0이 나올 때마다, 가지고 있는 선물 중 가장 가치가 큰 것을 삭제 & 출력 -> 최대 힙 필요
 */

int main() {
    int n, a, input; // n(아이들과 거점지를 방문한 횟수), a(거점지에서 충전하는 선물 개수), input(선물의 가치)
    priority_queue<int> pq; // 최대 힙

    // 입력
    cin >> n;
    while (n--) { // n만큼 반복
        cin >> a; // 거점지에서 충전하는 선물의 개수
        if (!a) { // 아이들을 만난 경우 - 선물 충전 안 하니까
            if (pq.empty()) { // 줄 선물이 없다면
                cout << "-1\n"; // -1 출력
            } else { // 줄 선물이 있다면
                cout << pq.top() << '\n'; // 가장 가치가 준 선물 주기
                pq.pop(); // 선물 지우기
            }
        } else { // 선물을 충전하는 경우
            while (a--) { // a만큼 반복
                cin >> input; // 선물의 가치 입력 받기
                pq.push(input); // 원소 추가
            }
        }
    }
    return 0;
}
