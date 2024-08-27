

/*总结9月21日与22日心得：

    1、明白二分查找的算法复杂度 log(N),由对数中log2（N）和log3(N),虽然底数不同，但扩大到一定程度loga(N)/logb(N)=常数
    2、旅行商问题复杂度为：O(n!),给定N个城市，需前往且确保旅程最短，必须把每个城市都走完N*（N-1）...(2)*1    
    3、对选择排序的延伸出来有了些许了解，非计算机科班的痛，看完就忘，需了解原理*/

#include<vector>
#include<iostream>


using namespace std;

int sort_index(int* arr,int len);
int main(){

int arr[6]={15,98,0,32,13,65};
vector<int> arr1;

//找出最值
cout<<"min valueindex= \n"<<sort_index(arr,6)<<endl;
//第二步：将最小的索引编号添加进序列


return 0;
}

//选择排序第一步骤：找出最小/最大索引编号

int sort_index(int* arr,int len){
    int min=arr[0];  //声明最值
    int index=0;
//    int len=sizeof(arr)/sizeof(arr[0]);
   // printf("len = %d\n",len);
    for(int i=1;i<len;i++)
        {
            if(min>arr[i]){
                min=arr[i];
                index =i;}
            printf("\n now value= %d, index =%d\n\n",min,index);
        }
    return index;
}







