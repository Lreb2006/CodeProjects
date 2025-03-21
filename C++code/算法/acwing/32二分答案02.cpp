// 题目2
// 分割数组的最大值(画匠问题)
// 给定一个非负整数数组 nums 和一个整数 m
// 你需要将这个数组分成 m 个非空的连续子数组。
// 设计一个算法使得这 m 个子数组各自和的最大值最小。
// 示例 1：
// 输入：nums = [7,2,5,10,8], k = 2
// 输出：18
// 示例 2：
// 输入：nums = [1,2,3,4,5], k = 2
// 输出：9
// 示例 3：
// 输入：nums = [1,4,4], k = 3
// 输出：4

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int nums[N];
int n,m;

int f(int mid){
    int q = 0,k = 0;
    for(int i = 0;i<n;i++){
        if(k+nums[i]<=mid){
            k += nums[i];
        }else{
            k = nums[i];
            q++;
        }
    }
    q++;
    return q;
}

int bsearch(int n,int m){
    int sum = 0,maxnum = 0;
    for(int i = 0;i<n;i++){
        cin>>nums[i];
        sum += nums[i];
        maxnum = max(maxnum,nums[i]);
    }

    int l = maxnum,r = sum;
    while(l<r){
        int mid = (l+r)/2;
        if(f(mid)>m)    l = mid+1;
        else    r = mid;
    }
    return l;
}

int main()
{
    cin>>n>>m;
    cout<<bsearch(n,m)<<endl;
    return 0;
}
