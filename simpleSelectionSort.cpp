#include<iostream>
#include<vector>
using namespace std;

/*简单选择排序*/
class simpleSelectionSort {
private:
	vector<int> nums;
public:
	simpleSelectionSort(vector<int> temp) :nums(temp){};

	void sort();
	void show();
};
//每一次从未排序的部分中选取最小的元素，放到已排序部分最尾
//采用的是swap(已排序部分尾部+1，未排序部分中最小元素)的方式来放置
void simpleSelectionSort::sort()
{
	
	for (int i = 0; i < nums.size(); i++)
	{
		int Min = nums[i];
		int index = i;
		for (int j = i; j < nums.size(); j++)
		{
			if (Min > nums[j])
			{
				Min = nums[j];
				index = j;
			}	
		}
		//swap(已排序部分尾部 + 1，未排序部分中最小元素)
		swap(nums[i], nums[index]);
	}
}
//打印排序后的数组
void simpleSelectionSort::show()
{
	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << " ";
	cout << endl;
}

////待排序数组
//vector<int> Temp = { 1,5,2,3,4,8,9,6,5,23,5,65,32,12,0 };
//int main()
//{
//	simpleSelectionSort A(Temp);
//	A.show();
//	A.sort();
//	A.show();
//
//
//	cout << "FINSH" << endl;
//	cin.get();
//
//	return 1;
//}