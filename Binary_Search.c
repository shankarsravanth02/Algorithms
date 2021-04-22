#include <stdio.h>
int main () {
	int i,n,x,arr[200];
	printf("enter n: ");
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
    	scanf("%d",&arr[i]);
	}
	printf("enter number to be searched: ");
	scanf("%d",&x);
    int result = binary_Search(arr, 0, n-1, x);
    printf("%d", result);
    return 0;
}
int binary_Search (int* A, int start, int end, int element) {
    if (end < start)
        return -1;
    else {
        int mid = (end + start) / 2;

        if (A[mid] == element)
            return mid;

        int a, b;
        a = binary_Search(A, start, mid - 1, element);
        b = binary_Search(A, mid + 1, end, element);

        if (a == -1 && b == -1)
            return (char)"No such element found";
        else if (a == -1 && b!= -1)
            return b;
        else
            return a;
    }
}
