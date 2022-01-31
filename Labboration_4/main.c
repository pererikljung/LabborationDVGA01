#include "tillbehor.h"
int main()
{
    const int REGISTRY_MAX_SIZE = 10;
    const int MENU_INPUT_SIZE = 5;
    fordon f[REGISTRY_MAX_SIZE];
    char cha[MENU_INPUT_SIZE];
    int choice, pos;
    int f_cur_arr_size = 0, in_menu = 1;
    printf("Välkommen till Trafikverkets databas för fordon.\nNedan kommer alternativ som går att göra i programmet.\n");
    while(in_menu)
    {
        printf("----------------------------------------------------------");
        printf("\n1. Lägg till Fordon \n2. Ta bort ett Fordon \n3. Sortering efter bilmärke \n4. Skriv ut information om Fordon\n5. Skriv ut hela fordonsregistret \n6. Avsluta programmet\n");
        printf("----------------------------------------------------------");
        while(1)
        {
            checkInputLength("\nVälj alternativ: ", cha, MENU_INPUT_SIZE);
            if(!checkNumber(cha))
            {
                printf("\nOiltigt nummer!\n");
                continue;
            }
            choice = atoi(cha);
            break;
        }
        switch(choice)
        {
            case 1:
                addVehicle(f, f_cur_arr_size);
                f_cur_arr_size++;
                break;
            case 2:
                if(f_cur_arr_size > 0)
                {
                    removeVehicle(f, f_cur_arr_size);
                    f_cur_arr_size--;
                    if(f_cur_arr_size == 0)
                    {
                        printf("\nDet finns inga fordon kvar i registret.\n");
                    }
                }
                else printf("\nDet finns inga fordon i registret.\n");
                break;
            case 3:
                sortVehicles(f, f_cur_arr_size);
                break;
            case 4:
                if(f_cur_arr_size > 0)
                {
                    scanf("%[^\n]d", &pos);
                    vehicleInfo(f, f_cur_arr_size);
                }
                else printf("\nDet finns inga fordon i registret.\n");
                break;
            case 5:
                printVehicles(f, f_cur_arr_size);
                break;
            case 6:
                in_menu = 0;
                break;
            default:
                printf("\nOgiltigt värde!\n");
        }
    }
}

void checkInputLength(char *printMessage, char *input, int size)
{
    printf("%s", printMessage);
    fgets(input, size, stdin);

    if (input[strlen(input) -1] != '\n')
    {
        int overflowing = 0;
        while (fgetc(stdin) != '\n')
        {
            overflowing++;
        }

        if (overflowing > 0)
        {
            printf("\nFör många bokstäver inskrivna. Högst %d är tillåtna!\n", size);
            checkInputLength(printMessage, input, size);
        }
    }
    else
    {
        input[strlen(input) -1] = '\0';      
    }
}
                       
int checkNumber(char *num)
{
    int i_num, i_num_temp, nums_in_int = 0;
    
    if((i_num = atoi(num)) == 0)
    {
        return 0;
    }
    i_num_temp = i_num;
    do
    { 
        i_num_temp = i_num_temp / 10; 
        nums_in_int++; 
    }
    while (i_num_temp != 0);

    if(nums_in_int != strlen(num)-1)
    {
        for(int i = nums_in_int; i < strlen(num)-1; i++)
        {
            if(num[i] < '1' || num[i] > '9')
            {
                return 0;
            }
        }
    }
    return 1;
}

int compareString(char s1[], char s2[])
{
    const char OFFSET = 'a' - 'A';
    char arr1[strlen(s1)], arr2[strlen(s2)];
    strcpy(arr1, s1);
    strcpy(arr2, s2);
    
    for (int i = 0; i <= strlen(s1); i++) {
        if (arr1[i] >= 'a' && arr1[i] <= 'z')
        {
            arr1[i] -= OFFSET;
        }
    }
    for (int i = 0; i <= strlen(arr2); i++) {
        if (arr2[i] >= 'a' && arr2[i] <= 'z')
        {
            arr2[i] -= OFFSET;
        }
    }
    return strcmp(arr1, arr2);
}

