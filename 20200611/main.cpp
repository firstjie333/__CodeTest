#include <iostream>
#include <vector>


/**
 * @brief 上台阶(动态规划，注意初始条件)
 * 
 * @param num 
 * @return int 
 */

int getMethods(int &num)
{
    int dp[num+1];

    dp[0]=0;
    dp[1]=0;
    dp[2]=1;
    dp[3]=2;

    for(int i=4; i<=num;i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[num];
}


int main()
{
    int N;
    std::cin >> N;

    for(size_t i=0;i <N;i++)
    {
        int num;
        std::cin >> num;

        std::cout << getMethods(num) << std::endl;

    }

}