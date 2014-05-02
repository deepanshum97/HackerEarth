#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

#define pb push_back
#define MaxN 100007
#define LogN 20 

int L[MaxN], P[2*MaxN][LogN], T[MaxN]; 
int N;

// Representation of the original graph or tree
struct Node 
{
   int v;
   Node *next; 
};

Node * head[MaxN];
Node * insert(Node *x, int k)
{
    Node * temp = new Node;
    temp->v = k; 
    temp->next = x;
    return temp; 
}

void preProcess()
{
    // Initialization
    for (int i=0 ; i<=N ; i++)
        for (int j=0 ; (1<<j) <= N ; j++)
            P[i][j] = -1;
    
    for (int i=1 ; i<=N ; i++)
        P[i][0] = T[i];
         
    // bottom up dynamic programming
    for (int j=1 ; (1<<j) <= N ; j++)
        for (int i=1 ; i<=N ; i++)   
            if (P[i][j-1] != -1)
               P[i][j] = P[P[i][j-1]][j-1]; 
}

int lca(int p, int q)
{
    int tmp, log, i;
   
   //if p is situated on a higher level than q then we swap them
   if (L[p] < L[q])
       tmp = p, p = q, q = tmp;
  
   //we compute the value of [log(L[p)]
   for (log = 1; 1 << log <= L[p]; log++);
       log--;
   
   //we find the ancestor of node p situated on the same level
   //with q using the values in P
   for (i = log; i >= 0; i--)
       if (L[p] - (1 << i) >= L[q])     
           p = P[p][i];
   
   if (p == q)
       return p;
   
   //we compute LCA(p, q) using the values in P
   for (i = log; i >= 0; i--)
       if (P[p][i] != -1 && P[p][i] != P[q][i])     
           p = P[p][i], q = P[q][i];
               
   return T[p];   
}

// initialize level of the tree
void dfs(int s, int h)
{
    L[s] = h;
    for (Node * x = head[s] ; x != NULL ; x = x->next)
    {
        if (x->v != T[s])
            dfs(x->v, h+1);    
    }     
}

int M;

int main()
{
    int t;
    scanf("%d", &t);
    T[1] = -1;
    L[1] = 0;
    
    while (t--)
    {
        scanf("%d", &N);
        N++;
        for (int i=0 ; i<=N ; i++)
            head[i] = NULL;
            
        for (int i=2 ; i<=N ; i++)
        {
            int u;
            scanf("%d", &u);
            u++;
            head[i] = insert(head[i], u);   
            head[u] = insert(head[u], i);
            T[i] = u;
        }
        
        dfs(1, 0);
        preProcess();
               
        int q;
        scanf("%d", &q);
        for (int i=1 ; i<=q ; i++)
        {
            int u, v;
            // u will send message to v
            scanf("%d %d", &u, &v);    
            u++;
            v++;
            
            if (lca(u, v) == v)
                printf("%d\n", L[u] - L[v] - 1);           
            else
                printf("-1\n");
        }   
    }
    return 0;   
}
