// #include <stdio.h>
// #include<stdbool.h>
// #include<string.h>

// #define BOOK_SIZE 100
// #define AUTHOR_SIZE 100
// #define NAME_SIZE 100
// #define MEMBER_SIZE 100

// struct book
// {
//     int bookNumber;
//     char bookName[BOOK_SIZE];
//     char bookAuthor[AUTHOR_SIZE];
//     bool issued;
//     int issuedToMemberNumber;
// };

// struct member
// {
//     int memberNumber;
//     char memberName[NAME_SIZE];
//     int booksIssued;
// };



// void loadBooks(struct book books[], int *bookCount,
//                int *nextBookNo)
// {
//     FILE *fp = fopen("books.txt", "r");

//     if (fp == NULL)
//     {
//         *bookCount = 0;
//         *nextBookNo = 1;
//         printf("Could not open books.txt\n");
//         return;
//     }

//     *bookCount = 0;
//     *nextBookNo = 1;

//     while (*bookCount < BOOK_SIZE)
//     {
//         struct book b;
//         int issuedValue;

//         int result = fscanf(fp, "%d|%99[^|]|%99[^|]|%d|%d",
//                             &b.bookNumber,
//                             b.bookName,
//                             b.bookAuthor,
//                             &issuedValue,
//                             &b.issuedToMemberNumber);

//         if (result != 5)
//             break;

//         b.issued = (issuedValue != 0);

//         books[*bookCount] = b;

//         if (b.bookNumber >= *nextBookNo)
//             *nextBookNo = b.bookNumber + 1;

//         (*bookCount)++;
//     }

//     fclose(fp);
// }



// void saveBooks(struct book books[], int bookCount)
// {
//     FILE *fp = fopen("books.txt", "w");

//     if (fp == NULL)
//     {
//         printf("Error saving books!\n");
//         return;
//     }

//     for (int i = 0; i < bookCount; i++)
//     {
//         fprintf(fp, "%d|%s|%s|%d|%d\n",
//                 books[i].bookNumber,
//                 books[i].bookName,
//                 books[i].bookAuthor,
//                 books[i].issued,
//                 books[i].issuedToMemberNumber);
//     }

//     fclose(fp);
// }



// void loadMembers(struct member members[], int *memberCount,
//                  int *nextMemberNo)
// {
//     FILE *fp = fopen("members.txt", "r");

//     if (fp == NULL)
//     {
//         *memberCount = 0;
//         *nextMemberNo = 1;
//         return;
//     }

//     *memberCount = 0;
//     *nextMemberNo = 1;

//     while (*memberCount < MEMBER_SIZE)
//     {
//         struct member m;

//         int result = fscanf(fp, "%d|%99[^|]|%d",
//                             &m.memberNumber,
//                             m.memberName,
//                             &m.booksIssued);

//         if (result != 3)
//             break;

//         members[*memberCount] = m;

//         if (m.memberNumber >= *nextMemberNo)
//             *nextMemberNo = m.memberNumber + 1;

//         (*memberCount)++;
//     }

//     fclose(fp);
// }



// void saveMembers(struct member members[], int memberCount)
// {
//     FILE *fp = fopen("members.txt", "w");

//     if (fp == NULL)
//     {
//         printf("Error saving members!\n");
//         return;
//     }

//     for (int i = 0; i < memberCount; i++)
//     {
//         fprintf(fp, "%d|%s|%d\n",
//                 members[i].memberNumber,
//                 members[i].memberName,
//                 members[i].booksIssued);
//     }

//     fclose(fp);
// }



// //books management
// void addBooks(struct book books[], int *bookCount,int *nextBookNo)
// {
//     if (*bookCount>=BOOK_SIZE)
//     {
//         printf("Library is full!\n");
//         return;
//     }

//     printf("\nEnter the book name: ");
//     fgets(books[*bookCount].bookName,BOOK_SIZE,stdin);
//     books[*bookCount].bookName[strcspn(books[*bookCount].bookName, "\n")] = '\0';

