#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
	int data;
	struct node *link;
}*ptr,*ptr1;
struct file{
	char name[20];
	int size;
	struct node *head;
}f[10];
int k=0,n,arr[10];
bool mem[10];
void initialise(){
	for(int i=0;i<10;i++){
		mem[i] =false;
	}
}
void insert(int data){
	ptr = malloc(sizeof(struct node));
	ptr->data = data;
	if(f[k].head==NULL)
        f[k].head=ptr;
    else
        ptr1->link=ptr;
    ptr1 = ptr;
    ptr1->link = NULL;
}
void create(){
	char name[20];
	int size,c=0,i,j;
	printf("Enter file name : ");
	scanf("%s",name);
	printf("Enter file size : ");
	scanf("%d",&size);
	n = size/10;
	for(i=0;i<10;i++){
		if(mem[i] == false && c<n){
			arr[c]=i;
			c++;
		}
	}
	if(c != n){
		printf("No sufficient space for memory\n");
	}else if(c==n){
		strcpy(f[k].name,name);
		f[k].size = size;
		f[k].head = NULL;
		for(i=0;i<n;i++){
			insert(arr[i]);
			mem[arr[i]] = true;
		}
		k++;
		printf("Allocated memory\n");
	}
}
void show(){
	printf("Filename\tFile_Size\t \tMemory_block\n");
	for(int i=0;i<k;i++){
		if(f[i].size != -1){
			printf("%s \t\t %d\t\t\t",f[i].name,f[i].size);
			ptr = f[i].head;
			while(ptr != NULL){
				printf(" %d ",ptr->data);
				ptr = ptr->link;
			}
			printf("\n");
		}
	}
}
void delete(){
	int i,j;
	char name[20];
	printf("Enter file name : ");
	scanf("%s",name);
	for(i=0;i<k;i++){
		if(strcmp(name,f[i].name)==0){
            f[i].size = -1;
            ptr = f[i].head;
            while(ptr!=NULL){
                mem[ptr->data] = false;
                ptr = ptr->link;
            }
			printf("File deleted\n");
			break;
		}
	}
	if(i==k){
			printf("File does not exist\n");
			return;
		}
}
void menu(){
	int ch;
	while(1){
		printf("\n1.Create file	2.Delete file	3.Show 	4.End the program");
		printf("\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				create();
				break;
			case 2: ;
				delete();
				break;
			case 3: show();
				break;
			case 4: exit(0);
			default: printf("Invalid choice!\n");
				break;
		}
	}
}
void main(){
	initialise();
	menu();
}
