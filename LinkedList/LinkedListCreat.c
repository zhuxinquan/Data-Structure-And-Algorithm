/*************************************************************************
	> File Name: LinkedListcreate.c
	> Author: zhuxinquan
	> Mail: zhuxinquan61@xiyoulinux.org
	> createed Time: 2017年02月28日 星期二 08时47分32秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode{
    int value;
    struct ListNode * next;
}Node;

Node * create(int number){
    Node * pHead = NULL;
    Node * pNode = pHead;
    if(number <= 0){
        return pHead;
    }
    while(number){
        Node * tempNode = (Node *)malloc(sizeof(Node));
        tempNode->value = number;
        tempNode->next = NULL;
        number--;
        if(pNode == NULL){
            pHead = tempNode;
            pNode = pHead;
            continue;
        }
        pNode->next = tempNode;
        pNode = pNode->next;
    }
    return pHead;
}

void traverse(Node * pHead){
    Node * pNode = pHead;
    while(pNode){
        printf("%d\t\n", pNode->value);
        pNode = pNode->next;
    }
}
/*
int main(int argc, char * argv){
   traverse(create(6)); 
}*/
