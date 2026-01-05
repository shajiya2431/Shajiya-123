#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define WHITE   "\033[1;37m"
#define RESET   "\033[0m"

int choice;
int BusNumber;
int TotalSeats = 50;
int AvailableSeats = 40;
int BookedSeats = 0;
int Seats;
char CreateUsername[30];
char Createpassword[20];
char Source[20] = "Delhi";
char Destination[20] = "Bihar";
char Username[30];
char password[20];
char Email[50];
long long Contact;
float ticketprice = 500;

void signup();
int login();
void UserMenu();
void BookTicket();
void CancelTicket();
void CheckBusDeatails();

int isValidUsername(char str[])
{
    for (int i=0; str[i]!='\0'; i++)
    {
        if(!isalpha(str[i]) && str[i]!=' ') 
        return 0;
    }
    return 1;
}

int main()
{
    while (1)
    {
        printf(MAGENTA"\n********BUS RESERVATION SYSTEM*********"RESET);
        printf(YELLOW"\n1. sign up"RESET);
        printf(YELLOW"\n2. Login"RESET);
        printf(YELLOW"\n3. Exit"RESET);
        printf(WHITE"\nplease enter your choice: "RESET);
        scanf("%d",&choice);

        if (choice == 1)
        {
            signup();
        }
        else if (choice == 2)
        {
            if (login())
            {
                while (1)
                {
                    UserMenu();
                    printf(WHITE"\nEnter your choice:"RESET);
                    scanf("%d",&choice);

                    switch (choice)
                    {
                        case 1: BookTicket();
                        break;
                        case 2: CancelTicket();
                        break;
                        case 3: CheckBusDeatails();
                        break;
                        case 4: 
                            printf(MAGENTA"logout!\n"RESET);
                            printf(GREEN"\nThank you"RESET);
                            return 0;
                        default:
                            printf(RED"Invalid\n"RESET);
                    }

                }
            }
        }
        else if (choice == 3)
        {
            printf(GREEN"Exit! Thank you \n"RESET);
            return 0;
        }
        else
        {
            printf(RED"Invalid option\n"RESET);
        }

    }
  
    return 0;
 
} 

void signup()
{
    while(1)
    {
        printf(YELLOW"Create Username (letters only): "RESET);
        scanf(" %[^\n]", CreateUsername);
        if(isValidUsername(CreateUsername))
        {
            break;
        }
        else
        {
            printf(RED"Invalid username! only leatters .\n"RESET);
        }
    }

    printf(YELLOW"Create password: "RESET);
    scanf("%s",Createpassword);

    printf(YELLOW"Enter your Email: "RESET);
    scanf("%s",Email);

    printf(YELLOW"Enter your Contact: "RESET);
    scanf("%lld",&Contact);


    printf(GREEN"sign up Successfully!\n"RESET);
}

int login()
{
    printf(YELLOW"Enter your username: "RESET);
    scanf(" %[^\n]",Username);

    if(!isValidUsername(Username))
    {
        printf(RED"Invalid Username! only letters and spaces allowed.\n"RESET);
        return 0;
    }

    printf(YELLOW"Enter your password: "RESET);
    scanf("%s",password);

    if(strcmp(Username,CreateUsername) == 0 && strcmp(password,Createpassword) ==0)
    {
        printf(GREEN"Login successful ! Welcome %s\n"RESET, Username);
        return 1;
    }
    else
    {
        printf(RED"Invalid username or password!\n"RESET);
        return 0;
    }
    
             
}

void UserMenu()
{
    printf(CYAN"\n\n========User Menu========"RESET);
    printf(YELLOW"\n1. Book a Ticket"RESET);
    printf(RED"\n2. Cancel a Ticket"RESET);
    printf(BLUE"\n3. Check Bus Status"RESET);
    printf(MAGENTA"\n4. Logout:"RESET);
    
}

void BookTicket()
{
    printf(YELLOW"Enter Bus Number:"RESET);
    scanf("%d",&BusNumber);
    printf(YELLOW"Enter number of seats to book:"RESET);
    scanf("%d",&Seats);

    if(Seats <= AvailableSeats)
    {
        AvailableSeats = AvailableSeats - Seats;
        printf(BLUE"Total payment: %.2f\n"RESET , Seats*ticketprice);
        printf(GREEN"Booked Successfully %d seats \n"RESET, Seats);
        printf(YELLOW"\n~~~~ Happy Journey ~~~\n"RESET);
    }
    else
    {
        printf(RED"Not enough seats available!\n"RESET);
    }
}

void CancelTicket()
{
    printf(YELLOW"Enter number of seats to cancel:"RESET);
    scanf("%d",&Seats);
    printf(YELLOW"Enter Bus Number:"RESET);
    scanf("%d",&BusNumber);

    AvailableSeats = AvailableSeats + Seats;
    printf(RED"Return payment: %.2f\n"RESET,Seats*ticketprice);
    printf(RED"%d seats cancelled successfully\n"RESET , Seats);
}

void CheckBusDeatails()
{
    printf(BLUE"\n******Check Bus Status******\n"RESET);
    printf(BLUE"\n* Bus Number: %d"RESET,BusNumber);
    printf(BLUE"\n* Source City: %s"RESET,Source);
    printf(BLUE"\n* Destination City: %s"RESET,Destination);
    printf(BLUE"\n* Total Seats : %d"RESET,TotalSeats);
    printf(BLUE"\n* Available Seats: %d"RESET,AvailableSeats);
    printf(BLUE"\n* fare: %f"RESET,ticketprice);
    
}

    