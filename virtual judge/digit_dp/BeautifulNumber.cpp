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
#include <unordered_map>
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RREP(i,a,b) for(int i=a;i>=b;i--)
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
//1<=l<=r<=9*10^18
//这是codeforce 55D
//很棒的一道数位dp题
//一个好的数是每一数位都可以被这个数整除
//求l至r中的“好数”的个数
/*
	对于所有这类问题，考虑状态
（到第几位，flag，关于用过数位的mask）
	dp[i][j][k]=# of beautiful number up to i-th digit, with accumulated sum equals j, used digits' lcm = k
	理由：注意到若每一个数位都可以被此数整除则说明所有数位的最小公倍数也可以被整除，
	所以说与其使用bit mask来表示已经使用的数字不如记录最小公倍数
	注意到数的加和可以至多为10的18次方，这显然太大了，所以我们要想办法在不影响结果的前提下缩小这个值。
	发现0至9的最小公倍数是2520，所以我们只要存取模2520的余数即可
	这样dp状态可以为20*2520*2520，仍然太大，但是我们注意到任意数位们的最小公倍数一定整除2520，
	所以我们将数据离散化，将2520的所有因数离散化，共48个因数。
	所以，我们成功将状态大小缩小为20*2520*48 ！
	这样就可以dp啦！
*/
const int mod=2520;
ll l,r;
ll dp[20][2525][50];
int digits[20],len;
int mp[3000];

int GCD(int a,int b){
	return a==0?b:GCD(b%a,a);
}

int LCM(int a,int b){
	return a/GCD(a,b)*b;
}

ll DFS(int pos,int sum,int lcm,int flag){//strictly less or equal flag
	if(pos<0)return sum%lcm==0;
	if(!flag&&dp[pos][sum][mp[lcm]]!=-1)return dp[pos][sum][mp[lcm]];
	//only the subproblems with no flag are solved
	int limit=flag?digits[pos]:9;
	ll ret=0ll;
	for(int i=0;i<=limit;++i){
		ll next_lcm=lcm;
		if(i)next_lcm=LCM(i,lcm);
		ret+=DFS(pos-1,(sum*10+i)%mod,next_lcm,flag&&(limit==i));
	}
	if(!flag)dp[pos][sum][mp[lcm]]=ret;
	return ret;
}

ll solve(ll a){
	len=0;
	while(a){
		digits[len++]=a%10;
		a/=10;
	}
	return DFS(len-1,0,1,1);
}

int main(){
	int _;scanf("%d",&_);
	int cnt=0;
	memset(dp,-1ll,sizeof(dp));
	for(int i=1;i<=2520;++i)
		if(2520%i==0)
			mp[i]=cnt++;
	while(_--){
		cin>>l>>r;
		cout<<solve(r)-solve(l-1)<<endl;
	}
	return 0;
}