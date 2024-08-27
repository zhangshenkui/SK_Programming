


1、string.h相关函数：
    memchr
    memcmp:比较两个内存快的内容进行比较
    memcpy
    memmove
    memeset
    strcat
    strchr
    strcmp
    strcoll
    strcpy
    strcspn： size_t strcspn(const char* str1,const char* str2); //返回值：如果找到返回字符位置，否则返回字符串长度；返回str1中出现的第一个属于str2的字符的位置
    strerror: char* strerror(int errnum);  //返回值：返回描述错误内容的字符串指针；给出错误代码errnum的描述内容
    strlen
    strncat
    strpbrk
    strrchr
    strspn
    strstr
    strtok
    strxfrm
    
2、unistd.h                 //主要定义了uinx相关的函数

    getpid()
    getcwd()
    chdir()
    getuid()
    access()
    read()
    write()

