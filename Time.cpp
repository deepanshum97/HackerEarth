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

int dp[10000];

int process(int a, int b, int c, int d)
{
    return (a*10 + b)*60 + c*10 + d;
}

int main()
{
    int N;
    scanf("%d", &N);
    for (int i=1 ; i<=N ; i++)
    {
        char str[15];
        scanf("%s", str);
        int a = process(str[0]-'0', str[1]-'0', str[3]-'0', str[4]-'0');
        int b = process(str[6]-'0', str[7]-'0', str[9]-'0', str[10]-'0');
        for (int i=a ; i<b ; i++)
            dp[i] += 1;        
    }
    
    for (int i=0 ; i<=1440 ; i++)
    {
        if (dp[i] > 1)
        {
            printf("Will need a moderator!\n");
            return 0;
        }    
    }
        
    printf("Who needs a moderator?\n");
    return 0;    
}
