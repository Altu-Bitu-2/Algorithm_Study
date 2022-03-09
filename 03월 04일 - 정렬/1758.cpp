//
// Created by haewonny on 2022-03-09.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, tip;
    long long result = 0;

    // 입력 - 스타박스 앞에 있는 사람의 수
    cin >> N;

    vector<int>arr(N);

    for(int i = 0; i < N; i++) // 팁 입력
        cin >> arr[i];

    // 연산
    sort(arr.begin(), arr.end(), greater<>());

    // 출력 - 강호가 받을 수 있는 팁의 최댓값(내림차순 정렬해야 팁 높음)
    for(int i = 0; i < N; i++){
        tip = arr[i] - i; // 팁 : (원래 주려고 생각한 가격) - (받은 등수 - 1) -> i가 0부터 시작하니까 그냥 빼도 됨
        if(tip < 0)
<<<<<<< Updated upstream
            break; // 내림차순 정렬 되어 있는 상황에서 앞사람이 이미 음수이면, 뒷사람은 자동으로 음수니까 break!
=======
            break; // 내림차순으로 정렬했을 때 앞사람이 이미 음수면, 뒷사람도 자동으로 음수니까 break
>>>>>>> Stashed changes
        result += tip;
    }

    cout << result;
}
