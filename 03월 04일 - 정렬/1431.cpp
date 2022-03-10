//
// Created by haewonny on 2022-03-09.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string& a, const string& b){
    // 조건 1. A와 B의 길이가 다르면, 짧은 것이 먼저 온다.
    if(a.length() != b.length())
        return a.length() < b.length();
    // 조건 2. 만약 서로 길이가 같다면, 자리수의 합이 작은 것이 먼저 온다.
    else{
        int aSum = 0, bSum = 0;

        for(int i = 0; i < a.length(); i++){ // 길이가 같음
            if(a[i] >= '0' && a[i] <= '9')
                aSum += a[i] - '0'; // A 자리수의 합
            if(b[i] >= '0' && b[i] <= '9')
                bSum += b[i] - '0'; // B 자리수의 합
        }
        /*
          '0'을 빼주는 이유!
          a[i] 요소가 문자 '1'이라면 아스키코드로는 49, 문자 '0'은 아스키코드 48이라
          49 - 48을 해서 정수형 1을 얻을 수 있다.
         */
        if(aSum != bSum)
            return aSum < bSum;
    }
    // 조건 3. 1, 2 조건으로 비교할 수 없으면, 사전순으로 비교
    return a < b;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;

    // 입력
    cin >> N;
    vector <string> arr(N);

    for(int i = 0; i < N; i++)
        cin >> arr[i];

    // 연산
   sort(arr.begin(), arr.end(), cmp); // 마지막 인자는 비교함수 -> 원하는 조건대로 정렬

    // 출력 - N개의 줄에 시리얼 번호 정렬한 결과
    for(int i = 0; i < N; i++)
        cout << arr[i] << "\n";

}
