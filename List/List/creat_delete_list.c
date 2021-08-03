#include<stdio.h>
#include<stdlib.h>
#include"list.h"

int 
main(int argc,char* argv[])
{
    llink listhead=list_creat();
  
    llink headpointer,tailpointer; //指向首元结点和尾结点的指针
    headpointer=tailpointer=listhead;
    if(listhead)
        printf("creat list success\n");
    else 
        printf("creat list failed\n");

    //插入部分元素

    int item[5]={1,2,3,4,5};
    int i=0;
    for(;i<5;i++){
        if(listinsert_head(listhead,item[i])){
            printf("insert at head success\n");
        }
    }
    if(!list_printf(listhead)){
        printf("print list failed.\n");
    }
    printf("list's length=%d\n",list_length(listhead));
   
    //链表特定位置插入
    //链表第1 末尾 和长度范围外插入
    //first position
    if(listinsert_position(listhead,1,1)){
        list_printf(listhead);
    }else
        printf("first location insert failed.\n");
    printf("list lenght=%d.\n",list_length(listhead));
    
    //lenght+1
    if(listinsert_position(listhead,list_length(listhead)+1,list_length(listhead)+1)){
        list_printf(listhead);
    }else
        printf("lenght+1 location insert failed.\n");
    printf("list lenght=%d.\n",list_length(listhead));
    
    //-1
    if(listinsert_position(listhead,-1,-1)){
        list_printf(listhead);
    }else
        printf("-1 location insert failed.\n");
    printf("list lenght=%d.\n",list_length(listhead));

    
    //length+2
    if(listinsert_position(listhead,list_length(listhead)+2,list_length(listhead)+2)){
        list_printf(listhead);
    }else
        printf("length +2 location insert failed.\n");
    printf("list lenght=%d.\n",list_length(listhead));
    //链表清空
    if(!list_clear(listhead)){
        printf("clear list failed\n");
    } else{
        printf("clear list successes\n");
    }
    
    
    printf("list's length=%d\n",list_length(listhead));
    
    //链表尾部插入
    for(i=0;i<5;i++){
        if(listinsert_tail(listhead,item[i]))
                printf("insert at tail success\n");
                
    }
    list_printf(listhead);
    
    return 0;
}
