#include<iostream>
using namespace std;

int main(void){
    string a = "hello";
    string a2 = "world";
    string a3 = a +" " + a2;    //字符串拼接
    cout<<a3<<endl;

    string s;
    getline(cin,s);   //获取一整行，包括空格
    //cin>>s;
    cout<<s<<endl;
    cout<<s.length()<<endl; //包括空格，不包括\0
    return 0;
}