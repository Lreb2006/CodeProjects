## <center>Acm校赛

!!! ## 二分查找模板

#### 函数实现
```cpp
#include <iostream>
using namespace std;

// 二分查找函数，查找目标值是否存在
int bsearch(int *a, int n, int x) { // 数组a，长度n，目标值x
    int l = 1, r = n;              // 左边界l，右边界r
    while (l <= r) {               // 循环直到左右边界重叠或越界
        int m = (l + r) / 2;       // 中间位置m
        if (a[m] == x) return m;   // 找到目标值返回下标
        else if (a[m] < x) l = m + 1; // 目标值在右区间
        else r = m - 1;            // 目标值在左区间
    }
    return -1;                     // 未找到目标值返回-1
}

int main() {
    int n = 6;                     // 数组长度
    int a[] = {0, 2, 4, 6, 8, 10, 12}; // 数组，a[0]占位
    int x = 8;                     // 要查找的目标值
    int pos = bsearch(a, n, x);    // 调用二分查找函数
    if (pos != -1) cout << "Found at: " << pos << endl;
    else cout << "Not found" << endl;
    return 0;
}
```

#### 非函数实现

```cpp
#include <iostream>
using namespace std;

int main() {
    int n = 6;                     // 数组长度
    int a[] = {0, 2, 4, 6, 8, 10, 12}; // 数组，a[0]占位
    int x = 8;                     // 要查找的目标值
    int l = 1, r = n;              // 左边界l，右边界r
    int pos = -1;                  // 存储目标值下标，默认-1表示未找到
    while (l <= r) {               // 循环直到左右边界重叠或越界
        int m = (l + r) / 2;       // 中间位置m
        if (a[m] == x) {           // 找到目标值
            pos = m;               // 记录下标
            break;                 // 退出循环
        } else if (a[m] < x) l = m + 1; // 目标值在右区间
        else r = m - 1;            // 目标值在左区间
    }
    if (pos != -1) cout << "Found at: " << pos << endl;
    else cout << "Not found" << endl;
    return 0;
}
```

!!! ## 一维前缀和模板

```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    const int N = 1e5 + 10;
    int sum[N], a[N];
    int n, m;                   
    cin >> n >> m;              //n为数组a的长度，m为询问次数
    int l, r;
    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> l >> r;          //左区间和右区间
        cout << sum[r] - sum[l-1] << endl;//区间[l, r]内元素的和,非下标
    }
    return 0;
}
```

!!!## 一维差分处理区间增量问题

```cpp
#include <iostream> 
using namespace std;

int main() {
    const int N = 1e5 + 10;     //N表示数组的最大长度
    int a[N] = {0}, b[N] = {0};
    int n, m;                   //n为数组a的长度，m为询问次数
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];            
        b[i] = a[i] - a[i - 1]; // 构建差分数组b
    }

    while (m--) {
        int l, r, c;            // l 和 r 表示操作的区间 [l, r]，c 表示加的值
        cin >> l >> r >> c; 
        b[l] += c;
        if (r + 1 <= n) {       // 如果 r+1 没有越界
            b[r + 1] -= c;
        }
    }
    // 根据差分数组 b 计算最终的数组a
    for (int i = 1; i <= n; i++) {
        a[i] = a[i - 1] + b[i]; // 根据前缀和恢复原数组a
    }
    
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " "; 
    }
    cout << endl;
    return 0; 
}
```

!!! ## 二维前缀和模板

```cpp
#include<bits/stdc++.h>
using namespace std;

const int N = 1e9+100;
int s[N][N],a[N][N];
int x,y,w;
int main() {
    int n,m,q;
    cin>>n>>m>>q;
    for(int i = 1;i<=n;i++){
        for(int j =1;j<=m;j++){
            cin>>a[i][j];
        }
    }
        for(int i = 1;i<=n;i++){
        for(int j =1;j<=m;j++){
            s[i][j] = s[i-1][j]+ s[i][j-1]+a[i][j] - s[i-1][j-1];//二维前缀和模板数组
        }
    }
    int x1,y1,x2,y2;
    for(int i = 1;i<=q;i++){
        cin>>x1>>y1>>x2>>y2;
        cout<<s[x2][y2] - s[x1-1][y2] - s[x2][y1-1] + s[x1-1][y1-1]<<endl; //求从x1,y1到x2,y2的区域和
    }
    return 0;
}
```

!!! ## 二维差分增量模板

