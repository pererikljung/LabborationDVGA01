#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort(int rows, int cols, int array[rows][cols]);

int main(){
    int ARRAY_ROW_SIZE = 10;
    int ARRAY_COL_SIZE = 10;
    int MAX_ARRAY_VALUE = 900;
    int MIN_ARRAY_VALUE = 0;
    int number_array[ARRAY_ROW_SIZE][ARRAY_COL_SIZE];
    int selected_menu[3];
    int choice;
    int in_menu = 1;
    int i,j,k;
    
    srand(time(0));
    printf("1. Generera en slumpmässad talföljd\n2. Sortera en genererad talföljd.\n3. Visa medelvärde, medianvärde samt min- och maxvärde\n4. Sök efter valfritt tal\n");
    while(in_menu == 1){
        printf("Välj alternativ: ");
        scanf("%d", &choice);
        switch (choice){
            case 1: 
                selected_menu[0] = 1;
                for(i = 0; i < ARRAY_ROW_SIZE; i++){
                    for(j = 0; j < ARRAY_COL_SIZE; j++){
                        number_array[i][j] = (rand() % (MAX_ARRAY_VALUE - MIN_ARRAY_VALUE + 1 )) + MIN_ARRAY_VALUE;
                        printf("%d ", number_array[i][j]);
                    }
                    printf("\n");
                }
                break;
            case 2: 
                if(selected_menu[0] != 1){
                    printf("Vänligen skapa en talföljd först. \n");
                    break;
                }
                sort(ARRAY_ROW_SIZE, ARRAY_COL_SIZE, number_array[ARRAY_ROW_SIZE][ARRAY_COL_SIZE]);
                break;
            default:
                printf("Oh no");
                in_menu = 0;
        }
    }
}

void sort(int rows, int cols, int array[rows][cols]){
    int temp_array_val;
    for(int k = 0; k < (rows * cols); k++){
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols - 1; j++){
                if(array[i][j] > array[i][j + 1]){
                    temp_array_val = array[i][j];
                    array[i][j] = array[i][j + 1];
                    array[i][j + 1] = temp_array_val;
                }
            }
        }
        for(int i=0; i<rows-1; i++)
        {
            if (array[i][cols-1]>array[i+1][0]){
                temp_array_val=array[i][cols-1];
                array[i][cols-1]=array[i+1][0];
                array[i+1][0]=temp_array_val;
            }
        }
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                printf("%d ", array[i][j]);
            }
            printf("\n");
        }
    }
}
