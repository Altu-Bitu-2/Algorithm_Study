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

    // vector 컨테이너 : 자동으로 메모리가 할당되는 배열
    vector<int> arr(21); // 21개의 원소 vector arr 생성(1번부터 시작해서)

    // 1부터 20까지 오름차순으로 놓인 카드들
    for (int i = 1; i <= 20; i++) {
        arr[i] = i;
    }

    // 입력 - 뒤집을 구간 입력 (10개의 구간)
    for (int i = 0; i < 10; i++) {
        int start, end;
        cin >> start >> end;

        while (start < end)
            swap(arr[start++], arr[end--]);
    }

    // 출력
    for (int i = 1; i <= 20; i++) {
        cout << arr[i] << " ";
    }
}