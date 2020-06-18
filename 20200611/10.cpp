#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * @brief 商队运输
 * 
 * @return int 
 */
int main()
{
	int n;
	while (cin >> n)
	{
		vector<vector<int>> m(n);//初始化元素个数
		for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			m[i].push_back(9999999);//n*n的矩阵
		for (int i = 0; i < n; ++i)
			m[i][i] = 0;//矩阵对角线元素置为0
		int a, b, c;
		for (int i = 0; i < n - 1; ++i)
		{
			cin >> a >> b >> c;
			m[b - 1][a - 1] = m[a - 1][b - 1] = c;//连等
		}
		for (int k = 0; k < n; ++k) //中间节点
		{
			for (int i = 0; i < n; ++i)//起点
			{
				for (int j = 0; j < n; ++j)//终点
				{
					if (m[i][k] + m[k][j] < m[i][j])
						m[i][j] = m[i][k] + m[k][j];  //将矩阵中的值更新为最长的到达路程
				}
			}
		}
		int res = -1;
		for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			res = max(res, m[i][j]);
		cout << 10 * res + (1 + res)*res / 2 << endl;
	}
	return 0;
}