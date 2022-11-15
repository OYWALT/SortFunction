#include<iostream>
#include<vector>
using namespace std;
/*插入排序*/
class insertSort {
private:
	vector<int> nums;
public:
	insertSort(vector<int> temp) :nums(temp) {};
	void sort();
	void makRoom(int index, int num);
	void show();
};

void insertSort::sort()
{
	//从第二个元素开始，第一个元素就认为是已经排好的数组
	for (int i = 1; i < nums.size(); i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			//寻找排列好的数组中从大到小的第一个小于num[i]的元素nums[j]，将nums[i]插入到j+1位置
			if (nums[i] >= nums[j])
			{
				makRoom(j + 1, i);
				break;//【注意！！！】别忘了这个break;
			}
			//当nums[i]小于所有排列好的数组元素时，将其插入位置0
			else if (j == 0)
				makRoom(0, i);
		}
	}
}
//将索引为num的元素插入到索引index处
void insertSort::makRoom(int index, int num)
{
	int temp = nums[num];
	for (int i = num; i >= index+1; i--)
	{
		nums[i] = nums[i - 1];
	}
	nums[index] = temp;
}
//打印排序后的数组
void insertSort::show()
{
	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << " ";
	cout << endl;
}

//待排序数组
//vector<int> temp = { 0, 14, 9, 6, 13, 21, 7, 16,  33, 4, 5, 6, 10 };
//int main()
//{
//	insertSort a(temp);
//	a.show();
//	a.sort();
//	a.show();
//
//
//	cout << "finsh" << endl;
//	cin.get();
//
//	return 1;
//}