#include<stdio.h>
 #include<stdlib.h>
 #include"list.h"
 
 int
 main(int argc,char* argv[])
 {
     llink listhead=listcreat();
 
     llink headpointer,tailpointer; //指向首元结点和尾结点的指针
     headpointer=tailpointer=listhead;
     if(listhead)
         printf("success\n");
     else
         printf("failed\n");
     return 0;
 }
                        