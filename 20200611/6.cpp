#include <iostream> 
#include <vector>
#include <set>


// 并查集: https://blog.csdn.net/u014376961/article/details/77296433
/**
 * @brief 认老乡
 * 
 * @return int 
 */

int findRoot(int x, std::vector<int> &root)
{
    if(x==root[x])
        return root[x];
    
    return findRoot( root[x], root);
}

void mergeRoot(int aRoot, int bRoot,  std::vector<int> &root)
{
    if(aRoot==bRoot)
        return;
    
    root[aRoot] = bRoot;
}

int main()
{
    int N,M;

    while(std::cin >> N >>M)
    {
        if(N==0 && M==0)
        return 0;

        std::vector<int> root;
        for(int i=0;i<N;i++)
            root.push_back(i);

        
        

        for(int i=0;i<M;i++)
        {
            int a,b;
            std::cin >> a >> b;

            int aRoot = findRoot(a-1, root);
            int bRoot = findRoot(b-1, root);
            mergeRoot(aRoot, bRoot, root);
        }

        int sameCountry=0;
        int root1 = findRoot(0, root);
        for(int i=1;i<N;i++)
        {
            if(findRoot(i, root)==root1)
                sameCountry++;
        }

        std::cout << sameCountry << std::endl; 
    }
    return 0;

}