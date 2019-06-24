#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;++i)

ll l,r;
int d[20],len;

ll DFS(){
  return 0;
}

ll solve(ll n){
  len=1;
  for(;n;n/=10)d[len++]=n%10;
  return DFS(len-1);
}

int main(){
  int _;cin>>_;
  while(_--){
    cin>>l>>r;
    cout<<solve(r)-solve(l-1)<<endl;
  }
}