//
// Created by haewonny on 2022-04-03.
//
#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> dp(1001);
    vector<int> A(1001);

    // 입력 1 - 수열의 크기 N
    int N;
    cin >> N;

    // 입력 2 - 수열
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    // 연산
    int ans = 0;

    for(int i = 0; i < N; i++){
        dp[i] = 1; // 초기값은 1
        for (int j = 0; j < i; j++) {
            if (A[i] > A[j])
                dp[i] = max(dp[i], dp[j] + 1); // 증가하는 수열
        }
        ans = max(ans, dp[i]); // 가장 긴 것
    }

    // 출력
    cout << ans << "\n";
}

