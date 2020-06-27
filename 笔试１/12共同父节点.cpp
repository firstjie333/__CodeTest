#include <iostream> 
#include <string>  
#include <cstring>

using namespace std;
/**************************************************************************************************
    Project 4

    给定一个深度小于6层的二叉树，它的每一个非空节点的数值都是整数，且小于16、大于等于0,这样每个节点可以
    表示为一个十六进制字符数组，例如：
            3
          /   \
         5     1
       /  \     \
      7    9     11 
    层数和节点序号都是从0开始计数，也就是第一层为0层，每层第一个节点序号为0.
    这个树中，11这个节点可以用 '23b' 表示，也就是它在第3层的第4个节点，数值是0xb.   
    现给定一系列以此法表示的节点，它们一起组成一个树，并指定其中的任意两个节点，请找出它们最近的共同祖先。
    举例：在这个树中，'207'和'219'的最近共同祖先为'105'，输入'207'和'219'，返回'105'即可。
    '105'和'23b'的最近共同祖先为'003'.
    函数 LCA():
    Input: 
        char (*tree)[3]: 十六进制含义的二维字符数组，为N*3的矩阵，每一行的三个数按顺序依照上述定义；
        int node_size: 树的节点个数；
        char a[3]: 要找最近共同祖先的第一个节点；
        char b[3]: 要找最近共同祖先的第二个节点；
        char lca[3]: 找到的共同祖先节点填充到这个字符数组中。
    return:
        bool: 返回是否成功找到最近共同祖先，true为找到，false为没找到。
    注意：LCA是 lowest common ancestor的缩写。所有节点信息以及需要寻找最近共同祖先的两个节点信息均在main函数中给定。
*/


void updateNode(char (*tree)[3], int node_size, char a[3] )
{
    // update level and index 
    a[0] = (a[0]-'0')-1 + '0';
    a[1] = (a[1]-'0')/2 + '0';

    // update value
    for(int i=0; i < node_size; i++)
    {
        if(tree[i][0]==a[0] && tree[i][1]==a[1])
            a[2]=tree[i][2];
    }
}
bool LCA(char (*tree)[3], int node_size, char a[3], char b[3], char lca[3])
{   
    bool find = false ;
    while (!find && (a[0]-'0')>=0)
    { 
        if(strncmp( a,b,1)==0 && strncmp( a,b,2)!=0)
        {
            updateNode(tree, node_size, a);
            updateNode(tree, node_size, b);
        }
        else if( strncmp( a,b,1)>0)
        {
            updateNode(tree, node_size, a);
        }
        else if(strncmp( a,b,1)<0)
        {
            updateNode(tree, node_size, b);
        }
        
        find = (strcmp(a,b)==0);
    }
    
    if(find)
    {
        lca[0]=a[0];
        lca[1]=a[1];
        lca[2]=a[2];
    }

    return find; 
}

int main()
{
    cout << "==========Project4=================" << endl;
    char tree[][3] = {  '2','0','7',
                        '1','0','5',
                        '3','2','c',
                        '2','1','9',
                        '0','0','3',
                        '1','1','1',
                        '2','3','b',
                        '3','6','4',
                        '3','7','f'};
    char lca[3] = {0};
    char a[3] = {'2','1','9'};
    char b[3] = {'3','7','f'};
    bool found = LCA(tree, 9, a, b, lca);
    if(!found)
        cout << "no lca found." << endl;
    else
        cout << "The lca of a and b is \'" << lca[0] << lca[1] << lca[2] << '\'' << endl;
    cout << endl;
    cout << "==========Project4=================" << endl;
}