#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N = 110;

int n, m;           // 迷宫的行数和列数
int g[N][N];        // 存储迷宫的结构，0表示通路，1表示墙
int d[N][N];        // 存储从起点到各点的最短距离，初始化为-1表示未访问
queue<PII> q;       // BFS队列，存储待处理的坐标

// 四个方向的移动向量：上、下、左、右
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            d[i][j] = -1; // 初始化距离数组为-1，表示未访问
        }
    }
    
    // 起点(0,0)初始化
    d[0][0] = 0;   // 起点到自身的距离为0
    q.push({0, 0}); // 将起点加入队列
    
    while (!q.empty()) {
        auto t = q.front(); // 取出队头元素
        q.pop();
        int x = t.first, y = t.second;

        // 检查当前节点是否是终点
        if (x == n - 1 && y == m - 1) {
            cout << d[x][y] << endl;
            return 0;
        }
        
        // 遍历四个方向
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            // 1.是否越界？2.是否是墙？3.是否已经访问过？
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && g[nx][ny] == 0 && d[nx][ny] == -1) {
                d[nx][ny] = d[x][y] + 1; // 更新距离
                q.push({nx, ny});        // 新坐标入队

                // 如果到达终点
                if (nx == n-1 && ny == m-1) {
                    cout << d[nx][ny] << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}