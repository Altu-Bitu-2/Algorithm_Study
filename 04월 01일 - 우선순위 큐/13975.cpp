//
// Created by haewonny on 2022-04-08.
//
#include <iostream>
#include <queue>

using namespace std;
typedef long long ll;

ll getCost(priority_queue<ll, vector<ll>, greater<>> &pq) { // 모든 장을 합치는데 필요한 최소비용을 구하는 함수
    ll ans = 0; // 최소 비용 ans

    while (pq.size() > 1) { // pq의 크기가 1보다 큰 동안
        ll card1 = pq.top(); // card1에 가장 작은 값 넣기
        pq.pop(); // 삭제
        ll card2 = pq.top(); // card2에 두번째로 작은 값 넣기
        pq.pop(); // 삭제
        ans += card1 + card2; // 최소 비용에 card1 + card2
        pq.push(card1 + card2); // pq에 추가
    }
    return ans;
}

/**
 * [파일 합치기 3]
 *
 * - 파일을 전부 합치기 위해서는 어차피 하나로 만들어야 한다!
 * - 이 때, 여러번 더해지는 값은 작을 수록 좋다
 * - 따라서, 현재 가장 작은 파일 2개를 합쳐야 비용을 최소화 할 수 있다.
 * -> 최소 힙으로 구현
 *
 * !주의! 파일의 개수는 최대 1,000,000이고 각 크기의 최대는 10,000이므로
 *       정답의 최댓값이 10^10으로 int 범위를 넘기 때문에 long long 써야 함
 */

int main() {
    int t, k, file; // t(t개의 테스트 케이스), k(소설을 구성하는 장의 수), file(파일의 크기)

    // 입력
    cin >> t;
    while (t--) { // 테스트 케이스의 수만큼 반복
        priority_queue<ll, vector<ll>, greater<>> pq; // 최소힙

        // 입력
        cin >> k;
        for (int i = 0; i < k; i++) { // k만큼 반복
            cin >> file; // 장의 수만큼 파일의 크기 입력
            pq.push(file);  // pq에 추가
        }

        // 연산 & 출력
        cout << getCost(pq) << '\n';
    }
    return 0;
}
