#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <sstream>
#include <complex>
using namespace std;
//not dp
int n,ret;
int a[1000000];

int main(){
	while(scanf("%d",&n) != EOF){
		memset(a,0,sizeof(a));
		int ret = -1, cnt = 0;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			if(!cnt)ret = a[i],cnt++;
			else{
				if(a[i] != ret)cnt--;
				else cnt++;
			}
		}
		cout << ret << endl;
	}
	return 0;
}