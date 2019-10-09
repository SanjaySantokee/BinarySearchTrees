// Name: Sanjay Santokee
// ID: 816008051
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include "NodeTypes.h"
#include "BinaryTree.h"
#include "Stack.h"
#include "Queue.h"
#include "BinarySearchTree.h"

using namespace std;

void menu(){
	cout<<"\t Binary Search Tree (BST)\n";
	cout<<"\t ---------------------------------------------\n";
	cout<<"\t 1. Create BST from Dictionary\n";
	cout<<"\t 2. Add Word to BST\n";
	cout<<"\t 3. Delete Word from BST\n";
	cout<<"\t 4. Search for Word in BST\n";
	cout<<"\t 5. Traverse BST\n";
	cout<<"\t 6. What Comes Before Word in BST?\n";
	cout<<"\t 7. What Comes After Word in BST?\n";
	cout<<"\t 8. Compare BSTs\n";
	cout<<"\t 9. Statistics\n";
	cout<<"\t R. Range & Rank\n";
	cout<<"\t Q. Quit\n";
	cout<<"\t Please enter an option:\n";
}

void R(){
	cout<<"\t Range & Rank\n";
	cout<<"\t ---------------------------------------------\n";
	cout<<"\t 1. Range\n";
	cout<<"\t 2. Rank\n";
	cout<<"\t M. Menu\n";
	cout<<"\t Please enter an option:\n";
}

BTNode * deleteTree(BTNode * root){
    while (root!=NULL){
        root=deleteNode(root,root->data);
    }
    return NULL;
}

BTNode * option1(BTNode * bst){
	ifstream in;
	char dictName[50];
	
	cout<<"Please enter the name of the dictionary file or M (Menu): ";
	cin>>dictName;
	
	if( strcmp(dictName,"M") == 0 )
		return bst;
	
	in.open(dictName);
	if(!in.is_open()){
		cout<<"No file found, returning to Main Menu"<<endl;
		return bst;
	}
	
	if(bst != NULL)
		bst= deleteTree(bst);
	
	string word;
	while(!in.eof()){
		in>>word;
		bst = insert(bst, word);
	}
	cout<<"\n File successfully read\n";
		
	in.close();
	return bst;
}

BTNode * option2(BTNode * bst){
	string word;
	cout<<"Please enter the word to insert in the BST or M (Menu): ";
	cin>>word;
	
	if(word == "M")
		return bst;
		
	BTNode * temp= contains(bst,word);
	
	if(temp == NULL){
		bst= insert(bst, word);
		cout<<word<<" successfully inserted in the BST";
	}
	else 
		cout<<"Duplicate word found in the BST";
	
	return bst;
}

BTNode * option3(BTNode * bst){
	string word;
	cout<<"Please enter the word to delete from the BST or M (Menu): ";
	cin>>word;
	
	if(word == "M")
		return bst;
	
	if(contains(bst, word) == NULL){
		cout<<"The word "<< word<< " is not in the BST"<<endl;
		return bst;
	}
	
	bst= deleteNode(bst, word);
	cout<<"The word "<< word<< " was deleted"<<endl;
		
	return bst;
}

BTNode * option4(BTNode * bst){
	string word;
	cout<<"Please enter a word to search for or M (Menu): ";
	cin>>word;
	
	if(word == "M")
		return bst;
	
	BTNode * temp= contains(bst,word);
	
	if(temp == NULL)
		cout<<"The word (" << word << ") is not present in the BST";
	else 
		cout<<"The word (" << word << ") is present in the BST";
		
	return bst;
}

void option5(BTNode * bst){
	
	cout << "PreOrder Traversal of BST (Non-recursive version): " << endl;

	preOrderIterative(bst);

	cout << endl << endl;

	cout << "InOrder Traversal of BST (Non-recursive version): " << endl;

	inOrderIterative (bst);

	cout << endl << endl;

	cout << "PostOrder Traversal of BST (Non-recursive version): " << endl;

	postOrderIterative (bst);

	cout << endl << endl;

	cout << "Level Order Traversal of BST (Non-recursive version): " << endl;

	levelOrder (bst);

	cout << endl << endl;

}

