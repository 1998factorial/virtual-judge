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

ll mod=1e9+7;
ll C[505][505];//C[i][j]=C[i-1][j-1]+C[i-1][j],i>=j

string a;
//given a string, output the number of palindromes given that you can only permute letters
int main(){
	C[0][0]=1ll;
	REP(i,1,505)C[i][0]=C[i][i]=1;
	REP(i,2,505){
		REP(j,1,i){
			C[i][j]=(C[i-1][j-1]+C[i-1][j]+mod)%mod;
		}
	}
	int _;cin>>_;
	while(_--){
		cin>>a;
		int n=a.size();
		int cnt[26];
		memset(cnt,0,sizeof(cnt));
		REP(i,0,n)cnt[a[i]-'a']++;
		int sum=0;
		REP(i,0,26)sum+=(cnt[i]%2!=0);
		if(sum>1)printf("%d\n",0);
		else{
			ll ret=1ll;
			int N=n/2;
			REP(i,0,26){
				ret=(ret*C[N][cnt[i]/2]+mod)%mod;
				N-=cnt[i]/2;
			}
			printf("%lld\n",ret);
		}
	}
	return 0;
}
