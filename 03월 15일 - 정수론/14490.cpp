//
// Created by haewonny on 2022-03-19.
//
#include <iostream>
#include <cstdio>

using namespace std;

// 유클리드 호제법 - 최대공약수 빠르게 찾기
int GCD(int a, int b){
    if(a % b == 0)
        return b;

    return GCD(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력 - n:m 형태
    int n, m, res;
    scanf("%d:%d", &n, &m);

    res = GCD(n, m);

    // 출력
    cout << n / res << ":" << m / res;

}