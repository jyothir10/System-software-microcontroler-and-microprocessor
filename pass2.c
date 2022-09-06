#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
void main(){

	FILE *fin,*ftab,*fsym,*fobj,*flen;
	char add[10],lab[20],mne[20],opnd[20],start[10],opc[10],op[10],sym[10],symadd[10];
	int len,lc,sa,c;

	fin = fopen("output.txt","r");
	fsym = fopen("symbtab.txt","r");
	ftab = fopen("optab.txt","r");
	flen = fopen("length.txt","r");
	fobj = fopen("object.txt","w+");

	fscanf(fin,"%s%s%s%s",add,lab,mne,opnd);
	fscanf(flen,"%d",&len);
	fclose(flen);

	if(strcmp(mne,"START")==0){
        strcpy(start,opnd);
        sa = strtol(opnd,NULL,16);
        lc = sa;
        fscanf(fin,"%s%s%s%s",&add,lab,mne,opnd);
        while(strcmp(mne,"RESW")!=0){
            lc += 0x3;
            fscanf(fin,"%s%s%s%s",&add,lab,mne,opnd);
        }
        c = lc-sa;
        fseek(fin,0,SEEK_SET);
        fscanf(fin,"%s%s%s%s",&add,lab,mne,opnd);
	}
	printf("H^%s^00%s^0000%d \nT^00%s^0%X^",lab,start,len,start,c);
	fprintf(fobj,"H^%s^00%s^0000%d \nT^00%s^0%X^",lab,start,len,start,c);

	fscanf(fin,"%s%s%s%s",add,lab,mne,opnd);
	fscanf(ftab,"%s%s",opc,op);

	while(strcmp(mne,"END")!=0){
        while(!feof(ftab)){
            if(strcmp(mne,opc)==0){
                fscanf(fsym,"%s%s",sym,symadd);
                while(!feof(fsym)){
                    if(strcmp(sym,opnd)==0){
                        printf("%s%s",op,symadd);
                        fprintf(fobj,"%s%s",op,symadd);
                        break;
                    }
                    else
                        fscanf(fsym,"%s%s",sym,symadd);
                }
                break;
            }
            else if((strcmp(mne,"WORD")==0)||(strcmp(mne,"BYTE")==0)){
                printf("0000%s",opnd);
                fprintf(fobj,"0000%s",opnd);
            }
            else if(strcmp(mne,"RESW")==0){
                break;
            }
            fscanf(ftab,"%s%s",opc,op);
        }
        fseek(fin,0,SEEK_CUR);
        fscanf(fin,"%s%s%s%s",add,lab,mne,opnd);

        if((strcmp(mne,"RESW")!=0)&&(strcmp(mne,"END")!=0)){    //for printing ^
            printf("^");
            fprintf(fobj,"^");
        }
        ftab = fopen("optab.txt","r");
	}
	printf("\nE^00%s",start);
	fprintf(fobj,"\nE^00%s",start);

	fclose(fin);
	fclose(ftab);
	fclose(fsym);
	fclose(fobj);
}
