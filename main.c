#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void  login();
void  mainmenu();
void  newrecord();
void  display();
void  search();
void  update();
void  deleterecord();

struct student
{
    int roll_no;
    char section[10];
    char name[15];
    char fname[15];
    char surname[15];
    char address[30];
    int marks;
    float grade;

};
    struct student s;

int main()
{
    printf("\n\t\t\t\tWelcome to School Of Scholars!\n");
    printf("\n\t\t\t\tPress any key to continue");
    getch();
    login();

}
void login(){
    char user[15],pass[15];
    system("cls");
printf("\nEnter Username and Password to login !\n\n");
printf("\nEnter Username: \n");
gets(user);
printf("\nEnter Password: \n");
gets(pass);
if(strcmp(user,"SOS1315")==0){
   if(strcmp(pass,"SOS@1315")==0){
       printf("\n Login Successful!");
       printf("\n Press any key to continue");
       getch();
       mainmenu();
   }
}
else{
    printf("\nInvalid Username or password\n");
}
}

void mainmenu(){
    int choice;
    lineno39:
system("cls");
printf("\t\t\tMenu\t\t\t\n");
printf("\n\t\t 1. Insert Record\n");
printf("\n\t\t 2. Display Record\n");
printf("\n\t\t 3. Search Record\n");
printf("\n\t\t 4. Update Record\n");
printf("\n\t\t 5. Delete Record\n");
printf("\n\t\t 6. Exit\n");
printf("\n Enter Your Choice");
scanf("%d",&choice);

switch(choice){
case 1:
    newrecord();
    goto lineno39;
case 2:
    display();
goto lineno39;
case 3:
     search();
     goto lineno39;
case 4:
    update();
     goto lineno39;
case 5:
    deleterecord();
     goto lineno39;
case 6:
    printf("\n\t\t You have successfully work on students record!");
    printf("Press any key to exit");
    getch();
    exit(0);

default:
    printf("\nInvalid Choice!Please enter a valid selection between 1 to 6");
    printf("\nPress any key to continue");
    getch();
    goto lineno39;
}

}

void newrecord()
    {
        system("cls");
        FILE *fp;
        fp=fopen("data.txt","ab+");
        if(fp==NULL)
        {
        printf("\nError! Can't Open File");
        return;
        }
        printf("\nEnter Name of Student: ");
        scanf("%s",s.name);
        printf("\nEnter Father's Name: ");
        scanf("%s",s.fname);
        printf("\nEnter Surname of Student: ");
        scanf("%s",s.surname);
        printf("\nEnter Roll Number of Student: ");
        scanf("%d",&s.roll_no);
        printf("\nEnter Class of student: ");
        scanf("%s",s.section);
        printf("\nEnter Address of student: ");
        scanf("%s",s.address);
        printf("\nEnter Marks of Student out of 100: ");
        fflush(stdin);
        scanf("%d",&s.marks);
        printf("\nEnter Grade of Student out of 10: ");
        fflush(stdin);
        scanf("%f",&s.grade);
        fwrite(&s,sizeof(s),1,fp);
        {
            printf("\nStudent data recorded Successfully ");
        }
        fclose(fp);
        printf("\nPress any key to continue");
        getch();
    }


void display()
{
    system("cls");
    FILE *fp;
    fp=fopen("data.txt","rb");
    if(fp==NULL)
    {
        printf("\nError While Opening File");
        return;
    }
    printf("\nExisting Records\n\n");
    while(fread(&s,sizeof(s),1,fp)==1)
    {
   printf("\nName of Student: %s",s.name);
   printf("\nFather's Name of Student: %s",s.fname);
   printf("\nSurname of student: %s",s.surname);
   printf("\nRoll Number: %d",s.roll_no);
   printf("\nAddress of Student: %s",s.address);
   printf("\nMarks: %d",s.marks);
   printf("\nGrade: %f",s.grade);
   printf("\n\n");
    }
    fclose(fp);
      printf("\npress any key to continue");
     getch();
}


void search()
{
system("cls");
    int roll,flag=0;
        FILE *fp;
        fp=fopen("data.txt","rb");
        if(fp==NULL)
        {
            printf("\nError Opening File");
            return;
        }
        printf("\nEnter Roll Number you want to search: ");
        scanf("%d",&roll);
        while(fread(&s,sizeof(s),1,fp)>0&&flag==0)
        {
            if(s.roll_no==roll)
            {
            flag=1;
           printf("\nName of Student: %s",s.name);
   printf("\nSurname of student: %s",s.surname);
   printf("\nRoll Number: %d",s.roll_no);
   printf("\nMarks: %d",s.marks);
   printf("\nGrade: %f",s.grade);
   printf("\n\n");
            }
        }
        if(flag==0)
        {
            printf("\n Error: No record found\a");
        }
        fclose(fp);
        printf("\n press any key to continue");
     getch();
}


void update(){
  system("cls");
    int flag=0;
    char b[15];
    FILE *fp;
    fp=fopen("data.txt","rb+");
    if(fp==NULL)
    {
        printf("\nError In Opening File");
        return;
    }
    printf("\nEnter Name of Student:");
    scanf("%s",b);
        while(fread(&s,sizeof(s),1,fp)>0&&flag==0)
        {
            if(strcmp(s.name,b)==0)
            {
                 flag=1;
                    printf("\nEdit Record\n\t\a");
                    fflush(stdin);
                    printf("\nUpdate Student Name:\t\a");
                    scanf("%s",s.name);
                    printf("\nUpdate Student Father's Name:\t\a");
                    scanf("%s",s.fname);
                    printf("\nUpdate Student Surname:\t\a");
                    scanf("%s",s.surname);
                    printf("\nUpdate Student Roll Number:\t\a");
                    scanf("%d",&s.roll_no);
                    printf("\nUpdate Address of Student:\t\a");
                    scanf("%s",s.address);
                    printf("\nEnter Class of student: ");
                    scanf("%s",s.section);
                    printf("\nUpdate Student Marks:\t\a");
                    scanf("%d",&s.marks);
                    printf("\nUpdate Student Garde:\t\a");
                    scanf("%f",&s.grade);
                    fseek(fp,-(long)sizeof(s),1);
                    fwrite(&s,sizeof(s),1,fp);
                    printf("\nRecord Updated Successfully");
            }
            else if(flag==0)
            {
                printf("\nNo such data exist!");
            }
        }
        fclose(fp);
        printf("\nPress any key to continue");
        getch();
}


void deleterecord(){
    system("cls");
    char n[20];
    unsigned flag=0;
    FILE *fp,*ft;
    fp=fopen("data.txt","rb");

    if(fp==NULL)
       {
           printf("\nError Opening File");
           return;
       }
       printf("\nEnter Name of Student:");
       scanf("%s",n);
       ft=fopen("data1.txt","ab+");
       while(fread(&s,sizeof(s),1,fp)==1)
        {
            if(strcmp(n,s.name)!=0)
            {
                printf("\n Record Deleted!\n ");
                fwrite(&s,sizeof(s),1,ft);
            }
            else
             flag=1;
        }
        if(flag==0)
        {
            printf("\nNo Such Record Found");
        }

        fclose(fp);
        fclose(ft);
        remove("data.txt");
        rename("data1.txt","data.txt");
        printf("\nPress any key to continue");
        getch();
}


