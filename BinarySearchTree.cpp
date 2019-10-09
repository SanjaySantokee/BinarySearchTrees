#include <iostream>
#include "NodeTypes.h"
#include "BinaryTree.h"
#include "Stack.h"
#include "Queue.h"

using namespace std;

BTNode * max(BTNode * root) {
	if(root==NULL)
		return NULL;
    while (root->right != NULL)
		root = root->right;

	return(root);
}


BTNode * min(BTNode * root) {
	if(root==NULL)
		return NULL;
    while (root->left != NULL)
		root = root->left;
    return(root);
}


BTNode * contains(BTNode * root, string key) {
	if(root==NULL)
		return NULL;

	if(root->data == key)
		return root;

	if(root->data < key)
		return contains(root->right, key);

	return contains(root->left, key);
}


BTNode * ceiling(BTNode * root, string key) {

	BTNode*temp = NULL;
	
	if (root==NULL || root->data == key)
		return root;
	
	if(root->data < key)
		return ceiling(root->right, key);
	else
		temp= ceiling(root->left, key);
	
	if(temp != NULL){
		if(temp->data >= key)
			return temp;
	}
	return root;
}


BTNode * inOrderSuccessor (BTNode * node) {

	BTNode* temp;
	//case 1 right subtree
	if(node->right != NULL){
		return min(node->right);
	}
	//case 2 no right subtree, uses the parent where last left turn was made

	BTNode* parent = node->parent;

	while(parent != NULL && parent->right == node){
		node = parent;
		parent = node->parent;
	}
	return parent;

}


bool isLeaf(BTNode * word){
    if( (word->left==NULL) && (word->right==NULL) )
        return true;

    return false;
}

BTNode * deleteNode(BTNode * root, string key) {
    if (root == NULL) 
		return root;
		
    if (key < root->data) 
		root->left = deleteNode(root->left, key);
		
    else if (key > root->data) 
		root->right = deleteNode(root->right, key);
    else
    {
        if(root->left == NULL)
        {
            BTNode *temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL)
        {
            BTNode *temp = root->left;
            delete root;
            return temp;
        }

        BTNode * curr = root->right;
        while(curr->left != NULL) curr = curr->left;

        root->data = curr->data;
        root->right = deleteNode(root->right, curr->data);
    }
    return root;
}


BTNode * floor(BTNode * root, string key) {
	
	BTNode*temp = NULL;
	
	if (root==NULL || root->data == key)
		return root;
	
	if(root->data > key)
		return floor(root->left, key);
	else
		temp= floor(root->right, key);
	
	if(temp != NULL){
		if(temp->data <= key)
			return temp;
	}
	return root;
}


BTNode * inOrderPredecessor (BTNode * node) {
	
	BTNode* temp;
	//case 1 right subtree
	if(node->left != NULL){
		return max(node->left);
	}
	//case 2 no right subtree, uses the parent where last left turn was made

	BTNode* parent = node->parent;

	while(parent != NULL && parent->left == node){
		node = parent;
		parent = node->parent;
	}
	return parent;

}


BTNode * insert(BTNode * root, string key) {
	BTNode* newNode;

	newNode=createBTNode(key);

	if(root==NULL)
		return newNode;

	BTNode* curr=root;

	while(key != curr->data){

		if(key<curr->data){

			if(curr->left==NULL){
			curr->left=newNode;
			newNode->parent=curr;
			return root;
			}

			curr=curr->left;
		}
		else{

			if(curr->right==NULL){
			curr->right=newNode;
			newNode->parent=curr;
			return root;
            }

		curr=curr->right;
		}
	}
	return NULL;
}


int Range(BTNode * root, string bottom, string high) {
    int r = 0;

    if (root == NULL)
        return 0;

    if (root->data == high && root->data == bottom)
        return 1;

    if (root->data == high || root->data == bottom)
        r++ ;

    if (root->data <= bottom) {
        r = r + Range(root->right, bottom, high);
    }
    else if (root->data >= high) {
        r = r + Range(root->left, bottom, high);
    }
    else if (root->data > bottom && root->data < high) {
        r++;
        r = r + Range(root->left, bottom, high);
        r = r + Range(root->right, bottom, high);
    }

    return r;
}



int Rank(BTNode * root, string key) {
	if(root==NULL){
		return 0;
	}
	int i=0;
	Stack *s = initStack();
	BTNode* curr=root;
	bool finished=false;

	while(!finished){
		while(curr!=NULL){
			if(curr->data < key)
				i++;
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
	return i;
}

