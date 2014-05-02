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

char str[1000];

int main()
{
     scanf("%s", str);
     bool l, o, v, e;
     l = o = v = e = false;
     for (int i=0 ; i<strlen(str) ; i++)
     {
         if (!l && str[i]=='l')
         {
             l = true;       
         }    
         else if (l && !o && str[i]=='o')
         {
             o = true;     
         }
         else if (l && o && !v && str[i] == 'v')
         {
             v = true;     
         }
         else if (l && o && v && !e && str[i] == 'e')
         {
             e = true;     
         }
         else
         {
             // do nothing    
         }
     }
     
     if (l && o && v && e)
         printf("I love you, too!\n");
     else
         printf("Let us breakup!\n");
         
     return 0;    
}