//     printf("Enter the author name: ");
//     fgets(books[*bookCount].bookAuthor,AUTHOR_SIZE,stdin);
//     books[*bookCount].bookAuthor[strcspn(books[*bookCount].bookAuthor, "\n")] = '\0';

//     books[*bookCount].bookNumber = *nextBookNo;
//     books[*bookCount].issued = false;
//     books[*bookCount].issuedToMemberNumber = -1;

//     printf("\nBook Number: %d",books[*bookCount].bookNumber);
//     printf("\nBook Name: %s ",books[*bookCount].bookName);
//     printf("\nAuthor: %s",books[*bookCount].bookAuthor);
//     printf("\nStatus: ");
//     if (books[*bookCount].issued)
//     {
//         printf("Issued");
//     }
//     else
//     {
//         printf("Available");
//     }
//     printf("\n\nYour book has been added.\n\n\n");
    
//     (*nextBookNo)++;
//     (*bookCount)++;
// }

// void displayBooks(struct book books[], int bookCount)
// {   
//     if (bookCount==0)
//     {
//         printf("No books yet. Add more books to display.\n\n\n");
//         return;
//     }
    
//     for (int i = 0; i < bookCount; i++)
//     {
//         printf("\nBook Number: %d",books[i].bookNumber);
//         printf("\nBook Name: %s ",books[i].bookName);
//         printf("\nAuthor: %s",books[i].bookAuthor);
//         printf("\nStatus: ");
//         if (books[i].issued)
//         {
//             printf("Issued\n\n\n");
//         }
//         else
//         {
//             printf("Available\n\n\n");
//         }
        
        
//     }
    
// }

// int searchBooks(struct book books[], int bookCount)
// {
//     int target;
//     if (bookCount == 0)
//     {
//         printf("No books available to search.\n");
//         return -1;
//     }
//     printf("Enter the book number: ");
//     scanf("%d",&target);
//     for (int i = 0; i < bookCount; i++)
//     {
//         if (target==books[i].bookNumber)
//         {
//             return i;
//         }
        
//     }
//     return -1;
// }


// //members management

// void addMember(struct member members[],int *memberCount,int *nextMemberNo)
// {
//     if (*memberCount>=MEMBER_SIZE)
//     {
//         printf("Library members are full!\n");
//         return;
//     }

//     printf("\nEnter the member name: ");
//     fgets(members[*memberCount].memberName,MEMBER_SIZE,stdin);
//     members[*memberCount].memberName[strcspn(members[*memberCount].memberName, "\n")] = '\0';

//     members[*memberCount].memberNumber = *nextMemberNo;
//     members[*memberCount].booksIssued = 0;

//     printf("\nMember Number: %d", members[*memberCount].memberNumber);
//     printf("\nMember Name: %s", members[*memberCount].memberName);
//     printf("\nBooks Issued: %d\n", members[*memberCount].booksIssued);
//     printf("Member added successfully!\n\n");

//     (*nextMemberNo)++;
//     (*memberCount)++;
// }


// void displayMembers(struct member members[], int memberCount)
// {
//     if (memberCount==0)
//     {
//         printf("No members to display. Please add more to display.\n\n\n");
//         return;
//     }

//     for (int i = 0; i < memberCount; i++)
//     {
//         printf("\nMember Number: %d",members[i].memberNumber);
//         printf("\nMember Name: %s",members[i].memberName);
//         printf("\nBooks Issued: %d\n\n", members[i].booksIssued);
          
//     }   
    
// }

// int searchMember(struct member members[], int memberCount)
// {
//     int searchMemberNo; 
//     if (memberCount==0)
//     {
//         printf("No members present. Add members to search.\n");
//         return -1;
//     }
    
//     printf("Enter the member number: \n");
//     scanf("%d",&searchMemberNo);

//     for (int i = 0; i < memberCount; i++)
//     {
//         if (searchMemberNo==members[i].memberNumber)
//         {
//             return i;
//         }
        
//     }
//     printf("Member not found.\n");
//     return -1;
// }

// void issueBooks(struct book books[], int bookCount,
//                 struct member members[], int memberCount)
// {
//     if (bookCount == 0 || memberCount == 0)
//     {
//         printf("You need at least one book and one member to issue a book.\n");
//         return;
//     }

