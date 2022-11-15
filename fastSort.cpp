#include<iostream>
#include<vector>

using namespace std;

/*快速排序*/
class fastSort {
private:
	vector<int> nums;
public:
	fastSort(vector<int>temp) :nums(temp) {};
	void sort(int start, int end);
	void show();
};

void fastSort::sort(int start,int end)
{
	if (end - start <= 0)
		return;
	int left = start;//【注意！！！】此处不是left=start+1; 而是left=start;
	int right = end;
	while (right > left)
	{
		//如果每次比较的值取的是最左边的第一个数，那么在进行比较分配左右子数组时，应该是右数组先开始，反之亦然。
		while (nums[right] > nums[start] && right > left)
			right--;
		while (nums[left] <= nums[start] && right > left)
			left++;
		if (left == right)
		{
			//当left和right重合时，将最左边第一个数与重合点进行交换
			swap(nums[start], nums[left]);
			break;
		}
		else
		{   //当右边出现小于左边第一个数的元素，左边出现大于左边第一个元素的数，则交换这两个数的位置。
			swap(nums[left], nums[right]);
		}
	}
	sort(start, left - 1);
	sort(left + 1, end);

}

//打印排序后的数组
void fastSort::show()
{
	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << " ";
	cout << endl;
}

////待排序数组
//vector<int> Temp = { 1,5,2,3,4,8,9,6,5,23,5,65,32,12,0 };
//int main()
//{
//	fastSort A(Temp);
//	A.show();
//	A.sort(0, Temp.size()-1);
//	A.show();
//
//
//	cout << "FINSH" << endl;
//	cin.get();
//
//	return 1;
//}