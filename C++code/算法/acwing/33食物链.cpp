#include <iostream>
#include <vector>
using namespace std;

const int N = 50010;  
int parent[N];        // 并查集的父节点数组
int dist[N];          // 节点到父节点的距离（用于模3判断关系）

// 查找根节点，并实现路径压缩
int find(int x) {
    if (parent[x] != x) {                // 如果当前节点不是根节点
        int orig = parent[x];            // 记录原始父节点
        parent[x] = find(parent[x]);     // 递归查找根节点，路径压缩
        dist[x] += dist[orig];           // 更新当前节点到根节点的距离
    }
    return parent[x];                    // 返回根节点
}

//         ————————-
//         ↓       ↑
// E → D → C → B → A
// 如果一个点到根节点的距离是1，如B到A，说明A吃B；
// 如果一个点到根节点的距离是2，如C到A，说明B吃C，且C吃A；
// 如果一个点到根节点的距离是3，如D到A，说明D与A是同类
// 说明每三个距离为一个循环，相当于...B → A → C → B → A
int main() {
    int n, k;
    cin >> n >> k;

    // 初始化并查集，每个节点的父节点是自己，距离初始化为0
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        dist[i] = 0;
    }

    int cnt = 0;  // 错误计数器

    while (k--) {
        int D, x, y;
        cin >> D >> x >> y;

        // 规则1：动物编号超过N是错误
        if (x > n || y > n) {
            cnt++;
            continue;
        }

        // 规则2：D=2时，X吃X自己是错误
        if (D == 2 && x == y) {
            cnt++;
            continue;
        }

        int rx = find(x);  // 找x的根
        int ry = find(y);  // 找y的根

        if (rx != ry) {
            // 合并两个集合
            parent[rx] = ry;  // 将rx的父节点设为ry

            // 根据关系类型调整距离
            if (D == 1) {  // 同类关系
                // 保持 (dist[x] + dist[rx]) ≡ dist[y] (mod 3)
                dist[rx] = (dist[y] - dist[x] + 3) % 3;
            } else {        // 捕食关系（x吃y）
                // 保持 (dist[x] + dist[rx]) ≡ dist[y] + 1 (mod 3)
                dist[rx] = (dist[y] - dist[x] + 1 + 3) % 3;
            }
        } else {
            // 已存在关系，验证当前声明是否矛盾
            if (D == 1) {  // 声明同类
                // 距离差应为0的模3等价类
                int mod = (dist[x] - dist[y]) % 3;
                if (mod < 0) mod += 3;  // 处理负数
                if (mod != 0) cnt++;
            } else {        // 声明x吃y
                // 距离差应为1的模3等价类
                int mod = (dist[x] - dist[y]) % 3;
                if (mod < 0) mod += 3;
                if (mod != 1) cnt++;
            }
        }
    }

    cout << cnt << endl;
    return 0;
}