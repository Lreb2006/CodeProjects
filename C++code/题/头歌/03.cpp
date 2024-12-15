#include<iostream>
using namespace std;

int main(void)
{
    int maxnum = -9999;
    int num;
    while(cin>>num){    //回车可以退出循环！！纱布vscode要按Ctrl+Z！纱布！纱！布！纱布vscode！！！
        if(num > maxnum)   maxnum = num;
    }
    cout<<maxnum<<endl;
    return 0;
}