#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int n;
vector <pair <int,int>> vec;

bool cmp(pair <int,int> a,pair <int,int> b){
    if(a.second != b.second)    return a.second < b.second;
    return a.first > b.first;
}

int main()
{
    cin>>n;
    vec.resize(n);
    for(int i = 0;i<n;i++){
        cin>>vec[i].first>>vec[i].second;
    }
    sort(vec.begin(),vec.end(),cmp);
    while(n--){
        vec[0].first += vec[0].second;
    }
    cout<<vec[0].first<<endl;
    return 0;
}
