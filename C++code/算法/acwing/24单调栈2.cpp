#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int arr[N];
pair<int, int> ans[N];
int n;
stack<int> s;
//输出每个元素的左边第一个比它小的元素的索引和右边第一个比它小的元素的索引
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        // 处理栈，直到栈顶元素小于当前元素
        while (!s.empty() && arr[s.top()] <= arr[i]) {
            ans[s.top()].second = i; // 记录当前元素的索引
            s.pop();
        }
        // 如果栈不为空，记录左边第一个比当前元素小的索引
        if (!s.empty()) {
            ans[i].first = s.top();
        } else {
            ans[i].first = -1; 
        }
        s.push(i);
    }

    // 处理栈中剩余的元素
    while (!s.empty()) {
        ans[s.top()].second = -1;
        s.pop();
    }

    // 输出结果
    for (int i = 0; i < n; i++) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }

    return 0;
}