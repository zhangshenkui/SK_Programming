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


//7.size_t fread(void *ptr,size_t size,size_t nnemb,FILE *stream)
//从流stream读取数据到ptr指向的数组中
//
//参数1：ptr指向最小尺寸size *nnemb字节的内存块指针
//参数2：size读取每个元素大小，字节为单位
//参数3：nnemb元素个数，大小以size为单位
//参数4：stream-FILE对象指针
//成功返回元素综述以size_t对象返回，总数与nnmemb参数不同，错误或者到文件末尾
//
//
//




int main(){





FILE *fpx;


char c[]="2022 Happy Healthy";

char buff[20];



fpx=fopen("file4.txt","w+");


fwrite(c,strlen(c)+1,1,fpx);
//size_t fwrite(const void *ptr,size_t size,size_t nmemb,FILE *stream)
//将ptr指向的数组中数据写入到流stream中
//参数2：size写入的每个元素的大小
//


fseek(fpx,0,SEEK_SET);
//int fseek(FILE *stream ,long int offset,int whence)
//设置流文件位置为给定偏移值offset
//
//参数2：offset,相对whence的偏移量，以字节为单位
//
//参数3：whence表示开始添加偏移offset的位置，三种
/***
 *
 *SEEK_SET:文件开头
 *SEEK_CUR:文件指针当前位置
 *SEEK_END:文件末尾
 * **/




fread(buff,strlen(c)+1,1,fpx);
printf("%s\n",buff);

fclose(fpx);






















return 0;


}
