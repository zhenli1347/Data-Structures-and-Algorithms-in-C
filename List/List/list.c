#include<stdio.h>
#include<stdlib.h>
#include"list.h"

//链表创建-带有头结点和首元结点（链表的第一个含数据的结点）
//头结点有利于插入/删除等操作在链表不同位置的统一和
//非空和空链表的统一
llink
list_creat(void)
{
    llink tounode=(llink)malloc(sizeof(struct List));
    if(!tounode)
        return tounode;
    tounode->next=NULL;
    return tounode;
}
//链表销毁
//包含头结点在内，全部释放

int
list_delete(const llink listhead)
{
    llink  temppointer=listhead;
    llink deletepointer=temppointer;
    
    if(!listhead){
        return false;
    }
    while(deletepointer){
        temppointer=temppointer->next;
        free(deletepointer);
        deletepointer=temppointer;
    }
    return true;
}

//链表清空-释放除头结点之外的链表结点
//成功返回头结点；错误返回NULL
int 
list_clear(const llink listhead)
{
    llink temppointer,clearpointer;
    
    if(!listhead){
        return false;
    }
    temppointer=clearpointer=listhead->next;
    while(clearpointer){
        temppointer=temppointer->next;
        free(clearpointer);
        clearpointer=temppointer;
    }
    
    listhead->next=NULL;
    return true;
    
}

//链表长度和打印

int
list_length(const llink listhead)
{
    int length=0;
    llink temppointer=listhead->next;
    while(temppointer){
        length++;
        temppointer=temppointer->next;
    }

    return length;
}

int
list_printf(const llink listhead)
{
    if(!listhead)
        return false;
    llink temp=listhead->next;
    while(temp){
        printf("%d ",temp->vertex);
        temp=temp->next;
    }
    printf("\n");
    return true;
}
/*链表的头部插入
 插入成功返回新节点的地址，失败返回空指针NULL
 */

llink
listinsert_head(const llink listhead,int item)
{
    llink newnode=(llink)malloc(sizeof(struct List));
    if(!newnode){
        return NULL;
    }
    newnode->vertex=item;
    newnode->next=listhead->next;
    listhead->next=newnode;
    return newnode;
}


/*链表的尾部插入*/
llink
listinsert_tail(const llink listhead,int item)
{
    llink newnode=(llink)malloc(sizeof(struct List));
    if(!newnode)
        return NULL;
    llink tail=listhead;
    while(tail->next){
        tail=tail->next;
    }
    newnode->vertex=item;
    newnode->next=NULL;
    tail->next=newnode;

    return newnode;
}

//链表特定位置插入
//待续
llink 
listinsert_position(const llink listhead,int position,int item)
{
    int length=list_length(listhead);
    if(position>length+1||position<1){
        return NULL;
    }
    
    int location;
    llink locationpointer=listhead;
    for(location=0;location<position-1;location++){
        locationpointer=locationpointer->next;
    }

    llink positionpointer=(llink)malloc(sizeof(struct List));
    if(!positionpointer)
        return NULL;
    positionpointer->vertex=item;
    positionpointer->next=locationpointer->next;
    locationpointer->next=positionpointer;

    return positionpointer;
}


//特定结点删除

 int
 listdelete_position(const llink listhead,int position)
  {
     int length=list_length(listhead);
      if(position<1||position>length){
          return false;
      }
      llink prevpointer;
      llink deletepointer;
  
      prevpointer=listhead;
      int i;
      for(i=0;i<position-1;i++)
          prevpointer=prevpointer->next;
      deletepointer=prevpointer->next;
      prevpointer->next=deletepointer->next;
      free(deletepointer);
      return true;
  }


   //链表查找第一个出现的元素
  
  llink
  list_search(const llink listhead,int item)
  {
      llink retvalue=NULL;
  
      llink itempointer=listhead->next;
  
      while(itempointer){
          if(itempointer->vertex==item){
              retvalue=itempointer;
              break;
          }else
              itempointer=itempointer->next;
      }
  
      return retvalue;
  }
