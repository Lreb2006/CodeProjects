#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int a[N][N],d[N][N];
int n,m,c;
int x1,y1,x2,y2;

int main()
{
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cin>>a[i][j];
            d[i][j] = (a[i][j] - a[i-1][j]) - (a[i][j-1] - a[i-1][j-1]);
        }
    }

    while(m--){
        cin>>x1>>y1>>x2>>y2>>c;
        d[x1][y1] += c;
        d[x1][y2+1] -= c;
        d[x2+1][y1] -= c;
        d[x2+1][y2+1] += c;
    }

    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            a[i][j] = d[i][j] + a[i-1][j] + a[i][j-1] - a[i-1][j-1];
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}