void addVehicle(fordon *fdn, int f_arr_pos)
{
    const int MAX_SIZE_NAME = 50;
    const int MAX_SIZE_AGE = 10;
    const int MAX_SIZE_VEHICLE_TYPE = 10;
    const int MAX_SIZE_VEHICLE_BRAND = 15;
    const int MAX_SIZE_VEHICLE_REG_NUM = 10;
    const int INFORMATION_FIELDS_NUM = 5;
    
    char temp[MAX_SIZE_AGE];
    int cur_info_field = 1;
    
    while (cur_info_field <= INFORMATION_FIELDS_NUM)
    {
        switch(cur_info_field)
        {
            case 1:
                checkInputLength("\nSkriv in ägarens namn: ", fdn[f_arr_pos].agare.namn, MAX_SIZE_NAME);
                break;
            case 2:
                checkInputLength("\nSkriv in ägarens ålder: ", temp, MAX_SIZE_AGE);
                if(!checkNumber(temp))
                {
                    printf("\nEj ett giltigt nummer\n");
                    continue;
                }
                fdn[f_arr_pos].agare.alder = atoi(temp);
                if(fdn[f_arr_pos].agare.alder < 1 || fdn[f_arr_pos].agare.alder > 120)
                {
                    printf("\nVälj en ålder mellan 1 och 120\n");
                    continue;
                }
                break;
            case 3:
                checkInputLength("\nSkriv in typen av fordon: ", fdn[f_arr_pos].typ, MAX_SIZE_VEHICLE_TYPE);
                break;
            case 4:
                checkInputLength("\nSkriv in fordonets märke: ", fdn[f_arr_pos].marke, MAX_SIZE_VEHICLE_BRAND);
                break;
            case 5:
                checkInputLength("\nSkriv in fordonets regnr: ", fdn[f_arr_pos].regnr, MAX_SIZE_VEHICLE_REG_NUM);
                printf("\nFordon registrerat!\n");
                break;
        }
        cur_info_field++;
    }
}

void removeVehicle(fordon *fdn, int f_cur_arr_size)
{
    const int C_POS_SIZE = 10;
    char c_pos[C_POS_SIZE];
    int i_pos, i_pos_temp, nums_in_int = 0;
    
    printf("Ta bort ett fordon från registret!");
    while(1)
    {
        printf("\nVälj en plats från 1 till %d: ", f_cur_arr_size);
        fgets(c_pos, C_POS_SIZE, stdin);
        
        if(!checkNumber(c_pos))
        {
            printf("\nEj ett nummer!\n");
            continue;
        }
        i_pos = atoi(c_pos);
        
        if(i_pos < 0 || i_pos > f_cur_arr_size)
        {
            printf("\nOgiltig plats!");
            continue;
        }
        for(int i = i_pos - 1; i < f_cur_arr_size - 1; i++)
        {
            fdn[i] = fdn[i + 1];
        }
        printf("Tog bort fordon från plats %d i listan.", i_pos);
        break;
    }
}

void sortVehicles(fordon *fdns, int f_cur_arr_size)
{
    fordon temp;
    for(int i = 0; i < f_cur_arr_size; i++)
    {
        for(int j = 0; j < f_cur_arr_size - i - 1; j++)
        {
            if(compareString(fdns[j].marke, fdns[j + 1].marke) > 0)
            {
                temp = fdns[j];
                fdns[j] = fdns[j + 1];
                fdns[j + 1] = temp;
            }
        }
    }
}

void vehicleInfo(fordon *fdn, int f_cur_arr_size)
{
    const int C_POS_SIZE = 10;
    char c_pos[C_POS_SIZE];
    int i_pos, i_pos_temp, nums_in_int = 0;
    
    printf("Hitta information om ett registrerat fordon!");
    while(1)
    {
        printf("\nVälj en plats från 1 till %d: ", f_cur_arr_size);
        fgets(c_pos, C_POS_SIZE, stdin);
        
        if(!checkNumber(c_pos))
        {
            printf("\nEj ett nummer!\n");
            continue;
        }
        i_pos = atoi(c_pos);
        
        if(i_pos < 0 || i_pos > f_cur_arr_size)
        {
            printf("\nOgiltig plats!");
            continue;
        }
        printf("\n----------------------------------------\n");
        printf("Fordon %d\n", i_pos);
        printf("Ägarens namn:        %s\n", fdn[i_pos-1].agare.namn);
        printf("Ägarens ålder:       %d\n", fdn[i_pos-1].agare.alder);
        printf("Fordontyp:           %s\n", fdn[i_pos-1].typ);
        printf("Märke:               %s\n", fdn[i_pos-1].marke);
        printf("Registreringsnummer: %s\n", fdn[i_pos-1].regnr);
        printf("----------------------------------------\n");
        break;
    }
}

void printVehicles(fordon *fdns, int f_cur_arr_size)
{
    if (f_cur_arr_size > 0) 
    {
        printf("\n----------------------------------------\n");
        for(int i = 0; i < f_cur_arr_size; i++)
        {
            printf("Fordon %d\n", i+1);
            printf("Ägarens namn:        %s\n", fdns[i].agare.namn);
            printf("Ägarens ålder:       %d\n", fdns[i].agare.alder);
            printf("Fordontyp:           %s\n", fdns[i].typ);
            printf("Märke:               %s\n", fdns[i].marke);
            printf("Registreringsnummer: %s\n", fdns[i].regnr);
            printf("----------------------------------------\n");
        }
    }
    else printf("\nDet finns inga registrerade fordon!\n");
}
