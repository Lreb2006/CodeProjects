#include<iostream>
using namespace std;

bool isOdd(int a){
    int x = a;
    if(x != 0){
        if(x%10%2 != 1){    
            return false;
        }else{
            x /= 100;    
            return isOdd(x);
        }
    }else{
        return true;
    }    
}
bool isEven(int a){
    int x = a;
    if(x != 0){
        x /= 10;
        if(x%10%2 != 0){
            return false;
        }else{
            x /= 10;
            return isEven(x);
        }
    }else{
        return true;
    }
}
int main(void)
{
    int n;
    int cnt = 0;
    cin>>n;
    for(int i = 1;i<=n;i++){
        if(isOdd(i)&&isEven(i))    cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}