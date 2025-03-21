#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int a[N],b[N];
int n,m,x;

int main()
{
    cin>>n>>m>>x;
    for(int i = 0;i<n;i++){
        cin>>a[i];  //升序
    }
    for(int i = 0;i<m;i++){
        cin>>b[i];  //升序
    }
    int j = 0,i = m-1;
    while(j<n&&i>=0){
        if(a[j]+b[i] == x){
            cout<<j<<" "<<i;
            return 0;
        }else if(a[j]+b[i] > x){    //偏大则右指针左移
            i--;
        }else if(a[j]+b[i] < x){    //偏小则左指针右移
            j++;
        }
    }
    return 0;
}