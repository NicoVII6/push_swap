void WrongPush(struct node* head, int data) {
struct node* newNode = malloc(sizeof(struct node));
newNode->data = data;
newNode->next = head;
head = newNode; // NO this line does not work!
}

void WrongPushTest() {
List head = BuildTwoThree();
WrongPush(head, 1); // try to push a 1 on front -- doesn't work
}

/* WrongPush() is very close to being correct. It takes the correct 3-Step Link In and puts it
an almost correct context. The problem is all in the very last line where the 3-Step Link
In dictates that we change the head pointer to refer to the new node. What does the line
head = newNode; do in WrongPush()? It sets a head pointer, but not the right one. It
sets the variable named head local to WrongPush(). It does not in any way change the
variable named head we really cared about which is back in the caller WrontPushTest().*/

/* We need Push() to be able to change some of the caller's memory — namely the head
variable. The traditional method to allow a function to change its caller's memory is to
pass a pointer to the caller's memory instead of a copy. So in C, to change an int in the
caller, pass a int* instead. To change a struct fraction, pass a struct
fraction* intead. To change an X, pass an X*. So in this case, the value we want to
change is struct node*, so we pass a struct node** instead. The two stars
(**) are a little scary, but really it's just a straight application of the rule. It just happens
that the value we want to change already has one star (*), so the parameter to change it
has two (**). Or put another way: the type of the head pointer is "pointer to a struct
node." In order to change that pointer, we need to pass a pointer to it, which will be a
"pointer to a pointer to a struct node".
Instead of defining WrongPush(struct node* head, int data); we define
Push(struct node** headRef, int data);. The first form passes a copy of
the head pointer. The second, correct form passes a pointer to the head pointer. The rule
is: to modify caller memory, pass a pointer to that memory. The parameter has the word
"ref" in it as a reminder that this is a "reference" (struct node**) pointer to the
head pointer instead of an ordinary (struct node*) copy of the head pointer.*/

/*
Takes a list and a data value.
Creates a new link with the given data and pushes
it onto the front of the list.
The list is not passed in by its head pointer.
Instead the list is passed in as a "reference" pointer
to the head pointer -- this allows us
to modify the caller's memory.
*/
void Push(struct node** headRef, int data) {
struct node* newNode = malloc(sizeof(struct node));
newNode->data = data;
newNode->next = *headRef; // The '*' to dereferences back to the real head
*headRef = newNode; // ditto
}
void PushTest() {
struct node* head = BuildTwoThree();// suppose this returns the list {2, 3}
Push(&head, 1); // note the &
Push(&head, 13);
// head is now the list {13, 1, 2, 3}
}

// Return the number of nodes in a list (while-loop version)
int Length(struct node* head) {
int count = 0;
struct node* current = head;
while (current != NULL) {
count++;
current = current->next
}
return(count);
}

/* 2) Changing a Pointer With A Reference Pointer
Many list functions need to change the caller's head pointer. To do this in the C language,
pass a pointer to the head pointer. Such a pointer to a pointer is sometimes called a
"reference pointer". The main steps for this technique are...
• Design the function to take a pointer to the head pointer. This is the
standard technique in C — pass a pointer to the "value of interest" that
needs to be changed. To change a struct node*, pass a struct
node**.
• Use '&' in the caller to compute and pass a pointer to the value of interest.
• Use '*' on the parameter in the callee function to access and change the
value of interest. */

void ChangeToNull(struct node** headRef) { // Takes a pointer tothe value of interest
*headRef = NULL; // use '*' to access the value of interest
}

void ChangeCaller() {
struct node* head1;
struct node* head2;
ChangeToNull(&head1); // use '&' to compute and pass a pointer to
ChangeToNull(&head2); // the value of interest
// head1 and head2 are NULL at this point
}

// ajouter au debut de la liste chainée

struct node* AddAtHead() {
struct node* head = NULL;
int i;
for (i=1; i<6; i++) {
Push(&head, i);
}
// head == {5, 4, 3, 2, 1};
return(head);
}

/* Build — Special Case + Tail Pointer
Consider the problem of building up the list {1, 2, 3, 4, 5} by appending the nodes to the
tail end. The difficulty is that the very first node must be added at the head pointer, but all
the other nodes are inserted after the last node using a tail pointer. The simplest way to
deal with both cases is to just have two separate cases in the code. Special case code first
adds the head node {1}. Then there is a separate loop that uses a tail pointer to add all the
other nodes. The tail pointer is kept pointing at the last node, and each new node is added
at tail->next. The only "problem" with this solution is that writing separate special
case code for the first node is a little unsatisfying. Nonetheless, this approach is a solid
one for production code — it is simple and runs fast. */
struct node* BuildWithSpecialCase() {
struct node* head = NULL;
struct node* tail;
int i;
// Deal with the head node here, and set the tail pointer
Push(&head, 1);
tail = head;
// Do all the other nodes using 'tail'
for (i=2; i<6; i++) {
Push(&(tail->next), i); // add node at tail->next
tail = tail->next; // advance tail to point to last node
}
return(head); // head == {1, 2, 3, 4, 5};
}