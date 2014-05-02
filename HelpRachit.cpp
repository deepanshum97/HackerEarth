#include <iostream>
#include <string>
#include <string.h>
#include <cstdlib>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <memory.h>
#include <stdio.h>
#include <ctime>
#include <cmath>
#include <cassert>

using namespace std;
 
#define LL long long
#define U unsigned
#define pnt pair<int,int>
#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define MEMS(a,b) memset((a),(b),sizeof(a))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define ABS(a) (((a)>=(0))?(a):(-(a)))
#define mp make_pair
#define pb push_back
#define ALL(a) a.begin(),a.end()
#define FI(i,b) FOR(i,0,b)
#define V(t) vector < t >
#define sz size()

vector<int> num[10001];
int prime[10006];
int dp[10006];

LL mulmod(LL a, LL b, LL c)
{
	LL x = 0,y = a%c;
	
	while(b>0)
    {
		if(b&1) x = (x+y)%c;
		y = (y<<1)%c;
		b >>= 1;
	}
	
	return x;
}

LL pow(LL a, LL b, LL c)
{
	LL x = 1, y = a;
	
	while(b>0)
    {
		if(b&1) x = mulmod(x,y,c);
		y = mulmod(y,y,c);
		b >>= 1;
	}
	
	return x;
}

bool miller_rabin(LL p, int it)
{
	if(p<2) return false;
	if(p==2) return true;
	if((p&1)==0) return false;
	
	LL s = p-1;
	while(s%2==0) s >>= 1;
	
	while(it--)
    {
		LL a = rand()%(p-1)+1,temp = s;
		LL mod = pow(a,temp,p);
		
		if(mod==-1 || mod==1) continue;
		
		while(temp!=p-1 && mod!=p-1)
        {
			mod = mulmod(mod,mod,p);
			temp <<= 1;
		}
		
		if(mod!=p-1) return false;
	}
	
	return true;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i=3 ; i<10000 ; i = i + 2)
    {
        int sq = i*i;
        int d = i-1;
        num[i].pb(sq - d);
        num[i].pb(sq - 2*d);
        num[i].pb(sq - 3*d);
        num[i].pb(sq - 4*d);
        for (int j=0 ; j<4 ; j++)
        {
            if (miller_rabin(num[i][j], 8))
                prime[i]++;    
        }   
        
        if (i==3)
            dp[i] = prime[i];
        if (i>3)
            dp[i] = dp[i-2] + prime[i];    
    }
    
    while (T--)
    {
         int Q;
         scanf("%d", &Q);
         double ans = (double)dp[Q] / (2*Q - 1);
         printf("%.6lf\n", ans * 100.00);      
    }
    return 0;    
}
