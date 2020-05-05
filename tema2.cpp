#include<iostream>
#include<conio.h>
int flag=0;
struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height;
}*root;
class avlTree
{
public:
    int max(int a, int b);
    int height(struct node *N);
    node* newNode(int key);
    void display(node *ptr, int level);
    node* rightRotate(struct node *y);
    node* leftRotate(struct node *x);
    int getBalance(struct node *N);
    struct node* insert(struct node* node, int key);
    struct node * minValueNode(struct node* node);
    struct node* deleteNode(struct node* root, int key);
    void preOrder(struct node *root);
    void postOrder(struct node *root);
    void inOrder(struct node *root);
    void search(int);
    void reflect(node * p);
    //Default constructor
    avlTree()
    {
        root = nullptr;
    }
};

void avlTree::search(int key)
{
    node *temp = root,*parent = root;
    if(temp== nullptr)
        std::cout<<"\nThe AVL Tree is empty\n"<<std::endl;
    else
    {
        while(temp!=NULL && temp->key!=key)
        {
            parent=temp;
            if(temp->key<key)
            {
                temp=temp->right;
            }
            else
            {
                temp=temp->left;
            }
        }
    }

    if(temp==NULL)
        std::cout<<"This element is NOT present in the tree!";
    else
    {std::cout<<"\nThis element is present in the tree! ";
        std::cout<<"\nIt's height is: "<<temp->height;
    }

}

void destroy(node *p)
{
    if(!p) return;
    destroy(p->left);
    destroy(p->right);
    delete p;
}
void d(node *p)
{    node* lc=p->left;
    if(lc&&(lc->left||lc->right)) d(lc);
    else
    { delete lc;
        p->left=NULL;
    }
    node* rc=p->right;
    if(rc&&(rc->left||rc->right)) d(rc);
    else
    { delete rc;
        p->right=NULL;
    }
}

int avlTree::max(int a, int b)
{
    return (a > b)? a : b;
}

int avlTree::height(struct node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

void avlTree::display(node *ptr, int level)
{
    int i;
    if (ptr!=NULL)
    {
        display(ptr->right, level + 1);
        printf("\n");
        if (ptr == root)
            std::cout<<"Root -> ";
        for (i = 0; i < level && ptr != root; i++)
            std::cout<<"        ";
        std::cout<<ptr->key;
        display(ptr->left, level + 1);
    }
}

struct node* avlTree::newNode(int key)
{
    struct node* node = (struct node*)
            malloc(sizeof(struct node));
    node->key   = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;
    return(node);
}

struct node* avlTree::rightRotate(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
    return x;
}

struct node* avlTree::leftRotate(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
    return y;
}

int avlTree::getBalance(struct node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

struct node* avlTree::insert(struct node* node, int key)
{
    if (node == NULL)
        return(newNode(key));
    if (key < node->key)
        node->left  = insert(node->left, key);
    else
        node->right = insert(node->right, key);
    node->height = max(height(node->left), height(node->right)) + 1;
    int balance = getBalance(node);
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
    if (balance > 1 && key > node->left->key)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

struct node * avlTree::minValueNode(struct node* node)
{
    struct node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

struct node* avlTree::deleteNode(struct node* root, int key)
{
    if (root == NULL)
        return root;
    if ( key < root->key )
        root->left = deleteNode(root->left, key);
    else if( key > root->key )
        root->right = deleteNode(root->right, key);
    else
    {
        if( (root->left == NULL) || (root->right == NULL) )
        {   struct node *temp = root->left ? root->left : root->right;
            flag=1;
            if(temp == NULL)
            {
                temp = root;
                root = NULL;
                flag=1;
            }
            else
            {*root = *temp;flag=1;}
            free(temp);
        }
        else
        {
            struct node* temp = minValueNode(root->right);

            root->key = temp->key;

            root->right = deleteNode(root->right, temp->key);
        }
    }
    if (root == NULL)
        return root;
    root->height = max(height(root->left), height(root->right)) + 1;
    int balance = getBalance(root);
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}


void avlTree::preOrder(struct node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void avlTree::postOrder(struct node *root)
{
    if(root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->key);
    }
}

void avlTree::inOrder(struct node *root)
{
    if(root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

int main()
{
    int choice, item;
    avlTree avl;
    while (1)
    {
        std::cout<<"\n\n***************************************"<<std::endl;
        std::cout<<"\tAVL Tree Implementation"<<std::endl;
        std::cout<<"***************************************"<<std::endl;
        std::cout<<"1.Insert Element into the tree"<<std::endl;
        std::cout<<"2.Display Balanced AVL Tree"<<std::endl;
        std::cout<<"3.Delete Element from tree"<<std::endl;
        std::cout<<"4.InOrder traversal"<<std::endl;
        std::cout<<"5.PreOrder traversal"<<std::endl;
        std::cout<<"6.PostOrder traversal"<<std::endl;
        std::cout<<"7.Search for an Element"<<std::endl;
        std::cout<<"0.Exit"<<std::endl;
        std::cout<<"\nEnter your Choice: ";
        std::cin>>choice;
        std::cout<<"\n";
        switch(choice)
        {
            case 1:
                std::cout<<"Enter value to be inserted: ";
                std::cin>>item;
                root = avl.insert(root, item);
                break;
            case 2:
                if (root == NULL)
                {
                    std::cout<<"Tree is Empty"<<std::endl;
                    continue;
                }
                std::cout<<"Balanced AVL Tree:"<<std::endl;
                avl.display(root, 1);
                break;
            case 3: std::cout<<"\nEnter value to be deleted: ";
                std::cin>>item;
                root = avl.deleteNode(root, item);
                if(flag==0)
                    std::cout<<"\nElement not found in this tree!";
                else
                    std::cout<<"\nElement deleted successfully!";
                break;
            case 4:
                std::cout<<"Inorder Traversal:"<<std::endl;
                avl.inOrder(root);
                std::cout<<std::endl;
                break;
            case 5:
                std::cout<<"Preorder Traversal:"<<std::endl;
                avl.preOrder(root);
                std::cout<<std::endl;
                break;
            case 6:
                std::cout<<"Postorder Traversal:"<<std::endl;
                avl.postOrder(root);
                std::cout<<std::endl;
                break;
            case 7:std::cout<<"\nEnter element to search: ";
                std::cin>>item;
                avl.search(item);
                break;
            case 0:exit(1);
                break;
            default:
                std::cout<<"\nWrong Choice!"<<std::endl;
        }
    }
}
