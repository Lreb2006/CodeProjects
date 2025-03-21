#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int arr[N],cnt[N];
int n;

int main()
{
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    int ans = 0;
    for(int i = 0,j = 0;j<n;j++){
        cnt[arr[j]]++;
        while(cnt[arr[j]]>1){
            cnt[arr[i]]--;
            i++;
        }
        ans = max(ans,j-i+1);
    }
    cout<<ans<<endl;
    return 0;
}