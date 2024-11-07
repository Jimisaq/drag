#include <stdio.h>
#include <limits.h>

#define ROWS 3
#define COLS 3

typedef struct{
    int value;
    int row;
    int column;
}MinMax;

//function to find minimum element
    MinMax findMin(int a[ROWS][COLS]){
        MinMax min;
        min.value = INT_MAX;

        for(int i=0;i<ROWS; i++){
            for (int j=0;j<COLS;j++){
                if(a[i][j] < min.value){
                    min.value = a[i][j];
                    min.row = i;
                    min.column = j;
                }
            }
        }
        return min;
    }

//function to find maximum element
    MinMax findMax(int a[ROWS][COLS]){
        MinMax max;
        max.value = INT_MIN;

        for(int i=0;i<ROWS; i++){
            for (int j=0;j<COLS;j++){
                if(a[i][j] > max.value){
                    max.value = a[i][j];
                    max.row = i;
                    max.column = j;
                }
            }
        }
        return max;
    }

//function to print the array
    void printArray(int a[ROWS][COLS]){
        for(int i=0;i<ROWS; i++){
            for (int j=0;j<COLS;j++){
                printf("%d ",a[i][j]);
            }
            printf("\n");
        }
    }

//main method
    int main(){
        int a[ROWS][COLS] = {{7,2,3},{4,5,9},{1,8,6}};

        printf("2D Array: \n");
        printArray(a);

        MinMax min = findMin(a);
        MinMax max = findMax(a);

        printf("Minimum Element: %d at (%d, %d).\n", min.value, min.row, min.column);
        printf("Maximum Element: %d at (%d, %d).\n", max.value, max.row, max.column);

        return 0;
    }