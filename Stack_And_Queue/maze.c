/*************************************************************************
	> File Name: maze.c
	> Author: zhuxinquan
	> Mail: zhuxinquan61@gmail.com
	> Created Time: 2015年09月29日 星期二 15时41分46秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define maxsize 100

int row = 0;                        //目的地行坐标
int line = 0;                       //目的地列坐标

typedef struct position{            //迷宫中的位置坐标
    int x;                          //行坐标
    int y;                          //列坐标
}Position;

typedef struct node{
    Position    seat;               //当前位置在迷宫中的坐标
    int         direction;
    /*定义当前位置走向下一个位置的方向
     *1,2,3,4分别对应上、右、下、左的位
     *置,这样做方便位置变换，只需要加1
    */
    struct node * next;
}LStack;

void InitStack(LStack * Stacktop)
{
    Stacktop = (LStack *)malloc(sizeof(LStack));
    Stacktop->next = NULL;
}

int Empty(LStack * Stacktop)
{
    if(Stacktop->next == NULL)
        return 1;
    else
        return 0;

}

int push(LStack * Stacktop, LStack * p)                 //出栈操作,成功返回0,出错返回-1,p为要接受栈顶值的内存空间
{
    if(Empty(Stacktop))
    {
        return -1;
    }
    else
    {
        p = (LStack *)malloc(sizeof(LStack));
        p = Stacktop->next;
        Stacktop = Stacktop->next;
        return 0;
    }
}

int pop(LStack * Stacktop, int x, int y, int direction)     //入栈操作，x, y, direction分别为入栈元素的位置坐标和方向
{
    LStack * p;
    p = (LStack *)malloc(sizeof(LStack));
    p->seat.x = x;
    p->seat.y = y;
    p->direction = direction;
    p->next = Stacktop->next;
    Stacktop->next = p;
    return 0;
}

int Gettop(LStack *Stacktop)

void InitMaze_static_array(int maze[][maxsize])
{
    int i, j;
    for(i = 0; i < line + 2; i++)
    {
        maze[0][i] = 1;
    }
    for(i = 0; i < line + 2; i++)
    {
        maze[row + 1][i] = 1;
    }
    for(i = 0; i < row + 2; i++)
    {
        maze[i][0] = 1;
    }
    for(i = 0; i < row + 2; i++)
    {
        maze[i][line + 1] = 1;
    }
    printf("请输入迷宫1代表障碍，0代表通路，每次输入一行用空格隔开：\n");
    for(i = 1; i <= row; i++) 
    {
        for(j = 1; j <= line; j++)
        {
            scanf("%d", &maze[i][j]);
        }
    }
}

void print_maze(int maze[][maxsize])
{
    int i, j;
    for(i = 1; i <= row; i++)
    {
        for(j = 1; j <= line; j++)
        {
            printf("%3d", maze[i][j]);
        }
        printf("\n");
    }
}

/*void InitMaze(int *** maze)                             //初始化迷宫，申请内存空间并将迷宫围墙全部填充为障碍
{
    int i, j;
    *maze = (int **)malloc(sizeof(int) * (row + 2));
    for(i = 0; i < row + 2; i++)
    {
        (*maze)[i] = (int *)malloc(sizeof(int) * (line + 2));
    }
    for(i = 0; i < line + 2; i++)                       //将迷宫的四周用1填充，代表障碍
    {
        *maze[0][i] = 1;
    }
    for(i = 0; i < line + 2; i++)
    {
        *(maze[line + 1][i]) = 1;
    }
    for(i = 0; i < row + 2; i++)
    {
        *(maze[i][0]) = 1;
    }
    for(i = 0; i < row + 2; i++)
    {
        *(maze[i][line + 1]) = 1;
    }
    printf("请输入迷宫1代表障碍，0代表通路，每次输入一行用空格隔开：\n");
    for(i = 1; i <= row; i++) 
    {
        for(j = 1; j <= line; j++)
        {
            scanf("%d", maze[i][j]);
        }
    }
}*/

void path(int maze[][maxsize], LStack * Stacktop, int start_x, int start_y, int end_x, int end_y)
{
    int cx = start_x, cy = start_y;                                         //cx, cy代表当前位置
    int direction = 1;
    while(cx != end_x || cy != end_y)
    {
        if(maze[cx - 1][cy] == 0)
        {
        }
    }
}

int main(void)
{
    int start_x, start_y, end_x, end_y;
    LStack * Stacktop;                                  //栈顶
    int maze[maxsize][maxsize];
    printf("input row and line(eg: 6,8):");
    scanf("%d,%d", &row, &line);
    InitStack(Stacktop);                                //初始化栈
    InitMaze_static_array(maze);                                    //初始化迷宫
    printf("输入的迷宫如下：\n");
    print_maze(maze);
    while(1)
    {
        printf("请输入起始位置坐标(eg:  (1,1) ) :\n");
        Scanf("(%d,%d)", &start_x, &start_y);
        if(start_x >= 1 && start_x <= row && start_y >= 1 && start_y <= line)
            break;
        else
            printf("输入错误！\n");
    }
    while(1)
    {
        printf("请输入目的位置坐标(eg:  (9,8) ) :\n");
        scanf("(%d,%d)", &end_x, &end_y);
        if(end_x <= row  end_x >= 1 && end_y >= 1 && end_y <= line)
            break;
        else
            printf("输入错误！\n");
    }
    path(maze, Stacktop, start_x, start_y, end_x, end_y);
}
