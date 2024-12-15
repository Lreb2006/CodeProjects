#include<iostream>
#include<cstring>
#include<cmath>     //把.h去掉改成c开头的就行

using namespace std;    //如果没有命名空间，需要使用std::cout，std::cin

int main(void)
{
    int n;
    cin>>n;     //==scanf(%d,&n);
    cout<<"Hello World!"<<n++<<endl;    //endl == "\n"
    cout<<"Hello World!"<<++n<<"\n";

    return 0;
}