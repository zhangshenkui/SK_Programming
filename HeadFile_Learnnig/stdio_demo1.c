#include <stdio.h>
#include <stdlib.h>


/********
 * 主题：40个内置函数的用法
 * 作者：zhangshenkui
 * 日期：2022/1/11
 * ************/



//1.fclose(),原型 int fclose(FILE *stream)

//2.fopen(),原型 FILE *fopen(const char *filename,const char *mode)

//3.clearerr(),原型void clearerrr(FILE *stream)

//4.原型：int feof(FILE *stream)
//返回值：流关联文件结束标识符 or 零（失败）


int main(){



/**********
 *fopen,在”只读“方式打开“存在”或”不存在“的txt
 *
 *不存在txt,fp1空指针，perror()函数打印
 *
 *feof(指针)函数检查是否到文件末尾
 *，fgetc(指针)负责将获取字符，并前移，未到末尾遍历打印字符
 *
 *关闭
 * ********************************/
FILE *fp1;
int c;
//fp1=fopen("file2.txt","r");  //仅读取，需存在， r+a+w
fp1=fopen("file.txt","r");  //仅读取，需存在， r+a+w
if(fp1==NULL){

	perror("open file occur error \n");    //新函数 void perror(const char *str)
	return -1;
}
while(1){
c=fgetc(fp1);   //新函数 int fgetc(FILE *stream); 制定流stream获取下一个字符（无符号字符），并把位置标识符前移（what）

if(feof(fp1)){  //新函数bool feof(file)检查文件指针是否到文件末尾EOF
	break;
}
printf("%c",c);

}

fclose(fp1);
//针对ferror()函数，int ferror(FILE *stream)
//指向FILE对象的指针，FILE对象标识了流
//返回非零值

//FILE *fp2=fopen("Eight_Pig.txt","r");
FILE *fp2;
fp2=fopen("file.txt","r");

char c1;
c1=fgetc(fp2);

if(~ferror(fp2)){

perror("ferror 函数测试\n");
printf("ferror_demo test failed \n");

}
clearerr(fp2);
if(~ferror(fp2)){                          //为什么这样做，因为如果打开不存在文件，野指针导致“segament Fault”

printf("ferror_demo test again \n");

}

fclose(fp2);








return 0;


}
