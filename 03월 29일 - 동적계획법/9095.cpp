//
// Created by haewonny on 2022-04-03.
//
#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력 1 - 테스트 케이스의 개수 T
    int T;
    cin >> T;

    int dp[11];
    // 초기값 설정
    dp[0] = 0;
    dp[1] = 1; //1
    dp[2] = 2; //1+1, 2
    dp[3] = 4; //1+1+1, 1+2, 2+1, 3

    while(T--){
        // 입력 2 - 정수 n (0 < n < 11)
        int n;
        cin >> n;

        // 연산
        for(int i = 4; i <= n; i++){
            dp[i] = (dp[i - 3] + dp[i - 2] + dp[i - 1]);
        }

        // 출력
        cout << dp[n] << "\n";
    }

}
