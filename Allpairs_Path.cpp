#include<stdio.h>
int i,j,k;
int cost[200][200],A[200][200];
int n;
      

void AllPairs(int cost[200][200],int n)
{   
    int Min;
    
	for(i=0;i<n;i++)
	   for(j=0;j<n;j++)
	        A[i][j]=cost[i][j]; // Copying cost to A matrix
	        
	for (k = 0; k < n; k++) 
	{
       for (i = 0; i < n; i++) 
	   {
            for (j = 0; j < n; j++)
            
		   {  
		        if(i==j)
		             A[i][j]=0; // a[1][1]=0
		        else 		        	
		            Min = A[i][k] + A[k][j];
                    if ( Min < A[i][j])
                       {
				         A[i][j] = Min;
                       }
            }
        }
          
    }
    printf("the all pairs floyd warshell matrix is:\n" );
    for (int i = 0; i < n; i++) 
	{
    for (int j = 0; j < n; j++) 
	{
        
		         
        printf("%4d", A[i][j]);
    }
    printf("\n");
   }
     
}


int main()
{
        printf("All pairs shortest path algorithm\n");
    	printf("\nEnter the no. of vertices:");
    	scanf("%d",&n);
    	printf("\nEnter the cost adjacency matrix:\n");
    	for(i=0;i<n;i++)    
			for(j=0;j<n;j++)
    		{
    			scanf("%d",&cost[i][j]);
    			if(cost[i][j]==0)
    				cost[i][j]=999;
    		}
  
    
    AllPairs(cost,n);
	  
}



/*
#include<stdio.h>
int min(int,int);
void floyds(int p[10][10],int n)
{
 int i,j,k;
 for(k=1;k<=n;k++)
  for(i=1;i<=n;i++)
   for(j=1;j<=n;j++)
    if(i==j)
     p[i][j]=0;
    else
     p[i][j]=min(p[i][j],p[i][k]+p[k][j]);
}
int min(int a,int b)
{
 if(a<b)
  return(a);
 else
  return(b);
}
void main()
{
 int p[10][10],w,n,e,u,v,i,j;;
 printf("\n Enter the number of vertices:");
 scanf("%d",&n);
 printf("\n Enter the number of edges:\n");
 scanf("%d",&e);
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
   p[i][j]=999;
 }
 for(i=1;i<=e;i++)
 {
  printf("\n Enter the end vertices of edge%d with its weight \n",i);
  scanf("%d%d%d",&u,&v,&w);
  p[u][v]=w;
 }
 printf("\n Matrix of input data:\n");
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
   printf("%d \t",p[i][j]);
  printf("\n");
 }
 floyds(p,n);
 printf("\n Transitive closure:\n");
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
   printf("%d \t",p[i][j]);
  printf("\n");
 }
 printf("\n The shortest paths are:\n");
 for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
  {
   if(i!=j)
    printf("\n <%d,%d>=%d",i,j,p[i][j]);
  }
}
*/
