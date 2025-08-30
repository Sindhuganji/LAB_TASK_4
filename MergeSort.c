#include <stdio.h>
void merge(int arr[],int left,int mid,int right){
    int i,j,k;
    int n1=mid-left+1;
    int n2=right-mid;
    int AL[100],AR[100];
    for(i=0;i<n1;i++){
        AL[i]=arr[left+i];
    }
    for(j=0;j<n2;j++){
        AR[j]=arr[mid+j+1];
    }
    i=0;
    j=0;
    k=left;
    while(i<n1 && j<n2){
        if(AL[i]<=AR[j]){
            arr[k]=AL[i];
            i++;
            k++;
        }
        else{
            arr[k]=AR[j];
            j++;
            k++;
        }
    }
    while(i<n1){
        arr[k]=AL[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=AR[j];
        j++;
        k++;
    }
}
void mergesort(int arr[],int left,int right){
    int mid;
    if(left<right){
        mid= (int )left+right/2;
        mergesort(arr,left,mid);
        mergesort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}
int main(){
    int i,n,arr[100];
    printf("\nEnter n value:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("\nEnter element %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    mergesort(arr,0,n-1);
    printf("\nSorted array:  ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}