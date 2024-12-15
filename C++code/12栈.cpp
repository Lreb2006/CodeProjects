#include<iostream>
#include<stack>
using namespace std;

int main(void)
{
    //栈：先进后出
    stack <int> s;
    s.push(1);  //压栈
    s.push(2);
    s.push(4);
    s.pop();    //出栈，出最后压的栈
    cout<<s.top()<<endl;    //访问栈顶
    //输出2
    cout<<"stack's length is:"<<s.size()<<endl;     //获取长度
    //无法使用迭代器，只能获取栈顶元素也只能操作栈顶元素，不能从栈底开始遍历
    return 0;
}