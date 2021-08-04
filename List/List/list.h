#ifndef LIST_H
#define LIST_H

#define false 0
#define true 1
struct List{
	int vertex;
	struct List *next;
};
typedef struct List *llink;//将 链表指针类型定义为 llink，可用于链表的头指针。
			   
//链表插入
void insert_list(llink *listheadpointer,int item);
void display_list(llink listhead);
llink insert_list_recursive(llink,int);
llink listinsert_head(const llink listhead,int item);// 链表头部插入 返回值为插入结点地址
llink listinsert_tail(const llink listhead,int item);//链表尾部插入  返回值同上
llink listinsert_position(const llink listhead,int position,int item);//链表特定位置插入


//特定结点删除
 
int
listdelete_position(const llink listhead,int postion);


//链表查找
llink search_list(llink,int);



//链表创建
llink  list_creat(void);
//创建单向链表，返回头指针或空指针;其中创建的链表中包含一个
//不含链表内容的节点-头节点（不同于包含链表内容的首元结点）

//链表销毁及清空
int  list_delete(const llink listhead);
int  list_clear(const llink listhead);

//链表长度
int list_length(const llink listhead);

//链表打印

int  list_printf(const llink listhead);

#endif
