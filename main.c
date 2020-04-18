#include <stdio.h>
#include "avlTree.h"
#include <stdlib.h>

void inOrderTraverse(TREE_NODE* tRoot);
void levelTraverse(TREE_NODE* tRoot, int *key_arr);
void printAsTree(TREE_NODE* tRoot, int i);

int main() {
    unsigned int arr[] = {16,3,7,11,9,26,18,14,15};
    int n_key[100];
    for(int i = 0; i < 100; i++)
    	n_key[i] = -2;
    struct buffer_info* buff = (tAVLTree*)avlTreeCreate((void*)keyCompareFunc, (void*)freeFunc);
    for (int i = 0; i <9; i++) {
        struct buffer_group *new_node = (struct buffer_group *) malloc(sizeof(struct buffer_group));
        new_node->group = arr[i];
        avlTreeAdd(buff, (TREE_NODE*)new_node);
    }
    printf("inOrderTraverseOutput: ");
    inOrderTraverse(buff->pTreeHeader);
    putchar('\n');
    printf("levelTraverseOutput: ");
    levelTraverse(buff->pTreeHeader, n_key);
    putchar('\n');
    printf("ShapeOfTreeOutput: \n");
    puts("root");
	puts("|");
	puts("v");
    printAsTree(buff->pTreeHeader, 1);
	return 0;
}
void inOrderTraverse(TREE_NODE* tRoot) {
    if(tRoot != NULL)
    {
        inOrderTraverse(tRoot->left_child);
        printf("%d ",((buf_node*)tRoot)->group);
        inOrderTraverse(tRoot->right_child);
    }
}

void levelTraverse(TREE_NODE* tRoot, int *key_arr) {
    if (tRoot == NULL) {
        return;
    }
    int begin=0,end=0;
    int i = 0;
    TREE_NODE *queue[11];
    queue[0] = tRoot;
    end++;
    while (begin != end) {
    	TREE_NODE* node = queue[begin++];
    	printf("%d ",((buf_node*)node)->group);
    	key_arr[i++] = ((buf_node*)node)->group;
    	if (node->left_child != NULL) {
    		queue[end++] = node->left_child;
    	} else {
    		key_arr[i++] = -1;
    	}
    	if(node->right_child != NULL) {
    		queue[end++] = node->right_child;
    	} else {
		    key_arr[i++] = -1;
	    }
    }
}
void printAsTree(TREE_NODE* tRoot, int i) {
	if(tRoot) {
		printAsTree(tRoot->right_child, i+1);
		for (int j = 0; j < (i-1)*4; ++j) {
			putchar(' ');
		}
		printf("%d\n",((buf_node*)tRoot)->group);
		printAsTree(tRoot->left_child, i+1);
	}
}