#include<iostream>
#include<vector>
using namespace std;

/*翻转数组
*/

 
/*
	1、遍历给定的这组数据；
	2、定义2个变量prev和last分别用来表示第一次出现降序位置和第一次出现升序的位置；
	3、保证从prev到last的值为降序的
	4、判断prev-1位置的值和last+1位置的值，使得旋转后可以成为升序；
*/
bool getResult(vector<int> &data){
	int prev, last;
	prev = last = -1;
	int length = data.size();
	//判断数据的有效性
	if (length == 0 || length == 1){
		return false;
	}
	else{
		//1、先遍历，找出prev以及last的位置
		for (int i = 0; i < length - 1; i++){
			if (data[i + 1] >= data[i] && prev == -1){
				continue;
			}
			else if (data[i + 1] < data[i] && prev == -1){
				prev = i;   //prev>-1
				continue;
			}
 
			if (prev>-1 && data[i] >= data[i + 1]){
				continue;
			}
			else if (prev > -1 && data[i] < data[i + 1] && last==-1){
				last = i;
				continue;
			}
			//根据以上，就可以找到第一次升和降的位置；
 
			//如果再出现降序，那么直接返回false；
			if (prev>-1 && last > -1 && data[i] > data[i + 1]){
				return false;
			}
		}
}
 
 
	//找到2个值以后，判断反转后是否为升序序列做出判断；
	//如果初始数列为升序；
	if (prev == -1){
		return false;
	}
	//如果初始为降序，那么last=-1；
	if (prev > -1 && last == -1){
		return true;
	}
	 if(prev==0 ){
		if (data[prev] <= data[last + 1]){
			return true;
		}
	}else if (prev > 0){
		 if (data[prev - 1] <= data[last] && data[prev] <= data[last + 1]){
			 return true;
		 }	
	 }
		return false;
}
int main(){
	int n;
	cin >> n;
	vector<int> vec;
	for (int i = 0; i < n;i++)
	{
		int temp;
		cin >> temp;
		vec.push_back(temp);
	}
	bool result = getResult(vec);
	if (result){
		cout << "yes" << endl;
	}
	else{
		cout << "no" << endl;
	}
	return 0;

}