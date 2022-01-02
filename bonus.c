#include "utils.h"
#include "counting.h"

//----- Counting Sort -----

/**
 * //TODO: Implementarea algoritmului counting sort
 * Restrictii: 0 <= arr[i] < 50
 * Dimensiunea vectorului de frecventa va fi 50
 * @param arr - vectorul care trebuie sortat
 * @param dim - dimensiunea vectorului
 * @return vectorul de frecventa utilizat in algoritm
 */
int* countingSort(int *arr, int dim)
{  int count[50]={0};
   int *sorted;

   sorted =(int *) malloc( dim * sizeof(int));
   int i,max=-9999;
   for(i=0;i<dim;i++){
       if(arr[i]>max)
       max=arr[i];
   }
   for(i=0;i<dim;i++){
       count[arr[i]]=count[arr[i]]+1;
   }
   for(i=0;i<max;i++){
       count[i+1]=count[i+1]+count[i];
   }
   for(i=dim-1;i>=0;i--) 
    {
        sorted[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
  for (i=0;i<dim;i++)
        arr[i]=sorted[i];

   free(sorted);
   return count;

}

/**
 * //TODO: Care este complexitatea spatiala si cea temporala? O(dim+50),O(dim+50)
 * De ce nu este mai folosit? La valori mai mari, consuma foarte multa memorie.
 * 
 */