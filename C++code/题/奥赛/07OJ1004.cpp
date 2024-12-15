#include<iostream>
using namespace std;

int main(void)
{
    char c;     //char可包含特殊字符
    cin>>c;
    printf("  %c\n",c);
    printf(" %c%c%c\n",c,c,c);
    printf("%c%c%c%c%c\n",c,c,c,c,c);   //%c表示字符
    return 0;  
}