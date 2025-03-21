#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
int n, k;
int a[N];
deque<int> q;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];

    // 求最小值：维护单调递增队列
    for (int i = 0; i < n; i++) {
        // 移除不在窗口内的队首元素
        if (!q.empty() && q.front() < i - k + 1) q.pop_front();
        // 维护单调递增：移除队尾大于等于当前元素的值
        while (!q.empty() && a[q.back()] >= a[i]) q.pop_back();
        
        q.push_back(i);
        if (i >= k - 1) cout << a[q.front()] << " ";
    }
    cout << endl;

    q.clear(); // 清空队列

    // 求最大值：维护单调递减队列
    for (int i = 0; i < n; i++) {
        // 移除不在窗口内的队首元素
        if (!q.empty() && q.front() < i - k + 1) q.pop_front();
        // 维护单调递减：移除队尾小于等于当前元素的值
        while (!q.empty() && a[q.back()] <= a[i]) q.pop_back();
        
        q.push_back(i);
        if (i >= k - 1) cout << a[q.front()] << " ";
    }
    cout << endl;

    return 0;
}
