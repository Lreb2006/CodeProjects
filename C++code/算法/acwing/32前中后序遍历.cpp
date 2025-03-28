#include<bits/stdc++.h>
using namespace std;

const int N = 10;
int n;
int path[N];
bool st[N]; //判断是否重复

void dfs(int a){
    if(a == n){ //a是path的下标，到a=n时恰好遍历完n-1
        for(int i = 0;i<n;i++){
            cout<<path[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i = 1;i<=n;i++){
        if(!st[i]){
            path[a] = i;    //从1开始
            st[i] = true;
            dfs(a+1);
            st[i] = false;  //回溯
        }
    }
}

int main()
{
    cin>>n;
    dfs(0);
    return 0;
}