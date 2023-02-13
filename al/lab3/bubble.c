#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n, i, j, t, opc = 0;
    printf("enter number of elements ");
    scanf("%d", &n);
    int a[n];
    printf("enter elements\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(i = n; i > 0; i--){
        for(j = 0; j < i; j++){
            if(a[j] > a[j+1]){
                opc++;
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }
    printf("sorted array:\n");
    for(i = 0; i < n; i++)
        printf("%d", a[i]);
    printf("\nopcount is: %d", opc);
}