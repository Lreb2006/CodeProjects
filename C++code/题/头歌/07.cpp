#include<iostream>
using namespace std;

int main(void)
{
    string str;
    getline(cin,str);
    for(int i = str.length()-1;i>=0;i--){   //倒序输出：倒序遍历
        cout<<str[i];
    }
    return 0;
}