//     int index = searchBooks(books,bookCount);

//     if(index!=-1)
//     {
//         if (books[index].issued)
//         {
//             printf("The book is already issued.\n");
//             return;
//         }
//         else
//         {
//             int memberIndex = searchMember(members, memberCount);
//             if (memberIndex==-1)
//             {
//                 return;
//             }
//             else
//             {
//                 books[index].issued = true;
//                 books[index].issuedToMemberNumber = members[memberIndex].memberNumber;
//                 members[memberIndex].booksIssued++;
//                 printf("Book issued succesfully!\n");
//             }

            
//         }
        
//     }
//     else
//     {
//         printf("No such book was found.\n");
//         return;
//     }
   
// }

// void returnBooks(struct book books[], int bookCount,
//                 struct member members[], int memberCount)
// {
//     if (bookCount==0|| memberCount==0)
//     {
//         printf("No books or members to return.\n");
//         return;
//     }

//     int index = searchBooks(books,bookCount);
//     if (index == -1)
//     {
//         printf("No such book was found.\n");
//         return;
//     }
//     else
//     {
//         int memberNumber = books[index].issuedToMemberNumber;
//         if (books[index].issued == false)
//         {
//             printf("This book has not beem issued.\n");
//             return;
//         }
//         else
//         {
//             for (int i = 0; i < memberCount; i++)
//             {
//                 if (memberNumber == members[i].memberNumber)
//                 {
//                     members[i].booksIssued--;
//                     break;
//                 }
                
//             }
            
//             books[index].issued = false;
//             books[index].issuedToMemberNumber = -1;
//             printf("Book returned successfully!\n");
//         }
//     }   
// }

// void deleteBooks(struct book books[], int *bookCount)
// {
//     if (*bookCount==0)
//     {
//         printf("Add books to delete.\n");
//         return;
//     }

//     int index = searchBooks(books,*bookCount);
//     if (index==-1)
//     {
//         printf("No such book was found.\n");
//         return;
//     }
    
//     if (books[index].issued)
//     {
//         printf("Cannot delete a book that is currently issued.\n");
//         return;
//     }

//     for (int i = index; i < *bookCount-1; i++)
//     {
//         books[i]=books[i+1];
//     }

//     (*bookCount)--;
    
//     printf("Book was successfully deleted.\n");
    
// }

// void deleteMember(struct member members[], int *memberCount,
//                   struct book books[], int bookCount)
// {
//     if (*memberCount==0)
//     {
//         printf("Add members to delete.\n");
//         return;
//     }

//     int index = searchMember(members,*memberCount);
//     if (index==-1)
//     {
//         printf("No such member was found.\n");
//         return;
//     }

//     if(members[index].booksIssued>0)
//     {
//         printf("Cannot delete a member who has books issued.\n");
//         return;
//     }
//     for (int i = 0; i < bookCount; i++)
//     {
//         if (books[i].issued &&
//             books[i].issuedToMemberNumber == members[index].memberNumber)
//         {
//             printf("Cannot delete this member. They still have an issued book.\n");
//             return;
//         }
//     }

//     for (int i = index; i < *memberCount - 1; i++)
//     {
//         members[i] = members[i + 1];
//     }
//     (*memberCount)--;

//     printf("Member was sucessfully deleted.\n");
// }


// int main(void){

    
//     struct book books[BOOK_SIZE];
//     struct member members[MEMBER_SIZE];
//     int bookCount=0;
//     int memberCount=0;
//     int nextBookNo = 1;
//     int nextMemberNo = 1;
//     loadBooks(books, &bookCount, &nextBookNo);
//     loadMembers(members, &memberCount, &nextMemberNo);

//     int userChoice;
//     printf("\n----------------------------------LIBRARY MANAGEMENT SYSTEM----------------------------------\n");
    
