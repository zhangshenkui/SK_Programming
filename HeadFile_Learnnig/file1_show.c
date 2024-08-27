



#include<stdio.h>




void main(){

FILE *fp;
int c;
int n=0;


fp=fopen("file.txt","r+");


do{

c=fgetc(fp);


if(feof(fp))
	break;

printf("%c",c);   //字符串打印

}while(1);


fclose(fp);






}
