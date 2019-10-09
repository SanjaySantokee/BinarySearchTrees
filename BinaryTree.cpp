#include <iostream>
#include "NodeTypes.h"
#include "BinaryTree.h"
#include "Stack.h"
#include "Queue.h"

using namespace std;

BTNode * createBTNode (string data) {
	BTNode * newNode;

	newNode = new BTNode;
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->parent = NULL;

	return newNode;

}

void visitNode (BTNode * btNode) {
	if(btNode==NULL)
		return;
	cout << btNode->data << " ";
}


int height (BTNode * node) {

    if (node==NULL)
		return 0;
    return 1 + max( height(node->left), height(node->right) );
}


void inOrderIterative(BTNode * root) {
	
	if(root==NULL){
		cout<<"BST is empty"<<endl;
		return;
	}
	
	Stack *s = initStack();
	BTNode* curr=root;
	bool finished=false;

	while(!finished){
		while(curr!=NULL){
			push(s,curr);
			curr=curr->left;
		}
		if(isEmptyStack(s)){
			finished=true;
		}
		else{
			curr=pop(s);
			visitNode(curr);
			curr=curr->right;
		}
	}
}


bool isEmptyTree (BTNode * root) {
	if(root==NULL)
		return true;
	
	return false;
}


bool isEqual (BTNode * root1, BTNode * root2) {
	
	if(root1 == NULL && root2 == NULL)
		return true;
	if(root1 != NULL && root2 != NULL){
	
		bool x = isEqual(root1->left, root2->left);
		bool y = isEqual(root1->right, root2->right);
		
	if( (x == true) && (y == true) && (root1->data == root2->data) )
		return true;
	else return false;
	}
	
	return false;	
	
}

void levelOrder (BTNode * root) {
	if(root==NULL){
        cout << "Empty BST\n";
        return;
    }
    
	Queue* q= initQueue();
	enqueue(q,root);
	BTNode* temp;

	while(!(isEmptyQueue(q))){
		temp= dequeue(q);
		visitNode(temp);
		
		if(temp->left != NULL)
			enqueue(q,temp->left);

		if(temp->right != NULL)
			enqueue(q,temp->right);
	}
	cout<<endl;
}


int moment(BTNode * root) {
	if(root==NULL)
		return 0;

	return 1 + moment(root->left) + moment(root->right);
}


int numLevels(BTNode * root) {
    if(root==NULL) {
		cout << "Empty BST\n"; 
		return 0;
	}
		
    int level=0, i=0;
    Queue *q = initQueue();
    BTNode *temp;
    enqueue(q, root);

    while(true)
    {
        i = sizeQueue(q);
        if (i == 0) 
			return level;
        level++;

        while(i>0)
        {
            temp = dequeue(q);
            if(temp->left!=NULL) 
				enqueue(q,temp->left);
            if(temp->right!=NULL) 
				enqueue(q,temp->right);
            i--;
        }
    }
}


void preOrderIterative (BTNode * root) {
	
	if(root==NULL){
		cout<<"BST is empty"<<endl;
		return;
	}
	
	Stack *s = initStack();
	BTNode* curr=root;
	bool finished=false;

	while(!finished){
		while(curr!=NULL){
			visitNode(curr);
			push(s,curr);
			curr=curr->left;
		}
		if(isEmptyStack(s)){
			finished=true;
		}
		else{
			curr=pop(s);
			curr=curr->right;
		}
	}
}

void postOrderIterative (BTNode* root) {
	
	if(root==NULL){
		cout<<"BST is empty"<<endl;
		return;
	}
	
	Stack* s1 = initStack();
	Stack* s2 = initStack();
	push(s1, root);
	BTNode* temp;

	while(!(isEmptyStack(s1))){
		temp= pop(s1);
		push(s2,temp);

		if(temp->left != NULL)
			push(s1, temp->left);

		if(temp->right != NULL)
			push(s1, temp->right);
	}

	while(!(isEmptyStack(s2)))
		visitNode(pop(s2));
}

int weight(BTNode * root) {
	if(root==NULL)
		return 0;

	if(root->left==NULL && root->right==NULL)
		return 1;

	return weight(root->left) + weight(root->right);
}

int width(BTNode * root) {
	
	if(root==NULL) {
		cout << "Empty BST\n"; 
		return 0;
	}
		
    int i=0, max=0;
    Queue *q = initQueue();
    BTNode *temp;
    enqueue(q, root);

    while(!isEmptyQueue(q)){
    	
        i = sizeQueue(q);
        
		if(i > max)
			max = i;

        while(i>0){
            temp = dequeue(q);
            if(temp->left!=NULL) 
				enqueue(q,temp->left);
				
            if(temp->right!=NULL) 
				enqueue(q,temp->right);
            i--;
        }
    }
    
    return max;
}