//     while (1)
//     {   
//         printf("\n--------------- MAIN MENU ----------------\n");
//         printf("1.  Add Book\n");
//         printf("2.  Display All Books\n");
//         printf("3.  Search Book\n");
//         printf("4.  Delete Book\n");
//         printf("5.  Add Member\n");
//         printf("6.  Display All Members\n");
//         printf("7.  Search Member\n");
//         printf("8.  Delete Member\n");
//         printf("9.  Issue Book\n");
//         printf("10. Return Book\n");
//         printf("11. Exit\n");
//         printf("------------------------------------------\n");

//         printf("Enter your choice: ");
//         if (scanf("%d", &userChoice) != 1)
//         {
//             printf("Invalid input! Enter a number.\n");
//             while (getchar() != '\n');

//             continue;
//         }

//         getchar();

//         switch (userChoice)
//         {
//             case 1:
//                 {   
//                     addBooks(books,&bookCount,&nextBookNo);
//                     saveBooks(books, bookCount);
//                     break;
//                 }
            
//             case 2:
//                 {
//                     displayBooks(books,bookCount);
//                     break;
//                 }

            
//             case 3:
//                 {
//                     int index = searchBooks(books,bookCount);
//                     if (index == -1)
//                     {
//                         printf("book was not found!\n\n\n");
//                     }
//                     else
//                     {
//                         printf("\nBook Number: %d",books[index].bookNumber);
//                         printf("\nBook Name: %s ",books[index].bookName);
//                         printf("\nAuthor: %s",books[index].bookAuthor);
//                         printf("\nStatus: ");
//                         if (books[index].issued)
//                         {
//                             printf("Issued\n\n\n");
//                         }
//                         else
//                         {
//                             printf("Available\n\n\n");
//                         } 
//                     }
//                     break;
//                 }

//             case 4:
//                 {
//                     deleteBooks(books,&bookCount);
//                     saveBooks(books, bookCount);
//                     break;
//                 }
                
//             case 5:
//                 {
//                     addMember(members,&memberCount,&nextMemberNo);
//                     saveMembers(members, memberCount);
//                     break;
//                 }

//             case 6:
//                 {
//                     displayMembers(members,memberCount);
//                     break;
//                 }

//             case 7:
//                 {
//                     int index = searchMember(members, memberCount);

//                     if (index != -1)
//                     {
//                         printf("\nMember Number: %d", members[index].memberNumber);
//                         printf("\nMember Name: %s", members[index].memberName);
//                         printf("\nBooks Issued: %d\n\n", members[index].booksIssued);
//                     }
//                     break;
//                 }
            
//             case 8:
//                 {
//                     deleteMember(members,&memberCount,books,bookCount);
//                     saveMembers(members, memberCount);
//                     break;
//                 }

//             case 9:
//                 {
//                     issueBooks(books, bookCount, members, memberCount);
//                     saveBooks(books, bookCount);
//                     saveMembers(members, memberCount);

//                     break;
//                 }

//             case 10:
//                 {
//                     returnBooks(books, bookCount, members, memberCount);
//                     saveBooks(books, bookCount);
//                     saveMembers(members, memberCount);
//                     break;
//                 }

//             case 11:
//                 {
//                     printf("Exiting....\n");
//                     printf("Thank you for using Library Management Program.");
//                     return 0;
//                 }

//             default:
//                 {
//                     printf("Invalid Choice! Try Again");
//                     break;
//                 }
//         }
//     }
    

//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define BOOK_SIZE 100
#define AUTHOR_SIZE 100
#define NAME_SIZE 100
#define MEMBER_SIZE 100

struct book
{
    int bookNumber;
    char bookName[BOOK_SIZE];
    char bookAuthor[AUTHOR_SIZE];
    bool issued;
    int issuedToMemberNumber;
};

struct member
{
    int memberNumber;
    char memberName[NAME_SIZE];
    int booksIssued;
};




void readText(const char *prompt, char *dest, int size)
{
    while (1)
    {
        printf("%s", prompt);

        if (fgets(dest, size, stdin) == NULL)
        {
            printf("\nInput closed. Exiting.\n");
            exit(0);
        }

        char *newline = strchr(dest, '\n');
        if (newline != NULL)
        {
            *newline = '\0';
        }
        else
        {
            // line was longer than the buffer, discard the rest
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
        }

        if (dest[0] == '\0')
        {
            printf("Input cannot be empty. Try again.\n");
            continue;
        }

        if (strchr(dest, '|') != NULL)
        {
            printf("The '|' character is not allowed. Try again.\n");
            continue;
        }

        return;
    }
}



