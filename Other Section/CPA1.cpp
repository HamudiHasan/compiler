#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include <stdlib.h>

#define MAX 53
#define SIZE 20
int number=0;
int id =0;
struct symbolTable
{
    char name[SIZE];
    char classType[SIZE];
    struct symbolTable *next;
}
*head[MAX];
typedef struct symbolTable node;
int searchFromTable(char name[], char classType[]);
int options()
{
    int option;
    printf("Press 1 to Insert\nPress 2 to Search\nPress 3 to Delete\nPress 4 to Show\nPress 5 to delete all\nPress 6 to exit");
    printf("\n\n");

    scanf("%d",&option);
    if(option>0 || option<7)
        return option;
    else
        printf("Wrong Input\n");
}

int hashFunction(char str [])
{
    int i;
    int sum = 0;
    for(i=0; str[i]; i++)
    {
        sum+=str[i];
    }
    sum=sum%MAX;
    return sum;
}

void insertIntoTable()
{
    char name[SIZE];
    char classType[SIZE];
    int hashValue;

    node *temp = NULL;
    printf("Enter name : \n");
    fflush(stdout);
    scanf("%s",name);
    fflush(stdin);

    printf("\nClass Type : ");
    fflush(stdout);
    gets(classType);
     fflush(stdin);

    hashValue = hashFunction(name);
      if( strcmp(classType,"number")==0){
        number++;
    }
        hashValue = hashFunction(name);
      if( strcmp(classType,"id")==0){
        id++;
    }



    if(searchFromTable(name,classType)==-1)
    {

        if( head[hashValue] == NULL )
        {
            head[hashValue] = new node;

            strcpy( head[hashValue]->name,name);
            strcpy( head[hashValue]->classType,classType );
            head[hashValue]->next = NULL;
        }
        else
        {
            temp = new node;

            strcpy( temp->name,name );
            strcpy( temp->classType,classType );
            temp->next = head[hashValue];
            head[hashValue] = temp;
        }
    }
    else return;
}

int searchFromTable(char name[], char classType[])
{
    node *temp = NULL;

    int hashValue;



    hashValue = hashFunction(name);

    if( head[hashValue] == NULL )
    {
        printf("Not Found\n");
        return -1;
    }

    temp = new node;
    temp = head[hashValue];

    while(temp)
    {


        if(strcmp(temp->name,name)==0&&strcmp(temp->classType,classType)==0)
        {
            printf("\nFound\n");
            return 1;
        }
        temp=temp->next;
    }
    printf("Not Found\n");
}

void deleteFromTable()
{
    node *prev = NULL;
    node *temp = NULL;

    char name[SIZE];
    char classType[SIZE];
    int hashValue;

    printf("Enter name : \n");
    fflush(stdout);
    scanf("%s",name);
    fflush(stdin);

    printf("\nClass Type : ");
    fflush(stdout);
    gets(classType);
    fflush(stdin);

    hashValue = hashFunction(name);

    if(head[hashValue]==NULL )
    {
        printf("Nothing to Delete");
        return;
    }

    temp = new node;
    temp = head[hashValue];
    if( strcmp(temp->name,name)==0&&strcmp(temp->classType,classType)==0)
    {
        head[hashValue] = head[hashValue]->next;
        free(temp);
        printf("Data Deleted\n");
        return;
    }
    prev=new node;
    prev=temp;

    while(temp!=NULL)
    {
        if(strcmp(temp->classType,"number")==0)
        {
            prev->next=temp->next;
            free(temp);
            printf("Data Deleted\n");
            return;
        }
        prev=temp;
        temp=temp->next;
    }
    printf("Data not not Found\n");

    return;
}
void showTable()
{
    int i;
    node *temp;
    temp = new node;
    for(i=0; i<MAX; i++)
    {
        temp=head[i];
        printf("\n%d) ",i+1);
        while(temp!=NULL)
        {
            printf("<%s,%s> ",temp->name,temp->classType);
            temp=temp->next;
        }
    }

    printf("Number = %d\n IDENTIFIER = %d",number,id);
}
void deleteAll()
{
        int i;

        node *prev = NULL;
        node *temp = NULL;

        prev = new node;
        temp = new node;

        for( i = 0; i < MAX; i++ )
        {
                if( head[i] != NULL )
                {
                        prev = head[i];
                        temp = prev->next;

                        while( temp != NULL )
                        {
                                delete (prev);

                                prev = temp;
                                temp = temp->next;
                        }
                        delete (prev);

                        head[i] = NULL;
                }
        }
        number=0;
        id=0;
}

void decetion(int option)
{
    if(option == 1)
    {
        insertIntoTable();
        printf("\n\n");
    }
    if(option == 2)
    {
        char name[SIZE];
        char classType[SIZE];

        printf("Enter name : \n");
        fflush(stdout);
        scanf("%s",name);
        fflush(stdin);

        printf("\nClass Type : ");
        fflush(stdout);
        gets(classType);
        fflush(stdin);

        int flag = searchFromTable(name,classType);
        printf("\n\n");
    }
    if(option == 3)
    {
        deleteFromTable();
        printf("\n\n");
    }
    if(option == 4)
    {
        showTable();
        printf("\n\n");
    }
        if(option == 5)
    {
      deleteAll();
    }
    if(option == 6)
    {
        exit(0);
    }
}

int main(void)
{
    int option;
    do
    {
        option = options();
        decetion(option);
    }
    while(option!=6);
}
