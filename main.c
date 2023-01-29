#include <stdio.h>
#include <stdlib.h>

#undef LINKED_LIST
#define STACKS0
#define QUEUE

#ifdef LINKED_LIST

/* INSERT, DELETE, SEARCH*/

struct Node{
    char val;
    struct Node *nxNodePtr;
};

typedef struct Node head;

void insertBegin(head **ptr, char val)
{
    if(*ptr == NULL)
    {
        head *p = (head *)malloc(sizeof(head));

        p->val = val;
        p->nxNodePtr = NULL;
        *ptr = p;
    }
    else
    {
        head *p = (head *)malloc(sizeof(head));
        p->val = val;
        p->nxNodePtr = *ptr;
        *ptr = p;
    }
}

void insertEnd(head **head_, char val)
{
    head **curr = NULL;
    head **tmp = NULL;

    tmp = *head_;
    curr = head_;

    if(*head_ == NULL)
    {
        head *p = (head *)malloc(sizeof(head));

        p->val = val;
        p->nxNodePtr = NULL;
        *head_ = p; 
    }
    else
    {
        /* önden bakıyoruz */
        while ((*curr)->nxNodePtr != NULL)
        {
            *curr = (*curr)->nxNodePtr; 
        }
        
        head *p = (head *)malloc(sizeof(head));
        p->val = val;
        p->nxNodePtr = NULL;

        (*curr)->nxNodePtr = p;
        *head_ = tmp;
    }
}

void display(head *ptr)
{
    while (ptr != NULL)
    {
        printf("%c --> ",ptr->val);
        ptr = ptr->nxNodePtr;
    }
}

void deleteNo(head **ptr, int number)
{
    head *tmp  = NULL;
    head *pre = NULL;
    tmp = *ptr;
    int cnt = 0;
    while (*ptr != NULL)
    {
        *ptr = (*ptr)->nxNodePtr;
        cnt++;
    }

    *ptr = tmp;
    
    for(int i = 1 ; i < number ; ++i)
    {
        pre = *ptr;
        *ptr = (*ptr)->nxNodePtr;
    }

    pre->nxNodePtr = (*ptr)->nxNodePtr;
    free(*ptr);
    *ptr = tmp;
}

void deleteBegin(head **ptr)
{
    head *tmp;
    if(*ptr != NULL)
    {
        tmp = *ptr;
        *ptr = (*ptr)->nxNodePtr;
        free(tmp);
    }
}

void deleteEnd(head **ptr)
{
    head *tmp = NULL;
    head *pre = NULL;
    tmp = *ptr;

    while ((*ptr)->nxNodePtr != NULL)
    {
        pre = *ptr;
        *ptr = (*ptr)->nxNodePtr;
    }

    free((*ptr)->nxNodePtr);
    
    pre->nxNodePtr = NULL;
    *ptr = tmp;
}

void insertNo(head **ptr, char val, int number)
{
    head *tmp = NULL;
    head *pre = NULL;
    tmp = *ptr;

    int cnt = 0;
    while (*ptr != NULL)
    {
        *ptr = (*ptr)->nxNodePtr;
        cnt++;
    }

    *ptr = tmp;
    
    if(0 < number && number < cnt)
    {   
        for(int i = 1 ; i < number ; ++i)
        {
            pre = *ptr;
            *ptr = (*ptr)->nxNodePtr;
        }
    }
    head *nwNode = (head*)malloc(sizeof(head));
    nwNode->val = val;
    nwNode->nxNodePtr = *ptr;

    pre->nxNodePtr = nwNode;

    *ptr = tmp;
}

void searchVal(head **ptr, char val)
{
    head *tmp = NULL;
    tmp = *ptr;
    int cnt = 1;

    while ((*ptr)->val != val && *ptr != NULL)
    {
        cnt++;
        (*ptr) = (*ptr)->nxNodePtr;
    }

    *ptr = tmp;
    printf("%c degeri %d numarali degerdir\n", val, cnt);

}
#endif //LINKED_LIST

#ifdef STACKS

struct Stacks_Node
{
    int val;
    struct Stacks_Node *stckNextNodePtr;
};

typedef struct Stacks_Node sTop;

void push(sTop **ptr,int val)
{
    /* create node*/
    struct Stacks_Node *nwNodeptr = (struct Stacks_Node*)malloc(sizeof(struct Stacks_Node));
    nwNodeptr->val = val;
    if(*ptr == NULL)
    {
        nwNodeptr->stckNextNodePtr = NULL;
    }
    else
    {
        nwNodeptr->stckNextNodePtr = *ptr;
    }

    *ptr = nwNodeptr;
}

