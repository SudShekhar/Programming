#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct st{
	char rec[1001];
	int vi;
	struct st *next;
};
typedef struct st st;
int match(char *a,char *b)
{	int i;
	for(i=0;i<strlen(b);i++)
	{
		if(a[i]!=b[i])return 0;
	}
	return 1;
}

void insert(st *h,st *temp)
{
	while(h->next && h->next->vi >= temp->vi)
	{
		h=h->next;
	}
	temp->next=h->next;
	h->next=temp;

	return;
}

int main(){
	int i,j,v,rep;
	scanf("%d",&rep);
	char name[1002];
	int key;
	st *root=(st*)malloc(sizeof(st));
	root->next=NULL;
	
	for(v=0;v<rep;v++)
	{
		scanf("%s %d",name,&key);
	//	printf("name is %s\n",name);
		st *node=(st*)malloc(sizeof(st));
		node->vi=key;
		strcpy(node->rec,name);
	//	printf("inseted %s cuzof %s\n",node->rec,name);
		node->next=NULL;
		insert(root,node);
	}
	st *t=root;
/*	while(t->next!=NULL)
	{
		printf("%s %d\n",t->rec,t->vi);
		t=t->next;
	}
*/
	scanf("%d",&rep);
	for(v=0;v<rep;v++)
	{
		scanf("%s",name);
		st *t=root->next;
	/*	if(t==NULL){
			printf("NO\n");
			continue;
		}
*/
		while(t)
		{
			if(match(t->rec,name))
			{
				printf("%s\n",t->rec);
				break;
			}
			else t=t->next;
		}
		if(t==NULL)printf("NO\n");
	}
	return 0;
}
