#include<stdio.h>
#include<conio.h>

//For Taxi-men / Taxi-women

int r,nor,not,nob,amt=0,count=0;
char s[10];
void Riksha()
{   
    printf("Welcome to Riksha Parking\n");
    printf("1. Park the Riksha (Y or N) : ");
    scanf("%s",s);
    if(s[0]=='Y' || s[0]=='y')
    {
        nor++;
        count++;
    }
    printf("2. Remove the Riksha (Y or N) : ");
    scanf("%s",s);
    if(s[0]=='Y' || s[0]=='y')
    {
        nor--;
        count--;
        amt+=50;
    }
    printf("3. Show the Riksha : ");
    printf("Total Riksha parked: %d",nor);
    printf("4. Exit\n");
}

void Taxi()
{
    printf("Welcome to Cab Parking\n");
    printf("1. Park the Cab (Y or N) : ");
    scanf("%s",s);
    if(s[0]=='Y' || s[0]=='y')
    {
        not++;
        count++;
    }
    printf("2. Remove the Cab (Y or N) : ");
    scanf("%s",s);
    if(s[0]=='Y' || s[0]=='y')
    {
        not--;
        count--;
        amt+=100;
    }
    printf("3. Show the Cab : ");
    printf("Total Cab parked: %d",not);
    printf("4. Exit\n");
}

void Bus()
{
    printf("Welcome to Bus Parking\n");
    printf("1. Park the Bus (Y or N) : ");
    scanf("%s",s);
    if(s[0]=='Y' || s[0]=='y')
    {
        nob++;
        count++;
    }
    printf("2. Remove the Bus (Y or N) : ");
    scanf("%s",s);
    if(s[0]=='Y' || s[0]=='y')
    {
        nob--;
        count--;
        amt+=200;
    }
    printf("3. Show the Bus : ");
    printf("Total Bus parked: %d",nob);
    printf("4. Exit\n");
}

void main()
{
    int ch;
    while(1)
    {
        printf("1. Riksha\n");
        printf("2. Taxi\n");
        printf("3. Bus\n");
        printf("4. Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: Riksha();
                    break;
            case 2: Taxi();
                    break;
            case 3: Bus();
                    break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}