```cpp
#include<bits/stdc++.h>
using namespace std;

const int N = 1000 + 10;
int a[N][N], b[N][N];
int n, m, q;

void insert(int x1, int y1, int x2, int y2, int c) {     
    b[x1][y1] += c;
    b[x2 + 1][y1] -= c;
    b[x1][y2 + 1] -= c;
    b[x2 + 1][y2 + 1] += c;
}

int main() {
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            b[i][j] = a[i][j] - a[i-1][j] - a[i][j-1] + a[i-1][j-1];
        }
    }
    while (q--) {
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        insert(x1, y1, x2, y2, c);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            a[i][j] = b[i][j] + a[i-1][j] + a[i][j-1] - a[i-1][j-1];
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
```

!!! ## 其他常用代码片段

#### 遍历所有排列情况

```cpp
do {   } while (next_permutation(v.begin(), v.end()));
```

#### 清理缓存区

```cpp
cin.ignore(numeric_limits<streamsize>::max(), '\n');
```

#### 经典队列操作应用题目

```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    int m, n;           //m表示缓存最大容量，n表示询问次数
    cin >> m >> n;      // 读取缓存容量 m 和页面访问次数 n
    deque<int> q(m);  // 创建一个大小为 m 的双端队列，用来模拟缓存，默认大小为 m
    int a;  // 用来存储当前访问的页面
    int cnt = 0;  // 用来记录页面缺失的次数
    int qq[1010] = {0};  // 定义一个数组 qq，长度为 1010，初始化所有元素为 0，用来记录哪些页面在缓存中
    for (int i = 1; i <= n; i++) {  // 遍历所有页面访问
        cin >> a;  // 读取当前访问的页面号
        if (!qq[a]) {  // 如果页面 a 不在缓存中
            cnt++;  // 页面缺失，增加缺页次数
            if (q.size() == m) {  // 如果缓存已满
                int x = q.front();  // 获取队列的第一个元素，即最久未使用的页面
                q.pop_front();  // 从队列中移除最久未使用的页面
                qq[x] = 0;  // 更新数组 qq，标记页面 x 不在缓存中
            }
            q.push_back(a);  // 将当前页面 a 加入队列（缓存）
            qq[a] = 1;  // 更新数组 qq，标记页面 a 已经在缓存中
        }
    }
    cout << cnt;  // 输出缺页次数
    return 0;  // 程序结束
}
```

#### 字符串输入

```cpp
string arr[100];
getline(cin, arr[i]);
```

#### 自定义排序函数

```cpp
bool cmp(类型 a, 类型 b) {
    // 第一条件: 比较 a 和 b
    if (条件1) {
        return 排序规则1;
    }
    // 第二条件: 如果第一条件不满足，比较 a 和 b
    if (条件2) {
        return 排序规则2;
    }
    // 第三条件: 如果前面所有条件都不满足，继续比较
    if (条件3) {
        return 排序规则3;
    }
    // 默认返回
    return 排序规则默认;
}
```

### 循环数组索引更新

```cpp
index = (index + 1) % n; // 因为是循环，使用%运算确保数组循环
```

>解释：
这段代码的含义是在一个固定大小为 n 的数组中循环更新 index，确保它始终保持在合法范围内（0 到 n-1）。它通过取模运算（%）实现循环行为。
具体分析：
**1.index + 1:**
将当前索引值 index 增加 1，表示向后移动一个位置。
**2.% n:**
模运算确保索引不会超出数组的边界。如果增加后索引等于或大于 n，模运算会使它“回到”开头。
例如：
2.1 如果 index + 1 = n，则 (index + 1) % n = 0。
2.2 如果 index + 1 = n + 1，则 (index + 1) % n = 1。
**3.循环效果:**
模运算的结果总是一个小于 n 的非负数，这样可以实现数组的循环访问。
3.1 当 index 为数组最后一个位置（n-1）时，执行 (index + 1) % n 会将索引跳转到第一个位置 0。
3.2 否则，索引会正常向后移动。

#### 注意做题时样例输入陷阱，特殊样例，比如数组长度为0，尤其注意题目给的范围，比如＞＝

#### 格式化输出

```cpp
cout << setfill('0') << setw(2) << sum;
cout << fixed << setprecision(2) << num << endl;
```

#### 输出32位二进制形式

```cpp
cout << bitset<32>(n) << endl;
cin >> oct >> n; // 从输入以八进制形式读取一个整数
cout << dec << n; // 以十进制形式输出该整数
```

#### sawp函数不要忘了使用

#### 注意样例空格

#### 字符串和整数转换
>
>以字符串的形式输入数组进行数字的运算时，字符’0’实际上是48
<img src="./image.png" alt="Example Image">
注意在C++中，字符和整数之间可以进行转换。字符'0'到'9'的ASCII码分别是48到57。当你从一个字符中减去'0'时，实际上是将该字符转换为对应的数字。

