#include<stdio.h>
#include <stdlib.h>
#include <limits.h>

int stack[100],choice,n,top,x,i;



void push(void);
void pop(void);
void display(int n);

unsigned int size  = 0;
  // Initally assumed that rear is at end
unsigned int front = 0;
int enqueue(int data,int n);
int dequeue();
int isFull();
int isEmpty();

int main()
{
    //clrscr();
    top=-1;
    int data;
    printf("\n Enter the size of stack or queue:");
    scanf("%d",&n);
    int queue[n];


    printf("\n\t STACK and queue OPERATIONS USING ARRAY");
    printf("\n\t--------------------------------");
    printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.Enqueue 4.dequeue\n\t 5.EXIT");
    do
    {
        printf("\n Enter the Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }


            case 3:

                printf("\nEnter data to enqueue: ");
                scanf("%d", &data);

                // Enqueue function returns 1 on success
                // otherwise 0
                if (enqueue(data,n))
                    printf("Element added to queue.");

                else
                    printf("Queue is full.");
                break;
                case 4:
                data = dequeue(n,queue);

                // on success dequeue returns element removed
                // otherwise returns INT_MIN
                if (data == INT_MIN)
                    printf("Queue is empty.");
                else
                    printf("Data => %d", data);

                break;
                case 5:
            {
                printf("\n\t EXIT POINT ");
                break;
            }
            default:
            {
                printf ("\n\t Please Enter a Valid Choice(1/2/3/4)");
            }

        }
    }
    while(choice!=4);
    return 0;
}
int enqueue(int data,int n)
{int queue[n];
    unsigned int rear  = n - 1;
    // Queue is full throw Queue out of capacity error.
    if (isFull())
    {
        return 0;
    }

    // Ensure rear never crosses array bounds
    rear = (rear + 1) % n;

    // Increment queue size
    size++;

    // Enqueue new element to queue
    queue[rear] = data;


    // Successfully enqueued element to queue
    return 1;
}


void push()
{
    if(top>=n-1)
    {
        printf("\n\tSTACK is over flow");

    }
    else
    {
        printf(" Enter a value to be pushed:");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
}
void pop()
{
    if(top<=-1)
    {
        printf("\n\t Stack is under flow");
    }
    else
    {
        printf("\n\t The popped elements is %d",stack[top]);
        top--;
    }
}


int isFull()
{
    return (size == n);
}
int dequeue(int n,int queue[])
{
    int data = INT_MIN;

    // Queue is empty, throw Queue underflow error
    if (isEmpty())
    {
        return INT_MIN;
    }

    // Dequeue element from queue
    data = queue[front];

    // Ensure front never crosses array bounds
    front = (front + 1) % n;

    // Decrease queue size
    size--;

    return data;
}
int isEmpty()
{
    return (size == 0);
}
