#include<iostream>
using namespace std;

// A Queue Node (Queue is implemented using Doubly Linked List)
class node{
public:
	int pageno;
	node *next,*prev;	
};

// A Queue (A FIFO collection of Queue Nodes)
class queue{
public:
	node *front,*rear;
	int count,no_frames;
};

// A hash (Collection of pointers to Queue Nodes)
class hashmap{
public:	
	int capacity;
	node **arr;
};

// A utility function to create a new Queue Node.
node* newnode(int data){
	node *temp = new node();
	temp->pageno = data;
	temp->next = temp->prev = NULL;
	return temp;
}

// A utility function to create an empty Queue.
queue* newqueue(int n){
	
	queue *q = new queue();
	q->count = 0;
	q->front = q->rear = NULL;
	q->no_frames = n;
	return q;
	
}
// A utility function to create an empty Hash of given capacity
hashmap* newhashmap(int cap){
	
	hashmap *h = new hashmap();
	h->capacity = cap;
	h->arr = new node*[h->capacity];
	for(int i=0;i<h->capacity;i++){
		h->arr[i] = NULL;
	}
	return h;
}

bool isempty(queue *q){
	return q->rear == NULL;
	
}

void dequeue(queue *q){
	
	if(isempty(q)){
		return;
	}
	
	if(q->rear == q->front){
		q->front = NULL;
	}
	node *t = q->rear;
	q->rear = q->rear->prev;
	if(q->rear){
		q->rear->next = NULL;
	}
	free(t);
	q->count--;
}

bool isfull(queue *q){
	return q->count == q->no_frames;
}

void enqueue(queue *q, hashmap  *h, int pageNo){
	
	if(isfull(q)){
		h->arr[q->rear->pageno] = NULL;
		dequeue(q);
	}
	
	node *t = newnode(pageNo);
	t->next = q->front;
	if(isempty(q)){
		q->front = q->rear = t;
	}
	else{
		q->front->prev = t;
		q->front = t;	
	}
	h->arr[pageNo] = t;
	q->count++;
	
}

 
// This function is called when a page with given 'pageNumber' is referenced
// from cache (or memory).
void referencePage(queue *q, hashmap  *h, int pageNo){
	
	node *t = h->arr[pageNo];
	if(t == NULL){
		enqueue(q,h,pageNo);
	}
	else if(t != q->front){
		
		t->prev->next = t->next;
		if(t->next){
			t->next->prev = t->prev;	
		}
		if(t== q->rear){
			q->rear = t->prev;
			q->rear->next = NULL;
		}
		
		//move to front;
		t->next = q->front;
		t->prev = NULL;
		t->next->prev = t;
		q->front = t;
		
	}
	
	
}

int main(){
	
	queue *q = newqueue(4);
	hashmap *h = newhashmap(10);
//	enqueue(q,h,2);
	dequeue(q);
//	referencePage(q,h,1);
//	referencePage(q,h,2);
//	referencePage(q,h,3);
//	referencePage(q,h,1);
//	referencePage(q,h,4);
//	referencePage(q,h,5);
//	
//	cout<<q->front->pageno;
//	cout<<q->front->next->pageno;
//	cout<<q->front->next->next->pageno;
//	cout<<q->front->next->next->next->pageno;
	
	
	return 0;
}
