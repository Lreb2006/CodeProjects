#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int p[N];    // 并查集父节点数组
int Size[N];  // 存储每个连通块的大小
int n, m;

// 查找根节点并进行路径压缩
int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    cin >> n >> m;
    // 初始化并查集，每个节点的父节点是自己，大小为1
    for (int i = 1; i <= n; ++i) {
        p[i] = i;
        Size[i] = 1;
    }

    while (m--) {
        string op;
        cin >> op;
        
        if (op == "C") {
            int a, b;
            cin >> a >> b;
            int rootA = find(a);
            int rootB = find(b);
            if (rootA != rootB) {
                p[rootA] = rootB;          // 将rootA合并到rootB
                Size[rootB] += Size[rootA]; // 更新rootB的大小
            }
        } else if (op == "Q1") {
            int a, b;
            cin >> a >> b;
            if (find(a) == find(b)) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        } else if (op == "Q2") {
            int a;
            cin >> a;
            cout << Size[find(a)] << "\n";
        }
    }
    return 0;
}