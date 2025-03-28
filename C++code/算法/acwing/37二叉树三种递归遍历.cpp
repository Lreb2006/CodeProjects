#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int arr[N];  // 存储节点值的数组
int n;  // 数组实际长度

// 递归前序遍历
void pre(int u, int n) {
    if (u >= n) return;
    cout << arr[u] << " ";
    pre(2 * u + 1, n);   // 左子节点索引为2u+1
    pre(2 * u + 2, n);   // 右子节点索引为2u+2
}

// 递归中序遍历
void in(int u, int n) {
    if (u >= n) return;
    in(2 * u + 1, n);
    cout << arr[u] << " ";
    in(2 * u + 2, n);
}

// 递归后序遍历
void post(int u, int n) {
    if (u >= n) return;
    post(2 * u + 1, n);
    post(2 * u + 2, n);
    cout << arr[u] << " ";
}

int main() {
    
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    pre(0, n);    // 前序遍历
    in(0, n);     // 中序遍历
    post(0, n);   // 后序遍历
    return 0;
}