// ---------- print helpers ----------
void printBook(struct book b)
{
    printf("\nBook Number: %d", b.bookNumber);
    printf("\nBook Name: %s", b.bookName);
    printf("\nAuthor: %s", b.bookAuthor);
    printf("\nStatus: ");
    if (b.issued)
    {
        printf("Issued\n\n\n");
    }
    else
    {
        printf("Available\n\n\n");
    }
}

void printMember(struct member m)
{
    printf("\nMember Number: %d", m.memberNumber);
    printf("\nMember Name: %s", m.memberName);
    printf("\nBooks Issued: %d\n\n", m.booksIssued);
}



// ---------- file handling ----------
void loadBooks(struct book books[], int *bookCount,
               int *nextBookNo)
{
    FILE *fp = fopen("books.txt", "r");

    *bookCount = 0;
    *nextBookNo = 1;

    if (fp == NULL)
    {
        return;
    }

    while (*bookCount < BOOK_SIZE)
    {
        struct book b;
        int issuedValue;

        int result = fscanf(fp, "%d|%99[^|]|%99[^|]|%d|%d",
                            &b.bookNumber,
                            b.bookName,
                            b.bookAuthor,
                            &issuedValue,
                            &b.issuedToMemberNumber);

        if (result != 5)
            break;

        b.issued = (issuedValue != 0);

        books[*bookCount] = b;

        if (b.bookNumber >= *nextBookNo)
            *nextBookNo = b.bookNumber + 1;

        (*bookCount)++;
    }

    fclose(fp);
}



void saveBooks(struct book books[], int bookCount)
{
    FILE *fp = fopen("books.txt", "w");

    if (fp == NULL)
    {
        printf("Error saving books!\n");
        return;
    }

    for (int i = 0; i < bookCount; i++)
    {
        fprintf(fp, "%d|%s|%s|%d|%d\n",
                books[i].bookNumber,
                books[i].bookName,
                books[i].bookAuthor,
                books[i].issued,
                books[i].issuedToMemberNumber);
    }

    fclose(fp);
}



void loadMembers(struct member members[], int *memberCount,
                 int *nextMemberNo)
{
    FILE *fp = fopen("members.txt", "r");

    *memberCount = 0;
    *nextMemberNo = 1;

    if (fp == NULL)
    {
        return;
    }

    while (*memberCount < MEMBER_SIZE)
    {
        struct member m;

        int result = fscanf(fp, "%d|%99[^|]|%d",
                            &m.memberNumber,
                            m.memberName,
                            &m.booksIssued);

        if (result != 3)
            break;

        members[*memberCount] = m;

        if (m.memberNumber >= *nextMemberNo)
            *nextMemberNo = m.memberNumber + 1;

        (*memberCount)++;
    }

    fclose(fp);
}



void saveMembers(struct member members[], int memberCount)
{
    FILE *fp = fopen("members.txt", "w");

    if (fp == NULL)
    {
        printf("Error saving members!\n");
        return;
    }

    for (int i = 0; i < memberCount; i++)
    {
        fprintf(fp, "%d|%s|%d\n",
                members[i].memberNumber,
                members[i].memberName,
                members[i].booksIssued);
    }

    fclose(fp);
}



 
void addBooks(struct book books[], int *bookCount, int *nextBookNo)
{
    if (*bookCount >= BOOK_SIZE)
    {
        printf("Library is full!\n");
        return;
    }

    readText("\nEnter the book name: ",
             books[*bookCount].bookName, BOOK_SIZE);

    readText("Enter the author name: ",
             books[*bookCount].bookAuthor, AUTHOR_SIZE);

    books[*bookCount].bookNumber = *nextBookNo;
    books[*bookCount].issued = false;
    books[*bookCount].issuedToMemberNumber = -1;

    printBook(books[*bookCount]);
    printf("Your book has been added.\n\n\n");

    (*nextBookNo)++;
    (*bookCount)++;
}

