//
// Created by haewonny on 2022-04-01.
//
#include <iostream>
#include <vector>

using namespace std;

const int INF_MAX = 1e9; // 가장 큰 값
const int SIZE = 11; // 최대 개수 11개

int n; // n 선언

vector<int> num(SIZE + 1); // 크기가 12인 num 벡터 선언
vector<int> expression(4); // 0: +, 1: -, 2: *, 3: /
int max_value = -INF_MAX, min_value = INF_MAX; // max값과 min값 설정

void backtracking(int cnt, int sum) { // cnt: 수 인덱스, sum: 연산 결과
    if (cnt == n - 1) { // 연산 모두 완료했다면 (기저조건)
        max_value = max(max_value, sum); // 최댓값
        min_value = min(min_value, sum); // 최솟값
        return;
    }
    for (int i = 0; i < 4; i++) { // 연산자 검사
        if (expression[i]) { // i번째 연산자가 존재하면
            expression[i]--; // 하나씩 감소
            int new_sum = 0; // 새로운 합 0
            switch (i) { // 연산자 종류에 따라
                case 0: // 0 이면 +
                    new_sum = sum + num[cnt + 1]; // 다음 숫자 더하기
                    break;
                case 1: // 1 이면 -
                    new_sum = sum - num[cnt + 1]; // 다음 숫자 빼기
                    break;
                case 2: // 2 이면 *
                    new_sum = sum * num[cnt + 1]; // 다음 숫자 곱하기
                    break;
                case 3: // 3 이면 /
                    new_sum = sum / num[cnt + 1]; // 다음 숫자 나누기
                    break;
            }
            backtracking(cnt + 1, new_sum); // 다음 숫자로
            expression[i]++; // 백트래킹
        }
    }
}

/**
 * 연산자 모두 돌려보면서 배치한 후, 각 연산자에 따른 값 계산
 */

int main() {
    // 입력
    cin >> n;

    for (int i = 0; i < n; i++) { // n만큼 num 입력 받기
        cin >> num[i];
    }
    for (int i = 0; i < 4; i++) { // 연산자 4개 입력 받기
        cin >> expression[i];
    }

    // 연산
    backtracking(0, num[0]);

    // 출력
    cout << max_value << '\n' << min_value;
    return 0;
}
