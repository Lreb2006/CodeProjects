#include<iostream>
#include<queue>
using namespace std;

int main(void)
{
    //队列：先进先出
    queue <int> q;
    for(int i = 1;i<=10;i++){
        q.push(i);
    } 
    cout<<q.front()<<" "<<q.back()<<endl;  //获取队首和获取队尾

    q.pop();    //出队，出队首
    cout<<q.front()<<" "<<q.back()<<endl;  

    q.push(11);     //入队，入队尾
    cout<<q.front()<<" "<<q.back()<<endl;  

    cout<<q.size()<<endl;   //获取长度
    return 0;
}