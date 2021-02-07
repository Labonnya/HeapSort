#include<stdio.h>
 int a[100],n,i;
void swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;

}
void maxHeapify(int a[],int n,int i)
{
    int largest=i;
    int l = 2*i+1;
    int r = 2*i+2;
    while(l<n && a[largest]<a[l])
    {
        largest=l;
    }
    while(r<n && a[largest]<a[r])
    {
        largest=r;
    }
    if(largest!=i)
    {
        swap(&a[largest],&a[i]);
        maxHeapify(a,n,largest);
    }
}

void heapsort (int a[],int n)
{
    for(i=(n/2)-1;i>=0;i--)
    {
        maxHeapify(a,n,i);
    }
    for(i=n-1;i>=0;i--)
    {
        swap(&a[i],&a[0]);
        maxHeapify(a,i,0);
    }
}

int main()
{
    printf("Enter number of elements for array: \n");
    scanf("%d",&n);
    printf("Enter elements for array: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    heapsort(a,n);
    printf("Sorted array is : ");
    for(i=0;i<n;i++)
    {
        printf(" %d ",a[i]);
    }
}
