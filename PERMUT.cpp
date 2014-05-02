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
#define MAX 105

int graph[MAX][MAX];
int K;
int num[MAX];
int newNum[MAX];
int visited[MAX];

void dfs(int s, vector<int> & pos)
{
    visited[s] = 1;
    pos.pb(s);
    
    for (int e=0 ; e<K ; e++)
        if (graph[s][e]>0 && !visited[e])
            dfs(e, pos);                
}

int main()
{
    scanf("%d", &K);
    for (int i=0 ; i<K ; i++)
        scanf("%d", &num[i]);
        
    for (int i=0 ; i<K ; i++)
    {
        newNum[i] = -1;
        char line[1000];
        scanf("%s", line);
        for (int j=0 ; j<K ; j++)
            if (line[j] == 'Y')
                graph[i][j] = graph[j][i] = 1;    
    }        
    
    for (int i=0 ; i<K ; i++)
    {
        vector<int> pos;
        if (!visited[i])
            dfs(i, pos);
        
        if (pos.size() == 0)
            continue;
                
        vector<int> numbers;
        for (int j=0 ; j<pos.size() ; j++)
            numbers.pb(num[pos[j]]);
            
        sort(numbers.begin(), numbers.end());
        sort(pos.begin(), pos.end());        
        
        assert(pos.size() == numbers.size());
        for (int j=0 ; j<pos.size() ; j++)   
            newNum[pos[j]] = numbers[j];                
    }
    
    for (int i=0 ; i<K ; i++)
        if (newNum[i] == -1)
            newNum[i] = num[i];
            
    for (int i=0 ; i<K ; i++)
        printf("%d ", newNum[i]);
   
    return 0;    
}
