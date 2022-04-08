//
// Created by haewonny on 2022-04-08.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * [N번째 큰 수]
 *
 * 메모리 제한이 있으므로, 입력값을 모두 저장하면 안된다.
 * 상위 n개만 저장하는 "최소" 힙을 만들어서 heap[0]을 현재까지의 N번째 큰수로 유지하는 풀이
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, input; // n, input 선언
    priority_queue<int, vector<int>, greater<>> pq; // 최소 힙, 정렬이랑 반대

    cin >> n;
    int size = n * n; // n*n의 표에는 수가 n^2개 채워져 있음
    while (size--) { // 채워진 수만큼 반복
        // 입력
        cin >> input;

        // 연산
        pq.push(input); // pq에 input 추가
        if (pq.size() > n) { // 최소 힙의 크기가 n 이상이라면
            pq.pop(); // 가장 작은 값 삭제
        }
    }

    // 출력
    cout << pq.top();
    return 0;
}
