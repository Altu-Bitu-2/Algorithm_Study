//
// Created by haewonny on 2022-03-09.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, S = 0;

    // 입력
    cin >> N;
    vector<int> A(N);
    vector<int> B(N);

    for(int i = 0; i < N; i++)
        cin >> A[i];
    for(int i = 0; i < N; i++)
        cin >> B[i];

    // 연산
    sort(A.begin(), A.end()); // 오름차순 정렬(default)
    sort(B.begin(), B.end(), greater<>()); // 내림차순 정렬

    // 출력 - S의 최솟값 출력
    for(int i = 0; i < N; i++)
        S += A[i] * B[i]; // A는 작은 수부터 시작하고, B는 큰 수부터 시작해야 곱했을 때 최소가 됨

    cout << S;


}
