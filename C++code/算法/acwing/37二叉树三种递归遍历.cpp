#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int vals[MAXN];  // 存储节点值的数组
int n;  // 数组实际长度

// 递归前序遍历
void pre_order(int u, int n) {
    if (u >= n) return;
    cout << vals[u] << " ";
    pre_order(2 * u + 1, n);   // 左子节点索引为2u+1
    pre_order(2 * u + 2, n);   // 右子节点索引为2u+2
}

// 递归中序遍历
void in_order(int u, int n) {
    if (u >= n) return;
    in_order(2 * u + 1, n);
    cout << vals[u] << " ";
    in_order(2 * u + 2, n);
}

// 递归后序遍历
void post_order(int u, int n) {
    if (u >= n) return;
    post_order(2 * u + 1, n);
    post_order(2 * u + 2, n);
    cout << vals[u] << " ";
}

int main() {
    
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> vals[i];
    }

    pre_order(0, n);    // 前序遍历
    in_order(0, n);     // 中序遍历
    post_order(0, n);   // 后序遍历
    return 0;
}