#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <complex>
#include <unordered_set>
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RREP(i,a,b) for(int i=a;i>=b;i--)
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
int x[27];
ll c[27][55];//coefficients
ll a[55],b[55];
//x[i]<=20;
//使用母函数，eg,x[2]=3,->(1+x^2+x^4+x^6+x^8)
//意思是：x^4 代表若使用2个b则获得4点价值
int main(){
	int _;cin>>_;
	while(_--){
		REP(i,1,27)scanf("%d",&x[i]);
		REP(i,1,27)REP(j,0,55)c[i][j]=0ll;
		for(int i=1;i<27;i++){//init generating function	
			for(int j=0;j<=x[i]&&i*j<=50;j++){
					c[i][i*j]=1ll;
			}
		}
		REP(i,0,51)a[i]=0ll;
		REP(i,0,51)b[i]=0ll;
		a[0]=1ll;
		REP(i,1,27){
			REP(i,0,51)b[i]=0ll;
			REP(j,0,51){
				REP(k,0,51){
					if(j+k<=50)b[j+k]+=c[i][j]*a[k];
				}
			}
			REP(j,0,51)a[j]=b[j];
		}
		ll ret=0ll;
		REP(i,1,51)ret+=a[i];
		printf("%lld\n",ret);
	}
	return 0;
}