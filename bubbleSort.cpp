#include<iostream>
#include<vector>

using namespace std;
/*冒泡排序*/
class bubbleSort {
private:
	vector<int> nums;
public:
	bubbleSort(vector<int> temp) :nums(temp) {};
	void sort();
	void show();
};

void bubbleSort::sort()
{
	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = 1; j < nums.size() - i; j++)
		{
			if (nums[j - 1] > nums[j])
				swap(nums[j - 1], nums[j]);
		}
	}
}

//打印排序后的数组
void bubbleSort::show()
{
	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << " ";
	cout << endl;
}

////待排序数组
//vector<int> Temp = { 1,5,2,3,4,8,9,6,5,23,5,65,32,12,0 };
//int main()
//{
//	bubbleSort A(Temp);
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