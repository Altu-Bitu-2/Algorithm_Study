//
// Created by haewonny on 2022-03-16.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> v;
    deque<int> deq;

    // 입력
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        long long num;
        cin >> num;
        v.push_back(num);
    }
    int input = 1;

    reverse(v.begin(), v.end()); // 원소들의 순서 역순으로 뒤집기

    for(int i = 0; i < N; i++) {
        if(v[i] == 1) { // 기술 1. 제일 위의 카드 1장을 바닥에 내려놓는다
            deq.push_back(input);
        }
        else if(v[i] == 2) { // 기술 2. 위에서 두 번째 카드를 바닥에 내려놓는다. 카드가 2장 이상일 때만 쓸 수 있다.
            int temp = deq[deq.size() - 1];
            deq.pop_back(); // 덱에 제일 뒤에 있는 원소 삭제
            deq.push_back(input); // 덱의 뒤에 원소 추가
            deq.push_back(temp);
        }
        else if(v[i] == 3) { // 기술 3. 제일 밑에 있는 카드를 바닥에 내려놓는다. 카드가 2장 이상일 때만 쓸 수 있다.
            deq.push_front(input); // 덱의 앞에 원소 추가
        }
        input++;
    }
    // 출력 - 초기 카드의 상태를 위에서부터 순서대로 출력
    while(!deq.empty()) { // 덱이 비어있지 않은 동안
        cout << deq[deq.size() - 1] << ' ';
        deq.pop_back();
    }
}

