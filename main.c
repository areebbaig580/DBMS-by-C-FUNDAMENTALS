#include <stdio.h>
#include <string.h>

typedef struct dbms
{
    char name[50];
    int roll_no;
    char program[50];
    float percentage;

} db;
int showmenu()
{
    int choice;
    printf("\n\tMENU\n");
    printf("1- Add students detail\n");
    printf("2- View all students detail\n");
    printf("3- View one student detail\n");
    printf("4- Update student detail\n");
    printf("5- Exit program\n\n");
    printf("select your choice: ");
    scanf("%d", &choice);
    return choice;
}
int main()
{
    int choice;
    char ch;
    int n;

    FILE *ptr;

    while ((choice = showmenu()) != 5)
    {

        if (choice == 1)
        {
            ptr = fopen("dbms.txt", "a");
            printf("Enter no. of students details need to enter: ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {

                db s[100]; // enough for 100 students
                printf("Enter name : ");
                scanf("%s", s[i].name);

                printf("Enter program: ");
                scanf("%s", s[i].program);

                printf("Enter roll no.: ");
                scanf("%d", &s[i].roll_no);

                printf("Enter percentage: ");
                scanf("%f", &s[i].percentage);

                fprintf(ptr, "%s\t\t %s\t\t\t %d\t\t\t\t %.2f\n", s[i].name, s[i].program, s[i].roll_no, s[i].percentage);
            }
            fclose(ptr);
        }
        else if (choice == 2)
        {
            ptr = fopen("dbms.txt", "r");
            while ((ch = fgetc(ptr)) != EOF)
            {
                printf("%c", ch);
            }
            fclose(ptr);
        }

        else if (choice == 3)
        {
            db s;
            int findr;

            ptr = fopen("dbms.txt", "r");

            printf("Enter Roll.no : ");
            scanf("%d", &findr);

            while (fscanf(ptr, "%s %s %d %f", s.name, s.program, &s.roll_no, &s.percentage) == 4)
            {
                if (s.roll_no == findr)
                {
                    printf("\nRecord Found:\n");
                    printf("Name: %s\n", s.name);
                    printf("Program: %s\n", s.program);
                    printf("Roll No: %d\n", s.roll_no);
                    printf("Percentage: %.2f\n", s.percentage);

                    break;
                }
            }
            fclose(ptr);
        }
        else if (choice == 4)
        {
            int update_r;
            FILE *ptr1;
            ptr = fopen("dbms.txt", "r");
            ptr1 = fopen("temp.txt", "w");

            printf("Enter Roll no. to update: ");
            scanf("%d", &update_r);

            db s;
            while (fscanf(ptr, "%s %s %d %f", s.name, s.program, &s.roll_no, &s.percentage) == 4)
            {

                if (s.roll_no == update_r)
                {
                    printf("\nName = %s \nProgramme = %s \nPercentage = %.2f\n", s.name, s.program, s.percentage);

                    printf("\nEnter new record:\n");
                    
                    printf("\nEnter name: ");
                    scanf("%s", s.name);

                    printf("Enter Programme: ");
                    scanf("%s", s.program);

                    printf("Enter Percentage: ");
                    scanf("%f", &s.percentage);

                    printf("\nRecord updated successfully!\n");
                }
                fprintf(ptr1, "%s\t\t %s\t\t\t %d\t\t\t\t %.2f\n", s.name, s.program, s.roll_no, s.percentage);
            }
            fclose(ptr);
            fclose(ptr1);

            remove("dbms.txt");
            rename("temp.txt","dbms.txt");
        }
    }

    if (choice == 5)
    {
        printf("\"Program closed\"");
    }

    return 0;
}
