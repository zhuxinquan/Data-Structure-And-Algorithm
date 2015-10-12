/*************************************************************************
	> File Name: magic.c
	> Author: zhuxinquan
	> Mail: zhuxinquan61@gmail.com
	> Created Time: 2015年10月11日 星期日 21时46分47秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>


typedef struct stacknode{
    char letter;
    struct stacknode * next;
}LetterNode;

typedef struct LetterNode{
    LetterNode * front;
    LetterNode * rear;
}LQueue;

LetterNode * Init_Stack()               //初始化栈
{
    LetterNode * s;
    s = (LetterNode *)malloc(sizeof(LetterNode));
    s->next = NULL;
    return s;
}

int push_stack(LetterNode * stack_top, char letter)     //入栈操作
{
    LetterNode * p;
    p = (LetterNode *)malloc(sizeof(LetterNode));
    if(p == NULL){
        return -1;
    }
    p->letter = letter;
    p->next = stack_top->next;
    stack_top->next = p;
    return 0;
}

int Stack_Is_Empty(LetterNode * stacktop)               //判断栈是否为空
{
    if(stacktop->next == NULL){
        return 1;
    }else{
        return 0;
    }
}

void pop_stack(LetterNode * stack_top, char * letter)   //出栈
{
    LetterNode * del;
    *letter = stack_top->next->letter;
    del = stack_top->next;
    stack_top->next = del->next;
    free(del);
}

LQueue * Init_queue()                                   //初始化队列
{
    LQueue * L;
    LetterNode * s;
    L = (LQueue *)malloc(sizeof(LQueue));
    s = (LetterNode *)malloc(sizeof(LetterNode));
    s->next = NULL;
    L->front = s;
    L->rear = s;
    return L;
}

int in_queue(LQueue * L, char letter)                   //入队
{
    LetterNode * p;
    p = (LetterNode *)malloc(sizeof(LetterNode));
    if(p == NULL){
        return -1;
    }
    p->letter = letter;
    p->next = NULL;
    L->rear->next = p;
    L->rear = p;
    return 0;
}

int Queue_Is_Empty(LQueue * L)                          //判断队列是否为空
{
    if(L->front->next == NULL){
        L->rear = L->front;
        return 1;
    }else{
        return 0;
    }
}

int out_queue(LQueue * L, char * letter)                //出队
{
    LetterNode * del;
    if(Queue_Is_Empty(L)){
        return -1;
    }
    *letter = L->front->next->letter;
    del = L->front->next;
    L->front->next = del->next;
    free(del);
    return 0;
}

void magic_expalin(char str[])
{
    char * p = str;
    char letter, letter1;
    LQueue * queue, *queue1;
    LetterNode * stack_top1, *stack_top2, *stack_top3;
    queue = Init_queue();
    queue1 = Init_queue();
    stack_top1 = Init_Stack();
    stack_top2 = Init_Stack();
    stack_top3 = Init_Stack();
    while(*p != 0)
    {
        push_stack(stack_top1, *p);
        p++;
    }
    while(!Stack_Is_Empty(stack_top1))
    {
        pop_stack(stack_top1, &letter);
        if(letter == 40)
        {
            pop_stack(stack_top2, &letter1);
            while(1)
            {
                pop_stack(stack_top2, &letter);
                if(letter == 41){
                    break;
                }
                push_stack(stack_top3, letter1);
                push_stack(stack_top3, letter);
            }
            push_stack(stack_top3, letter1);
            while(!Stack_Is_Empty(stack_top3))
            {
                pop_stack(stack_top3, &letter);
                push_stack(stack_top1, letter);
            }
        }
        else
        {
            push_stack(stack_top2, letter);
        }
    }
    while(!Stack_Is_Empty(stack_top2))
    {
        pop_stack(stack_top2, &letter);
        in_queue(queue, letter);
    }
    while(!Queue_Is_Empty(queue))
    {
        out_queue(queue, &letter);
        if(letter >= 97 && letter <= 122){
            in_queue(queue1, letter);
        }else if(letter == 'A'){
            in_queue(queue1, 's');
            in_queue(queue1, 'a');
            in_queue(queue1, 'e');
        }else if(letter == 'B'){
            in_queue(queue1, 't');
            in_queue(queue1, 'A');
            in_queue(queue1, 'd');
            in_queue(queue1, 'A');
        }
    }
    while(!Queue_Is_Empty(queue1))
    {
        out_queue(queue1, &letter);
        if(letter >= 97 && letter <= 122){
            in_queue(queue, letter);
        }else if(letter == 'A'){
            in_queue(queue, 's');
            in_queue(queue, 'a');
            in_queue(queue, 'e');
        }else if(letter == 'B'){
            in_queue(queue, 't');
            in_queue(queue, 'A');
            in_queue(queue, 'd');
            in_queue(queue, 'A');
        }
    }
    /*while(!Queue_Is_Empty(queue))
    {
        out_queue(queue, &letter);
        printf("%c", letter);
    }
    printf("\n");*/
    printf("\n");
    while(!Queue_Is_Empty(queue))
    {
        out_queue(queue, &letter);
        switch(letter)
        {
            case 't':printf("天");break;
            case 'd':printf("地");break;
            case 's':printf("上");break;
            case 'a':printf("一只");break;
            case 'e':printf("鹅");break;
            case 'z':printf("追");break;
            case 'g':printf("赶");break;
            case 'x':printf("下");break;
            case 'n':printf("蛋");break;
            case 'h':printf("恨");break;
        }
    }
    printf("\n");
}

int main(void)
{
    char str[100] = {0};
    printf("请输入{B, A, s, a, e, t, d, z, g, x, n, h}：");
    scanf("%s", str);
    magic_expalin(str);
    return 0;
}
