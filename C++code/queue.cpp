#include<bits/stdc++.h>
#include<queue>
using namespace std;

int main(){
    //构造
    queue <int> q;
    //进队
    q.push(1);
    q.push(2);
    q.push(3);
    //出队
    q.pop();
    //取队首
    cout<<q.front()<<endl;
    //取队尾
    cout<<q.back()<<endl;
    //获取长度
    cout<<q.size()<<endl;
    //清空
    while(!q.empty()){
        q.pop();
    }
    //判空
    cout<<q.empty()<<endl;
    return 0;
}