void displayBooks(struct book books[], int bookCount)
{
    if (bookCount == 0)
    {
        printf("No books yet. Add more books to display.\n\n\n");
        return;
    }

    for (int i = 0; i < bookCount; i++)
    {
        printBook(books[i]);
    }
}

int searchBooks(struct book books[], int bookCount)
{
    int target;

    if (bookCount == 0)
    {
        printf("No books available to search.\n");
        return -1;
    }

    printf("Enter the book number: ");
    if (scanf("%d", &target) != 1)
    {
        printf("Invalid input! Enter a number.\n");
        while (getchar() != '\n');
        return -1;
    }

    for (int i = 0; i < bookCount; i++)
    {
        if (target == books[i].bookNumber)
        {
            return i;
        }
    }
    return -1;
}

void deleteBooks(struct book books[], int *bookCount)
{
    if (*bookCount == 0)
    {
        printf("Add books to delete.\n");
        return;
    }

    int index = searchBooks(books, *bookCount);
    if (index == -1)
    {
        printf("No such book was found.\n");
        return;
    }

    if (books[index].issued)
    {
        printf("Cannot delete a book that is currently issued.\n");
        return;
    }

    for (int i = index; i < *bookCount - 1; i++)
    {
        books[i] = books[i + 1];
    }

    (*bookCount)--;

    printf("Book was successfully deleted.\n");
}



// ---------- members management ----------
void addMember(struct member members[], int *memberCount, int *nextMemberNo)
{
    if (*memberCount >= MEMBER_SIZE)
    {
        printf("Library members are full!\n");
        return;
    }

    readText("\nEnter the member name: ",
             members[*memberCount].memberName, NAME_SIZE);

    members[*memberCount].memberNumber = *nextMemberNo;
    members[*memberCount].booksIssued = 0;

    printMember(members[*memberCount]);
    printf("Member added successfully!\n\n");

    (*nextMemberNo)++;
    (*memberCount)++;
}

void displayMembers(struct member members[], int memberCount)
{
    if (memberCount == 0)
    {
        printf("No members to display. Please add more to display.\n\n\n");
        return;
    }

    for (int i = 0; i < memberCount; i++)
    {
        printMember(members[i]);
    }
}

int searchMember(struct member members[], int memberCount)
{
    int searchMemberNo;

    if (memberCount == 0)
    {
        printf("No members present. Add members to search.\n");
        return -1;
    }

    printf("Enter the member number: ");
    if (scanf("%d", &searchMemberNo) != 1)
    {
        printf("Invalid input! Enter a number.\n");
        while (getchar() != '\n');
        return -1;
    }

    for (int i = 0; i < memberCount; i++)
    {
        if (searchMemberNo == members[i].memberNumber)
        {
            return i;
        }
    }

    printf("Member not found.\n");
    return -1;
}

void deleteMember(struct member members[], int *memberCount,
                  struct book books[], int bookCount)
{
    if (*memberCount == 0)
    {
        printf("Add members to delete.\n");
        return;
    }

    
    int index = searchMember(members, *memberCount);
    if (index == -1)
    {
        return;
    }

    if (members[index].booksIssued > 0)
    {
        printf("Cannot delete a member who has books issued.\n");
        return;
    }

    for (int i = 0; i < bookCount; i++)
    {
        if (books[i].issued &&
            books[i].issuedToMemberNumber == members[index].memberNumber)
        {
            printf("Cannot delete this member. They still have an issued book.\n");
            return;
        }
    }

    for (int i = index; i < *memberCount - 1; i++)
    {
        members[i] = members[i + 1];
    }
    (*memberCount)--;

    printf("Member was successfully deleted.\n");
}



// ---------- issue and return ----------
void issueBooks(struct book books[], int bookCount,
                struct member members[], int memberCount)
{
    if (bookCount == 0 || memberCount == 0)
    {
        printf("You need at least one book and one member to issue a book.\n");
        return;
    }

