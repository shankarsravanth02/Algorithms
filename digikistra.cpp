#include<stdio.h>
#include<limits.h>
int i,u,n,j;
int  min_dist(int dist[],bool S[],int n ) ;
int printSolution(int dist[], int n) ;

int  min_dist(int dist[], bool S[],int n)  // S=source
{   
   int min=INT_MAX,min_index;
   for (int v=0;v<n;v++)
       if (S[v] == false && dist[v] <= min)
                min = dist[v], min_index = v;
   return min_index;
           
}

void dijkstra(int cost[10][10],int start,int n)// start is source vertex
{  
   int dist[n], i,count=0,v; bool S[n];
   for ( i = 0; i < n; i++)
      dist[i] = INT_MAX, S[i] = false;
      dist[start] = 0;
    for ( count = 0; count < n - 1; count++)
	{
      int u = min_dist(dist,S,n);
      S[u] = true;      
      for ( v = 0; v < n; v++)
        {  if ( ( !S[v] && cost[u][v] ) && ( dist[u] != INT_MAX))
		           if(  dist[u] + cost[u][v] < dist[v]  ) 
		               dist[v] = dist[u] + cost[u][v];
        }
    }
	printSolution(dist, n);
}
  
int printSolution(int dist[], int n) 
       
 {   
    printf("the dijkstra matrix is:\n" );
    printf("Vertex Distance from Source\n");
	for (int i = 0; i < n; i++)
		printf("%d to %d\n", i, dist[i]);
}

int main()
{
	int cost[10][10], n;
	printf(" Dijkstra's Single source shortest path algorithm:");
	printf("\n enter the no.of vertices ",n);
	scanf("%d",&n);
	printf("enter the cost adjacancy matrix :");		
    for (i=0;i<n;i++)
	  for (j=0;j<n;j++)
	    {  scanf("%d",&cost[i][j]);
//	      if(cost[i][j]==0)
//	          cost[i][j]=999;
	          
        }
    
   /* int cost[10][10] = { { 0, 6, 0, 0, 0, 0, 0, 8, 0 },
      { 6, 0, 8, 0, 0, 0, 0, 13, 0 },
      { 0, 8, 0, 7, 0, 6, 0, 0, 2 },
      { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
      { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
      { 0, 0, 6, 14, 10, 0, 2, 0, 0 },
      { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
      { 8, 13, 0, 0, 0, 0, 1, 0, 7 },
      { 0, 0, 2, 0, 0, 0, 6, 7, 0 }
   };*/
   dijkstra(cost,0,n);
   return 0;
        
}
