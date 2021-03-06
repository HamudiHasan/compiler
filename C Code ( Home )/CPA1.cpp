#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include <stdlib.h>

#define MAX 53
#define SIZE 20
struct symbolTable
{
    char name[SIZE];
    char classType[SIZE];
    struct symbolTable *next;
}
*head[MAX];
typedef struct symbolTable node;
int options()
{
    int option;
    printf("Press 1 to Insert\nPress 2 to Search\nPress 3 to Delete\nPress 4 to Show\nPress 5 to exit");
    printf("\n\n");

    scanf("%d",&option);
    if(option>0 || option<6)
        return option;
    else
        printf("Wrong Input\n");
}

int hashFunction(char str [])
{
    int i;
    int sum = 0;
    for(i=0;str[i];i++)
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

int searchFromTable()
{
    node *temp = NULL;
    char name[SIZE + 1];
    char classType[SIZE + 1];
    int hashValue,temp1,temp2;

    printf("Enter name : \n");
    fflush(stdout);
    scanf("%s",name);
    fflush(stdin);

    printf("\nClass Type : ");
    fflush(stdout);
    gets(classType);
    fflush(stdin);

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
    if( strcmp(temp->name,name)==0&&strcmp(temp->classType,classType)==0 )
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
        if(strcmp(temp->name,name)==0&&strcmp(temp->classType,classType)==0)
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
    for(i=0;i<MAX;i++)
    {
        temp=head[i];
        printf("\n%d) ",i+1);
        while(temp!=NULL)
        {
            printf("<%s,%s> ",temp->name,temp->classType);
            temp=temp->next;
        }
    }
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
        int flag = searchFromTable();
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
    while(option!=5);
}
