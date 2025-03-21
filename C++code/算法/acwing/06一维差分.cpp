#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int d[N],a[N];
int n,m;
int l,r,c;

int main()
{
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        d[i] = a[i] - a[i-1];
    }
    while(m--){
        cin>>l>>r>>c;
        d[l] += c;
        if(r+1<=n){
            d[r+1] -= c;
        }
    }
    for(int i = 1;i<=n;i++){
        a[i] = a[i-1] + d[i];
    }
    for(int i = 1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}