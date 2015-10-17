/* FIXME: Implement! */
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode *root,*right, *left;
};

struct TreeNode *flatten(struct TreeNode *root){
	while(root){
		if(root->left){
			struct TreeNode *right = root->right;
			struct TreeNode *rightMost = root->left;
			while(rightMost->right)
				rightMost = rightMost->right;
			root->right = flatten(root->left);
			root->right = root->left;
			root->left = NULL;			
			rightMost->right = right;
		}
	return root;
	}
	return 0;
}

void printout(struct TreeNode * root, int level, char RL) {	//CHECK TREENODE by Tree Traversal
	int i;
	for(i=0; i<level; i++){
		printf("  %c",RL);
	}
	printf("%d\n",root->val);
	if(root->left) {
		printout(root->left,level+1,'L');	
	}
	if(root->right) {
		printout(root->right,level+1,'R');
	}
}

int main()
{
	struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	root->val = 1;
	root->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	root->left->val = 2;
	root->left->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	root->left->left->val = 3;
	root->left->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	root->left->right->val = 4;
	root->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	root->right->val = 5;
	root->right->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	root->right->right->val = 6;
	
	printout(root,0,' ');	//print Original Tree
	flatten(root);
	printf("************\n");
	printout(root,0,' ');	//print Flattened Tree
    return 0;
}
