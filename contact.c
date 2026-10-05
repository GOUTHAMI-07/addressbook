#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include <ctype.h>
#include <string.h>
int matches[100];
int editindex = -1;
void name(AddressBook *addressBook);
void phone(AddressBook *addressBook);
void email(AddressBook *addressBook);
int search(AddressBook *addressBook);


void listContacts(AddressBook *addressBook) //int sortCriteria)
{
    // Sort contacts based on the choosen criteria
    int criteria;
    printf("sort based on 1.name\n2.phone number\n3.email\n");
    scanf("%d",&criteria);
    switch(criteria)
    {
        case 1:
        for(int i=0;i<addressBook->contactCount-1;i++)
        {
            for(int j=0;j<addressBook->contactCount-1;j++){
                int c=strcasecmp(addressBook->contacts[j].name, addressBook->contacts[j+1].name);
                if(c>0)
                {
                    Contact temp= addressBook->contacts[j];
                     addressBook->contacts[j] = addressBook->contacts[j+1];
                     addressBook->contacts[j+1] =temp;
                }

            }

        }
        break;
        case 2:
        for(int i=0;i<addressBook->contactCount-1;i++)
        {
            for(int j=0;j<addressBook->contactCount-1;j++)
            {
                int c=strcasecmp(addressBook->contacts[j].phone, addressBook->contacts[j+1].phone);
                if(c>0){
                    Contact temp= addressBook->contacts[j];
                     addressBook->contacts[j] = addressBook->contacts[j+1];
                     addressBook->contacts[j+1] =temp;
                
                }
            }

        }
        break;
        case 3:
        for(int i=0;i<addressBook->contactCount-1;i++)
        {
            for(int j=0;j<addressBook->contactCount-1;j++)
            {
                int c=strcasecmp(addressBook->contacts[j].email, addressBook->contacts[j+1].email);
                if(c>0){
                    Contact temp= addressBook->contacts[j];
                     addressBook->contacts[j] = addressBook->contacts[j+1];
                     addressBook->contacts[j+1] =temp;
                }
            }
        } 
        break;
    }  
    for(int i=0;i<addressBook->contactCount;i++)
    {
            printf("%s\t%s\t%s\n",addressBook->contacts[i].name,
                addressBook->contacts[i].phone,addressBook->contacts[i].email);
    } 
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    
    // Load contacts from file during initialization (After files)
    //loadContactsFromFile(addressBook);
}


void saveAndExit(AddressBook *addressBook) 
{
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */
    name(addressBook);
    phone(addressBook);
    email(addressBook);
    addressBook->contactCount++;
}

int searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
    search(addressBook);
}
    


void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
    int choice;
    int present;
    int fieldchoice;

    present = search(addressBook);

    if(present == 0)
    {
        return;
    }

    printf("Enter contact from 1 to %d to edit: ", present);
    scanf("%d", &choice);

    if(choice < 1 || choice > present)
    {
        printf("Invalid choice\n");
        return;
    }

    editindex = matches[choice - 1];
    addressBook->contacts[addressBook->contactCount] =
        addressBook->contacts[editindex];

    printf("Enter field to edit\n");
    printf("1. Name\n");
    printf("2. Phone\n");
    printf("3. Email\n");
    scanf("%d",&fieldchoice);

    switch(fieldchoice)
    {
        case 1:
        {
            name(addressBook);

            strcpy(addressBook->contacts[editindex].name,
                   addressBook->contacts[addressBook->contactCount].name);

            printf("Name updated successfully\n");
            break;
        }

        case 2:
        {
            phone(addressBook);

            strcpy(addressBook->contacts[editindex].phone,
                   addressBook->contacts[addressBook->contactCount].phone);

            printf("Phone updated successfully\n");
            break;
        }

        case 3:
        {
            email(addressBook);

            strcpy(addressBook->contacts[editindex].email,
                   addressBook->contacts[addressBook->contactCount].email);

            printf("Email updated successfully\n");
            break;
        }

        default:
        {
            printf("Invalid choice\n");
            editindex = -1;
            return;
        }
    }

    editindex = -1;

    printf("Contact updated successfully\n");
}