#### 注意int long范围，数组可能是double类型等等

#### 字符数组长度

```cpp
char a[100];
int b = strlen(a);
```

#### 字符串长度

```cpp
string a;
int b = a.size();
```

#### 宏定义

```cpp
#define 宏名 替换内容
```

#### 定义尽量都在主函数外定义

#### 类型别名

```cpp
using ll = long long;
```

#### 结构体数组示例（贪心排序题可能用到）

```cpp
#include <iostream>
#include <algorithm> // 包含 sort 函数
using namespace std;

struct Point {
    int x, y;
};

// 自定义比较函数
bool cmp(const Point &a, const Point &b) {
    if (a.x == b.x) {
        return a.y < b.y;  // 如果 x 相同，按 y 排序
    }
    return a.x < b.x;  // 否则按 x 排序
}

int main() {
    Point points[3];
    // 通过 cin 输入结构体数组
    for (int i = 0; i < 3; i++) {
        cin >> points[i].x >> points[i].y;
    }
    // 使用自定义比较函数进行排序
    sort(points, points + 3, cmp);
    // 输出排序后的数组
    for (int i = 0; i < 3; ++i) {
        cout << "points[" << i << "]: x=" << points[i].x << ", y=" << points[i].y << endl;
    }
    return 0;
}
```

### `lower_bound` 和 `upper_bound`
>
>lower_bound 是 C++ 标准库 <algorithm> 中的一个非常有用的函数，它用于在已排序的容器中查找第一个不小于（即大于或等于）给定值的元素的位置。它可以用于数组、vector、deque、set 和 map 等支持随机访问或二叉搜索的数据结构。
（容器中的元素必须是已排序的。lower_bound 使用二分查找，因此只有在排序容器中才能正确工作。）
auto 是 C++11 引入的一个关键字，用于自动推导变量的类型。通过使用 auto，编译器可以根据变量初始化时的值自动推导出该变量的类型。这使得代码更加简洁，特别是在处理复杂的类型时（例如迭代器或类型较长的容器元素）。

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> vec = {1, 3, 3, 5, 7, 9};
// 查找第一个不小于 3 的位置（即第一个 3）
auto lb = lower_bound(vec.begin(), vec.end(), 3);
// 查找第一个大于 3 的位置（即第一个大于 3 的元素位置）
auto ub = upper_bound(vec.begin(), vec.end(), 3);
//lb 的位置是 vec.begin() + 1，即指向第一个 3。
//ub 的位置是 vec.begin() + 3，即指向第一个大于 3 的元素 5。
cout << "lb: " << (lb - vec.begin()) << endl;  // 输出 1，表示第一个 3
cout << "ub: " << (ub - vec.begin()) << endl;  // 输出 3，表示 5
```

!!! ### STL 常用函数

#### 最值

```cpp
max(x, y);  // 返回 x 和 y 较大值
min(x, y);  // 返回 x 和 y 较小值
```

#### pair(简单的二元结构体)

>声明方式：`pair<int, double> id;`  
`int`、`double`可以换成任何一个其他的类型，前后两个类型可以不一样
`id.first;`     // 访问第一个值，此时是 int 类型
`id.second;`      // 访问第二个值，此时是 double 类型

#### 排序

`sort(va.begin(), va.end(), cmp);`

#### vector
>
>用 push_back() 和 pop_back() 在 vector 的尾部加入或删除元素

```cpp
vector<int> v;
//初始化
// v.size() = 0
v.push_back(23333);               // v.size() = 1, v = { 23333 }
v.insert(v.begin() + 0, 890);    // v.size() = 2, v = { 890, 23333 }
v.insert(v.begin() + 1, 12345);  // v.size() = 3, v = { 890, 12345, 23333 }
v.erase(v.begin() + 0);          // v.size() = 2, v = { 12345, 23333 }
for (int i = 0; i<v.size(); i++) {
    printf("%d\n", v[i]);        // 依次输出 12345、23333
}
v.pop_back();                    // v.size() = 1, v = { 12345 }
```

#### 使用 insert() 在某个特定的位置插入一个元素，时间复杂度为O(n)O(n)。使用 erase() 删除某个位置的元素，时间复杂度为O(n)O(n)。不大常用

#### 栈 stack（重要）
>
>STL 在头文件 stack 提供了后入先出（LIFO）栈 stack。
使用 push() 向栈中加入元素。
使用 top() 获取栈顶元素（并不删除）。
使用 pop() 删除栈顶元素。
使用 empty() 判断栈是否为空

```cpp
stack<int> s;

