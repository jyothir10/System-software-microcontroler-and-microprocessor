#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main(){
	FILE *f1,*f2,*f3,*f4;
	char la[20],opnd[20],mne[20],name[20],opc[20],loc[20],op1[25];
	int sa,lc,o,pl;
	f1 = fopen("input.txt","r");
	f3 = fopen("symbtab.txt","w+");
	f4 = fopen("output.txt","w+");
	fscanf(f1,"%s %s %s",la,mne,op1);
	if(strcmp(mne,"START")==0){
		sa = strtol(op1,NULL,16);
		lc = sa;
		printf("_\t%s\t%s\t%s\n",la,mne,op1);
		fprintf(f4,"_\t%s\t%s\t%s\n",la,mne,op1);
	}
	else{
		lc = 0X0;
	}
	fscanf(f1,"%s %s %s",la,mne,opnd);
	while(strcmp(mne,"END")!=0){
		printf("%X\t%s\t%s\t%s\n",lc,la,mne,opnd);
		fprintf(f4,"%X\t%s\t%s\t%s\n",lc,la,mne,opnd);
		if(strcmp(la,"_")!=0){
			fprintf(f3,"%s\t%X\n",la,lc);		//creating symtab
		}
		f2 = fopen("optab.txt","r");
		fscanf(f2,"%s %x",opc,&o);
		while(!feof(f2)){
			if(strcmp(mne,opc)==0){
				lc += 0x3;
			}
			fscanf(f2,"%s %x",opc,&o);
		}
		fclose(f2);
		if(strcmp(mne,"RESW")==0){
			lc += (0x3*atoi(opnd));
		}
		fscanf(f1,"%s %s %s",la,mne,opnd);
	}
    pl = lc-sa;

	printf("_\t%s\t%s\t%s\n",la,mne,opnd);
	fprintf(f4,"_\t%s\t%s\t%s\n",la,mne,opnd);
	fclose(f1);
	fclose(f3);
	  printf("\nPro %x",pl);
}