void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
    //squeeze the array
    int del;
    printf("delete based on 1.name 2.phone 3.email\n");
    scanf("%d",&del);
    switch(del){
        case 1:{
        char n[20];
        printf("enter name to delete");
        scanf(" %[^\n]",n);
        int count=0;
        int match[100];
        for(int i=0;i<addressBook->contactCount;i++)
        {
            char *ch=strcasestr(addressBook->contacts[i].name,n);
            if(ch!=NULL)
            {
                printf("%d.%s\n",count+1,addressBook->contacts[i].name);
                match[count]=i;
                count++;

            }
            

        }
        if(count==0){
            printf("Contact not found to delete");
            break;
        }
        int s;
        printf("enter the serial number");
        scanf("%d",&s);
        int index=match[s-1];
        for(int i=index;i<addressBook->contactCount-1;i++)
        {
            addressBook->contacts[i]=addressBook->contacts[i+1];
        }
        addressBook->contactCount--;
        break;
    }
        case 2:
        {
        char n[10];
        printf("enter phone number to delete");
        scanf("%s",n);
        int count=0;
        int match[100];
        for(int i=0;i<addressBook->contactCount;i++)
        {
            char *ch=strcasestr(addressBook->contacts[i].phone,n);
            if(ch!=NULL){
                printf("%d.%s\n",count+1,addressBook->contacts[i].phone);
                match[count]=i;
                count++;

            }
            

        }
        if(count==0){
            printf("Contact not found to delete");
            break;
        }
        int s;
        printf("enter the serial number");
        scanf("%d",&s);
        int index=match[s-1];
        for(int i=index;i<addressBook->contactCount-1;i++)
        {
            addressBook->contacts[i]=addressBook->contacts[i+1];
        }
        addressBook->contactCount--;
        break;
    }
        case 3:
        {
        char n[50];
        printf("enter email to delete");
        scanf("%s",n);
        int count=0;
        int match[100];
        for(int i=0;i<addressBook->contactCount;i++)
        {
            char *ch=strcasestr(addressBook->contacts[i].email,n);
            if(ch!=NULL){
                printf("%d.%s\n",count+1,addressBook->contacts[i].email);
                match[count]=i;
                count++;

            }
            

        }
        if(count==0){
            printf("Contact not found to delete");
            break;
        }
        int s;
        printf("enter the serial number");
        scanf("%d",&s);
        int index=match[s-1];
        for(int i=index;i<addressBook->contactCount-1;i++)
        {
            addressBook->contacts[i]=addressBook->contacts[i+1];
        }
        addressBook->contactCount--;
        break;
    }



    }

   
}
void name(AddressBook *addressBook)
{
    int valid=1;
    while(valid)
    {
    int valid=1;
    printf("Enter your name\n");
    scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].name);
    int n=strlen(addressBook->contacts[addressBook->contactCount].name);
    if(n<2)
    {
        valid=0;
        printf("Invalid name must contain atleast 2 char\n");
    }
    for(int i=0;i<n;i++)
    {
    if((!isalnum(addressBook->contacts[addressBook->contactCount].name[i]))&&!(isspace(addressBook->contacts[addressBook->contactCount].name[i]))){
        valid=0;
        printf("Invalid name ,name should contain only alphabet,number and space\n");
        break;
    }
    }
    if(valid)
    {
        break;
    }

}
    
}
void phone(AddressBook *addressBook)
{
    int unique=1;
    while(unique)
    {
    int unique=1;
    printf("Enter your phone number\n");
    scanf("%s",addressBook->contacts[addressBook->contactCount].phone);
    if(strlen(addressBook->contacts[addressBook->contactCount].phone)!=10)
    {
        unique=0;
        printf("Invalid Number,number must be 10 digits\n");
    }
    else if(addressBook->contacts[addressBook->contactCount].phone[0]<'6')
    {
        unique=0;
        printf("Invalidnumber Number,number should be in range of 6-9\n");
    }
    else
    {
        for(int i=0;i<addressBook->contactCount;i++){
            if(strcmp(addressBook->contacts[i].phone,addressBook->contacts[addressBook->contactCount].phone)==0)
            {
                unique=0;
                printf("Phone number already exists\n");
                break;
            }
        }
    }
    if(unique)
    {
        break;
    }
}

}
void email(AddressBook *addressBook)
{
    int valid=1;
     while(valid){
        int valid=1;
        printf("Enter your email\n");
        scanf("%s",addressBook->contacts[addressBook->contactCount].email);
        int n=strlen(addressBook->contacts[addressBook->contactCount].email);
        char *dot=strstr(addressBook->contacts[addressBook->contactCount].email,".com");
        char *at=strchr(addressBook->contacts[addressBook->contactCount].email,'@');
        if(dot==NULL)
        {
            printf("Invaild,last four char of email should be .com\n");
            valid=0;
        }
        else if(strlen(dot)!=4)
        {
            printf("Invalid,after .com no other character should be present\n");
            valid=0;
        }
        else if(at==NULL)
        {
            printf("Inavlid,email should contain atleast one '@' char\n");
            valid=0;
        }
        else{
            int count=0;
            for(int i=0;i<n;i++){
                if(addressBook->contacts[addressBook->contactCount].email[i]=='@'){
                    count++;
                }
            }
            if(count!=1){
                valid=0;
                printf("Invalid email should contain only one '@'\n");
            }
        }
        if(dot==at+1)
        {
            printf("Invaild atleast one char should be present between @ and .com");
            valid=0;
        }
        else if(!(isalnum(addressBook->contacts[addressBook->contactCount].email[0])))
        {
            printf("Invaild first character should be only alphabet or number");
            valid=0;
        }
        else
        {
        for(int i=0;i<n;i++)
        {
        char ch=addressBook->contacts[addressBook->contactCount].email[i];
        if(!(islower(ch)||ch=='.'|| ch=='@'||isdigit(ch) ))
        {
            printf("Invalid,email must contain only lower case letters @ and . only\n");
            valid=0;
            break;
        }
        }
    }
if(valid)
{
    for(int i=0;i<addressBook->contactCount;i++){
        if(strcmp(addressBook->contacts[i].email,addressBook->contacts[addressBook->contactCount].email)==0){
            printf("email already exists\n");
            valid=0;
            break;
        }
        
    }
}
if(valid)
{
    break;
}
}


}
int search(AddressBook *addressBook)
{
    int n;
    int count=0;
    printf("Search Based on\n1.Name\n2.Phone\n3.Email");
    scanf("%d",&n);
    //compare using strcasestr if searching by name
    switch(n){
        case 1:
        {
        char name1[50];
        printf("Enter name to search");
        scanf(" %[^\n]",name1);
        for(int i=0;i<addressBook->contactCount;i++){
        char *ch=strcasestr(addressBook->contacts[i].name , name1);
        if(ch!=NULL){
            printf("%d.%s %s %s\n",count+1,addressBook->contacts[i].name,
                addressBook->contacts[i].phone,addressBook->contacts[i].email);
                matches[count]=i;
                count++;
        }
        
    }
    break;
}
    
    case 2:
    {
    char num[10];
    printf("enter number to search");
    scanf("%s",num);
    for(int i=0;i<addressBook->contactCount;i++){
        char *ch=strcasestr(addressBook->contacts[i].phone ,num);
        if(ch!=NULL){
            printf("%d.%s %s %s\n",count+1,addressBook->contacts[i].name,
                addressBook->contacts[i].phone,addressBook->contacts[i].email);
                matches[count]=i;
                count++;
        }
        
    }
    break;
}
    case 3:
    {
    char mail[20];
    printf("enter email to search");
    scanf("%s",mail);
    for(int i=0;i<addressBook->contactCount;i++){
        char *ch=strcasestr(addressBook->contacts[i].email ,mail);
        if(ch!=NULL){
            printf("%d.%s %s %s\n",count+1,addressBook->contacts[i].name,
                addressBook->contacts[i].phone,addressBook->contacts[i].email);
                matches[count]=i;
                count++;
        }
       
    }

    break;
}
    default:
    printf("Invalid choice\n");
    return 0;
    }

    if(count == 0)
    {
        printf("Contact not found\n");
    }

    return count;
}





