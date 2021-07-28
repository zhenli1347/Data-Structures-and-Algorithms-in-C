#ifndef LIST_H
#define LIST_H

struct List{
	int vertex;
	struct List *next;
};
typedef struct List *llink;//将链表结构指针类型定义为 llink，可用于链表的头指针
							//后续创建的链表包含头节点(不包含链表的具体内容)和首元结点（链表的第一个数据结点）
			   

void insert_list(llink *,int);
void display_list(llink);
llink insert_list_recursive(llink,int);
llink search_list(llink,int);
int list_length(llink);

#endif
