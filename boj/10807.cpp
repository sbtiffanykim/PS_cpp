// 10807_개수 세기
// https://www.acmicpc.net/problem/10807
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, v;
    int occur[201] = {};

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        occur[tmp + 100]++;
    }
    cin >> v;
    cout << occur[v + 100];
}