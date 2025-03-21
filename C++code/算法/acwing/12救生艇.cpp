#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int arr[N];
int n;
int lim;    //最大承载数量

//时间复杂度为O(N*logN)，空间复杂度为1
int numBoats(int arr[],int n,int lim){
    sort(arr,arr+n);    //排序
    int l = 0,r = n-1;  //双指针
    int sum = 0,ans = 0;
    while(l<=r){
        if(l == r){
            sum = arr[l];
        }else{
            sum = arr[l] + arr[r];
        }
        if(sum<=lim){
            l++;
            r--;
            ans++;
        }else{
            r--;
            ans++;
        }
    }
    return ans;
}

int main()
{
    //每艘船最多同时载两人
    cin>>n>>lim;
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    cout<<numBoats(arr,n,lim)<<endl;
    return 0;
}