//
// Created by haewonny on 2022-03-19.
//
#include <iostream>
#include <math.h>
/*
  서로소 a, b / 최대공약수 G / 최소공배수 L
  L = G * a * b
  L / G = a * b
 */
using namespace std;

int GCD(int a, int b){
    if(a % b == 0)
        return b;

    return GCD(b, a % b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력 - G(어떤 두 개의 자연수의 최대공약수), L(그 자연수들의 최소공배수)
    int G, L, a, b;
    cin >> G >> L;

    int temp = L / G; // 두 자연수의 곱

//    for(int i = 1; i <= sqrt(temp); i++) {
//        if (temp % i == 0 && GCD(i, temp / i) == 1) { // 약수의 짝이 서로소
//            a = i * G;
//            b = (temp / i) * G;
//        }
//    }
    // **최적화 -> 반복문의 시작점을 잘 설정하면 한번에 찾은 값이 최솟값
    for(int i = sqrt(temp); i > 0; i--) {
        if (temp % i == 0 && GCD(i, temp / i) == 1) { // 약수의 짝이 서로소
            a = i * G;
            b = (temp / i) * G;
            break;
        }
    }
    cout << a << ' ' << b;
}
