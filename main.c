#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct node
{
    int data;
    struct node *lptr,*rptr;
};
struct node *first=NULL;

void main_menu();
void cases(int);
void create();
void insertbeg();
void insertmid();
void insertend();
void deletebeg();
void deletemid();
void deleteend();
void Sorting();
void print();
int main()
{
    while(1)
    {
        main_menu();
    }

    return 0;
}

void main_menu()
{
    int choice;
    system("cls");
    printf("\n\t  OPERATIONS IN CIRCULAR DOUBLE LINKED LIST");
    printf("\n\t*********************************************");
    printf("\n1.Create\n2.Insert\n3.Delete\n4.Sort\n5.Print\n\n");
    printf("Enter Your Choice : ");
    scanf("%d",&choice);
    system("cls");
    cases(choice);
}
void cases(int choice)
{
    int ch;
    switch(choice)
                {
                    case 1: create();
                            break;
                    case 2: printf("\n1.Insert at Begining\n2.Insert at Middle\n3.Insert at End\n");
                            do
                            {
                                printf("\nEnter Your Choice : ");
                                scanf("%d",&ch);
                                switch(ch)
                                {
                                    case 1: insertbeg();
                                            break;
                                    case 2: insertmid();
                                            break;
                                    case 3: insertend();
                                            break;
                                    default :printf("Wrong Choice!!!");
                                }
                            }while(ch!=1&&ch!=2&&ch!=3);
                            break;
                    case 3:
                            printf("\n1.Delete at Begining\n2.Delete at Middle\n3.Delete at End\n");
                            do
                            {
                                printf("\nEnter Your Choice : ");
                                scanf("%d",&ch);
                                switch(ch)
                                {
                                    case 1: deletebeg();
                                            break;
                                    case 2: deletemid();
                                            break;
                                    case 3: deleteend();
                                            break;
                                    default : printf("Wrong Choice!!!");
                                }
                            }while(ch!=1&&ch!=2&&ch!=3);
                            break;
                    case 4: Sorting();
                            break;
                    case 5: print();
                            break;
                    default : printf("Wrong Choice!!!");
                              getch();
                }
    getch();
}
void create()
{
    char ch;
    struct node *ptr,*cpt;
    ptr=(struct node *)malloc(sizeof(struct node));
    printf("Enter Data : ");
    scanf("%d",&ptr->data);
    ptr->lptr=ptr->rptr=NULL;
    first=ptr;
    do
    {
        cpt=(struct node *)malloc(sizeof(struct node));
        printf("Enter Data : ");
        scanf("%d",&cpt->data);
        ptr->rptr=cpt;
        cpt->lptr=ptr;
        ptr=cpt;
        printf("\nPress 'C' to Enter More & 'E' to Exit : ");
        scanf(" %c",&ch);

    }while(ch=='C'||ch=='c');
    cpt->rptr=first;
    first->lptr=cpt;
}

void insertbeg()
{
    struct node *ptr,*cpt;
    ptr=first;
    if(first==NULL)
    {
        printf("\nData List is Empty\nFirst Create Data List\n");
    }
    else
    {
        cpt=(struct node *)malloc(sizeof(struct node));
        printf("Enter Data : ");
        scanf("%d",&cpt->data);
        cpt->rptr=first;
        cpt->lptr=first->lptr;
        ptr=first->lptr;
        ptr->rptr=cpt;
        first=cpt;
        printf("Data %d is Inserted",cpt->data);
    }
}

void insertmid()
{
    int data;
    struct node *ptr,*cpt;
    ptr=first;
    if(ptr==NULL)
    {
        printf("\nData List is Empty\nFirst Create Data List\n");
    }
    else
    {
        printf("Enter Data After Which You Want to Insert : ");
        scanf("%d",&data);
        do
        {
            if(ptr->data==data)
                break;
            ptr=ptr->rptr;
        }while(ptr!=first);
        if(ptr==first)
        {
            printf("Data %d is Not Found",data);
        }
        else
        {
            cpt=(struct node *)malloc(sizeof(struct node));
            printf("Enter Data : ");
            scanf("%d",&cpt->data);
            cpt->lptr=ptr;
            cpt->rptr=ptr->rptr;
            ptr->rptr=cpt;
            ptr=ptr->rptr;
            ptr->lptr=cpt;
            printf("Data %d is Inserted",cpt->data);
            getch();
        }
    }
}

