#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int arr[N];
int help[N];
int n;

long long mergeSort(int l,int r){
    if(l == r){
        return 0;  // 单个元素没有逆序对,结束函数的执行，返回0
    }
    int m = (l+r)/2;
    // res 存储当前区间的总逆序对数 = 左半部分的逆序对 + 右半部分的逆序对 + 合并时产生的逆序对
    long long res = mergeSort(l,m) + mergeSort(m+1,r);
    int a = l,b = m+1,i = l;
    while(a<=m && b<=r){
        if(arr[a]<=arr[b]){
            help[i] = arr[a];
            i++;
            a++;
        }else{
            help[i] = arr[b];
            i++;
            b++;
            // 当前右边的数比左边的数小时，左边剩余的所有数都能和右边的数构成逆序对
            // m-a+1 表示左边剩余数字的个数
            res += m-a+1;
        }
    }
    while(a<=m){
        help[i] = arr[a];
        i++;
        a++;
    }
    while(b<=r){
        help[i] = arr[b];
        i++;
        b++;
    }
    for(i = l;i<=r;i++){
        arr[i] = help[i];
    }
    return res;
}

int main()
{
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    cout<<mergeSort(0,n-1)<<endl;
    return 0;
}
