#include <iostream>
using namespace std;

BTNode * createBTNode (string data);
void visitNode (BTNode * btNode);

int height (BTNode * root);
void inOrderIterative(BTNode * root);
bool isEmptyTree (BTNode * root);
bool isEqual (BTNode * root1, BTNode * root2);
void levelOrder (BTNode * root);
int moment(BTNode * root);
int numLevels(BTNode * root);
void preOrderIterative (BTNode * root);
void postOrderIterative (BTNode * root);
int weight(BTNode * root);
int width(BTNode * root);
int getWidthLevel(BTNode * root, int level);
