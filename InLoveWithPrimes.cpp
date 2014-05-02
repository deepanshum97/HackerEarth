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

int prime[1000005];
vector<int> primeList(int lo, int hi)
{
    vector<int> primes;
    int n = lo;
    int m = hi;
    
    for (int p=2 ; p*p<=m ; ++p)
    {
        int less = p/n;
        less = less*n;
        
        for (int j=less ; j<=m ; j = j+p)
        {
            if (j!=p && j>=n)
               prime[j-n] = 1;    
        }    
    }                  
    
    for (int i=0 ; i<m-n+1 ; i++)
    {
        if (prime[i]==0 && n+i!=1)
            primes.pb(n+i);    
    }
    
    return primes;
}

int main()
{
    int t;
    scanf("%d", &t);
    vector<int> primes = primeList(1, 100000);
    while (t--)
    {
        int S;
        scanf("%d", &S);
        if (S<4)
            printf("Arjit\n");
        else
        {
            bool flag = false;
            for (int i=0 ; i<primes.size() ; i++)
            {
                if (S - primes[i] <=0)
                    break;
                if (find(primes.begin(), primes.end(), S - primes[i])!=primes.end())
                {
                    flag = true;
                    // printf("%d %d\n", primes[i], S - primes[i]);
                    break;
                }    
            }
            
            if (flag)
                printf("Deepa\n");
            else 
                printf("Arjit\n");    
        }      
    }
    return 0;    
}