void insertend()
{
    struct node *ptr,*cpt;
    ptr=first;
    if(ptr==NULL)
    {
        printf("\nData List is Empty\nFirst Create Data List\n");
    }
    else
    {
        while(ptr->rptr!=first)
        {
            ptr=ptr->rptr;
        }
        cpt=(struct node *)malloc(sizeof(struct node));
        printf("Enter Data : ");
        scanf("%d",&cpt->data);
        cpt->lptr=ptr;
        ptr->rptr=cpt;
        cpt->rptr=first;
        first->lptr=cpt;
        printf("Data %d is Inserted",cpt->data);
    }
}

void deletebeg()
{
    struct node *ptr,*cpt;
    ptr=first;
    if(ptr==NULL)
    {
        printf("\nData List is Empty\n");
    }
    else
    {
        cpt=ptr->lptr;
        cpt->rptr=ptr->rptr;
        ptr->lptr=cpt;
        cpt=ptr->rptr;
        cpt->lptr=ptr->lptr;
        ptr->lptr=ptr->rptr=NULL;
        first=cpt;
        printf("\nData Deleted : %d",ptr->data);
        free(ptr);
    }
}

void deletemid()
{
    int data;
    struct node *ptr,*cpt;
    ptr=first;
    if(ptr==NULL)
    {
        printf("\nData List is Empty\n");
    }
    else
    {
        printf("Enter Data Which You Want To Delete : ");
        scanf("%d",&data);
        do
        {
            if(ptr->data==data)
                break;
            cpt=ptr;
            ptr=ptr->rptr;
        }while(ptr!=first);
        if(ptr==first)
        {
            printf("Data %d is Not Found",data);
        }
        else
        {
            cpt->rptr=ptr->rptr;
            ptr->lptr=cpt;
            cpt=ptr->rptr;
            cpt->lptr=ptr->lptr;
            ptr->lptr=ptr->rptr=NULL;
            printf("\nData Deleted : %d\n",ptr->data);
            free(ptr);
        }
    }
}

void deleteend()
{
    struct node *ptr,*cpt;
    ptr=first;
    if(ptr==NULL)
    {
        printf("\nData List is Empty\n");
    }
    else
    {
        while(ptr->rptr!=first)
        {
            cpt=ptr;
            ptr=ptr->rptr;
        }
        cpt->rptr=first;
        first->lptr=cpt;
        ptr->lptr=ptr->rptr=NULL;
        printf("\nData Deleted : %d",ptr->data);
        free(ptr);
    }
}

void Sorting()
{
    int temp;
    struct node *ptr,*cpt;
    ptr=first;
    if(first==NULL)
    {
        printf("\nData List is Empty\n");
    }
    else
    {
            while(ptr->rptr!=first)
            {
                cpt=ptr->rptr;
                while(cpt!=first)
                {
                    if(ptr->data>cpt->data)
                    {
                        temp=ptr->data;
                        ptr->data=cpt->data;
                        cpt->data=temp;
                    }
                    cpt=cpt->rptr;
                }
                ptr=ptr->rptr;
            }
        printf("\nData List is Sorted\n");
    }
}
void print()
{
    struct node *ptr;
    ptr=first;
    int i=1;
    if(ptr==NULL)
    {
        printf("\nData List is Empty\n");
    }
    else
    {
        printf("\nData List :\n*******************\n");
        while(ptr->rptr!=first)
         {
            printf("DATA %d : %d\n",i,ptr->data);
            ptr=ptr->rptr;
            i++;
         }
        printf("DATA %d : %d\n",i,ptr->data);
        printf("*******************");
    }
}
