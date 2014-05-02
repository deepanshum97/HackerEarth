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
#define ABS(a) (((a)>=(0))?(a):(-(a)))
#define mp make_pair
#define pb push_back
#define ALL(a) a.begin(),a.end()
#define FI(i,b) FOR(i,0,b)
#define V(t) vector < t >
#define sz size()
#define MAX 10007

int K;
char str[MAX], tempStr[MAX];

int main()
{
    scanf("%d", &K);
    scanf("%s", str);
    int len = strlen(str);
    
    int mod = 0;
    char a[1009], b[1009], c[1009];
    strcpy(a, str);
    strcpy(b, str);          
    do
    {
        strcpy(c, b);
        for (int j=0 ; 2*j < len; j++)
            b[2*j] = c[j];    
            
        int k = len-1;
        for (int j=1 ; j<len ; j = j+2)
            b[j] = c[k--];
        
        mod++;    
    } while (strcmp(b, a) != 0);
    
    K = K % mod;
    
    for (int i=1 ; i<=K ; i++)
    {
        strcpy(tempStr, str);
        int j;
        for (j=0 ; 2*j < len; j++)
            str[j] = tempStr[2*j];    
        
        j--;    
        int k = 1;
        for (int l=len-1 ; l>=j+1 ; l--)
            str[l] = tempStr[k], k = k+2;     
    }    
    
    printf("%s\n", str);
    // scanf("%s", str);
    return 0;    
}
