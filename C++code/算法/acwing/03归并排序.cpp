#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int arr[N];
int help[N];
int n;

void mergeSort(int l,int r){
    if(l == r){
        return;
    }
    int m = (l+r)/2;
    mergeSort(l,m);
    mergeSort(m+1,r);
    int a = l,b = m+1,i = l;
    while(a<=m&&b<=r){
        if(arr[a]<=arr[b]){
            help[i] = arr[a];
            i++;
            a++;
        }else{
            help[i] = arr[b];
            i++;
            b++;
        }
    }
    while(a<=m){
        help[i] = arr[a];
        i++;
        a++;    //自增是为了跳出循环
    }
    while(b<=r){
        help[i] = arr[b];
        i++;
        b++;
    }
    for(i = l;i<=r;i++){
        arr[i] = help[i];
    }
}

int main()
{
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    mergeSort(0,n-1);
    for(int i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}