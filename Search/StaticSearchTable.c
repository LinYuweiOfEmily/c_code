#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/*
本次代码实现静态查找表（一维数组为例）的几种常见查找算法:
1.顺序查找：虽然是最常使用的一种查找算法，但书上有所改进，在0号结点设“哨兵”（存储key），这样就不需要每一步都检查是否查找完毕。
           大大提高了效率
2.折半查找：需要在已经排好序的情况下使用，效率相较于顺序查找大大提升
*/
//顺序查找
int SearchSeq(int k[],int length,int x)
{
    k[length] = x;
    for(int i=0;i<length;i++)
    {
        if(k[i]==x)
        {
            return i;
        }
    }
}
//折半查找
int SearchBin(int k[],int length,int x)
{
    int low,high;
    low = 0;
    high = length-1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(k[mid]==x)
        {
            return mid;
        }else if(k[mid]>x)
        {
            high = mid-1;
        }else
        {
            low = mid + 1;
        }
    }
    return -1;
}
int main()
{
    return 0;
}