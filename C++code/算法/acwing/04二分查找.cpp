#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int arr[N];
int n,q,x;

// 查找第一个等于x的位置
int bsearch_left(int arr[], int n, int x){
    int l = 0, r = n-1;
    while(l < r){
        int m = l + (r-l)/2;
        if(arr[m] >= x) r = m;
        else l = m + 1;
    }
    if(arr[l] != x) return -1;
    return l;
}

// 查找最后一个等于x的位置
int bsearch_right(int arr[], int n, int x){
    int l = 0, r = n-1;
    while(l < r){
        int m = l + (r-l+1)/2;
        if(arr[m] <= x) l = m;
        else r = m - 1;
    }
    if(arr[l] != x) return -1;
    return l;
}

int main()
{
    scanf("%d%d",&n,&q);
    for(int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
    while(q--){
        scanf("%d",&x);
        int left = bsearch_left(arr, n, x);
        int right = bsearch_right(arr, n, x);
        cout << left << " " << right << endl;
    }
    return 0;
}