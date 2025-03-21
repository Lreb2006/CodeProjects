#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int arr[N];
int n,x;

int bsearch(int arr[],int n,int x){
    int l = 0,r = n-1;
    while(l<=r){
        int m = l+(r-l)/2;
        if(arr[m] == x) return m;
        else if(arr[m] > x)    r = m-1;
        else    l = m+1;
    }
    return -1;
}

int main()
{
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    scanf("%d",&x);
    cout<<bsearch(arr,n,x)<<endl;
    return 0;
}