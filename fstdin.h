/*************************************************************************
	> File Name: fstdin.h
	> Author: zhuxinquan
	> Mail: zhuxinquan61@gmail.com
	> Created Time: 2015年12月09日 星期三 16时24分08秒
 ************************************************************************/

#ifndef _FSTDIN_H
#define _FSTDIN_H
void fstdin(){
    int c;
    do{
        c = fgetc(stdin);
    }while(c != '\n' && c != EOF);
}
#endif
