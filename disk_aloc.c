#include<stdio.h>
#include<stdlib.h>
int n,r[10],start;
void input(){
	printf("Enter the no of requests: ");
	scanf("%d",&n);
	printf("Enter the requests: ");
	for(int i =0;i<n;i++){
		scanf("%d",&r[i]);
	}
	printf("Enter the starting address: ");
	scanf("%d",&start);
}
void fcfs(){
	int seektime=0,i;
	float avgseektime = 0;
	printf("FCFS:\n");
	printf("%d",start);
	for(i =0;i<n;i++){
		printf(" %d ",r[i]);
	}
	seektime += abs(start-r[0]);
	for(i =1;i<n;i++){
		seektime += abs(r[i] - r[i-1]);
	}
	printf("\nSeektime: %d",seektime);
	avgseektime = (float)seektime/n;
	printf("\nAvg seektime: %f\n",avgseektime);
}
void sort(int a[11]){
	int i,j,smallest,t;
	for(i=0;i<=n;i++){
		smallest = i;
		for(j=i+1;j<=n;j++){
			if(a[j]<a[smallest])
				smallest = j;
		}
		t = a[i];
		a[i] = a[smallest];
		a[smallest] = t;
	}
}
void scan(){
	int seektime=0,s,i,left,right,temp[11];
	float avgseektime = 0;
	temp[0] = start;
	printf("SCAN: \n");
	for(i=1;i<=n;i++)
		temp[i] = r[i-1];
	sort(temp);
	for(i=0;i<=n;i++){
		if(temp[i]==start){
			s = i;
			break;
		}
	}
	left = temp[s] - temp[s-1];
	right = temp[s+1] - temp[s];
	if(left<right){
		for(i=s;i>=0;i--)
			printf(" %d ",temp[i]);
		if(temp[0]!=0)
			printf("0");
		for(i=s+1;i<=n;i++)
			printf(" %d ",temp[i]);
		seektime = temp[s] + temp[n];	
	}
	else{
		for(i=s;i<=n;i++)
			printf(" %d ",temp[i]);
		if(temp[n]!=199)
			printf("199");
		for(i=s-1;i>=0;i--)
			printf(" %d ",temp[i]);
		seektime = (199-temp[s]) + (199-temp[0]);	
	}
	printf("\nSeektime: %d",seektime);
	avgseektime = (float)seektime/n;
	printf("\nAvg seektime: %f\n",avgseektime);
}
void cscan(){
	int seektime=0,s,i,left,right,temp[11];
	float avgseektime = 0;
	temp[0] = start;
	printf("CSCAN: \n");
	for(i=1;i<=n;i++)
		temp[i] = r[i-1];
	sort(temp);
	for(i=0;i<=n;i++){
		if(temp[i]==start){
			s = i;
			break;
		}
	}
	left = temp[s] - temp[s-1];
	right = temp[s+1] - temp[s];
	if(left<right){
		for(i=s;i>=0;i--)
			printf(" %d ",temp[i]);
		if(temp[0]!=0)
			printf(" 0 ");
		if(temp[n]!=199)
			printf(" 199 ");
		for(i=n;i>=s+1;i--)
			printf(" %d ",temp[i]);
		seektime = temp[s] + (199-temp[s+1]);	
	}
	else{
		for(i=s;i<=n;i++)
			printf(" %d ",temp[i]);
		if(temp[n]!=199)
			printf(" 199 ");
		if(temp[0]!=0)
			printf(" 0 ");
		for(i=0;i<=s-1;i++)
			printf(" %d ",temp[i]);
		seektime = (199-temp[s]) + temp[s-1];	
	}
	printf("\nSeektime: %d",seektime);
	avgseektime = (float)seektime/n;
	printf("\nAvg seektime: %f\n",avgseektime);
}
void menu(){
	int ch;
	printf("1.FCFS 2.SCAN	3.CSCAN	4.End the program");
	while(1){
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1: fcfs();
				break;
			case 2: scan();
				break;
			case 3: cscan();
				break; 
			case 4: exit(0);
			default: printf("Invalid choice!");
		}
	}
}
void main(){
	input();
	menu();
}
