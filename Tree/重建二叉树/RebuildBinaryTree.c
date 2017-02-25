/*************************************************************************
	> File Name: RebuildBinaryTree.c
	> Author: zhuxinquan
	> Mail: zhuxinquan61@xiyoulinux.org
	> Created Time: 2017年02月25日 星期六 17时31分56秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

typedef struct BinaryTreeNode{
    int value;
    struct BinaryTreeNode * left;
    struct BinaryTreeNode * right;
}Node;

Node * Construct(int * preorder, int * inorder, int length);
Node * ConstructCore(int * startPreOrder, int * endPreOrder, int * startInorder, int * endInOrder);

int FindTreeDeep(Node * BT){  
    int deep=0;  
    if(BT){  
        int lchilddeep=FindTreeDeep(BT->left);  
        int rchilddeep=FindTreeDeep(BT->right);  
        deep=lchilddeep>=rchilddeep?lchilddeep+1:rchilddeep+1;  
    }  
    return deep;  
}  

void printBinaryTree(Node * root){
    if(root == NULL){
        return ;
    }
    printf("%d\n", root->value);
    if(root->left != NULL){
        printBinaryTree(root->left);
    }
    
    if(root->right != NULL){
        printBinaryTree(root->right);
    }
}

void Test(char* testName, int* preorder, int* inorder, int length)
{
    if(testName != NULL)
        printf("%s begins:\n", testName);

    printf("The preorder sequence is: ");
    for(int i = 0; i < length; ++ i)
        printf("%d ", preorder[i]);
    printf("\n");

    printf("The inorder sequence is: ");
    for(int i = 0; i < length; ++ i)
        printf("%d ", inorder[i]);
    printf("\n");

    Node* root = Construct(preorder, inorder, length);

    if(root != NULL){
       printf("deep:%d\n",FindTreeDeep(root));
    }

    printBinaryTree(root);
}

void Test1()
{
    int preorder[8] = {1, 2, 4, 7, 3, 5, 6, 8};
    int inorder[8] = {4, 7, 2, 1, 5, 3, 8, 6};

    Test("Test1", preorder, inorder, 8);
}

// 所有结点都没有右子结点
//            1
//           / 
//          2   
//         / 
//        3 
//       /
//      4
//     /
//    5
void Test2()
{
    int preorder[5] = {1, 2, 3, 4, 5};
    int inorder[5] = {5, 4, 3, 2, 1};

    Test("Test2", preorder, inorder, 5);
}

// 所有结点都没有左子结点
//            1
//             \
//              2   
//               \
//                3 
//                 \
//                  4
//                   \
//                    5
void Test3()
{
    int preorder[5] = {1, 2, 3, 4, 5};
    int inorder[5] = {1, 2, 3, 4, 5};

    Test("Test3", preorder, inorder, 5);
}

// 树中只有一个结点
void Test4()
{
    int preorder[1] = {1};
    int inorder[1] = {1};

    Test("Test4", preorder, inorder, 1);
}

// 完全二叉树
//              1
//           /     \
//          2       3  
//         / \     / \
//        4   5   6   7
void Test5()
{
    int preorder[7] = {1, 2, 4, 5, 3, 6, 7};
    int inorder[7] = {4, 2, 5, 1, 6, 3, 7};

    Test("Test5", preorder, inorder, 7);
}

// 输入空指针
void Test6()
{
    Test("Test6", NULL, NULL, 0);
}

// 输入的两个序列不匹配
void Test7()
{
    int preorder[7] = {1, 2, 4, 5, 3, 6, 7};
    int inorder[7] = {4, 2, 8, 1, 6, 3, 7};

    Test("Test7: for unmatched input", preorder, inorder, 7);
}


Node * Construct(int * preorder, int * inorder, int length){
    if(preorder == NULL || inorder == NULL || length <= 0)
        return NULL;

    return ConstructCore(preorder, preorder + length - 1,
        inorder, inorder + length - 1);    
}

Node * ConstructCore(int * startPreOrder, int * endPreOrder, int * startInorder, int * endInOrder){
    int rootValue = startPreOrder[0];
    Node * root = (Node *)malloc(sizeof(Node));
    root->value = rootValue;
    root->left = NULL;
    root->right = NULL;

    //只有一个节点，或者数据错误
    if(startPreOrder == endPreOrder){
        if(startInorder == endInOrder && *startPreOrder == * startInorder){
            return root;
        }else{
            perror("Invalid input!");
            exit(EXIT_FAILURE);
        }
    }

    //中序遍历中找根节点
    int * rootInorder = startInorder;
    while(rootInorder <= endInOrder && *rootInorder != rootValue){
        ++ rootInorder;
    }
    
    //在中序中检测数据数据是否合法
    if(rootInorder == endInOrder && *rootInorder != rootValue){
        perror("Invalid input!");
        exit(EXIT_FAILURE);
    }

    int leftLength = rootInorder - startInorder;
    int * leftPreOrderEnd = startPreOrder + leftLength;

    if(leftLength > 0){
        //构建左子树
        root->left = ConstructCore(startPreOrder + 1, leftPreOrderEnd, 
            startInorder, rootInorder - 1);
    }
    if(leftLength < endPreOrder - startPreOrder)
    {
        // 构建右子树
        root->right = ConstructCore(leftPreOrderEnd + 1, endPreOrder,
            rootInorder + 1, endInOrder);
    }

    return root;
}

int main(int argc, char * argv[]){

    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();

    return 0;
}
