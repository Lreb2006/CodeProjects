#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, x;
stack<int> s;
int result[N];
//处理左边最近的比当前数小的数
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;

        // 保证从小到大，单调递增
        while (!s.empty() && s.top() >= x) {
            s.pop();
        }

        // 如果栈为空，说明没有比当前元素小的元素
        if (s.empty()) {
            result[i] = -1;
        } else {
            result[i] = s.top();
        }

        // 将当前元素压入栈中
        s.push(x);
    }

    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}