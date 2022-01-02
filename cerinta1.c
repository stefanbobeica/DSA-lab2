#include "merge.h"
#include "quick.h"
#include "utils.h"

//----- MergeSort -----

/**
 * //TODO: Implementarea metodei "merge" din cadrul algoritmului Merge Sort
 * @param arr - vectorul care trebuie sortat
 * @param left - pozitia initiala
 * @param middle - pozitia din mijloc
 * @param right - pozitia finala
 */
void merge(int *arr, int left, int middle, int right)
{ 
int n1,n2,i,j;
n1 = middle - left + 1;
n2 = right - middle ;
int *left_arr , *right_arr;
left_arr=(int *)malloc(n1*sizeof(int));
right_arr=(int *)malloc(n2*sizeof(int));
for (i=0 ; i < n1 ; i++){
   left_arr[i]=arr[left+i];
}
for (i=0 ; i < n2 ; i++){
   right_arr[i]=arr[middle+1+i];
}
   
   i=0;
   j=0;
   
   int k=left;
  while((i<n1) && (j<n2)){
       if(left_arr[i]<right_arr[j]){
           arr[k]=left_arr[i];
           i=i+1;
       }
       else{
           arr[k]=right_arr[j];
           j=j+1;
          }
           k=k+1;

   }
     while(i<n1){
         arr[k]=left_arr[i];
         i++;
         k++;
     }
     while(j<n2){
         arr[k]=right_arr[j];
         j++;
         k++;
     }
free(left_arr);
free(right_arr);


}


/**
 * //TODO: Implementarea metodei "mergesort" din cadrul algoritmului Merge Sort
 * @param arr - vectorul care trebuie sortat
 * @param left - pozitia initiala
 * @param right - pozitia finala
 */
void mergesort(int *arr, int left, int right)
{ int middle;
    
    if(left<right){
        middle=left+(right-left)/2;
        mergesort(arr,left,middle);
        mergesort(arr,(middle+1),right);
        merge(arr,left,middle,right);

}

}

//----- Quick Sort -----

/**
 * //TODO: Implementarea metodei de interschimbare a doua elemente
 * @param x - primul element
 * @param y - al doilea element
 */
void swap(int *x, int *y)
{int aux;
aux=*x;
*x=*y;
*y=aux;

}

/**
 * //TODO: Implementarea metodei de partitionare din cadrul algoritmului Quick Sort
 * Consideram pivotul a fi ultimul element din vector
 * @param arr - vectorul care trebuie sortat
 * @param low - pozitia initiala
 * @param high - pozitia finala
 */
int partition(int *arr, int low, int high)
{ int pivot;
pivot=arr[high];
int i=low-1;
for(int j = low; j < high-1 ;j++)
{   if(arr[j]<=pivot){
      i++;
      swap(arr+i,arr+j);
}
}
swap(arr+i+1,&pivot);
return (i+1);
}

/**
 * //TODO: Implementarea metodei "quicksort" din cadrul algoritmului Quick Sort
 * @param arr - vectorul care trebuie sortat
 * @param low - pozitia initiala
 * @param high - pozitia finala
 */
void quicksort(int *arr, int low, int high)
{     int q;
    if(low<high){
    q=partition(arr,low,high);


quicksort(arr,low,(q-1));
quicksort(arr,(q+1),high);
    }
}

//----- Analiza functiilor -----

/**
 * //TODO: Care dintre metodele anterior implementate reprezinta metode de sortare stabile
 * si care reprezinta metode de sortare instabile? Argumentati.
 * Quick sort este instabil, deoarece poate inversa 2 elemente identice.
 * Merge sort este stabil, deoarece nu inverseaza 2 elemente identice.
 */