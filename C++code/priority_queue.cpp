#include<bits/stdc++.h>
#include<queue>
using namespace std;

int main(){
    //构造大顶堆:队首总是最大的元素
    priority_queue <int> pque;
    //构造小顶堆
    priority_queue<int, vector<int>, greater<int>> min_pq;
    //进堆
    pque.push(3);
    pque.push(1);
    pque.push(4);
    pque.push(2);
    //获取堆顶
    while(!pque.empty()){
        cout<<pque.top()<<" ";
        pque.pop();
    }
    cout<<endl;
    //获取长度
    cout<<pque.size()<<endl;
    return 0;
}