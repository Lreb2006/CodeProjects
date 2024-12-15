#include<iostream>
using namespace std;

//最大公约数
int GCD(int a,int b){
    while(b != 0){
        int t = b;
        b = a%b;
        a = t;
    }
    return a;
}
//递归的欧几里得法
int gcd(int a,int b){
    if(b == 0)  return a;
    return gcd(b,a%b);
}
//最小公倍数
int lcm(int a,int b){
    return a/gcd(a,b)*b;    //先除后乘防止爆栈
}
int main(void)
{
    cout<<gcd(18,24)<<endl;
    return 0;
} 