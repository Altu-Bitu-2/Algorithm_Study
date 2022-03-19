//
// Created by haewonny on 2022-03-16.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.second != b.second) {
        return a.second > b.second;
    }
    else
        return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    double sum = 0;

    vector<int> v;
    map<int, int> m;

    // 입력
    cin >> N;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        v.push_back(num);
        m[num]++;
        sum += num;
    }
    sort(v.begin(), v.end()); // 중앙값 구하기 위해 오름차순 정렬

    vector<pair<int, int>> freq(m.begin(), m.end()); // 값, 빈도수 저장
    sort(freq.begin(), freq.end(), cmp);

    // 1. 산술평균 출력 - 소수점 이하 첫째 자리에서 반올림한 값을 출력
//    double avg = sum / N;
//    if(avg > -0.5 && avg < 0) cout << round(avg + 0.5) << '\n';
//    else cout << round(avg) << '\n';
    cout << floor(sum / N + 0.5) << '\n';

    // 2. 중앙값 출력
    cout << v[N / 2] << '\n';

    // 3. 최빈값 출력 - 여러 개 있을 때에는 최빈값 중 두 번째로 작은 값을 출력
    if (freq[0].second == freq[1].second) {
        cout << freq[1].first << '\n';
    } else {
        cout << freq[0].first << '\n';
    }

    // 4. 범위 출력
    cout << v[N - 1] - v[0] << '\n'; // 범위
}