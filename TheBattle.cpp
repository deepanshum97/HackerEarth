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
#define MOD 1000000007LL

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
    LL N;
    LL num[5];
    for (int i=1 ; i<=4 ; i++)
        num[i] = bigMod(i, MOD-2, MOD);
        
    scanf("%lld", &N);
    LL ans = 1;
    for (int i=0 ; i<4 ; i++)
        ans = (ans * (N-i)) % MOD;
        
    for (int i=1 ; i<=4 ; i++)
        ans = (ans * num[i]) % MOD;
        
    printf("%lld\n", (ans + MOD)%MOD);
    return 0;    
}
