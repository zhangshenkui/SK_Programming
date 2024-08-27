




#include <stdio.h>
#include <stdlib.h>


/********
 * 主题：40个内置函数的用法
 * 作者：zhangshenkui
 * 日期：2022/1/11
 * ************/



//1.fclose(),原型 int fclose(FILE *stream)
// stream--FILE对象（存储未见流信息对象类型库变量）的指针，成功返回零，失败返回EOF（宏）

//2.fopen(),原型 FILE *fopen(const char *filename,const char *mode)
//filename--C字符串，文件名称
//mode-文件访问模式，五种
/* * r:读取，文件必须存在
 * * w:写入，创建一个写入空文件，已有，空覆盖原有内容
 * * a:追加，文件末尾追加;不存在，创建新文件
 * * r+:打开一个用于更新文件，可读可写，文件必须存在
 * * w+:创建一个用于读写的空文件
 * * a+:打开一个用于读取和追加的文件
 *返回值：FILE指针，失败返回NULL(空指针)，设置全局变量errno来标识错误
 * */

//3.clearerr(),原型void clearerrr(FILE *stream)
//stream--指向FILE对象的指针，该FILE对象标识了流
//清除给定流stream的文件结束和错误标识符
//
//检测不是一个有效流，返回-1，设置errno为EBADF


int main(){


/************三段，生成一个file.txt文件，写入“标准输入输出XXXX，关闭”****************/
FILE *fp;

fp=fopen("file.txt","w");

fprintf(fp,"%s","标准输入输出头文件demo1");

fclose(fp);

/************三段，打开文件，追加一段，关闭，测试六种mode**********************************/

FILE *fp1;
fp1=fopen("file.txt","a+");
fprintf(fp1,"%s","\n 追加一段用于demo2-fopen_function\n");
fprintf(fp1,"%s  %s %s %d %s","We","are","in",2022,"\n");

//追加一段：展示写入内容----Failed
int c;
//char c;
while(1){
c=fgetc(fp1);
if(feof(fp1)){

	break;
}
printf("%c",c);

}
fclose(fp1);



/*********一个空文件file1.txt,读取一个以只写模式打开的文件****************/

FILE *fp2;
char c1;
fp2=fopen("file1.txt","w");
c1=fgetc(fp2);
if(ferror(fp2)){

printf("Read file1.txt,occcur error \n");
}
clearerr(fp2);
if(ferror(fp2)){
	printf("读取文件，发生错误\n");
}
fclose(fp2);



printf("%s","显示有问题\n");

return 0;




}
