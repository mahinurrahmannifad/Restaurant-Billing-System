/*
BY____Mahinur Rahman Nifad
ID: 0242220005341134
SWE_Batch-39(A)
Project Name:  Restaurant Ordering System in C
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
void mainmenu(void);
void customer(void);
void staffAttendance(void);
void osnack(void);
void cdetails(void);
void give_feedback(void);
void view_feedbacks();

COORD coord = {0, 0};
COORD max_res, cursor_size;
void gotoxy(int x, int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main()
{
    mainmenu();
    return 0;
}
void mainmenu(void)
{
    system("cls");

    gotoxy(30, 1);
    printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd Welcome To Nifad's Cafe\xcd\xcd\xcd\xcd\xcd\xcd\xcd");

    gotoxy(30, 3);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU");
    printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(30, 5);
    printf("\xDB\xDB\xDB\xDB\xB2 1. Customer Section");
    gotoxy(30, 7);
    printf("\xDB\xDB\xDB\xDB\xB2 2. Give Feedback");
    gotoxy(30, 9);
    printf("\xDB\xDB\xDB\xDB\xB2 3. View Feedbacks");
    gotoxy(30, 11);
    printf("\xDB\xDB\xDB\xDB\xB2 4. Staff Attendance");
    gotoxy(30, 13);
    printf("\xDB\xDB\xDB\xDB\xB2 5. Close Application");
    gotoxy(30, 17);
    printf("------------------------------------------");
    gotoxy(30, 20);

    int select;
    gotoxy(30, 15);
    printf("Enter Your Options:");
    scanf("%d", &select);
    if (select == 1)
    {
        customer();
    }
    else if (select == 2)
    {
        give_feedback();
    }
    else if (select == 3)
    {
        view_feedbacks();
    }
    else if (select == 4)
    {
        staffAttendance();
    }
    else if (select == 5)
    {
        system("cls");
        printf("\n\n\n");
        printf("\t\t Thank you  ");
        printf("\t\t Feeling Hungry Time to Snack\n");

        printf("\t---------------------------------------------\n");
        exit(0);
    }
    else
    {
        gotoxy(30, 23);
        printf("Wrong input! Kindly input the correct Option.....");
        getch();
        mainmenu();
    }
}
void customer(void)
{

    system("cls");
    system("COLOR F2");
    int c;
    gotoxy(20, 3);
    printf("----------------------------------------------");

    gotoxy(25, 5);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2Select Catagories");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(25, 7);
    printf("\xDB\xDB\xDB\xDB\xB2 1. Order Snack");
    gotoxy(25, 9);
    printf("\xDB\xDB\xDB\xDB\xB2 2. View Order");
    gotoxy(25, 11);
    printf("\xDB\xDB\xDB\xDB\xB2 3. Back to main menu");
    gotoxy(25, 18);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    gotoxy(25, 22);
    printf("----------------------------------------------");
    gotoxy(25, 15);
    printf("Enter Your Options:");
    scanf("%d", &c);
    int load;
    for (load = 0; load <= 5000; load++)
    {

        printf("\rLoading : %d", load / 500);
    }
    if (c == 1)
    {
        system("cls");
        osnack();
    }
    else if (c == 2)
    {
        system("cls");
        system("COLOR F3");
        // gotoxy(30,10);
        FILE *vorder;
        char v;
        vorder = fopen("order.txt", "r");
        while ((v = fgetc(vorder)) != EOF)
        {

            printf("%c", v);
        }
        gotoxy(40, 45);
        printf("press any key back to CATEGOIES");
        if (getch())
            customer();
    }

    else if (c == 3)
    {

        system("cls");
        mainmenu();
    }
    else
    {
        gotoxy(25, 25);
        printf("Wrong input! Kindly input the correct Option.....");
        getch();
        customer();
    }
}

void osnack(void)
{
    system("COLOR F4");

    int choice;
    int again;
    int quantity;
    double total = 0;

    printf("\t---------------------------------------------\n");
    printf("\t\t\t SNACK MENU\n");
    printf("\t---------------------------------------------\n");
    printf("\t INPUT NUMBER FOR SELECTED MENU \n\n\t1.French Fries 150 Taka\n\n\t2.Cheeseburger 250 Taka \n\n\t3.Sandwich 220 Taka \n\n\t4.Hot dog 180 Taka \n\n\t5.Noodles 60 Taka \n\n\t6.Cold Coffe 120 Taka\n \n\t7.Back to main mune\n\t \n\tEnter Your Choice---> ");

    char s;
    FILE *snkmenu;
    snkmenu = fopen("menu.txt", "rt");
    while ((s = getc(snkmenu)) != EOF)
    {

        printf("%c", s);
    }
    fclose(snkmenu);
    printf("\n\nInput Customer Order:");
    printf("\n\n");
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("Quantity:");
        scanf("%d", &quantity);
        total = total + 150 * (quantity);
        printf("\n");
        printf("\t Press 1 To Order Again: \n\t Press 2 To Get Your Total:\n\n\n Enter Your Choice:");
        scanf("%d", &again);
        printf("\n");
        if (again == 1)
        {
            printf("\n\n");
            osnack();
        }
        else if (again == 2)
        {
            printf("Your Total Amount is: %.2f\n\n", total);

            int totl = total;
            FILE *ttl;
            ttl = fopen("order.txt", "a");
            fprintf(ttl, "\nGrand Total: %d\n", totl);
            fclose(ttl);
            cdetails();
        }
    }

    else if (choice == 2)
    {
        printf("Quantity:");
        scanf("%d", &quantity);
        total = total + 250 * (quantity);
        printf("\n");
        printf("\t Press 1 To Order Again: \n\t Press 2 To Get Your Total:\n\n\n Enter Your Choice:");
        scanf("%d", &again);
        printf("\n");
        if (again == 1)
        {
            printf("\n\n");
            osnack();
        }
        else if (again == 2)
        {
            printf("Your Total Amount is: %.2f\n\n", total);

            int totl = total;
            FILE *ttl;
            ttl = fopen("order.txt", "a");
            fprintf(ttl, "\nGrand Total: %d\n", totl);
            fclose(ttl);
            cdetails();
        }
    }
    else if (choice == 3)
    {
        printf("Quantity :");
        scanf("%d", &quantity);
        total = total + 220 * (quantity);
        printf("\n");
        printf("\t Press 1 To Order Again: \n\t Press 2 To Get Your Total:\n\n\n Enter Your Choice:");
        scanf("%d", &again);
        printf("\n");
        if (again == 1)
        {
            printf("\n\n");
            osnack();
        }
        else if (again == 2)
        {
            printf("Your Total Amount is: %.2f\n\n", total);

            int totl = total;
            FILE *ttl;
            ttl = fopen("order.txt", "a");
            fprintf(ttl, "\nGrand Total: %d\n", totl);
            fclose(ttl);
            cdetails();
        }
    }
    else if (choice == 4)
    {
        printf("Quantity :");
        scanf("%d", &quantity);
        total = total + 180 * (quantity);
        printf("\n");
        printf("\t Press 1 To Order Again: \n\t Press 2 To Get Your Total:\n\n\n Enter Your Choice:");
        scanf("%d", &again);
        printf("\n");
        if (again == 1)
        {
            printf("\n\n");
            osnack();
        }
        else if (again == 2)
        {
            printf("Your Total Amount is: %.2f\n\n", total);

            int totl = total;
            FILE *ttl;
            ttl = fopen("order.txt", "a");
            fprintf(ttl, "\nGrand Total: %d\n", totl);
            fclose(ttl);
            cdetails();
        }
    }
    else if (choice == 5)
    {
        printf("Quantity :");
        scanf("%d", &quantity);
        total = total + 60 * (quantity);
        printf("\n");
        printf("\t Press 1 To Order Again: \n\t Press 2 To Get Your Total:\n\n\n Enter Your Choice:");
        scanf("%d", &again);
        printf("\n");
        if (again == 1)
        {
            printf("\n\n");
            osnack();
        }
        else if (again == 2)
        {
            printf("Your Total Amount is: %.2f\n\n", total);

            int totl = total;
            FILE *ttl;
            ttl = fopen("order.txt", "a");
            fprintf(ttl, "\nGrand Total: %d\n", totl);
            fclose(ttl);
            cdetails();
        }
    }
    else if (choice == 6)
    {
        printf("Quantity :");
        scanf("%d", &quantity);
        total = total + 120 * (quantity);
        printf("\n");
        printf("\t Press 1 To Order Again: \n\t Press 2 To Get Your Total:\n\n\n Enter Your Choice:");
        scanf("%d", &again);
        printf("\n");
        if (again == 1)
        {
            printf("\n\n");
            osnack();
        }
        else if (again == 2)
        {
            printf("Your Total Amount is: %.2f\n\n", total);

            int totl = total;
            FILE *ttl;
            ttl = fopen("order.txt", "a");
            fprintf(ttl, "\nGrand Total: %d\n", totl);
            fclose(ttl);
            cdetails();
        }
    }
    else if (choice == 7)
    {
        system("cls");
        customer();
    }
    else
    {
        printf("\t Wrong input! Kindly input the correct Option.....\n\n");
        getch();
        osnack();
    }
}
void cdetails(void)
{
    char fname[20];
    char lname[20];
    long long int phone;

    printf("\tInput Customer Details\n");
    printf("First Name :");
    scanf("%s", &fname);
    printf("Last Name :");
    scanf("%s", &lname);
    printf("Phone : ");
    scanf("%lld", &phone);
    printf("\n\n");
    printf("\xB2\xB2\xB2\xB2\xB2Your Details Entered Are \xB2\xB2\xB2\xB2\xB2\n");
    FILE *cust;
    cust = fopen("order.txt", "a");
    fprintf(cust, "Order by : %s %s \nPhone Number : %lld\n", fname, lname, phone);
    fclose(cust);
    printf("First Name: %s\nLast Name: %s\nPhone:%lld\n", fname, lname, phone);
    printf("\n\n\n");
    printf("\t-------------------------------------------------------------\n");
    printf("\t\t Your Order will be in 15 minutes..\n");
    printf("\t\t THANK YOU...\n");
    printf("Press Any Back to Main Menu");
    if (getch())
        mainmenu();
}
void give_feedback(void)
{
    system("cls");
    system("COLOR FD");

    char name[50];
    char feedback[1000];
    FILE *fp;
    gotoxy(10, 2);
    printf("*************************************************************************************");
    gotoxy(40, 4);
    printf("\xDB\xDB\xDB\xDB\xB2 Give Your Feedback \xDB\xDB\xDB\xDB\xB2");
    gotoxy(10, 5);
    printf("*************************************************************************************");
    gotoxy(25, 8);
    printf("\xDB\xDB\xDB\xDB\xB2 Enter your name: ");
    scanf(" %[^\n]", name);
    gotoxy(25, 10);
    printf("\xDB\xDB\xDB\xDB\xB2 Enter your Feedback (max 1000 characters):\n");
    gotoxy(25, 12);
    scanf(" %[^\n]", feedback);

    fp = fopen("feedback.txt", "a");
    if (fp == NULL)
    {
        gotoxy(25, 15);
        printf("Error: Unable to open file for writing.\n");
        return;
    }

    fprintf(fp, "%s said: %s\n", name, feedback);
    fclose(fp);
    gotoxy(25, 16);
    printf("Thank you for your feedback!\n");

    if (getch())
        mainmenu();
}
void view_feedbacks()
{
    system("cls");
    system("COLOR FB");

    char feedback[1000];
    FILE *fp;
    // gotoxy(7,5);
    fp = fopen("feedback.txt", "r");
    if (fp == NULL)
    {
        printf("Error: Unable to open file for reading.\n");
        return;
    }
    gotoxy(30, 1);
    printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("List of feedbacks:");
    printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n");
    while (fgets(feedback, sizeof(feedback), fp) != NULL)
    {
        gotoxy(20, 5);
        printf("%s", feedback);
    }

    fclose(fp);
    if (getch())
        mainmenu();
}

void staffAttendance()
{
    system("cls");
    FILE *attendanceFile;
    time_t currentTime;
    struct tm *localTime;
    char staffName[50];
    int staffID;

    printf("\nStaff Attendance\n");
    printf("Enter staff ID: ");
    scanf("%d", &staffID);

    printf("Enter staff name: ");
    scanf(" %[^\n]", staffName);

    attendanceFile = fopen("attendance.txt", "a");
    if (attendanceFile == NULL)
    {
        printf("Error: Unable to open file for writing.\n");
        return;
    }

    currentTime = time(NULL);
    localTime = localtime(&currentTime);

    fprintf(attendanceFile, "Staff ID: %d\n", staffID);
    fprintf(attendanceFile, "Staff Name: %s\n", staffName);
    fprintf(attendanceFile, "Date: %02d-%02d-%d\n", localTime->tm_mday, localTime->tm_mon + 1, localTime->tm_year + 1900);
    fprintf(attendanceFile, "Time: %02d:%02d:%02d\n\n", localTime->tm_hour, localTime->tm_min, localTime->tm_sec);

    fclose(attendanceFile);

    printf("Attendance recorded successfully!\n");
}
