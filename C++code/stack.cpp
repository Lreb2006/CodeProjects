#include<iostream>
#include<stack>
using namespace std;

int main(){
    //构造
    stack <int> s;
    //进栈
    s.push(1);
    s.push(2);
    //出栈
    s.pop();
    //获取栈顶
    cout<<s.top()<<endl;
    //获取长度
    cout<<s.size()<<endl;
    //清空
    while(!s.empty()) {
        s.pop();
    }
    //判空
    cout<<s.empty()<<endl;
    return 0;
}