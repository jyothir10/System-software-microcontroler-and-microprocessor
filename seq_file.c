#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct file{
	char name[10];
	int size;
	int start;
}f[10];
int block[10],j=0;
void create(char name[10],int size){
	int i,k,m;
	for(i=0;i<10;i++){
        if(block[i]==0){
            f[j].start = i;
            m = size/10;
            for(k=i;k<i+m;k++){
                if(block[k] == 1){
                    f[j].start = -1;
                    break;
                }
            }
            if(k==i+m && k<=10){
                for(k=i;k<i+m;k++)
                    block[k] = 1;
                strcpy(f[j].name,name);
                f[j++].size = size;
                printf("File is allocated");
                break;
            }
        }
	}
	if(i == 10)
        printf("Not allocated!Memory not available");
}
void delete(char name[10],int size){
    int i,p;
	for(i=0;i<10;i++){
		if(strcmp(name,f[i].name)==0){
                p = f[i].start;
                f[i].start = -1;
                printf("File is deleted\n");
                break;
		}
	}
    if(i==10){
        printf("File does not exist\n");
        return;
    }
    for(i = p;i< p+(size/10);i++)
        block[i] = 0;
}
void fat(){
    printf("Filename Size Start\n");
	for(int i=0;i<j;i++){
		if(f[i].start != -1){
			printf("%s\t %d\t%d\n",f[i].name,f[i].size,f[i].start);
		}
	}
}
void menu(){
	int ch,size;
	char name[10];
	while(1){
		printf("\n1.Create file	2.Delete file	3.show FAT	4.End the program\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1: printf("Enter file name : ");
				scanf("%s",name);
				printf("Enter file size : ");
				scanf("%d",&size);
				create(name,size);
				break;
			case 2: printf("Enter file name : ");
				scanf("%s",name);
				printf("Enter the file size: ");
				scanf("%d",&size);
				delete(name,size);
				break;
			case 3: fat();
				break;
			case 4: exit(0);
			default: printf("Invalid choice!");
				break;
		}
	}
}
void main(){
	for(int i=0;i<10;i++)
		block[i]=0;
	menu();
}
