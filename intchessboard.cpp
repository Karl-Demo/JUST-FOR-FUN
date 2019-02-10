#include<stdio.h>
#define MAXN 25

int main(){
	FILE* fp;
	fp=fopen("D://forchess","w+");
	int k=0;
	for(int i=0;i<MAXN;i++){
		k=0;
		for(int j=0;j<MAXN;j++){
			fputc(' ',fp);
			fputc(' ',fp);
			fputc(' ',fp);
			fputc('*',fp);
		}
		fputc(10,fp);
	}
	fseek(fp,81,0);
	fputc(fgetc(fp),stdout);
	fputc(fgetc(fp),stdout);
	fputc(fgetc(fp),stdout);
	putchar(65);
	} 
