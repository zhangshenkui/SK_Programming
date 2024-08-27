

#include <stdio.h>

#include <unistd.h>   //错误针对fpos_t


void main(){


FILE *fpx;

fpos_t pos;


char buff[1023];

fpx=fopen("Demo_show1.txt","rb");//rb:只读二进制文件，必须存在

if (fpx==NULL){

printf("Failed open \n");
}else{

//pos=fpos_t(16);
fgetpos(fpx,&pos);
//pos=16;


if(fsetpos(fpx,&pos)!=0)
	perror("fsetpos error");
else{
/*新定位文件指针读取16字符到buffer缓冲区**/
fread(buff,sizeof(char),16,fpx);

printf("16 bytes at byte %ld:  %.16s/n",pos,buff);
}


}
fclose(fpx);



}
