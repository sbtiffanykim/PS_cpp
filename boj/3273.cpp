// 3273_두 수의 합
// https://www.acmicpc.net/problem/3273

#include <bits/stdc++.h>
using namespace std;

int occur[2000001] = {};  // 입력받은 숫자 기록

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x, ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        occur[tmp]++;
    }
    cin >> x;
    // 총 절반 앞쪽에 대해서 더하면 x가 되는 (i, x-i)가 존재할 경우
    for (int i = 1; i < (x + 1) / 2; ++i) {
        if (occur[i] == 1 && occur[x - i] == 1) ans++;
    }
    cout << ans;
}