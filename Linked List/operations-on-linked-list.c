#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

struct Node* createNode(int value)
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

void createList(int n)
{
    int value, i;
    struct Node *newNode, *temp;

    for(i = 1; i <= n; i++)
    {
        printf("Enter element %d: ", i);
        scanf("%d", &value);

        newNode = createNode(value);

        if(head == NULL)
        {
            head = newNode;
        }
        else
        {
            temp = head;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }
}

void traverseList()
{
    struct Node *temp = head;

    if(head == NULL)
    {
        printf("Current List: Empty\n");
        return;
    }

    printf("Current List: ");

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

void insertBeginning(int value)
{
    struct Node *newNode = createNode(value);

    newNode->next = head;
    head = newNode;
}

void insertEnd(int value)
{
    struct Node *newNode = createNode(value);
    struct Node *temp = head;

    if(head == NULL)
    {
        head = newNode;
        return;
    }

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void insertBefore(int element, int value)
{
    struct Node *temp = head;
    struct Node *newNode = createNode(value);

    if(head == NULL)
    {
        return;
    }

    if(head->data == element)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    while(temp->next != NULL && temp->next->data != element)
    {
        temp = temp->next;
    }

    if(temp->next != NULL)
    {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void insertAfter(int element, int value)
{
    struct Node *temp = head;

    while(temp != NULL && temp->data != element)
    {
        temp = temp->next;
    }

    if(temp != NULL)
    {
        struct Node *newNode = createNode(value);

        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteBeginning()
{
    struct Node *temp;

    if(head == NULL)
    {
        return;
    }

    temp = head;
    head = head->next;

    free(temp);
}

void deleteEnd()
{
    struct Node *temp = head;

    if(head == NULL)
    {
        return;
    }

    if(head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

void deleteElement(int value)
{
    struct Node *temp = head;

    if(head == NULL)
    {
        return;
    }

    if(head->data == value)
    {
        head = head->next;
        free(temp);
        return;
    }

    while(temp->next != NULL && temp->next->data != value)
    {
        temp = temp->next;
    }

    if(temp->next != NULL)
    {
        struct Node *del = temp->next;

        temp->next = del->next;
        free(del);
    }
}

int main()
{
    int n, choice, value, element;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    createList(n);

    while(1)
    {
        printf("\n");
        traverseList();

        printf("\n----- LINKED LIST OPERATIONS -----\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert Before an Element\n");
        printf("4. Insert After an Element\n");
        printf("5. Traverse\n");
        printf("6. Delete at Beginning\n");
        printf("7. Delete at End\n");
        printf("8. Delete an Element\n");
        printf("9. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);

                insertBeginning(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);

                insertEnd(value);
                break;

            case 3:
                printf("Enter element before which to insert: ");
                scanf("%d", &element);

                printf("Enter value: ");
                scanf("%d", &value);

                insertBefore(element, value);
                break;

            case 4:
                printf("Enter element after which to insert: ");
                scanf("%d", &element);

                printf("Enter value: ");
                scanf("%d", &value);

                insertAfter(element, value);
                break;

            case 5:
                traverseList();
                break;

            case 6:
                deleteBeginning();
                break;

            case 7:
                deleteEnd();
                break;

            case 8:
                printf("Enter element to delete: ");
                scanf("%d", &value);

                deleteElement(value);
                break;

            case 9:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}