void pop(sTop **ptr)
{
    sTop *p = NULL;
    p = *ptr;

    *ptr = (*ptr)->stckNextNodePtr;
    free(p);
}

int isEmpty(sTop *ptr)
{
    return ptr == NULL;
}

void displayStack(sTop *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n",ptr->val);
        ptr = ptr->stckNextNodePtr;
    }
}

#endif //STACKS

#ifdef QUEUE

struct QueueNode
{
    int val;
    struct QueueNode *nxtQueueNodePtr;
};

struct Queue
{
    struct QueueNode *front;
    struct QueueNode *rear;
};

typedef struct QueueNode queuenode_t;
typedef struct Queue queue_t;

queuenode_t* createNode(int val)
{
    queuenode_t *nwNodePtr = (queuenode_t*)malloc(sizeof(queuenode_t));
    nwNodePtr->val = val;
    nwNodePtr->nxtQueueNodePtr = NULL;
    return nwNodePtr;
}

queue_t* createQueue()
{
    queue_t *ptr = (queue_t*)malloc(sizeof(queue_t));
    ptr->front = ptr->rear = NULL;
    return ptr;
}

/* sonuna ekler */
void enqueue(queue_t *ptr, int value)
{
    queue_t *qNode = createNode(value);
    if(ptr->rear == NULL)
    {
        ptr->front = ptr->rear = qNode;
        return;
    }

    ptr->rear->nxtQueueNodePtr = qNode;
    ptr->rear = qNode;
}

/* sondan çıkarır */
void dequeue(queue_t *ptr)
{
    if(ptr->front == NULL) return NULL;

    queuenode_t *tmp = ptr->front;
    ptr->front = ptr->front->nxtQueueNodePtr;

    if(ptr->front == NULL)
    {
        ptr->rear = NULL;
    }
    free(tmp);
}

void display(queue_t *q)
{
    while (q->front != NULL)
    {
        printf("%d --> ", q->front->val);
        q->front = q->front->nxtQueueNodePtr;
    }
}

#endif /* QUEUE */

int main()
{
    #ifdef LINKED_LIST
    head *headPtr = NULL;

    int userInput = 0;
    char val = '\0';
    int number = 0;

    printf("1 - insert begin\n");
    printf("2 - insert end\n");
    printf("3 - delete begin\n");
    printf("4 - delete no\n");
    printf("5 - delete end\n");
    printf("6 - insert no\n");
    printf("7 - search val\n");
    printf("8 - exit\n");

    while (1)
    {
        scanf("%d",&userInput);
        switch (userInput)
        {
        case 1:
            printf("Input Val\n");
            scanf("%s", &val);
            insertBegin(&headPtr, val);
            display(headPtr);
            printf("\n");            
        break;

        case 2:
            printf("Input Val\n");
            scanf("%s",&val);
            insertEnd(&headPtr, val);
            display(headPtr);
            printf("\n");            
        break;

        case 3:
            printf("Input Val\n");
            deleteBegin(&headPtr);
            display(headPtr);
            printf("\n");            
        break;

        case 4:
            printf("Input num\n");
            scanf("%d",&number);
            deleteNo(&headPtr, number);
            display(headPtr);
            printf("\n");            
        break;

        case 5:
            deleteEnd(&headPtr);
            display(headPtr);
            printf("\n"); 
        break;

        case 6:
            printf("Input insert Val\n");
            scanf("%s",&val);
            printf("Input num\n");
            scanf("%d",&number);            
            insertNo(&headPtr, val, number);
            display(headPtr);
            printf("\n");
        break;

        case 7:
            printf("Input Search val\n");
            scanf("%s",&val);
            searchVal(&headPtr, val);

        break;

        default:
            exit(1);
        break;
        }
    }
    #endif //LINKED LIST    
    
    #ifdef STACKS
    sTop *sTopPtr = NULL;
    printf("%d 1- bos 0- dolu\n", isEmpty(sTopPtr));
    push(&sTopPtr, 1);
    push(&sTopPtr, 5);
    push(&sTopPtr, 3);
    push(&sTopPtr, 7);
    pop(&sTopPtr);
    printf("%d 1- bos 0- dolu\n", isEmpty(sTopPtr));
    displayStack(sTopPtr);
    #endif //STACKS 

    #ifdef QUEUE
    queue_t *queue = createQueue();
    enqueue(queue, 1);
    enqueue(queue, 5);
    dequeue(queue);
    display(queue);
    #endif /* QUEUE */
    return 0;
}