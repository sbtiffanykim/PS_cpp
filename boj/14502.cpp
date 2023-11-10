// 14502_연구소
// https://www.acmicpc.net/problem/14502

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[8][8];
int n, m, ans;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<pair<int, int>> blank;
queue<pair<int, int>> virus;

// 바이러스 전파를 탐색하는 함수
int bfs() {
    queue<pair<int, int>> q;
    int vis[8][8] = {};
    int virus_cnt = 0;  // 바이러스 수 세기 위한 변수
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (board[i][j] == 2) q.push({i, j});

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        virus_cnt++;
        for (int i = 0; i < 4; ++i) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            // 전파 가능한 좌표일 경우
            // 여러번 탐색해야 하므로 board자체의 값은 바꾸지 않음
            if (!vis[nx][ny] && board[nx][ny] == 0) {
                vis[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
    return virus_cnt;
}

// depth번째 벽을 세운 후 idx번째 빈칸에 대해 탐색하는 함수
void dfs(int depth, int idx) {
    // 벽 3개 다 세운 경우
    if (depth == 3) {
        int tmp = bfs();  // 바이러스 전파 탐색
        // 안전지대 = 빈칸 - 바이러스 퍼진 영역의 수 + 원래 바이러스의 수 - 세운 벽의 개수(=3)
        // bfs의 리턴값에 원래 바이러스가 있던 칸도 포함되므로, 원래 바이러스가 있던 칸 개수를 더해주어야 함
        ans = max(ans, (int(blank.size()) - tmp + int(virus.size()) - 3));
        return;
    }
    // i번째 빈칸에 대해 벽으로 바꾸면서 백트래킹 진행
    for (int i = idx; i < int(blank.size()); ++i) {
        board[blank[i].X][blank[i].Y] = 1;  // 벽 설정
        dfs(depth + 1, i + 1);              // 다음 빈칸에 대해 탐색
        board[blank[i].X][blank[i].Y] = 0;  // 벽 해제
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
            if (board[i][j] == 0)  // 빈칸 좌표 저장
                blank.push_back({i, j});
            else if (board[i][j] == 2)  // 바이러스 좌표 저장
                virus.push({i, j});
        }
    dfs(0, 0);
    cout << ans;
}