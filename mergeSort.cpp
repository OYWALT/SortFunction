#include <iostream>
#include <vector>
using namespace std;
class mergeSort {
private:
	vector<int> array;
	int length;

public:
	mergeSort(vector<int> nums) :array(nums), length(nums.size()) {};
	~mergeSort() {};
	vector<int> mergeArray(vector<int>& nums1, vector<int>& nums2);
	void sort();
	void show();

};

//将数组拆分成等分，递归，并在回溯期间进行有序数组的归并
vector<int> mergeSort::mergeArray(vector<int>& nums1, vector<int>& nums2)
{
	//递归退出条件，当需要合并的两个数组中，其中一个数组为空，则返回另一个数组
	if (nums1.size() == 0 || nums2.size() == 0)
		return nums1.size() ? nums1 : nums2;

	//将每个传进的来的数组都分割成两个数组继续递归
	int mid1 = nums1.size() / 2;
	vector<int> nums11 = vector<int>(nums1.begin(), nums1.begin() + mid1);
	vector<int> nums12 = vector<int>(nums1.begin() + mid1, nums1.end());
	int mid2 = nums2.size() / 2;
	vector<int> nums21 = vector<int>(nums2.begin(), nums2.begin() + mid2);
	vector<int> nums22 = vector<int>(nums2.begin() + mid2, nums2.end());

	nums1 = mergeArray(nums11, nums12);
	nums2 = mergeArray(nums21, nums22);

	//在每层递归，将两个有序数组中的元素进行归并，合成一个数组后返回
	vector<int> temp(nums1.size()+nums2.size(),0);
	int index = 0;
	int index1 = 0;
	int index2 = 0;
	while (index1 < nums1.size() || index2 < nums2.size())
	{
		if (index1<nums1.size()&&index2<nums2.size())
		{
			if(nums1[index1] > nums2[index2])
			temp[index++] = nums2[index2++];
			else
			temp[index++] = nums1[index1++];
		}
		else if (index2 < nums2.size())
			temp[index++] = nums2[index2++];
		else if (index1 < nums1.size())
			temp[index++] = nums1[index1++];
	}
	//返回两两有序数组的合成数组
	return temp;
}

//将原数组拆分成两等份，进行递归，回溯时归并
void mergeSort::sort()
{
	int mid = array.size() / 2;
	vector<int> nums1 = vector<int>(array.begin(), array.begin() + mid);
	vector<int> nums2 = vector<int>(array.begin() + mid, array.end());
	array = mergeArray(nums1, nums2);
}

//打印排序后的数组
void mergeSort::show()
{
	for (int i = 0; i < array.size(); i++)
		cout << array[i] << " ";
	cout << endl;
}

int main()
{
	vector<int> nums = { 0, 14, 9, 6, 13, 21, 7, 16,  33, 4, 5, 6, 10};

	mergeSort temp(nums);
	temp.show();
	temp.sort();
	temp.show();
	cin.get();

	return 0;
}