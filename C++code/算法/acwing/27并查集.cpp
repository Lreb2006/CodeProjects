#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int n,m;
int p[N];   // 并查集数组，p[i] 表示元素 i 的父节点
int a,b;

// 并查集查找操作，带路径压缩优化
int find(int x){
    if(p[x] != x)   // 如果x不是该集合的代表
        p[x] = find(p[x]);  // 查找x的祖先直到找到代表,于是顺手路径压缩
    return p[x];    //如果x是祖先，则返回
}

int main()
{
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        p[i] = i;
    }
    while(m--){
        string op;
        cin>>op>>a>>b;
        if(op == "M")   p[find(a)] = find(b);   // 让 a 的根节点指向 b 的根节点，实现集合合并
        else if(op == "Q"){
            if(find(a) == find(b)){
                cout<<"Yes"<<endl;
            }else{
                cout<<"No"<<endl;
            }
        }
    }
    return 0;
}