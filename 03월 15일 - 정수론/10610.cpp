//
// Created by haewonny on 2022-03-19.
//
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
/*
 < 30의 배수 조건 >
 1. 각 자리수의 합이 3의 배수
 2. 끝이 0이어야 함
 */
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력 - 길거리에서 우연히 발견한 양수 N
    string N;
    cin >> N;

    long long sum = 0;

    sort(N.begin(), N.end(), greater<>()); // 내림차순 정렬
    for(auto o : N){
        sum += o - '0';
    }

    // 출력 - 미르코가 만들고 싶어하는 수 출력, 존재하지 않으면 -1 출력
    if (N[N.length() - 1] != '0' || sum % 3 != 0) // 끝자리가 0이 아님
        cout << -1 << "\n";
    else {
        cout << N << "\n";
    }
}
