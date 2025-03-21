#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int s[N],a[N];
int n,m;
int l,r;

int main()
{
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        s[i] = s[i-1] + a[i];
    }
    while(m--){
        cin>>l>>r;
        cout<<s[r]-s[l-1];
    }
    return 0;
}