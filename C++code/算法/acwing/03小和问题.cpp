#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int arr[N];
int help[N];
int n;

long long merge(int l,int r){
    int m = (l+r)/2;
    long long ans = 0,sum = 0;
    for(int j = m+1,i = l;j<=r;j++){
        while(i<=m&&arr[i]<=arr[j]){
            sum += arr[i];
            i++;
        }
        ans += sum;
    }
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
    return ans;
}

long long smallSum(int l,int r){
    if(l == r){
        return 0;
    }
    int m = (l+r)/2;
    return smallSum(l,m) + smallSum(m+1,r) + merge(l,r);
}

int main()
{
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    cout<<smallSum(0,n-1)<<endl;
    return 0;
}