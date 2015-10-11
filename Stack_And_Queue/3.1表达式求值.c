/*************************************************************************
	> File Name: 3.1表达式求值.c
	> Author: zhuxinquan
	> Mail: zhuxinquan61@gmail.com
	> Created Time: 2015年09月22日 星期二 16时04分13秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define FALSE 0
#define TRUE 1

typedef struct stacknode{
    float data;
    struct stacknode * next;
}StackType;

float get_stack(StackType *, float *);             //取栈顶元素
float pop_stack(StackType *, float *);             //出栈
float Push_stack(StackType *, float);       //入栈
char compare(char, char);               //比较运算符优先级
float Operation(float , float, float );        //实际运算函数

StackType * Init_stack()
{
    StackType * top;
    top = (StackType *)malloc(sizeof(StackType));
    top->next = NULL;
    return top;
}

float Push_stack(StackType * top, float x)
{
    StackType * p;
    p = (StackType *)malloc(sizeof(StackType));
    if(p == NULL){
        return FALSE;
    }
    p->data = x;
    p->next = top->next;
    top->next = p;
    return TRUE;
}

float pop_stack(StackType * top, float * x)
{
    StackType * p;
    if(top->next == NULL){
        return -1;
    }
    p = top->next;
    top->next = p->next;
    *x = p->data;
    free(p);
    return 0;
}

float getnext(float * n)                        //该函数返回0为数字，返回1为运算符
{
    char c;
    *n = 0;
    while((c = getchar()) == ' ');          //跳过空格
    if(!isdigit(c)){                        //判断是否是数字
        *n = c;
        return 1;
    }
    do{
        *n = *n * 10 + (c - '0');           //使用循环获得连续的数字，乘10进位
        c = getchar();
    }while(isdigit(c));
    ungetc(c, stdin);                       //读到一个运算符，将运算符写回输入缓存
    return 0;
}

/*对于连续出现的运算符进行比较优先级
 * 结果有> < =，可以得到+-×/之间的优
 * 先级，加减乘除的优先级都低于'('，
 * 但是都高于')',并且根据从左到右运算
 * 可知当运算符相同时，第一个大于第二
 * 个,0表示不存在
 * */

char compare(char a, char b)
{
    int i, j;
    char pre[7][7] ={                       //定义运算符之间的优先级
        {'>','>','<','<','<','>','>'},
        {'>','>','<','<','<','>','>'},
        {'>','>','>','>','<','>','>'},
        {'>','>','>','>','<','>','>'},
        {'<','<','<','<','<','=','0'},
        {'>','>','>','>','0','>','>'},
        {'<','<','<','<','<','0','='},
    };
    switch(a){
        case '+': i = 0; break;
        case '-': i = 1; break;
        case '*': i = 2; break;
        case '/': i = 3; break;
        case '(': i = 4; break;
        case ')': i = 5; break;
        case '#': i = 6; break;
    }
    switch(b){
        case '+': j = 0; break;
        case '-': j = 1; break;
        case '*': j = 2; break;
        case '/': j = 3; break;
        case '(': j = 4; break;
        case ')': j = 5; break;
        case '#': j = 6; break;
        case  10: printf("表达式要以#结尾！！！\n");exit(1);
    }
    return pre[i][j];
}

float Operation(float a, float operate, float b)           //实际操作两个数a,b的运算
{
    float i, j, result;
    i = (float)a;
    j = (float)b;

    switch((int)operate){
        case '+': result = a + b; break;
        case '-': result = a - b; break;
        case '*': result = a * b; break;
        case '/': result = a / b; break;
    }
    return result;
}

float EvaluateExpression()
{
    float n;
    float c;                                  //存储输入缓存中的字符或数字
    float flag;                               //从输入缓存中取操作符的返回值，0表示取出数字，1表示取出运算符
    float x;                                  //取栈顶操作符
    float operate;                            //存储要计算的操作符
    float a, b;                               //存取要计算的操作数
    StackType * top_oprd, * top_optr;       //top_oprd为操作数栈，top_optr为运算符栈
    
    char op[] = "+-*/()#";

    top_oprd = Init_stack();
    top_optr = Init_stack();
    
    Push_stack(top_optr, '#');
    flag = getnext(&c);
    
    get_stack(top_optr, &x);
    while((float)c != '#' || (float)x != '#')         //表达式的起始位置都是'#'，如果读取的新的字符和运算符都是'#'说明运算已经结束
    {
        if(flag == 0)                   //返回数字
        {
            Push_stack(top_oprd, c);
            flag = getnext(&c);
        }
        else                            //返回运算符
        {
            get_stack(top_optr, &x);        //取栈顶运算符
            switch(compare((float)x, (float)c))
            {
                case '<':               //栈顶操作符运算优先级低
                Push_stack(top_optr, c);
                flag = getnext(&c);
                break;
                case '>':               //栈顶运算符优先级高,先退出两个数据进行运算，然后将运算结果在存入数据栈
                pop_stack(top_optr, &operate);
                pop_stack(top_oprd, &a);
                pop_stack(top_oprd, &b);
                Push_stack(top_oprd, Operation(b, operate, a));         //由于压栈的顺序，则应当是先出的操作数在后
                break;
                case '=':               //操作符'('')'紧挨，则直接去除括号
                pop_stack(top_optr, &operate);
                flag = getnext(&c);
                break;
                case '0':               //比较结果得出表达式错误
                printf("input error!\n");
                exit(1);
            }
        }
        get_stack(top_optr, &x);
    }
    get_stack(top_oprd, &c);
    return c;

}

float get_stack(StackType * top, float * x)
{
    if(top->next == NULL)
    {
        return -1;
    }
    *x = top->next->data;
    return 0;
}

float main(void)
{
    float c;
    printf("please input expression (end in #):");
    c = EvaluateExpression();
    printf("result = %f\n", c);
    getchar();
}
