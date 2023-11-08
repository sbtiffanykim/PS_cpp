// 1475_방 번호
// https://www.acmicpc.net/problem/1475
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, num[10] = {}, ans = 0;
    cin >> n;

    // 자릿수 저장
    while (n > 0) {
        num[n % 10]++;
        n /= 10;
    }
    // 가장 많이 사용된 자릿수 개수
    for (int i = 0; i < 10; ++i) {
        if (i == 6 || i == 9) continue;
        ans = max(ans, num[i]);
    }
    // 6, 9는 서로 바꿔 쓸 수 있으므로 해당 경우의 수 고려
    ans = max(ans, (num[6] + num[9] + 1) / 2);
    cout << ans;
}