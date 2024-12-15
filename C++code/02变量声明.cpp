#include<iostream>
using namespace std;

int main(void){
    int n;
    cin>>n;
    for(int i = 0;i<10;i++){
        cout<<n<<" ";
    }
    cout<<endl;
    for(int i = 0;i<10;i++){
        cout<<++n<<" ";
        
    }
    return 0;
}