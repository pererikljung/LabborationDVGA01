#include "tillbehor.h"
int main()
{
    fordon f[10];
    int num = 0;
    int choice, pos;
    printf("Välkommen till Trafikverkets databas för fordon \n\nNedan kommer alternativ som går att göra i programmet\n");
    do
    {
        printf("1. Lägg till Fordon \n2. Ta bort ett Fordon \n3. Sortering efter bilmärke \n4. Skriv ut information om Fordon\n5. Skriv ut hela fordonsregistret \n6. Avsluta programmet\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                addVehicle(f, num);
                num++;
                break;
            case 2:
                if(num > 0)
                {
                    printf("Välj plats från listan att ta bort ett fordon från (räknar från 1 och uppåt): ");
                    scanf("%d", &pos);
                    removeVehicle(f, num, pos);
                    num--;
                }
                else printf("Det finns inga fordon i registret.");
                break;
            case 3:
                sortVehicles(f, num);
                break;
            case 4:
                break;
            case 5:
                printVehicles(f, num);
                break;
            default:
                break;
        }
    }
    while(choice < 6 && choice > 0);
}

void addVehicle(fordon *fdn, int num)
{
    printf("Skriv in ägarens namn: ");
    scanf("%s", &fdn[num].agare.namn);
    printf("Skriv in ägarens ålder: ");
    scanf("%d", &fdn[num].agare.alder);
    printf("Skriv in typen av fordon: ");
    scanf("%s", &fdn[num].typ);
    printf("Skriv in fordonets märke: ");
    scanf("%s", &fdn[num].marke);
    printf("Skriv in fordonets regnr: ");
    scanf("%s", &fdn[num].regnr);
}

void removeVehicle(fordon *fdn, int size, int pos)
{
    if(pos < 0 || pos > size)
    {
        printf("Välj en plats från 1 till %d", size);
    }
    else
    {
        for(int i = pos-1; i < size-1; i++)
        {
            fdn[i] = fdn[i + 1];
        }
    }
}

void sortVehicles(fordon *fdns, int size)
{
    fordon temp;
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size-1-i; j++)
        {
            if(compareString(fdns[j].marke, fdns[j+1].marke) > 0)
            {
                temp = fdns[j];
                fdns[j] = fdns[j+1];
                fdns[j+1] = temp;
            }
        }
    }
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

void printVehicles(fordon *fdns, int size)
{
    if (size > 0) 
    {
        for(int i = 0; i < size; i++)
        {
            printf("\n--------------------\n");
            printf("Fordon %d\n", i+1);
            printf("Ägarens namn:        %s\n", fdns[i].agare.namn);
            printf("Ägarens ålder:       %d\n", fdns[i].agare.alder);
            printf("Fordontyp:           %s\n", fdns[i].typ);
            printf("Märke:               %s\n", fdns[i].marke);
            printf("Registreringsnummer: %s\n", fdns[i].regnr);
            printf("--------------------\n");
        }
    }
    else printf("Det finns inga registrerade fordon!\n");
}
