#include <stdio.h>
int partitioning(int arr[],int low,int high){
    int pivot,i,j,temp;
    pivot=arr[low];
    i=low+1;
    j=high;
    while(i<=j){
        while(arr[i]<=pivot && i<=high){
            ++i;
        }
        while(arr[j]>pivot && j>=low){
            --j;
        }
        if(i<j){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    temp=arr[low];
    arr[low]=arr[j];
    arr[j]=temp;
    return j;
}
void Quicksort(int arr[],int low,int high){
    int p;
    if(low<high){
        p=partitioning(arr,low,high);
        Quicksort(arr,low,p-1);
        Quicksort(arr,p+1,high);
    }
}
int main(){
    int arr[100],n,i;
    printf("\nEnter n value: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("\nEnter element at %d: ",i);
        scanf("%d",&arr[i]);
    }
    Quicksort(arr,0,n-1);
    printf("\nSorted Array: ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}