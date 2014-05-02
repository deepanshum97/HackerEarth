#include <cstdio>

using namespace std;

bool contains(int n)
{
     while (n)
     {
        if (n%100 == 21)
           return true;
        n = n/10;          
     }         
     return false;
}

int main()
{
    int t;
    scanf("%d", &t);
    
    while (t--)
    {
        int n;
        scanf("%d", &n);
        if (n%21 == 0)
        {
             printf("The streak is broken!\n");    
        }
        else if (contains(n))
        {
             printf("The streak is broken!\n");
        }
        else 
        {
            printf("The streak lives still in our heart!\n"); 
        }      
    }
    return 0;
}
