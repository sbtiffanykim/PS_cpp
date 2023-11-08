/// 2577_숫자의 개수

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int nums[10] = {};
    int a, b, c;
    cin >> a >> b >> c;
    int t = a * b * c;
    while (t > 0)
    {
        nums[t % 10]++;
        t /= 10;
    }
    for (int i = 0; i < 10; ++i)
        cout << nums[i] << '\n';
    return 0;
}