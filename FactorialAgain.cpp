#include <cstdio>
#include <cstdlib>

using namespace std;

typedef long long LL;

LL modFact(LL n, LL p) 
{ 
    LL res = 1; 
    while (n > 0) 
    { 
        for (LL i = 1, m = n % p; i <= m; i++) res = (res * i) % p; 
        if ((n /= p) % 2 > 0) res = p - res; 
    } 
    return res; 
}

LL N, P;

LL bigMod(LL a, LL b, LL c)
{
   LL x, y;
   x = a;
   y = 1;
   
   while (b)
   {
       if (b & 1)
           y = (y * x) % c;
           
       b = b / 2;
       x = (x * x) % c;      
   }             
   
   return y;
}

int T;
int main()
{
    scanf("%d", &T);

    while (T--)
    {
        scanf("%lld", &N);
        scanf("%lld", &P);
        LL n = 3LL*N;
        LL m = n % P;
                     
        if (n >= P)
            printf("0\n");
        else
        {             
            LL deno = bigMod(6LL, N, P);   
            deno = bigMod(deno, P-2, P);
            LL nume = 1;
            for (LL i=n+1 ; i<P ; i++)
                nume = (nume * i)%P;
            
            nume = bigMod(nume, P-2, P);
            nume = P - nume;
            printf("%lld\n", (nume * deno) % P);
        }
    }
    return 0;    
}
