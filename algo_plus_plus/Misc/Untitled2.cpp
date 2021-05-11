#include<iostream>
using namespace std;


class node{
public:	
	int pageno;
	node *next, *prev;
};

class queue{
public:
	node *front, *rear;
	int count,noOfFrames;
};

class hashmap{
public:
	int capacity;
	node **arr;	
};

node* createnode(int n){
	
	node *temp = new node();
	temp->pageno = n;
	temp->next =NULL;
	temp->prev = NULL;
	return temp;
}

queue* createqueue(int frames){
	
	queue *q = new queue();
	q->noOfFrames = frames;
	q->front = q->rear = NULL;
	q->count = 0;
	return q;
	
}

hashmap* createmap(int capacity){
	hashmap *h = new hashmap();
	h->capacity = capacity;
	h->arr = new node*[h->capacity];
	for(int i=0;i<h->capacity;i++){
		h->arr[i] = NULL;
	}
	return h;
}

bool isempty(queue *q){
	
	return q->rear == NULL;
}

bool isfull(queue *q){
	return q->count == q->noOfFrames;
}


void dequeue(queue *q){
	
	
	if(isempty(q)){
		return;
	}
	if(q->rear == q->front){
		q->front = NULL;
	}
	
	node *temp = q->rear;
	q->rear = q->rear->prev;
	if(q->rear){
		q->rear->next = NULL;
	}
	free(temp);
	q->count--;
}


void enqueue(queue *q,hashmap *h, int page){
	
	if(isfull(q)){
		h->arr[q->rear->pageno] = NULL;
		dequeue(q);
	}
	
	node *temp = createnode(page);
	temp->next = q->front;
	if(isempty(q)){
		q->rear = q->front = temp;
	}
	else{
		q->front->prev = temp;
		q->front = temp;
	}
	h->arr[page] = temp;
	q->count++;	
}


void reference(queue *q,hashmap *h,int page){
	
	node *find = h->arr[page];
	if(find == NULL){
		enqueue(q,h,page);
	}
	else if(find != q->front){
		
		
		find->prev->next = find->next;
		if(find->next){
			find->next->prev = find->prev;
		}
		if(find == q->rear){
			q->rear = find->prev;
			q->rear->next = NULL;
		}
		
		find->next = q->front;
		find->prev = NULL;
		q->front->prev = find;
		q->front = find;
		
	}
	
}


void print(queue *q){
	node* temp = q->front;
	while(temp!=NULL){
		cout<<temp->pageno<< " ";
		temp = temp->next;
	}
	cout<<endl;
}

int main(){
	
	queue *q = createqueue(4);
	hashmap *h = createmap(10);
	
//	enqueue(q,h,2);
//	dequeue(q);
	reference(q,h,1);
	print(q);
	reference(q,h,2);
	print(q);
	reference(q,h,3);
	print(q);
	reference(q,h,1);
	print(q);
	reference(q,h,4);
	print(q);
	reference(q,h,5);
	
	
	print(q);
	
	return 0;
}
