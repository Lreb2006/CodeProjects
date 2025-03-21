#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int arr[N];
int n;

int findRepititon(int arr[]){
    int slow = arr[0];      //慢指针跳一次
    int fast = arr[arr[0]]; //快指针跳两次
    while(slow != fast){
        slow = arr[slow];
        fast = arr[arr[fast]];
    }
    fast = 0;   //相遇一次快指针变为0
    while(slow != fast){
        slow = arr[slow];
        fast = arr[fast];   //快指针跳一次
    }
    return slow;
}

int main()
{
    //定义数组长度为n，数值在1~n-1之间
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    cout<<findRepititon(arr)<<endl;
    return 0;
}