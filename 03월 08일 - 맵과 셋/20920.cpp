//
// Created by haewonny on 2022-03-12.
//
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> voca; // 단어장 역할
map<string, int> m; // 단어의 빈도수 저장하는 맵

bool cmp(const string &a, const string &b) {
    /*
      단어장의 단어 순서
      1. 자주 나오는 단어일수록 앞에 배치한다.
      2. 해당 단어의 길이가 길수록 앞에 배치한다.
      3. 알파벳 사전 순으로 앞에 있는 단어일수록 앞에 배치한다.
     */
    if (a.size() == b.size() && m[a] == m[b]) { // 두 문자열의 길이와 빈도수가 같으면
        return a < b; // 알파벳 사전순
    } else if (m[a] == m[b]) {  // 두 문자열의 빈도수만 같다면
        return a.size() > b.size(); // 단어의 길이가 길수록
    }
    return m[a] > m[b]; // 자주 나오는 단어일수록 앞에
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    string v;
    // 입력 - 영어 지문에 나오는 단어의 개수 N, 외울 단어의 길이 기준 M
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> v; // 단어 입력
        if (v.size() < M) // 단어의 길이가 M 미만이면 다음 단어 입력 받음 -> M 이상인 단어만 외우려고
            continue;
        else if (m.find(v) == m.end()) { // m.find() : 데이터를 끝까지 찾지 못했을 경우 m.end() 반환 --> 입력한 데이터가 처음
            m[v] = 0;  // 빈도수 0
            voca.push_back(v); // push_back() : 벡터의 끝에 요소 추가
        }
        m[v]++; // 입력받은 단어가 단어장에 있으면 횟수 더하기
    }
    sort(voca.begin(), voca.end(), cmp);

    // 출력
    for (int i = 0; i < voca.size(); i++)
        cout << voca[i] << "\n";
}
