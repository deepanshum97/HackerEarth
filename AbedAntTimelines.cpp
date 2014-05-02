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
#include <list>
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

int T, N, M, P;

int main()
{
    scanf("%d", &T);
    while (T--)
    {
       scanf("%d %d", &N, &M);
       int x1, y1, x2, y2;
       scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
       scanf("%d", &P);
       int x = MIN(ABS(x2 - x1), N - ABS(x2 - x1));
       int y = MIN(ABS(y2 - y1), M - ABS(y2 - y1));
       
       int ans = (x + y)*P;
       if (ans <= 1000)
       {
           printf("%d\n", ans);
           printf("You saved the group.\n");
       }
       else
       {
           printf("%d\n", ans); 
           printf("Let go of the group.\n"); 
       }     
    }
    return 0;    
}
