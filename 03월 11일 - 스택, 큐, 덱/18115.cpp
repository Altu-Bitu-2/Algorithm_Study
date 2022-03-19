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

    reverse(v.begin(), v.end()); // 원소들의 순서 역순으로 뒤집기
// 풀이 1. if else문 이용 ->  조건의 개수(N)에 따라 O(N) 시간에 실행
//    for(int i = 0; i < N; i++) {
//        if(v[i] == 1) { // 기술 1. 제일 위의 카드 1장을 바닥에 내려놓는다
//            deq.push_back(i + 1);
//        }
//        else if(v[i] == 2) { // 기술 2. 위에서 두 번째 카드를 바닥에 내려놓는다. 카드가 2장 이상일 때만 쓸 수 있다.
//            int temp = deq[deq.size() - 1];
//            deq.pop_back(); // 덱에 제일 뒤에 있는 원소 삭제
//            deq.push_back(i + 1); // 덱의 뒤에 원소 추가
//            deq.push_back(temp);
//        }
//        else if(v[i] == 3) { // 기술 3. 제일 밑에 있는 카드를 바닥에 내려놓는다. 카드가 2장 이상일 때만 쓸 수 있다.
//            deq.push_front(i + 1); // 덱의 앞에 원소 추가
//        }
//    }

// 풀이 2. switch-case문 이용 -> O(1) 만에 실행
    for(int i = 0; i < N; i++){
        switch(v[i]){
            case 1:
                deq.push_back(i + 1);
                break;
            case 2: {
                int temp = deq[deq.size() - 1];
                deq.pop_back(); // 덱에 제일 뒤에 있는 원소 삭제
                deq.push_back(i + 1); // 덱의 뒤에 원소 추가
                deq.push_back(temp);
                break;
            }
            case 3:
                deq.push_front(i + 1);
                break;
        }
    }
    // 출력 - 초기 카드의 상태를 위에서부터 순서대로 출력
    while(!deq.empty()) { // 덱이 비어있지 않은 동안
        cout << deq[deq.size() - 1] << ' ';
        deq.pop_back();
    }
}

