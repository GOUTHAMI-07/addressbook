#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include <ctype.h>
#include <string.h>
void name(AddressBook *addressBook);
void phone(AddressBook *addressBook);
void email(AddressBook *addressBook);
void search(AddressBook *addressBook);


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
            printf("%s\t%s\t%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
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


   


void searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
    search(addressBook);
}
    


void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
    printf("enter name to search");
    search(addressBook);
    int field;
    printf("enter field to edit 1.name 2.phone 3.email");
    scanf("%d",&field);
    switch(field)
    {
        case 1:
        char newname[20];
        printf("enter newname");
        scanf("%s",newname);
        int i=0;
        printf("enter the index");
        scanf("%d",&i);
        strcpy(addressBook->contacts[i].name,newname);
        case 2:
        char newphone[10];
        printf("enter newnumber");
        scanf("%s",newnumber);
        int i=0;
    }
}

void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
    //squeeze the array
    int del;
    printf("delete based on 1.name 2.phone 3.email");
    scanf("%d",&del);
    switch(del){
        case 1:{
        char n[20];
        printf("enter name to delete");
        scanf("%s",n);
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
    scanf("%s",addressBook->contacts[addressBook->contactCount].name);
    int n=strlen(addressBook->contacts[addressBook->contactCount].name);
    if(n<2)
    {
        valid=0;
    }
    for(int i=0;i<n;i++)
    {
    if((!isalnum(addressBook->contacts[addressBook->contactCount].name[i]))&&!(isspace(addressBook->contacts[addressBook->contactCount].name[i]))){
        valid=0;
        break;
    }
    }
    if(valid)
    {
        break;
    }
    else
    {
        printf("Invalid name,name must contain atleat 2 char and name should conatain only alphabet number and sapce\n");
    }
}
    
}
void phone(AddressBook *addressBook)
{
    while(1)
    {
    printf("Enter your phone number\n");
    scanf("%s",addressBook->contacts[addressBook->contactCount].phone);
    if(strlen(addressBook->contacts[addressBook->contactCount].phone)!=10)
    {
        printf("invalid number,number must be 10 digits\n");
    }
    else if(addressBook->contacts[addressBook->contactCount].phone[0]<'6')
    {
        printf("Number should be in range of 6-9\n");
    }
    else
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
        printf("Enter your email");
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
        else if(dot==at+1)
        {
            printf("Invaild atleast one char should be present between @ and .com");
            valid=0;
        }
        else if(addressBook->contacts[addressBook->contactCount].email[0]=='@')
        {
            printf("Invaild first character should not be @");
            valid=0;
        }
        else
        {
        for(int i=0;i<n;i++)
        {
            char ch=addressBook->contacts[addressBook->contactCount].email[i];
        if(!(islower(ch)||ch=='.'|| ch=='@' ))
        {
            printf("Invalid,email must contain only lower case letters,@ and . only\n");
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
void search(AddressBook *addressBook)
{
    int n;
    printf("Search Based on\n1.Name\n2.Phone\n3.Email");
    scanf("%d",&n);
    //compare using strcasestr if searching by name
    switch(n){
        case 1:
        {
        int f=1;
        char name1[50];
        printf("Enter name to search");
        scanf("%s",name1);
        for(int i=0;i<addressBook->contactCount;i++){
        char *ch=strcasestr(addressBook->contacts[i].name , name1);
        if(ch!=NULL){
            printf("%d %s\n",i,addressBook->contacts[i].name);
            f=0;
        }
        
    }
    if(f==1)
    {
        printf("not found");
    }
    break;
}
    
    case 2:
    {
    int f=1;
    char num[10];
    printf("enter number to search");
    scanf("%s",num);
    for(int i=0;i<addressBook->contactCount;i++){
        char *ch=strstr(addressBook->contacts[i].phone ,num);
        if(ch!=NULL){
            printf("%d %s\n",i,addressBook->contacts[i].phone);
            f=0;
        }
        
    }
    if(f)
    {
        printf("not found");

    }

    break;
}
    case 3:
    {
    int f=1;
    char mail[20];
    printf("enter email to search");
    scanf("%s",mail);
    for(int i=0;i<addressBook->contactCount;i++){
        char *ch=strcasestr(addressBook->contacts[i].email ,mail);
        if(ch!=NULL){
            printf("%d %s\n",i,addressBook->contacts[i].email);
            f=0;
        }
       
    }
    if(f)
    {
        printf("not found");
    }
    break;

 }


 }
}



