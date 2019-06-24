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
#include <array>
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RREP(i,a,b) for(int i=a;i>=b;i--)
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;

string solve(int A,int B){
	if(!A)return "0";
	string ret="";
	ret+=to_string(A/B);//get integer part
	if(A%B==0)return ret;
	ret+='.';
	//find the integer part
	int r=A%B,pre;
	bool repeat=false;
	map<int,int> a;
	while(!repeat&&r){
		if(a.count(r)){
			pre=a[r];
			repeat=true;
		}
		else{
			a[r]=ret.size();
		}
		r*=10;
		ret+=to_string(r/B);
		r%=B;
	}
	if(repeat)ret+=')',ret.insert(pre,"(");
	return ret;
}

int main(){
	cout<<solve(3,28)<<endl;
	return 0;
}