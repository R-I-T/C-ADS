#include<stdio.h>
#include<malloc.h>

struct node {
    int n;
    int degree;
    struct node* parent;
    struct node* child;
    struct node* sibling;
};

struct node* MAKE_BIN_HEAP();
int BIN_LINK(struct node*, struct node*);
struct node* create_node(int);
struct node* BIN_HEAP_UNION(struct node*, struct node*);
struct node* BIN_HEAP_INSERT(struct node*, struct node*);
struct node* BIN_HEAP_MERGE(struct node*, struct node*);
struct node* BIN_HEAP_EXTRACT_MIN(struct node*);
int REVERT_LIST(struct node*);
int display(struct node*);
struct node* FIND_NODE(struct node*, int);
int BIN_HEAP_DECREASE_KEY(struct node*, int, int);
int BIN_HEAP_DELETE(struct node*, int);

int count = 1;
struct node * H = NULL;
struct node *Hr = NULL;

struct node* MAKE_BIN_HEAP() {
    struct node* np;
    np = NULL;
    return np;
}



int BIN_LINK(struct node* y, struct node* z) {
    y->parent = z;
    y->sibling = z->child;
    z->child = y;
    z->degree = z->degree + 1;
}

struct node* create_node(int k) {
    struct node* p;
    p = (struct node*) malloc(sizeof(struct node));
    p->n = k;
    return p;
}

struct node* BIN_HEAP_UNION(struct node* H1, struct node* H2) {
    struct node* prev_x;
    struct node* next_x;
    struct node* x;
    struct node* H = MAKE_BIN_HEAP();
    H = BIN_HEAP_MERGE(H1, H2);
    if (H == NULL)
        return H;
    prev_x = NULL;
    x = H;
    next_x = x->sibling;
    while (next_x != NULL) {
        if ((x->degree != next_x->degree) || ((next_x->sibling != NULL)
                && (next_x->sibling)->degree == x->degree)) {
            prev_x = x;
            x = next_x;
        } else {
            if (x->n <= next_x->n) {
                x->sibling = next_x->sibling;
                BIN_LINK(next_x, x);
            } else {
                if (prev_x == NULL)
                    H = next_x;
                else
                    prev_x->sibling = next_x;
                BIN_LINK(x, next_x);
                x = next_x;
            }
        }
        next_x = x->sibling;
    }
    return H;
}

struct node* BIN_HEAP_INSERT(struct node* H, struct node* x) {
    struct node* H1 = MAKE_BIN_HEAP();
    x->parent = NULL;
    x->child = NULL;
    x->sibling = NULL;
    x->degree = 0;
    H1 = x;
    H = BIN_HEAP_UNION(H, H1);
    return H;
}

struct node* BIN_HEAP_MERGE(struct node* H1, struct node* H2) {
    struct node* H = MAKE_BIN_HEAP();
    struct node* y;
    struct node* z;
    struct node* a;
    struct node* b;
    y = H1;
    z = H2;
    if (y != NULL) {
        if (z != NULL && y->degree <= z->degree)
            H = y;
        else if (z != NULL && y->degree > z->degree)
            /* need some modifications here;the first and the else conditions can be merged together!!!! */
            H = z;
        else
            H = y;
    } else
        H = z;
    while (y != NULL && z != NULL) {
        if (y->degree < z->degree) {
            y = y->sibling;
        } else if (y->degree == z->degree) {
            a = y->sibling;
            y->sibling = z;
            y = a;
        } else {
            b = z->sibling;
            z->sibling = y;
            z = b;
        }
    }
    return H;
}

int display(struct node* H) {
    struct node* p;
    if (H == NULL) {
        printf("\n Heap is empty!!!");
        return 0;
    }
    printf("\n Root nodes are : ");
    p = H;
    while (p != NULL) {
        printf("%d", p->n);
        if (p->sibling != NULL)
            printf("-->");
        p = p->sibling;
    }
    printf("\n");
}

struct node* BIN_HEAP_EXTRACT_MIN(struct node* H1) {
    int min;
    struct node* t = NULL;
    struct node* x = H1;
    struct node *Hr;
    struct node* p;
    Hr = NULL;
    if (x == NULL) {
        printf("\n Nothing to extract!!!");
        return x;
    }
    min=x->n;
    p = x;
    while (p->sibling != NULL) {
        if ((p->sibling)->n < min) {
            min = (p->sibling)->n;
            t = p;
            x = p->sibling;
        }
        p = p->sibling;
    }
    if (t == NULL && x->sibling == NULL)
        H1 = NULL;
    else if (t == NULL)
        H1 = x->sibling;
    else if (t->sibling == NULL)
        t = NULL;
    else
        t->sibling = x->sibling;
    if (x->child != NULL) {
        REVERT_LIST(x->child);
        (x->child)->sibling = NULL;
    }
    H = BIN_HEAP_UNION(H1, Hr);
    return x;
}

