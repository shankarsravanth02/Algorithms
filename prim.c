#include<stdio.h>
#include<limits.h>
#define vertices 5
int minimum_key(int k[], int mst[])  
{  
   int minimum  = INT_MAX, min,i;
      for (i = 0; i < vertices; i++)
      {
         if (mst[i] == 0 && k[i] < minimum )
         {
             minimum  = k[i], min = i;
         }
      }  
   return min;  
}
void prim(int g[vertices][vertices])  
{  
     int parent[vertices];  
     int k[vertices];    
     int mst[vertices];    
     int i, count,u,v;  
     for (i = 0; i < vertices; i++)  
        k[i] = INT_MAX, mst[i] = 0;  
     k[0] = 0;      
     parent[0] = -1;  
     for (count = 0; count < vertices-1; count++)  
     {  
        u = minimum_key(k, mst);  
        mst[u] = 1;
        for (v = 0; v < vertices; v++)  
        {
          if (g[u][v] && mst[v] == 0 && g[u][v] <  k[v])  
          {
             parent[v]  = u, k[v] = g[u][v];
          }
        }
     }  
     for (i = 1; i < vertices; i++)  
     {
        printf("%d  %d    %d \n", parent[i], i, g[i][parent[i]]);
     }
}
void main()  
{  
   int i,j,n,a[n][n];
   printf("enter n:");
   scanf("%d",&n);
   printf("enter elements:");
   for(i=0;i<n;i++)
   {
     for(j=0;j<n;j++)
     {
        scanf("%d",&a[i][j]);
     }
   }
   prim(a);  
}
