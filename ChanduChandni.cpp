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

int hashTable[2000008];
const double phi = (double)(1 + sqrt(5))/2.0;

int main()
{
    for (int i=1 ; i<=1000000 ; i++)
        hashTable[i] = -1;
    for (int i=1 ; i<=1000000 ; i++)
        hashTable[(int)((double)i*phi)] = (int)(phi*phi*i);    

    int t;
    scanf("%d", &t);
    while(t--)
    {
         int a, b;
         scanf("%d %d", &a, &b);
         if (hashTable[a] == b)
             printf("Chandu\n");
         else 
             printf("Chandni\n");           
    }
    
    return 0;
}
