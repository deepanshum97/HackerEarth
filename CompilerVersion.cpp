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

char line[2007][70];

void process(int i)
{
    int len = strlen(line[i]);
    bool state = false;
    for (int j=0 ; j<len ; )
    {
        if (state)
        {
            printf("%c", line[i][j]);
            j = j + 1;          
        }
        else if (line[i][j]=='/' && line[i][j+1]=='/')
        {
            printf("%c%c", line[i][j], line[i][j+1]); 
            state = true;
            j = j + 2;                 
        }    
        else if (!state && line[i][j]=='-' && line[i][j+1]=='>')
        {
            printf(".");
            j = j + 2;     
        }
        else 
        {
            printf("%c", line[i][j]);
            j = j + 1;
        }
    }     
    printf("\n");
}

int main()
{
     int index = 0;
     while(1)
     {
         scanf("%[^\n]",line[index++]);
         char c = getchar();
         if(c == EOF)
             break;
     }
     
     int len = index;
     for (int i=0 ; i<len ; i++)
     {
         process(i);    
     }
     return 0;    
}
