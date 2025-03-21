#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
vector<pair<int,int>> vec;
int n;
int l,r;


int main()
{
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>l>>r;
        vec.push_back({l,r});
    }
    sort(vec.begin(),vec.end());    //根据左端点排序
    
    return 0;
}