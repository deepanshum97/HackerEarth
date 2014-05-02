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

int main()
{
    int t;
    scanf("%d", &t);
    LL table[] = {1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, 208012, 742900, 2674440, 9694845, 35357670, 129644790, 477638700, 1767263190LL, 6564120420LL, 24466267020LL, 91482563640LL, 343059613650LL, 1289904147324LL, 4861946401452LL, 18367353072152LL, 69533550916004LL, 263747951750360LL, 1002242216651368LL, 3814986502092304LL};
    int len = sizeof(table) / sizeof(LL);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        printf("%lld\n", table[n-1]);  
    }
    
    return 0;    
}
