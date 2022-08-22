#include <stdio.h>
#include<stdlib.h>
#include<stdint.h>

#define maxSizeArray1 5
#define maxSizeArray2 3
#define maxSizeArray3 maxSizeArray1+maxSizeArray2

uint32_t *mergearray(uint32_t *a, uint32_t *b)
{
  
    uint32_t *arr3, i, j;
    arr3 = (uint32_t*) malloc(maxSizeArray3*sizeof(uint32_t));

    for (i = 0; i < maxSizeArray1; i++) {
        arr3[i] = a[i];
    }
  
    for (i = 0, j = maxSizeArray1;
         j < maxSizeArray3 && i < maxSizeArray2; i++, j++) {
        arr3[j] = b[i];
    }
  
    return arr3;
}
// sort
void swap(uint32_t* xp, uint32_t* yp)
{
    uint32_t temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(uint32_t *arr, uint32_t n)
{
    uint32_t i, j, min_idx;
 
    for (i = 0; i < n - 1; i++) {
 
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
 
        swap(&arr[min_idx], &arr[i]);
    }
}

void search(uint32_t index, uint32_t *arr){
    if (index < arr[0] && index > arr[maxSizeArray3-1]){
        printf("Element is not present in array\n");
    } else{
        int result = binarySearch(arr, 0, maxSizeArray3-1, index);
        (result == -1)
            ? printf("Element is not present in array\n")
            : printf("Element is present at index %d \n", result);
    }
    
}
int binarySearch(int *arr, int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
 
        if (arr[mid] == x)
            return mid;
 
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
 
        return binarySearch(arr, mid + 1, r, x);
    }
 
    return -1;
}

uint32_t main(uint32_t argc, char* argv[]){
    uint32_t *arr1, *arr2, *arr3;

    arr1 = (uint32_t*) malloc(maxSizeArray1*sizeof(uint32_t));
    arr2 = (uint32_t*) malloc(maxSizeArray2*sizeof(uint32_t));
    arr3 = (uint32_t*) malloc(maxSizeArray3*sizeof(uint32_t));
    
    uint32_t i;
    printf("Input array 1: ");
    for (i = 0; i < maxSizeArray1; ++i){
        scanf("%d",&arr1[i]);
    }
    printf("\nInput array 2: ");
    for (i = 0; i < maxSizeArray2; ++i){
        scanf("%d",&arr2[i]);
    }

    arr3 = mergearray(arr1,arr2);
    selectionSort(arr3,maxSizeArray3);

    printf("result sort: ");
    for (i = 0; i < maxSizeArray3; ++i){
        printf("%d ",*(arr3+i));
    }
    printf("\nInput index: ");
    int index;
    scanf("%d",&index);
    search(index,arr3);
    return 0;
}