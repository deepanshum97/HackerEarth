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
#define MaxN 100005

LL M[10006];

int T, N;

// computes gcd(a,b)
int gcd(int a, int b) 
{
  int tmp;
  while(b){a%=b; tmp=a; a=b; b=tmp;}
  return a;
}

LL bigMod(LL a, LL b, LL c)
{
    LL x=1, y = a;       
    while (b)
    {
        if (b & 1)
            x = (x * y) % c;
            
        b = b/2;
        y = (y*y)%c;      
    }
    
    return x;
}

int main()
{
    LL mod = 1000000007LL;
    for (int p=1 ; p<=10000 ; p++)
    {
        for (int i=p ; i<=10000 ; i = i + p)
        {
            // printf("%d %d\n", p, i);
            if (gcd(i, p) == p)
                M[i] = (M[i] + bigMod((LL)p, (LL)i, mod)) % mod;
        }    
    }

    LL dp[10005];
    dp[0] = 0;
    for (int i=1 ; i<=10000 ; i++)
        dp[i] = (dp[i-1] + M[i])%mod; 
    scanf("%d", &T);
    while (T--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%lld\n", (dp[b] - dp[a-1] + mod)%mod);
    }
    return 0;    
}
