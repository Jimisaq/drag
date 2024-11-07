#include <stdio.h>
int main(){
    
    //initializing the arrays.
        int arr1[5] = {1,5,7,3,9};
        int arr2[3][2] = {{1,5},{7,3},{9,8}};
        int arr3[2][2][2] = {{{1,5},{7,3}},{{9,8},{2,4}}};

    //Traversing single dimension array while printing each element 
        printf("Traversing single dimension array\n");

        for(int i=0;i<5;i++){
            printf("Element[%d]: %d \n",i,arr1[i]);
        }

    //printing the base address of the single dimension array
        printf("Base address of single dimension array is: %p\n\n",(void*)&arr1[0]);

    //Traversing two dimension array while printing each element 
        printf("Traversing 2-dimension array\n");

        for(int i=0;i<3;i++){
            for(int j=0;j<2;j++){
                printf("Element[%d][%d]: %d \n",i,j,arr2[i][j]);
            }
        }

    //printing the base address of the two dimension array
        printf("Base address of 2-dimension array is: %p \n\n",&arr2[0][0]);

    //Traversing three dimension array while printing each element
        printf("Traversing 3-dimension array\n");

        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                for(int k=0;k<2;k++){
                    printf("Element[%d][%d][%d]: %d \n",i,j,k,arr3[i][j][k]);
                }
            }
        }

    //printing the base address of the three dimension array
        printf("Base address of 3-dimension array is: %p \n\n",&arr3[0][0][0]);

    return 0;
}