//
// Created by haewonny on 2022-03-16.
//
#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    queue<int> q;

    // 입력
    cin >> N >> K;
    for(int i = 1; i <= N; i++)
        q.push(i); // 큐의 뒤에 원소를 추가

    // 출력
    cout << "<";
    while (!q.empty()) { // 큐가 비어있지 않은 동안
        for (int i = 0; i < K - 1; i++) {
            q.push(q.front()); // K - 1까지의 값을 큐의 뒤에 넣기
            q.pop();
        }

        cout << q.front();
        q.pop(); // K번째 수 pop

        if (!q.empty()) {
            cout << ", ";
        }

    }
    cout << ">" << endl;
}