int REVERT_LIST(struct node* y) {
    if (y->sibling != NULL) {
        REVERT_LIST(y->sibling);
        (y->sibling)->sibling = y;
    } else {
        Hr = y;
    }
}

struct node* FIND_NODE(struct node* H, int k) {
    struct node* x = H;
    struct node* p = NULL;
    if (x->n == k) {
        p = x;
        return p;
    }
    if (x->child != NULL && p == NULL) {
        p = FIND_NODE(x->child, k);
    }

    if (x->sibling != NULL && p == NULL) {
        p = FIND_NODE(x->sibling, k);
    }
    return p;
}

int BIN_HEAP_DECREASE_KEY(struct node* H, int i, int k) {
    int temp;
    struct node* p;
    struct node* y;
    struct node* z;
    p = FIND_NODE(H, i);
    if (p == NULL) {
        printf("\n Invalid choice of key to be reduced!!! ");
        return 0;
    }
    if (k > p->n) {
        printf("\n New key value is greater than the current key value!!!");
        return 0;
    }
    p->n = k;
    y = p;
    z = p->parent;
    while (z != NULL && y->n < z->n) {
        temp = y->n;
        y->n = z->n;
        z->n = temp;
        y = z;
        z = z->parent;
    }
    printf("\n Key reduced successfully!!!");
}

int BIN_HEAP_DELETE(struct node* H, int k) {
    struct node* np;
    if (H == NULL) {
        printf("\n Heap is empty!!!");
        return 0;
    }
    BIN_HEAP_DECREASE_KEY(H, k, -1000);
    np = BIN_HEAP_EXTRACT_MIN(H);
    if (np != NULL)
        printf("\n Node deleted successfully!!!");
}

int main() {
    int i, n, m, choice,l;
    struct node* p;
    struct node* np;
    char ch;
    printf("\n Enter the no. of elements: ");
    scanf("%d", &n);
    printf("\n Enter the elements: ");
    for (i = 1; i <= n; i++) {
        scanf("%d", &m);
        np = create_node(m);
        H = BIN_HEAP_INSERT(H, np);
    }
    display(H);
    do {
        printf("\n1)INSERT AN ELEMENT \n2)EXTRACT THE MINIMUM KEY NODE\n3)DECREASE A NODE KEY\n 4)DELETE A NODE\n5)Display\n6)QUIT\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:do {
                   printf("\n Enter the element to be inserted: ");
                   scanf("%d", &m);
                   p = create_node(m);
                   H = BIN_HEAP_INSERT(H, p);
                   printf("\n Heap is: ");
                   display(H);
                   printf("\n Do you want to insert more? (y/Y): ");
                   fflush(stdin);
                   scanf("%c", &ch);
                   } while (ch == 'Y' || ch == 'y');
                    break;
        case 2:do {
                    p = BIN_HEAP_EXTRACT_MIN(H);
                    if (p != NULL)
                       printf("\n Extracted node is  %d", p->n);
                    printf("\n Heap will be: ");
                    display(H);
                    printf("\n Do you want to extract more? (y/Y): ");
                    fflush(stdin);
                    scanf("%c", &ch);
                    } while (ch == 'Y' || ch == 'y');
                    break;
        case 3:do {
                    printf("\n Enter the node to be decreased: ");
                    scanf("%d", &m);
                    printf("\n Enter the new value: ");
                    scanf("%d", &l);
                    BIN_HEAP_DECREASE_KEY(H, m, l);
                    printf("\n Heap will be: ");
                    display(H);
                    printf("\n Do you want to decrease key value  once more? (y/Y): ");
                    fflush(stdin);
                    scanf("%c", &ch);
                    } while (ch == 'Y' || ch == 'y');
                    break;
        case 4:do {
                    printf("\n Enter the key value of the node to be deleted: ");
                    scanf("%d", &m);
                    BIN_HEAP_DELETE(H, m);
                    printf("\n Do you want to delete more? (y/Y): ");
                    fflush(stdin);
                    scanf("%c", &ch);
                    } while (ch == 'y' || ch == 'Y');
                    break;
        case 5:display(H);break;
        case 6:exit(0);
             break;
        default:printf("\n Invalid entry!!!");
        }
    } while (choice!= 6);
}
