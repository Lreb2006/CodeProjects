#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int arr[N];
int n;

int trap(int arr[],int n){
    int l = 1,r = n-2,lmax = arr[0],rmax = arr[n-1];    //从两头往中间的指针
    int ans = 0;
    while(l<=r){
        if(lmax <= rmax){
            ans += max(0,lmax-arr[l]);
            lmax = max(lmax,arr[l]);
            l++;
        }else{
            ans += max(0,rmax-arr[r]);
            rmax = max(rmax,arr[r]);
            r--;
        }
    }
    return ans;
}

int main(){
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    cout<<trap(arr,n)<<endl;
}