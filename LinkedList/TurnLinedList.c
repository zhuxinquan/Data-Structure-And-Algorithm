/*************************************************************************
	> File Name: reverseLinedList.c
	> Author: zhuxinquan
	> Mail: zhuxinquan61@xiyoulinux.org
	> Created Time: 2017年02月28日 星期二 09时08分40秒
 ************************************************************************/

#include<stdio.h>
#include"LinkedListCreat.c"

Node * reverseLinedList(Node * pHead){
    Node * pReverseHead = NULL;
    Node * pNode = pHead;
    Node * pPrev = NULL;
    while(pNode != NULL){
        Node * pNext = pNode->next;
        if(pNext == NULL){
            pReverseHead = pNode;
        }
        pNode->next = pPrev;
        pPrev = pNode;
        pNode = pNext;
    }
    return pReverseHead;
}

Node * recursionReverseList(Node * pHead){
    if(pHead == NULL || pHead->next == NULL){
        return pHead;
    }
    Node * nextNode = pHead->next;
    pHead->next = NULL;
    Node * pNewHead = recursionReverseList(nextNode);
    nextNode->next = pHead;
    return pNewHead;
}

int main(int argc, char * argv[]){
    Node * pHead = create(6);
    traverse(pHead);
    //Node * pNewHead = reverseLinedList(pHead);
    Node * pNewHead = recursionReverseList(pHead);
    traverse(pNewHead);
}
