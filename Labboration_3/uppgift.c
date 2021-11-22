#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort(int rows, int cols, int array[rows][cols]);
void find_and_print_values(int rows, int cols, int array[rows][cols]);

int main(){
    int ARRAY_ROW_SIZE = 10;
    int ARRAY_COL_SIZE = 10;
    int HIGH_THRESHOLD_VALUE = 900;
    int LOW_THRESHOLD_VALUE = 0;
    int number_array[ARRAY_ROW_SIZE][ARRAY_COL_SIZE];
    int selected_menu[3];
    int choice;
    int in_menu = 1;
    int i,j;
    
    srand(time(NULL));
    printf("1. Generera en slumpmässad talföljd\n2. Sortera en genererad talföljd.\n3. Visa medelvärde, medianvärde samt min- och maxvärde\n4. Sök efter valfritt tal\n");
    while(in_menu){
        printf("Välj alternativ: ");
        scanf("%d", &choice);
        switch (choice){
            case 1: 
                selected_menu[0] = 1;
				selected_menu[1] = 0;
                for(i = 0; i < ARRAY_ROW_SIZE; i++){
                    for(j = 0; j < ARRAY_COL_SIZE; j++){
                        number_array[i][j] = (rand() % (HIGH_THRESHOLD_VALUE - LOW_THRESHOLD_VALUE + 1 )) + LOW_THRESHOLD_VALUE;
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
				selected_menu[1] = 1;
                sort(ARRAY_ROW_SIZE, ARRAY_COL_SIZE, number_array);
                break;
			case 3:
				if(selected_menu[0] != 1){
                    printf("Vänligen skapa en talföljd först. \n");
                    break;
                }
				if(selected_menu[1] != 1){
					printf("Vänligen sortera en talföljd först. \n");
					break;
				}
				//printf("\n3. Hitta värden\n");
				find_and_print_values(ARRAY_ROW_SIZE, ARRAY_COL_SIZE, number_array);
				break;
			case 4:
				if(selected_menu[0] != 1){
                    printf("Vänligen skapa en talföljd först. \n");
                    break;
                }
				if(selected_menu[1] != 1){
					printf("Vänligen sortera en talföljd först. \n");
					break;
				}
				printf("\n4. Sök\n");
				break; 
            default:
                printf("Oh no\n");
                in_menu = 0;
        }
    }
	printf("Exited");
}

void sort(int rows, int cols, int array[rows][cols]){
    int temp_array_val;
    int swapped = 1;
	while(swapped){
        swapped = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols - 1; j++){
                if(array[i][j] > array[i][j + 1]){
                    swapped = 1;
                    temp_array_val = array[i][j];
                    array[i][j] = array[i][j + 1];
                    array[i][j + 1] = temp_array_val;
                }
            }
        }
        for(int i=0; i<rows-1; i++)
        {
            if (array[i][cols-1]>array[i + 1][0]){
                swapped = 1;
                temp_array_val=array[i][cols - 1];
                array[i][cols-1]=array[i + 1][0];
                array[i + 1][0]=temp_array_val;
            }
        }
    }
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

void find_and_print_values(int rows, int cols, int array[rows][cols]){
	float sum, mean;
	int median, min, max;
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			if(i == 0 && j == 0){
				min = array[i][j];
				max = array[i][j];
			}
			if(min > array[i][j]){
				min = array[i][j];
			}
			else if(max < array[i][j]){
				max = array[i][j];
			}
			sum += array[i][j];
		}
	}
	mean = sum/(rows*cols);
	median = (array[(rows-1)/2][(cols-1)] + array[rows/2][0])/2;
	printf("\nMedelvärde: %g\nMedianvärde: %d\nMinvärde: %d\nMaxvärde: %d\n", mean, median, min, max);
}
