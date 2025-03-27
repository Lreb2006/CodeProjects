#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int arr[N], q[N], res[N]; // arr存储节点值，q作为队列，res存储结果

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i]; // 输入每个节点的值，节点编号从1开始

    int front = 0, end = 0, idx = 0; // front和end是队列的前后指针，idx是结果数组的索引
    q[end] = 1; // 根节点入队
    end++;
    bool reverse = false; // 标记当前层是否反转，默认第一层不反转

    while (front < end) { // 当队列非空时循环处理每一层
        int size = end - front; // 计算当前层的节点数量

        // 根据reverseLevel决定当前层的遍历方向
        if (reverse) {
            // 反转顺序：从队列末尾到front
            for (int i = end - 1; i >= front; --i) {
                res[idx++] = arr[q[i]]; // 将节点值存入结果数组
            }
        } else {
            // 正常顺序：从front到队列末尾
            for (int i = front; i < end; i++) {
                res[idx] = arr[q[i]];
                idx++;
            }
        }

        // 处理下一层节点并入队
        for (int i = 0; i < size; ++i) {
            int cur = q[front]; // 取出当前节点
            front++;
            int left = cur*2; // 左子节点索引
            int right = left + 1; // 右子节点索引
            if (left <= n) q[end++] = left; // 如果存在左子节点，入队
            if (right <= n) q[end++] = right; // 如果存在右子节点，入队
        }
        reverse = !reverse; // 切换下一层的反转标志
    }

    for (int i = 0; i < idx; ++i) {
        cout << res[i] << (i == idx - 1 ? "\n" : " ");  // 输出结果，用空格分隔，末尾换行
    }

    return 0;
}