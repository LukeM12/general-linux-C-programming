#include<stdio.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<string.h>
struct Node *make_El(char *, int , char *, char *);
struct Node {
    char *title;
    int port;
    //IP 
    char *sender;
    char *recvr;
    struct Node *next;
    struct Node *prev;
};
struct QueueList {
    struct Node *start;
    struct Node *end;
    int length;
};
/*
 * This function creates an empty queue
 **/
int create_queue(struct QueueList *Queue, char *title, int port, char *sender, char *recvr) {
		if (!Queue->start){
			struct Node *temp; 
			temp = make_El(title,port, sender, recvr);
			if (!temp){
				printf("New Node not created");
				return 1;
			}
			Queue->start = temp;
			return 1;
		}
	
		struct Node *temp; 
		temp= make_El(title,port, sender, recvr);
		if (!temp){
				printf("New Queue Not Added");
				return 1;
		}
		struct Node *end = Queue->end;
		
		end->next = temp;
        temp->prev = end;
        end = temp;
        return 1;
}

int EnQueue(struct QueueList *Queue) {
		if (!Queue->start){
			printf("Queue is empty");
			return 1;
		}
		struct Node *start = Queue->start;
		struct Node *temp = start;
		start = start->next;
		free(temp);
		if (temp){
				printf("EnQueue failed");
				return 0;
		}
        return 1;
}

struct Node *make_El(char *title, int port, char *sender, char *recvr ){
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    if ( ! (temp) ){
        printf("ERROR : Element Memory Leak");
    }
    //Now copy the information into the newly made node
    if (title){
        //temp->title = 
    }
    if (port){
        temp->port = port;
    }
    if (sender){
        //temp->sender = strdup(input.sender);
    }
    if (recvr){
        //temp->recvr = strdup(input.recvr);
    }
    return temp;
}
/*
* This program makes both a server and a client at the same time
* (Over TCP/IP) It holds 2 queues that takes information about the
* networking transactions and processes them as necessary
*/

void main(){

    struct QueueList client;

    //Some test data
    char temp[5] = "192";
    int port = 150;
    struct Node inputNode;
    inputNode.sender = strdup(temp);
    int valid = create_queue(&client, NULL, port, temp, NULL);
    //Able to get a valid point for start Node, but not display the port number
    //Possibly, it is just a matter of fixing referencing modes
    //But this is how the Queue should be called for this project
    struct Node *this = client.start;
    printf("Memory address of the client %p\n", this);
    printf("Debug me with GDB\n");
}

    //Note for testing, the point is to make a structure and add it to the 
    //Queue, which paramters are filled out
    //Then
    //1)Pass the data flawlessly to the queue
    //2)Add more queue-like operatings, enqueue, deletequeue
    //3)Test Queueue operations
    //4)Set up sockets for data transfer
    //5)Start trading information test cases
    //6)Migrate that to python binding the C and python libraries 
    //7)Make GUI in python 
    //Starting with 2 queues, one for client and one for server
/*
* This function makes a new element to be added to the queue
*/
/*
int add_queue(struct Node **head, struct Node input){
    if (!(*head)) {
        int temp = create_queue(head, input);
            return 1;
        }
    }
    struct Node *curr;
    curr = head);

    int temp = create_queue(&curr, input);


    if (input.title) {
        curr->title = input.title;
    }
    if (input.port) {
        curr->port = input.port;
    }
    if (input.sender) {
        curr->sender = input.sender;
    }
    if (input.recvr) {
        curr->recvr = input.recvr;
    }

    curr->next = 
    curr->prex = 
    return 1;
}
*/

