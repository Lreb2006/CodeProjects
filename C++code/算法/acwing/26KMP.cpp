#include <iostream>
using namespace std;
const int N = 100100, M = 1000010;
int n, m;
int ne[N];
char s[M], p[N]; // s：主串，p：模式串

void get_next() {
    for (int i = 2, j = 0; i <= n; i++) {
        while (j && p[i] != p[j + 1]){
            j = ne[j];  // 如果 p[i]与 p[j+1]不匹配，就回退 j 到 ne[j]，直到找到合适的 j 或者 j 回退到 0
        }
        if (p[i] == p[j + 1]){
            j++;
            ne[i] = j;
        }
    }
}

void kmp() {
    for (int i = 1, j = 0; i <= m; i++) {
        while (j && s[i] != p[j + 1]){
            j = ne[j];  // 回退至上一个可能的匹配位置
        }
        if (s[i] == p[j + 1]){
            j++;
        }
        if (j == n) {
            printf("%d ", i - n);
            j = ne[j];
        }
    }
}
int main()
{
    cin >> n >> (p + 1) >> m >> (s + 1);    //从 p+1 开始存储，即 p[1] 为模式串的第一个字符
    get_next();
    kmp();
    return 0;
}
