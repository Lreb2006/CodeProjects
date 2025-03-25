#include<bits/stdc++.h>
using namespace std;

const int N = 10;  
int n;             // 棋盘的大小 n x n
char g[N][N];      // 棋盘，g[i][j]表示第i行第j列的格子
bool col[N];       // 列标记数组，col[i]表示第i列是否被占用
bool dg[N];        // 正对角线标记数组，dg[i]表示第i条正对角线是否被占用
bool udg[N];       // 反对角线标记数组，udg[i]表示第i条反对角线是否被占用

// 深度优先搜索函数，a表示当前处理的行数
void dfs(int a){
    
    if(a == n){
        for(int i = 0; i < n; i++){
            cout << g[i] << endl;  // 输出第i行的棋盘状态
        }
        cout << endl;  
        return;
    }

    // 尝试在当前行的每一列放置皇后
    for(int i = 0; i < n; i++){
        // 检查第i列、正对角线和反对角线是否被占用
        if(!col[i] && !dg[a + i] && !udg[a - i + n]){
            g[a][i] = 'Q';  // 放置皇后
            col[i] = dg[a + i] = udg[a - i + n] = true;  // 标记列、正对角线和反对角线为占用
            dfs(a + 1);  // 递归处理下一行
            col[i] = dg[a + i] = udg[a - i + n] = false;  // 回溯，取消标记
            g[a][i] = '.';  // 回溯，移除皇后
        }
    }
}

int main()
{
    cin >> n;  
    // 初始化棋盘，所有格子初始化为'.'
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            g[i][j] = '.';
        }
    }
    dfs(0);  
    return 0;
}