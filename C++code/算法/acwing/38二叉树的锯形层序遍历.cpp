#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int arr[N], q[N], res[N];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> arr[i];

    int front = 0, rear = 0, idx = 0;
    q[rear++] = 1; // 根节点入队
    bool reverseLevel = false;

    while (front < rear) {
        int levelSize = rear - front;

        // 直接处理当前层的输出顺序
        if (reverseLevel) 
            for (int i = rear - 1; i >= front; --i)
                res[idx++] = arr[q[i]];
        else 
            for (int i = front; i < rear; ++i)
                res[idx++] = arr[q[i]];

        // 处理下一层节点
        for (int i = 0; i < levelSize; ++i) {
            int cur = q[front++];
            int left = cur << 1, right = left + 1;
            if (left <= n) q[rear++] = left;
            if (right <= n) q[rear++] = right;
        }
        reverseLevel = !reverseLevel;
    }

    for (int i = 0; i < idx; ++i)
        cout << res[i] << " \n"[i == idx-1];

    return 0;
}