    int index = searchBooks(books, bookCount);

    if (index == -1)
    {
        printf("No such book was found.\n");
        return;
    }

    if (books[index].issued)
    {
        printf("The book is already issued.\n");
        return;
    }

    // searchMember already prints a message if the member is not found
    int memberIndex = searchMember(members, memberCount);
    if (memberIndex == -1)
    {
        return;
    }

    books[index].issued = true;
    books[index].issuedToMemberNumber = members[memberIndex].memberNumber;
    members[memberIndex].booksIssued++;
    printf("Book issued successfully!\n");
}

void returnBooks(struct book books[], int bookCount,
                 struct member members[], int memberCount)
{
    if (bookCount == 0 || memberCount == 0)
    {
        printf("No books or members to return.\n");
        return;
    }

    int index = searchBooks(books, bookCount);
    if (index == -1)
    {
        printf("No such book was found.\n");
        return;
    }

    if (!books[index].issued)
    {
        printf("This book has not been issued.\n");
        return;
    }

    int memberNumber = books[index].issuedToMemberNumber;

    for (int i = 0; i < memberCount; i++)
    {
        if (memberNumber == members[i].memberNumber)
        {
            members[i].booksIssued--;
            break;
        }
    }

    books[index].issued = false;
    books[index].issuedToMemberNumber = -1;
    printf("Book returned successfully!\n");
}



int main(void)
{
    struct book books[BOOK_SIZE];
    struct member members[MEMBER_SIZE];
    int bookCount = 0;
    int memberCount = 0;
    int nextBookNo = 1;
    int nextMemberNo = 1;

    loadBooks(books, &bookCount, &nextBookNo);
    loadMembers(members, &memberCount, &nextMemberNo);

    int userChoice;
    printf("\n----------------------------------LIBRARY MANAGEMENT SYSTEM----------------------------------\n");

    while (1)
    {
        printf("\n--------------- MAIN MENU ----------------\n");
        printf("1.  Add Book\n");
        printf("2.  Display All Books\n");
        printf("3.  Search Book\n");
        printf("4.  Delete Book\n");
        printf("5.  Add Member\n");
        printf("6.  Display All Members\n");
        printf("7.  Search Member\n");
        printf("8.  Delete Member\n");
        printf("9.  Issue Book\n");
        printf("10. Return Book\n");
        printf("11. Exit\n");
        printf("------------------------------------------\n");

        printf("Enter your choice: ");
        if (scanf("%d", &userChoice) != 1)
        {
            printf("Invalid input! Enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        while (getchar() != '\n');

        switch (userChoice)
        {
            case 1:
                addBooks(books, &bookCount, &nextBookNo);
                saveBooks(books, bookCount);
                break;

            case 2:
                displayBooks(books, bookCount);
                break;

            case 3:
            {
                int index = searchBooks(books, bookCount);
                if (index == -1)
                {
                    printf("Book was not found!\n\n\n");
                }
                else
                {
                    printBook(books[index]);
                }
                break;
            }

            case 4:
                deleteBooks(books, &bookCount);
                saveBooks(books, bookCount);
                break;

            case 5:
                addMember(members, &memberCount, &nextMemberNo);
                saveMembers(members, memberCount);
                break;

            case 6:
                displayMembers(members, memberCount);
                break;

            case 7:
            {
                int index = searchMember(members, memberCount);
                if (index != -1)
                {
                    printMember(members[index]);
                }
                break;
            }

            case 8:
                deleteMember(members, &memberCount, books, bookCount);
                saveMembers(members, memberCount);
                break;

            case 9:
                issueBooks(books, bookCount, members, memberCount);
                saveBooks(books, bookCount);
                saveMembers(members, memberCount);
                break;

            case 10:
                returnBooks(books, bookCount, members, memberCount);
                saveBooks(books, bookCount);
                saveMembers(members, memberCount);
                break;

            case 11:
                printf("Exiting....\n");
                printf("Thank you for using Library Management Program.\n");
                return 0;

            default:
                printf("Invalid Choice! Try Again.\n");
                break;
        }
    }

    return 0;
}