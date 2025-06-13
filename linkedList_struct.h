#define SIZE 50

typedef struct {
	int x,y;
	 
}segment_t;

typedef segment_t LType;

typedef struct node_s
{
	LType data;
	struct node_s *next;
} node_t;

node_t *getnode(void)
{
	node_t *node;
	node = (node_t *)malloc(sizeof(node_t));
	node->next = NULL;
	return (node);
}
void addAfter(node_t *p, LType item)
{
	node_t *newp;
	newp = getnode();
	newp->data = item;
	newp->next = p->next;
	p->next = newp;
}
node_t *addBeginning(node_t *headp, LType item)
{
	node_t *newp;
	newp = getnode();
	newp->data = item;
	newp->next = headp;
	return (newp);
}

node_t *deleteFirst(node_t *headp, LType *item) 
{
	node_t *del;
	del = headp;
	*item = del->data;
	headp = del->next;
	free(del);
	return (headp);
}

void deleteAfter(node_t *p, LType *item)
{
	node_t *del;
	del = p->next;

	*item = del->data;
	p->next = del->next;
	
	free(del);
}
void deleteLast(node_t* head) {
	if (head == NULL) return;

	if (head->next == NULL) {
		// Kuyruðun tek segmenti varsa, silme!
		return;
	}

	node_t* prev = NULL;
	node_t* curr = head;

	while (curr->next != NULL) {
		prev = curr;
		curr = curr->next;
	}

	prev->next = NULL;
	free(curr);
}
