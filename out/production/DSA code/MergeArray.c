#include <stdio.h>
int main(){

    //initialising sizes of the array
        int n1 = 5;
        int n2 = 5;
        int n = n1+n2;

    //initialising two single dimension arrays
        int arr1[n1];
        int arr2[n2];

    //initialising merged array
        int mergedarr[n];

    //populating the first array
        for(int i=0;i<n1;i++){
            arr1[i]=i*i;
        }

    //populating the second array
        for(int i=0;i<n2;i++){
            arr2[i]=i*2;
        }

    //printing elements in the first array
        printf("First array: \n");

        for(int i=0;i<n1;i++){
            printf("%d \n" ,arr1[i]);
        }

    //printing elements in the second array
        printf("Second array: \n");

        for(int i=0;i<n2;i++){
            printf("%d \n" ,arr2[i]);
        }

    //initialising counters for the arrays
        int i = 0;
        int i1 = 0;
        int i2 = 0;

    //populating the merged array with elements of the first array
        for(int j=0;j<n1;j++){
                mergedarr[i] = arr1[i1];
                i = i+1;
                i1 = i1+1;
        
        }

    //populating the merged array with elements of the second array
        for(int j=0;j<n2;j++){
                mergedarr[i] = arr2[i2];
                i = i+1;
                i2 = i2+1;
        }


    //printing elements in the merged array
        printf("The merged array is: \n");

        for(int j=0;j<n;j++){
            printf("%d, ", mergedarr[j]);
        }

}