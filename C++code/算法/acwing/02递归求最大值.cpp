#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e5+10;
int arr[N];
int n;

int f(int arr[],int l,int r){
    if(l == r){
        return arr[l];
    }
    int m = (l+r)/2;
    int lmax = f(arr,l,m);
    int rmax = f(arr,m+1,r);
    return max(lmax,rmax);
}

int main()
{
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    cout<<f(arr,0,n-1)<<endl;
    return 0;
}