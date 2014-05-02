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

int T, N, M;
int dp[100000];

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d", &M, &N);
        vector<int> arr;
        for (int i=0 ; i<N ; i++)        
        {
            int x;
            scanf("%d", &x);
            arr.pb(x);    
        }
        
        sort(arr.begin(), arr.end());
        memset(dp, 0, sizeof dp);
        
        for (int i=0 ; i<N ; i++)
            dp[arr[i]] = 1;
            
        for (int i=1 ; i<=M ; i++)
        {
            if (!dp[i])
            {
                for (int j=0 ; j<N ; j++)
                {
                    if (i-arr[j]>=0 && !dp[i-arr[j]])
                    {
                        dp[i] = 1;
                        break;                
                    }       
                }           
            }    
        }
        
        if(dp[M])
            printf("Little Deepu\n");
        else
            printf("Kate\n");
    }
    return 0;    
}
