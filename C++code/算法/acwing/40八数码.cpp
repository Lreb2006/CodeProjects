#include<bits/stdc++.h>
using namespace std;

int main()
{
    string start;    // 初始网格的字符串形式
    for(int i = 0;i<9;i++){
        char c;
        cin>>c;
        start += c;
    }

    string end = "12345678x";    // 目标网格的字符串形式
    queue<string> q;    // BFS队列
    unordered_map<string,int> d;    // 哈希表，记录状态到步数的映射,初始化为0

    q.push(start);  // 将起点加入队列
    d[start] = 0;   // 起点到自身的距离为0

    // 四个方向的移动向量:上、下、左、右
    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,-1,1};

    while(!q.empty()){
        auto t = q.front();
        q.pop();

        int distance = d[t];

        // 检查初始网格是否是终点,or找到目标状态，返回步数
        if(t == end){
            cout<<distance<<endl;
            return 0;
        }

        int pos = t.find('x');   // 找到x的位置
        int x = pos/3,y = pos%3;    //将x的位置转换为二维坐标

        for(int i = 0;i<4;i++){
            int nx = x + dx[i],ny = y + dy[i];
            // 是否越界？
            if(nx >= 0&&nx < 3&&ny >= 0&&ny < 3){
                string state = t;   // 基于当前状态生成新状态的副本,如果直接操作 t，原始状态会被破坏，无法继续生成其他方向的新状态（例如向下交换）
                swap(state[pos],state[nx*3+ny]);    //交换x和相邻字符,二维转一维
                if(d.count(state) == 0){
                    d[state] = distance + 1;
                    q.push(state);
                }
            }
        }
    }
    // 队列处理完毕仍未找到解，输出 -1
    cout<<"-1"<<endl;
    return 0;
}