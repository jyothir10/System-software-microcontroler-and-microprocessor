#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
struct file{
	char name[20];
	int size;
	int index[10];
}f[10];
int k=0,n,arr[10];
bool mem[10];
void initialise(){
	for(int i=0;i<10;i++){
		mem[i] =false;
	}
	for(;k<10;k++){
		f[k].index[0] =-1;
	}
	k=0;
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
		for(i=0;i<n;i++){
			f[k].index[i] = arr[i];
			mem[arr[i]] = true;
		}
		k++;
		printf("Allocated memory\n");
	}
}
void delete(){
	int i,j;
	char name[20];
	printf("Enter file name : ");
	scanf("%s",name);
	for(i=0;i<10;i++){
		if(strcmp(name,f[i].name)==0){
			for(j=0; j<(f[i].size/10);j++){
				mem[f[i].index[j]]  = false;
			}
			f[i].index[0] =-1;
			printf("File deleted\n");
			break;
		}
	}
    if(i==10){
        printf("File does not exist\n");
        return;
    }
}
void show(){
	printf("Filename\tFile_Size\t \tIndex_block\n");
	for(int i=0;i<k;i++){
		if(f[i].index[0]!= -1){
			printf("%s \t\t %d\t\t\t",f[i].name,f[i].size);
			for(int j=0;j<(f[i].size/10);j++)
				printf(" %d ",f[i].index[j]);
			printf("\n");
		}
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

