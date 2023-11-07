// 2206_벽 부수고 이동하기
#include <bits/stdc++.h>
using namespace std;

int n, m;
char board[1000][1000];
int dist[1000][1000][2];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs()
{
    // dist 초기화
    // dist[i][j][0]: 벽을 하나도 부수지 않고 (i, j)까지 오는 데 걸리는 시간
    // dist[i][j][1]: 벽을 하나만 부수고 (i, j)까지 오는 데 걸리는 시간
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            dist[i][j][0] = dist[i][j][1] = -1;
    dist[0][0][0] = dist[0][0][1] = 1;
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0}); // (x, y, 벽 부수지 않음) 으로 시작
    while (!q.empty())
    {
        int x, y, broken;
        tie(x, y, broken) = q.front();
        if (x == n - 1 && y == m - 1) // (N, M)에 도달한 경우 저장된 거리를 반환
            return dist[x][y][broken];
        q.pop();
        int nxtdist = dist[x][y][broken] + 1; // 지금까지의 거리에 1을 더한 변수
        for (int dir = 0; dir < 4; ++dir)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            // 범위 넘어가면 무시
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            // 방문한 적이 없는 이동 가능한 칸인 경우
            if (dist[nx][ny][broken] == -1 && board[nx][ny] == '0')
            {
                dist[nx][ny][broken] = nxtdist;
                q.push({nx, ny, broken});
            }
            // (nx, ny)를 부숴야하는 경우
            if (dist[nx][ny][1] == -1 && board[nx][ny] == '1' && !broken)
            {
                dist[nx][ny][1] = nxtdist;
                q.push({nx, ny, 1});
            }
        }
    }
    // 끝까지 도달할 수 없는 경우
    return -1;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> board[i][j];

    cout << bfs();
    return 0;
}