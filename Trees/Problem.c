#include "stdio.h"
#include "stdlib.h"
#include "TreesLib.h"


int treenum(tree t)
{
	if (!t)
		return 0  ;
	return 1 + treenum(t->r) + treenum(t->l) ; 
}

int treesum(tree t)
{
	if (!t)
		return 0 ; 
	return t->value + treesum(t->l)+treesum(t->r) ; 
}

int treemax(tree t)
{
	if (!t)
		return -1;
	return max (t->value,max(treemax(t->l),treemax(t->r))) ; 
}
int main()
{
    freopen("in.txt", "r+", stdin);
    freopen("out.txt", "w+", stdout);
    tree t = createLeaf(8);
    t->l = createLeaf(3);
    t->r = createLeaf(10);
    t->r->r = createLeaf(14);
    t->r->r->l = createLeaf(13);
    t->l->l = createLeaf(1);
    t->l->r = createLeaf(6);
    t->l->r->l = createLeaf(4);
    t->l->r->r = createLeaf(7);
    levelOrderTraversal(t);
    printf("%d\n",treemax(t));
}