void option6(BTNode * bst){
	BTNode * f;
	f= NULL;
	string word;
	
	cout<<"Please enter word: ";
	cin>>word;
	
	f= floor(bst,word);
	if(f == NULL)
		cout<<"There isnt any such word in the BST"<<endl;
	else if(word == f->data)
		cout<<"The word "<< f->data <<" is in the BST"<<endl<<endl;
	else cout<<"The floor of "<<word<<" is "<<f->data<<endl;
	
}

void option7(BTNode * bst){
	BTNode * c;
	c= NULL;
	string word;
	
	cout<<"Please enter word: ";
	cin>>word;
	
	c= ceiling(bst,word);
	if(c == NULL)
		cout<<"There isnt any such word in the BST"<<endl;
	else if(word == c->data)
		cout<<"The word "<< c->data <<" is in the BST"<<endl<<endl;
	else cout<<"The ceiling of "<<word<<" is "<<c->data<<endl;
	
}

void option8(BTNode * bst){
	BTNode * bst2;
	bst2= NULL;
	
	bst2= option1(bst2);
			
	bool check= isEqual(bst,bst2);
	if(check==true)
		cout<<"New BST is identical to the current BST";
	if(check==false)
		cout<<"New BST is not identical to the current BST";
	
}

void option9(BTNode * bst){
	int x=0;
	BTNode * a;
	
	cout<<"\t (1) The number of nodes in the tree: ";
	
		x= moment(bst);
	    cout << x << endl;
	
	cout<<"\t (2) The height of the tree: ";
	
		x= height (bst);
    	cout<< x << endl;
	
	cout<<"\t (3) The width of the tree: ";

		x= width(bst);
		cout<<"Width is :"<<x<<endl;
	
	cout<<"\t (4) The weight of the tree: ";
		
		x= weight(bst);
    	cout << x << endl;
	
	cout<<"\t (5) The number of levels in the tree: ";
		
		x= numLevels(bst);
    	cout<< x << endl;
	
		a =  min(bst);
		cout << "\t (6) Smallest word in BST is " << a->data << endl;
		    
		a = max(bst);
   		cout << "\t     Biggest word in BST is " << a->data << endl;

	    
}

void optionRange(BTNode * bst){
	string bottom, high;
	
	cout<<"Please enter a word for start of range: ";
	cin>>bottom;
	
	cout<<"Please enter word for end of range: ";
	cin>>high;
	int x= Range(bst, bottom, high);
	cout<<"Range: "<< x <<endl;
	
}

void optionRank(BTNode * bst){
	string key;
	cout<<"Please enter word to check rank of: ";
	cin>>key;
	int x= Rank(bst, key);
	cout<<"Rank: "<< x <<endl;
	
}

int main () {

	BTNode * bst;

	bst = NULL;
	
	char choice, Rchoice;
	
	menu();
	cin>>choice;
	cout<<"\n";
	while(choice!='Q'){
		
	switch(choice){
		case '1':
			bst= option1(bst);
			break;
		
		case '2':
			bst= option2(bst);
			break;
		
		case '3':
			bst= option3(bst);
			break;
			
		case '4':
			bst= option4(bst);
			break;
			
		case '5':
			option5(bst);
			break;
		
		case '6':
			option6(bst);
			break;
		
		case '7':
			option7(bst);
			break;
			
		case '8':
			option8(bst);
			break;
		
		case '9':
			option9(bst);
			break;
		
		case 'R':
			
			R();
			cin>>Rchoice;
			cout<<"\n";
			while(Rchoice!='M'){
				
			switch(Rchoice){
				case '1':
					optionRange(bst);
					break;
				
				case '2':
					optionRank(bst);
					break;
				
				case 'M':
					cout << "Returning to Main Menu"<<endl;
					break;
				
				default:
		            cout << "--> Error: Invalid option.";
		            break;

				}
			cout<<"\n\n\n";
			R();
			cin>>Rchoice;
			cout<<"\n";
			}
					
			break;
			
		case 'Q':
			return 0;
			break;
			
		default:
            cout << "--> Error: Invalid option.";
            break;

	}
	cout<<"\n\n\n";
	menu();
	cin>>choice;
	cout<<"\n";
	}
	
	return 0;
}
