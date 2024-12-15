#include<iostream>
using namespace std;

int main(void)
{
    double s;
    cin>>s;     //要游的目标距离
    double n = 2.0;
    double sum = 0;
    int cnt = 0;    //要游的步数
    while(sum < s){
        sum = sum + n;
        n = n*0.98;
        cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}