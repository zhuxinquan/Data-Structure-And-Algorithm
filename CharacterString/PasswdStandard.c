/*************************************************************************
	> File Name: PasswdStandard.c
	> Author: zhuxinquan
	> Mail: zhuxinquan61@xiyoulinux.org
	> Created Time: 2017年02月27日 星期一 09时44分50秒
 ************************************************************************/
/*
 * 密码需要满足如下要求：
 * 1.长度大于等于8且小于等于16位
 * 2.至少包含大写字母、小写字母、特殊字符和数字中的三种
 * 3.密码中不能包含连续相同的字符串，如cc，cvtecvte等都是不符合规范的
 */

#include<stdio.h>
#include<stdlib.h>

/*
 * 判断输入密码的长度和密码中字符的种类是否符合规范
 */
int countTypeAndLengthOk(char * s){
    int A_Z = 0;
    int a_z = 0;
    int number = 0;
    int specialCharacter = 0;
    int i = 0;
    int length = 0;
    //统计密码长度和使用字符的种类
    while(s[i] != '\0'){
        length++;
        if(s[i] >= 'A' && s[i] <= 'Z'){
            A_Z = 1;
        }else if(s[i] >= 'a' && s[i] <= 'z'){
            a_z = 1;
        }else if(s[i] >= '0' && s[i] <= '9'){
            number = 1;
        }else{
            specialCharacter = 1;
        }
        i++;
    }
    if(length >= 8 && length <= 16 && (A_Z + a_z + number + specialCharacter) >= 3){
        return 1;
    }
    return 0;
}

/**
 * 判断是否包含连续相同的子串
 */
int noContainContinueString(char * s){
    int left, right, tempLeft, tempRight;
    for(left = 0; s[left] != '\0'; left++){
        for(right = left + 1; s[right] != '\0'; right++){
            if(s[left] == s[right] && (right - left) == 1){
                return 0;
            }else if(s[left] == s[right]){
                tempLeft = left;
                tempRight = right;
                while(s[tempRight] != '\0' && s[tempLeft] == s[tempRight]){
                    if(right - tempLeft == 1){
                        return 0;
                    }
                    tempLeft++;
                    tempRight++;
                }
            }
        }
    }
    return 1;
}

int isStandardPasswd(char * s){
    if(!countTypeAndLengthOk(s) || !noContainContinueString(s)){
        return 0;
    }
    return 1;
}

int main(int argc, char * argv[]){
    if(argc < 2){
        printf("Usage: %s \'PasswdString\' \n", argv[0]);
        exit(EXIT_FAILURE);
    }
    int boolean = isStandardPasswd(argv[1]);
    if(boolean){
        printf("Is Standard Passwd!\n");
    }else{
        printf("Not Standard Passwd!\n");
    }
}
