#include <stdio.h>
#include <stdlib.h>
#include<string.h>

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


//5.原型:int fflush(FILE *stream)
//FILE对象指定一个缓冲流
//成功返回“零值”，失败“EOF",且设置错误标识符（feof)


//6.原型：int fgetpos(FILE *stream,fpos_t *pos) 获取stream当前文件位置，写入到pos
//参数2：pos指向fpos_t对象的指针
//返回值：成功返回0，错误非零值

int main(){





/**********程序将缓冲输出保存在buff,直至调动fflush()开始缓冲输出，最后休眠5秒钟，结束之前
 * 剩余输出到STDOUT************************/
char buff[1023];

memset(buff,'\0',sizeof(buff));   //void *memset(void *str,int c,size_t n)
//复制字符c到str的前n个---一个用于初始化，全部赋值；一个是替换，前多少个替换成字符c

///FILE *stdout;
///stdout=fopen("file4.txt","w+");
fprintf(stdout,"启用全缓冲\n");
setvbuf(stdout,buff,_IOFBF,1024); 
//原型 int setvbuf(FILE *stream,char *buff,int mode,size_t size)定义流如何缓冲
//参数2：buff,分配给用户缓冲，设置为NULL，自动指定大小缓冲
//参数3：mode文件缓冲模
/******三种*
 * *_IOFBF:全缓冲； 输出：缓冲填满时一次性写入；输入：缓冲在请求输入且缓冲为空时被填充
 * *—IOLBF:行缓冲：输出：遇到换行符或缓冲填满时被写入；输入：缓冲在请求输入且缓冲为空时被填充，直至遇到下一个缓冲符
 * *——IONBF：无缓冲，不使用缓冲，每个I/O操作都被即时写入，buffer和size参数被忽略
//参数4：size， 缓冲大小，字节为单位
/**/


fprintf(stdout,"demo for fflush_function \n");
fprintf(stdout,"storage in Buff  \n");
fflush(stdout);

fprintf(stdout,"编程时出现 \n");
fprintf(stdout,"Sleep for 5 minute \n");

sleep(5);

///fclose(stdout);---对应上面45 -46行保留输入






FILE *fpx;
fpos_t position;   //也是一种种类

fpx=fopen("file1.txt","w+");

fgetpos(fpx,&position);

fputs("hello_world!!!!\n",fpx); //int fputs(const char *str,FILE *stream)  字符写入流stream

fsetpos(fpx,&position);//int fsetpos(FILE *stream,const fpos_t *pos)
//参数2，通过fgetpos()获得的位置
//返回值，成功返回0，失败非零值，并且全局变量errno设置值，通过perror来解释

fputs("Covered Once Content",fpx);

fclose(fpx);



return 0;


}