bool flag = s.empty();  // flag = true，栈初始为空

s.push(23333);  
s.push(66666);
while (!s.empty()){
    cout<<s.top();      // 依次输出66666，23333
    s.pop();
}
```

#### 队列queue(重要)
>
>STL 在头文件 #include<queue> 中提供了先入先出（FIFO）队列 queue。
使用 push() 向队列中加入元素。
使用 front() 获取队首元素（并不删除）。
使用 pop() 删除队首元素。
使用 empty() 判断队列是否为空

```cpp
queue<int>q;

bool flag = q.empty();          // flag = true，队列初始为空

q.push(23333);
q.push(66666);
while (!q.empty()) {
    printf("%d\n", q.front());   // 依次输出 23333，66666
    q.pop();
}
```

#### 双端队列deque
>
>需要使用双端队列的情况，一般题目会明确说需要头尾插入弹出

```cpp
deque<int> dq;
dq.front();             // 获取队首元素
dq.back();              // 获取队尾元素

dq.pop_back();          // 删除队尾元素
dq.pop_front();         // 删除队首元素

dq.push_back(23333);    // 在队尾加入元素
dq.push_front(23333);   // 在队首加入元素
```

#### 优先队列 priority_queue
>
>STL 在头文件 queue 中提供优先队列 priority_queue，在任意时间都能取出队列中的最大值。

```cpp
priority_queue<int> pq;

bool flag = q.empty();  // flag = true，优先队列初始为空

pq.top();               // 获取优先队列中最大的元素（并不删除）

pq.push(23333);         // 向优先队列中加入元素
q.push(-1);
q.push(66666);
while (!q.empty()) {
    printf("%d\n", q.top()); // 依次输出 66666，23333，-1
    q.pop();            // 删除优先队列中最大元素
}
```

#### map(非常好用)
>
>需要引入map头文件，提供一对一映射,无重复元素,基于关键字查找，可以简单理解为，一种特殊的数组，其下标可以为double、string（字符）、int等等，通过这种下标去访问“数组”中的元素。
声明形式:`map<key_type,value_type>`变量名

```cpp
#include <iostream>
#include <map> // 头文件
#include <string>
using namespace std;

map<int, string> node;      // 定义用身份证号找人名的 map
map<string, int> node2;     // 定义用人名找身份证号的 map

int main(){
    node[123456] = "zhangsan";  
    node2["Bob"] = 23333;       
    cout << "ID:123456, his name is: " << node[123456] << endl;  
    cout << "Bob's ID: " << node2["Bob"] << endl;  
    node.clear();           //清空容器
}
```

#### 子串操作

```cpp

#include <iostream>
#include <cstring> // 包含 C 字符串处理函数 strstr
using namespace std;

int main() {
    //子串截取
    string s = "Hello, World!";
    string sub = s.substr(7, 5);    // 从下标 7 开始截取 5 个字符
    s.erase(7, 10);                 // 从下标7 删除 10 个字符

    //查找子串
    size_t pos = s.find("World");   // 查找 "World" 的位置，一般返回第一个字母起始下标
    if (pos != string::npos) {
    cout << "Found at: " << pos << endl; // 如果找到，输出位置
    }

    // 定义两个字符数组，用于存储输入的源字符串和需要查找的子串
    char str[100];                  // 源字符串
    char target[100];               // 子串
    cin.getline(str, 100);          // 使用 getline 读取一整行字符串
    cin.getline(target, 100);       // 输入需要查找的子串
    const char* pos = strstr(str, target);  // 使用 strstr 函数查找子串在源字符串中的位置
     // 判断是否找到子串
    if (pos != nullptr) {
        // 如果找到，计算子串的起始下标，并输出
        cout << "Substring found at index: " << (pos - str) << endl;  
    } else {
        cout << "Substring not found!" << endl;  
    }
    return 0; 
}
```

!!! ### 双指针模板

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, x;           // n为数组大小，x为目标和
    cin >> n >> x;      // 输入n和目标和x
    int a[n + 1];       // 数组，从1开始存储
    for (int i = 1; i <= n; i++) {
        cin >> a[i];    // 输入数组
    }
    sort(a + 1, a + n + 1); // 排序数组
    int i = 1, j = n;   // 双指针初始化
    while (i < j) {
        int s = a[i] + a[j]; // 当前两个数的和
        if (s == x) {
            cout << a[i] << " " << a[j] << endl;
            break;
        } else if (s < x) {
            i++;        // 左指针右移
        } else {
            j--;        // 右指针左移
        }
    }
    if (i >= j) {
        cout << "No solution" << endl; // 没有找到满足条件的数对
    }
    return 0;
}
```
