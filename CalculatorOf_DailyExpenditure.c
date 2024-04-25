#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Expenditure
{
    int  date[31];
    char item_name[20];
    char userName[20];
    char password[20];
    float item_price[20];
    int total_amount;
    struct item
    {

    int value;

    }item[20];

} Expenditure;
int mo[40];
void reg();
void login();
void main_page();
void add_item();
void display();
void search();

int main()
{  FILE *fp;
    fp=fopen("Calculator_of_daily_Expenditure.txt", "w");
    //w == write
    int ch;
    struct Expenditure e1;

     for (int i=0;i<=31;i++)
        {
            mo[i]=0;
        }
    system("color e");
    printf("\t\t\t\t************************************\n");
    printf("\t\t\t\t*                                  *\n");
    printf("\t\t\t\t* Calculator of Daily Expenditure  *\n");
    printf("\t\t\t\t*                                  *\n");
    printf("\t\t\t\t************************************\n\n\n");
    printf("\t\t\t-----------------------------------------\n");
   // printf("\t\t\t|                                       |");
    printf("\t\t\t|\t\t1:Login                 |\n");
    printf("\t\t\t|\t\t2:Resister              |\n");
    printf("\t\t\t-----------------------------------------\n");
    printf("\n\t\t\tEnter Your Choice:  ");
    scanf("%d",&ch);
    if (ch==1)
    {
        //system("CLS");
        login();
    }
    else if (ch==2)
    {
        //system("CLS");
        reg();
    }
    else
    {
         printf("\n\n\t\t\t\t\t\tWrong Input.\n\n");
        printf("\nPress Any Key TO Continue");
        getch();
        system("CLS");
         main();
    }


 fclose(fp);
    return 0;
}


void reg()
{

    FILE *fp;
    fp=fopen("Calculator_of_daily_Expenditure.txt", "w");
    struct Expenditure obj ;
    fflush(stdin);
    printf("\n\t\t\t->->->->Resister:<-<-<-<-\n");
    printf( "\n\t\tEnter Username : ") ;
    scanf("%s",obj.userName);
    printf("\n\t\tEnter New Password : ");
    scanf("%s",obj.password);
    fwrite(&obj,sizeof(obj),1,fp);


    fclose(fp);
     printf("\nPress Any Key TO Continue");
    getch();
   system("CLS");
    login();

}


void login()
{
    system("color b");
    printf("\t\t\t\t************************************\n");
    printf("\t\t\t\t*                                  *\n");
    printf("\t\t\t\t* Calculator of Daily Expenditure  *\n");
    printf("\t\t\t\t*                                  *\n");
    printf("\t\t\t\t************************************\n\n\n");
    char username[20],Password [20];
     FILE *fp;
    fp=fopen("Calculator_of_daily_Expenditure.txt", "r");
    rewind(fp);
    struct Expenditure obj;
    printf("\n\n\t\t\t\t->->->-> LogIn : <-<-<-<-\n\n");
    printf("\t\t\tEnter Your Username : ");
    scanf("%s",username);
    printf("\n\t\t\tEnter Your Password : ");
    scanf("%s",Password);

    while(fread(&obj,sizeof(obj),1,fp))
    {
        if (strcmp(username,obj.userName)==0&& strcmp(Password,obj.password)==0)
        {
            printf("\n\n\t\t\t\tSuccessfully login!\n\n\n");
            printf("\nPress Any Key TO Continue");
            getch();
            system("CLS");
            main_page();
        }
        else
            printf("Please Enter Correct User Name and Password!");
            login();
    }

    fclose(fp);
}
void main_page()
{
    FILE *fp;
    fp=fopen("Calculator_of_daily_Expenditure.txt", "w");
     system("color e");
    printf("\t\t\t\t************************************\n");
    printf("\t\t\t\t*                                  *\n");
    printf("\t\t\t\t* Calculator of Daily Expenditure  *\n");
    printf("\t\t\t\t*                                  *\n");
    printf("\t\t\t\t************************************\n\n\n");

    int ch;

    do
    {   printf("\t\t--------------------------------------------------\n");
        printf("\t\t\t\t1: Add Item\n");
        printf("\n\t\t\t\t2: View The Record of Expense \n");
        printf("\n\t\t\t\t3: Search\n");
        printf("\n\t\t\t\t4: Exit\n");
        printf("\t\t--------------------------------------------------\n");
        printf("\n\t\tEnter Your Choice:  ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            add_item();
            break;
        case 2:
            display();
            break;
        case 3:
            search();
            break;
        case 4:
            exit(0);
        default:
          printf("\n\n\t\t\t\t\t\tWrong Input.\n\n");
        printf("\nPress Any Key TO Continue");
        getch();
        system("CLS");
        main_page();
        }
    }
    while (ch!=0);


 fclose(fp);
}

void add_item()
{
    FILE *fp;
    fp=fopen("Calculator_of_daily_Expenditure.txt", "w");
    struct Expenditure add;

    char item_1[20],item_2[20],item_3[20],item_4[20],item_5[20];
    int a,b,c,d,e;
    int Day;
    printf("Enter your date (01 to 31) : ");
    scanf("%d",&Day);

     printf("\nEnter Your Product name and Price 1:\n");
        scanf("%s %d",item_1,&a);

    printf("\nEnter Your Product name and Price 2:\n");
        scanf("%s %d",item_2,&b);
     printf("\nEnter Your Product name and Price 3:\n");
        scanf("%s %d",item_3,&c);
    printf("\nEnter Your Product name and Price 4:\n");
        scanf("%s %d",item_4,&d);
    printf("\nEnter Your Product name and Price 5:\n");
        scanf("%s %d",item_5,&e);

       int total=a+b+c+d+e;
        add.date[Day]=total;
       mo[Day]+=add.date[Day];

fwrite(&add,sizeof(add),1,fp);

    fclose(fp);
}


void display()
{
    Expenditure E;
    FILE *fp;
    fp=fopen("Calculator_of_daily_Expenditure.txt", "r");
     rewind(fp);
     fread(&E,sizeof(E),1,fp);
    int day;

   printf("Enter your date to show the Expenditure:");
   scanf("%d",&day);

   printf("Date: %d Expense: %d",day,E.date[day]);


    fclose(fp);

}
void search()
{   FILE *fp;
  fp=fopen("Calculator_of_daily_Expenditure.txt", "r");

    struct Expenditure s;
    rewind(fp);
    fread(&s,sizeof(s),1,fp);
    int DAY,d;
    int sum=0;
    printf("\n\n\nDo you want to search by month/date?\n\n");
    printf("\t\t--------------------------------------------------\n");
    printf("\t\t\t1: Specific Date Expense.\n");
    printf("\t\t\t2: Monthly expense.\n");
    printf("\t\t--------------------------------------------------\n");
    printf("Enter your choice : ");
    scanf("%d",&d);
    if(d==1)
    {
    printf("Enter your date: ");
    scanf("%d",&DAY);
   printf("Date: %d\t Expense is: %d\n\n",DAY,s.date[DAY]);
    }

    else if(d==2)
    {
       //for (int i=0; i<=30 ;i++)
       //{
       // sum+=mo[i];
       //}
       printf("%d",sum) ;
     for (int i=0; i<=30 ;i++)
       {
        sum+=mo[i];
       }
       printf("Monthly Expense is:  %d Taka\n\n\n",sum) ;
    }
   fclose(fp);

}
