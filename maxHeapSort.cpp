#include <iostream>
#include <vector>
using namespace std;

/*堆排序*/
class maxHeapSort {
private:
	vector<int> array;
	int length;
public:
	maxHeapSort(vector<int> nums) :array(nums), length(nums.size()-1) {};
	void heapAdjust(int k,int len);
	void maxHeap();
	void heapSort();
	void show();
};

/*
 * 从节点k开始，构造以节点k位根节点的子树为大根堆
 */
void maxHeapSort::heapAdjust(int k,int len)
{
	int temp = 0;
	for (int i = 2 * k; i <= len; i *= 2)
	{
		//找到节点k左右子节点中较大的那个
		if (i < len && array[i] < array[i + 1])
		{
			i++;
		}
		//比较当前节点与其两个叶子节点最大的那个元素之间的大小关系
		//如果当前节点>叶子节点的最大值，直接跳出循环
		//如果当前节点<叶子节点的最大值，则交换当前节点与叶子节点值，
		if (array[k] < array[i])
		{
			temp = array[k];
			array[k] = array[i];
			array[i] = temp;
			//【注意】此时由于当前节点与叶子节点的值发生交换，可能会导致被交换的叶子树不再满足大根堆的要求
			//因此需要将当前节点的索引移动到被交换的叶子索引处，继续向下检查每个节点的值是否都大于其两个叶子子节点
			k = i;
		}
		else
			break;
	}
}
/*
 * 初始化整个数组元素构造成大根堆
 * 前提知识：当一棵树有len个节点，根节点索引为1，则其最后一个非叶子节点在数组中的索引为len/2
 */
void maxHeapSort::maxHeap()
{
	//获得当前树的最后一个非叶子节点
	int k = length / 2;
	//从最后一个非叶子节点索引开始层序遍历倒序往根节点移，保证以节点i为根节点的子树都满足大根堆
	for (int i = length / 2; i >= 1; i--)
	{
		heapAdjust(i, length);
	}
}

void maxHeapSort::heapSort()
{
	//将需要排列顺序的数组构造成一个大根堆
	maxHeap();

	//首先需要保证以nums[1]为根节点的树变为大根堆
	for (int i = array.size() - 1; i >= 1; i--)
	{
		heapAdjust(1,i);
		//对于数组长度为len的大根堆，将其num[1]与数组最后一个元素交换后，用于构造大根堆的数组缩短一个元素
		//最大元素被保存在原数组的nums[i]中
		int temp = array[1];
		array[1] = array[i];
		array[i] = temp;


	}

}
//打印排序后的数组
void maxHeapSort::show()
{
	for (int i = 0; i < array.size(); i++)
	cout << array[i] << "  ";
	cout << endl;
}

//int main()
//{
//	vector<int> nums = { 0, 14, 9, 6, 13, 21, 10, 16, 17, 2, 12 };
//
//	maxHeapSort temp(nums);
//	temp.heapSort();
//	temp.show();
//	cin.get();
//
//	return 0;
//}