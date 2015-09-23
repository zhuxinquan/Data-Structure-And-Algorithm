/*************************************************************************
	> File Name: 一元多项式运算器.c
	> Author: zhuxinquan
	> Mail: zhuxinquan61@gmail.com
	> Created Time: 2015年09月20日 星期日 22时47分56秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct Polynomial{
    float coef;         //系数
    int   expn;         //指数
    struct Polynomial * next;
}polyn;

polyn * Creatpolyn()                //创建多项式
{
    polyn * head, * tail, *s;
    float c;
    int e;                           //c == coefficient, e == exponent
    tail = head = (polyn *)malloc(sizeof(polyn));
    printf("input c, e (End: c = 0, Separated by space):\n");
    scanf("%f,%d", &c, &e);
    while(c != 0)
    {
        s = (polyn *)malloc(sizeof(polyn));
        s->coef = c;
        s->expn = e;
        tail->next = s;
        tail = s;
        scanf("%f,%d", &c, &e);
    }
    tail->next = NULL;
    return head;
}

void print_polyn(polyn * p)             //输出多项式
{
    polyn * q = p->next;
    int flag = 1;
    if(!q)
    {
        putchar('0');
        printf("\n");
        return;
    }
    while(q)
    {
        if(q->coef > 0 && flag != 1)
        {
            putchar('+');
        }
        if(q->coef != 1 && q->coef != -1)
        {
            printf("%g", q->coef);
            if(q->expn == 1)
            {
                putchar('X');
            }
            else if(q->expn)
            {
                printf("X^%d", q->expn);
            }
        }
        else
        {
            if(q->coef == 1)
            {
                if(!q->expn) putchar('1');
                else if(q->expn == 1) putchar('X');
                else printf("X^%d", q->expn);
            }
            if(q->coef == -1)
            {
                if(!q->expn) printf("-1");
                else if(q->expn == 1) printf("X");
                else printf("X^%d", q->expn);
            }
        }
        q = q->next;
        flag++;
    }
    printf("\n");
}

polyn * add_polyn(polyn * pa, polyn * pb)           //两个多项式相加
{
    polyn * qa = pa->next;
    polyn * qb = pb->next;
    polyn * headc, *pc, *qc;
    pc = (polyn *)malloc(sizeof(polyn));
    pc->next = NULL;                            //pc用作headc的尾指针
    headc = pc;
    while(qa != NULL &&  qb != NULL)
    {
        qc = (polyn *)malloc(sizeof(polyn));
        if(qa->expn < qb->expn)
        {
            qc->coef = qa->coef;
            qc->expn = qa->expn;
            qa = qa->next;
        }
        else if(qa->expn == qb->expn)
        {
            qc->coef = qa->coef + qb->coef;
            qc->expn = qa->expn;
            qa = qa->next;
            qb = qb->next;
        }
        else
        {
            qc->coef = qb->coef;
            qc->expn = qb->expn;
            qb = qb->next;
        }
        
        if(qc->coef != 0)
        {
            qc->next = NULL;                        //qc->next = pc->next
            pc->next = qc;
            pc = qc;
        }
        else    free(qc);
    }
    while(qa != NULL)                               //qa还有剩余项
    {
        qc = (polyn *)malloc(sizeof(polyn));
        qc->coef = qa->coef;
        qc->expn = qa->expn;
        qa = qa->next;
        qc->next = NULL;
        pc->next = qc;
        pc = qc;
    }
    while(qb != NULL)                               //qb还有剩余项
    {
        qc = (polyn *)malloc(sizeof(polyn));
        qc->coef = qb->coef;
        qc->expn = qb->expn;
        qb = qb->next;
        qc->next = NULL;
        pc->next = qc;
        pc = qc;
    }
    return headc;
}

polyn * subtraction_polyn(polyn * pa, polyn * pb)   //多项式相减
{
    polyn * head = pb;
    polyn * p = pb->next;
    polyn * pd;                                       //pd保存相减得到的新的结果
    while(p)
    {
        p->coef *= -1;                              //转换为和负数相加
        p = p->next;
    }
    pd = add_polyn(pa, head);
    for(p = head->next; p; p = p->next)             //还原
    {
        p->coef *= -1;
    }
    return pd;
}

void sort_link(polyn * head)
{
    int e, te;
    int coef;
    polyn * p, * q;
    for(p = head->next; ; p = p->next)
    {
        e = p->expn;
        for(q = p->next; ; q = q->next)
        {
            if(q->expn < e)
            {
                e = q->expn;
                te = p->expn;
                coef = p->coef;
                p->expn = q->expn;
                p->coef = q->coef;
                q->coef = coef;
                q->expn = te;
            }
            if(!q->next){
                break;
            }
       }
        if(p->next->next == NULL){
            break;
        }
    }
}

int main(void)
{
    polyn * pa, *pb, *padd, *psub;
    printf("please input polynomial pa(like 1,1 and 0,0 is over ):\n");
    pa = Creatpolyn();
    printf("please input polynomial pb(like 1,1 and 0,0 is over ):\n");
    pb = Creatpolyn();
    sort_link(pa);
    sort_link(pb);
    printf("pa=");
    print_polyn(pa);
    printf("pb=");
    print_polyn(pb);
    padd = add_polyn(pa, pb);
    psub = subtraction_polyn(pa, pb);
    printf("pa+pb=");
    print_polyn(padd);
    printf("pa-pb=");
    print_polyn(psub);
}
