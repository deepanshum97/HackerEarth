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

int N, M, Q;
map<int, pair<int, int> > ans;

int main()
{
    scanf("%d %d", &N, &M);
    for (int i=1 ; i<=N ; i++)
    {
        for (int j=1 ; j<=M ; j++)
        {
            int x;
            scanf("%d", &x);
            ans[x] = mp(i, j);       
        }    
    }
    
    scanf("%d", &Q);
    for (int i=0 ; i<Q ; i++)
    {
        int x;
        scanf("%d", &x);
        if (ans[x].first!=0 && ans[x].second!=0)
            printf("%d %d\n", ans[x].first-1, ans[x].second-1);
        else
            printf("-1 -1\n");    
    }
    return 0;    
}
