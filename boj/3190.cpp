// 3190_뱀
// https://www.acmicpc.net/problem/3190

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[105][105];  // 1: 사과, 2: 뱀
int n, k, l;
int a, b, x;
char c;
int dx[4] = {0, 1, 0, -1};  // 뱀 머리 방향 => [0]: E, [1]: S, [2]: W, [3]: N
int dy[4] = {1, 0, -1, 0};  // 뱀 머리 방향 => [0]: E, [1]: S, [2]: W, [3]: N
deque<pair<int, int>> snake;
queue<pair<int, char>> dirChange;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> k;
    while (k--) {
        cin >> a >> b;
        board[a][b] = 1;  // 사과 위치 저장
    }
    cin >> l;
    while (l--) {
        cin >> x >> c;
        dirChange.push({x, c});  // 회전 시간, 방향 저장
    }
    snake.push_front({1, 1});

    int time = 0;  // 시간 기록
    int dir = 0;   // 뱀 머리 방향 => [0]: E, [1]: S, [2]: W, [3]: N

    while (1) {
        auto cur = snake.front();
        board[cur.X][cur.Y] = 2;
        // 1. 몸 길이 늘리기(머리 좌표 이동)
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        // 2. 벽이나 자기 몸 치면 끝내기
        // 이동 후 부딪히므로 지금까지의 시간에 1 더해 반환
        if (nx < 1 || nx > n || ny < 1 || ny > n || board[nx][ny] == 2) break;
        // 3-1. 이동한 칸에 사과 있으면 사과 먹기
        if (board[nx][ny] == 1) board[nx][ny] = 2;
        // 3-2. 이동한 칸에 사과 없으면 꼬리길이 줄이기
        else if (board[nx][ny] != 1) {
            auto tail = snake.back();
            board[tail.X][tail.Y] = 0;
            snake.pop_back();
            board[nx][ny] = 2;
        }
        snake.push_front({nx, ny});  // 이동 후 뱀 좌표 저장
        // 4. 시간 증가
        time++;

        // 5. 회전 후 새로 머리방향 설정
        auto dc = dirChange.front();
        if (dc.X == time) {
            if (dc.Y == 'D')
                dir = (dir + 1) % 4;
            else if (dc.Y == 'L')
                dir = (dir + 3) % 4;
            dirChange.pop();
        }
    }
    cout << time + 1;
}