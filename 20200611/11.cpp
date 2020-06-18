#include <iostream>


/**************************************************************************************************
    Project 2

    假设一只猫一天可能吃1～3只老鼠，编写程序求这只猫在t天内吃掉n只老鼠一共有多少种吃法？
    函数 CountRat():
    Input:
        int t: 时间t天
        int n: 老鼠数量
    return:
        int: 不同吃法总数
*/

int CountRat(int t, int n)
{
    //! 动态规划问题
    // t----day, n----mouse 
    int dp[t+1][n+1];

    for(size_t i=0;i<=t;i++)
        for(size_t j=0;j<=n;j++)
            dp[i][j]=0;

    if(t>n)
        return 0;
    if(t==n)
        return 1;

    dp[1][0]=0;
    dp[1][1]=dp[1][2]=dp[1][3]=1;
    
    
    for(auto day=2; day<=t; day++)
    {
        for(auto mouse=0 ; mouse<=n && mouse<= 3*t; mouse++)
        {
            if(mouse < day)   dp[day][mouse]=0;
            if(mouse == day)  dp[day][mouse]=1;
            else
                dp[day][mouse]= dp[day-1][mouse-1] + dp[day-1][mouse-2] + dp[day-1][mouse-3];
        }
    }

    return dp[t][n];
}


int main()
{
    int t,n;
    while(std::cin>>t>>n)
    {
        std::cout<< CountRat(t,n) << std::endl;
    }
}