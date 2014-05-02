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
#define MaxN 100009

using namespace std;

vector<int> primeList(int lo, int hi)
{
    int n = lo;
    int m = hi;
    int prime[40000];
    for (int i=0 ; i<40000 ; i++)
        prime[i] = 0;
    
    for (int p = 2 ; p*p <= m ; p++)
    {
        int less = n/p;
        less = less*p;
        for (int j=less ; j<=m ; j = j + p)
        {
            if ((j!=p) && (j>=n))
                prime[j-n] = 1;
        }    
    }
    
    vector<int> primes;
    for (int i=0 ; i<m-n+1 ; i++)
    {
        if (prime[i]==0 && (n+i)!=1)
            primes.pb(n+i);    
    }            
    
    return primes;
}

int X, Y, T;

int main()
{
    vector<int> primes = primeList(1, 31623);
    for (int i=0 ; i<primes.size() ; i++)
        primes[i] *= primes[i];
        
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d", &X, &Y);
        if (X > Y)
        {
           int tmp = X;
           X = Y;
           Y = tmp;      
        }
        
        vector<bool> mark(Y - X + 1, true);
        for (int i=2 ; i*i<=Y ; i++)
        {
            int gap = i*i;
            int base = X + (gap - X%gap)%gap;
            
            for (int i=base ; i<=Y ; i = i + gap)
                mark[i-X] = false;
        }
        
        printf("%d\n", count(mark.begin(), mark.end(), true));
    }     
    return 0;
}
