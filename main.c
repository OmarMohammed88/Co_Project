#include <stdio.h>
#include <stdlib.h>

//defining the maximum number of elements in the queue
#define MAX 5

//definition of the 5 queues as global variables as all functions change them
int queue1[MAX], queue2[MAX], queue3[MAX], queue4[MAX], queue5[MAX];

//defining a size variable for each queue
int size1 = 0, size2 = 0, size3 = 0, size4 = 0, size5 = 0;

//defining a rear and a front to each queue with rear initialized to the MAX - 1 and the front to ZERO
int rear1 = MAX - 1, front1 = 0, rear2 = MAX - 1, front2 = 0, rear3 = MAX - 1, front3 = 0, rear4 = MAX - 1, front4 = 0, rear5 = MAX - 1, front5 = 0;

//functions prototypes
void insert(int, int);
void deeleetee(int);
void update(int, int, int);
int search(int, int);


int main()
{
    while (1)
    {
        //variable declaration
        int queueNumber, opCode, data, newData;
        //scanning the qnumber and the opcode
        scanf("%d %d", &queueNumber, &opCode);
        //if the op is delete no need to scan data otherwise scan it
        if(opCode != 2)
        {
            scanf(" %d", &data);
        }
        //input validation
        if (queueNumber < 1 || queueNumber > 5)
        {
            puts("wrong input");
            return 0;
        }
        //input validation
        else if(opCode < 1 || opCode > 5)
        {
            puts("wrong input");
            return 0;
        }
        else
        {
            //checking what the op code is to perform the operation
            switch(opCode)
            {
            //case 1 is for insertion
            case 1:
                insert(queueNumber, data);
                break;
            //case 2 is for deletion
            case 2:
                deeleetee(queueNumber);
                break;
            //case 3 is for searching
            case 3:
                printf("%d\n", search(queueNumber, data));
                break;
            //case 4 is for updating
            case 4:
                //is case of update the data scanned at the beginning of the execution will be considered the data we want it to be replaced
                printf("enter new data you wish to insert\n");
                //the new data we want it to replace the old data is scanned here
                scanf("%d", &newData);
                update(queueNumber, data, newData);
                break;
            }
        }
    }
    return 0;
}

void insert(int queueNumber, int data)
{
    //performing the insertion depending on the queue number in the signal
    switch(queueNumber)
    {
    case 1:
        //if the size of the current queue is equal to the max value then the queue is full
        if(size1 == MAX)
        {
            printf("queue is full");
            return;
        }
        //incrementing the rear in a circular queue
        rear1 = (rear1 + 1) % MAX;
        //inserting the data in the new rear and incrementing the size of the queue
        queue1[rear1] = data;
        size1++;
        break;
        //the same is applied to the other cases
    case 2:
        if(size2 == MAX)
        {
            printf("queue is full\n");
            return;
        }
        rear2 = (rear2 + 1) % MAX;
        queue2[rear2] = data;
        size2++;
        break;
    case 3:
        if(size3 == MAX)
        {
            printf("queue is full\n");
            return;
        }
        rear3 = (rear3 + 1) % MAX;
        queue3[rear3] = data;
        size3++;
        break;
    case 4:
        if(size4 == MAX)
        {
            printf("queue is full\n");
            return;
        }
        rear4 = (rear4 + 1) % MAX;
        queue4[rear4] = data;
        size4++;
        break;
    case 5:
        if(size5 == MAX)
        {
            printf("queue is full\n");
            return;
        }
        rear5 = (rear5 + 1) % MAX;
        queue5[rear5] = data;
        size5++;
        break;
    //if none of the cases above
    default:
        printf("wrong input\n");
    }
}

void deeleetee(int queueNumber)
{
    //depending on the qnumber we will delete the last first value entered from it
    switch(queueNumber)
    {
    case 1:
        //if the size of the current queue is equal to 1 then it's empty
        if(size1 == 0)
            {
                printf("Queue empty\n");
                return;
            }
        //incrementing the front in a circular queue manner -deleting the first element-
        front1 = (front1 + 1) % MAX;
        //decrementing the size of the current queue
        size1--;
        break;
        //the same is applied to the rest of the cases
    case 2:
        if(front2 == rear2)
            {
                printf("Queue empty\n");
                return;
            }
        front2 = (front2 + 1) % MAX;
        break;
    case 3:
        if(front3 == rear3)
            {
                printf("Queue empty\n");
                return;
            }
        front3 = (front3 + 1) % MAX;
        break;
    case 4:
        if(front4 == rear4)
            {
                printf("Queue empty\n");
                return;
            }
        front4 = (front4 + 1) % MAX;
        break;
    case 5:
        if(front5 == rear5)
            {
                printf("Queue empty\n");
                return;
            }
        front5 = (front5 + 1) % MAX;
        break;
    //if none of the cases above were true
    default:
        printf("wrong input\n");
    }
}

int search(int queueNumber, int data)
{
    int i, siz;
    //deciding which queue we will search in
    switch(queueNumber)
    {
    case 1:
        //traversing the queue to search for the value
        for(i=front1, siz=0; siz<size1; siz++)
        {
            //if the value is equal to the data we're searching in
			if(queue1[i] == data)
            {
                //return the index of the value
                return i;
            }
                //incrementing the i in a circular queue manner
			i=(i+1)%MAX;
		}
		//if not found during the loop return -1
        return -1;
        //the same applies for the rest cases
    case 2:
        for(i = front2; i != rear2; ++i)
            {
                if(queue2[i] == data)
                    return i;
                if(i == (MAX - 1))
                    i = 0;
            }
        return -1;
    case 3:
        for(i = front3; i != rear3; ++i)
            {
                if(queue3[i] == data)
                    return i;
                if(i == (MAX - 1))
                    i = 0;
            }
        return -1;
    case 4:
        for(i = front4; i != rear4; ++i)
            {
                if(queue1[i] == data)
                    return i;
                if(i == (MAX - 1))
                    i = 0;
            }
        return -1;
    case 5:
        for(i = front5; i != rear5; ++i)
            {
                if(queue1[i] == data)
                    return i;
                if(i == (MAX - 1))
                    i = 0;
            }
        return -1;
    default:
        //if none of the cases above applies
        return -1;
    }

}

void update(int queueNumber, int oldData, int newData)
{
    //first searching for the index with the search function above
    int index = search(queueNumber, oldData);
    //if the item is not found print wrong output and exit function
    if(index == -1)
    {
        printf("wrong input\n");
        return;
    }
    //choosing the appropriate queue to search in
    switch(queueNumber)
    {
    case 1:
        //change the value of the found index from function search and replace it with the new data that was scanned from the user previously
        queue1[index] = newData;
        break;
        //same applies for the rest of the cases
    case 2:
        queue2[index] = newData;
        break;
    case 3:
        queue3[index] = newData;
        break;
    case 4:
        queue4[index] = newData;
        break;
    case 5:
        queue5[index] = newData;
        break;
    default:
        //if none of the cases above applies
        printf("wrong input\n");
    }
}
