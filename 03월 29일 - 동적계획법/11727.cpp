//
// Created by haewonny on 2022-04-03.
//
#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    int n;
    cin >> n;

    int dp[1000];

    // 초기값 설정
    dp[0] = 0; // 2x0 직사각형을 만드는 방법의 수는 0개
    dp[1] = 1; // 2x1 직사각형을 만드는 방법의 수는 1개
    dp[2] = 3; // 2x2 직사각형을 만드는 방법의 수는 3개

    // 연산
    for(int i = 3; i <= n; i++){
        dp[i] = (dp[i - 1] + dp[i - 2] * 2)%10007;
    }

    // 출력 - 2xn 크기의 직사각형을 채우는 방법의 수를 10007로 나눈 나머지
    cout << dp[n];

}
