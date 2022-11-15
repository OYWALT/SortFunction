#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*基数排序*/
class radixSort
{
private:
	struct ListNode
	{
		int val;
		ListNode* next;
		ListNode() :val(0), next(nullptr) {};
		ListNode(int value) :val(value), next(nullptr) {};
		ListNode(int value, ListNode* ptr) :val(value), next(ptr) {};
	};
	vector<ListNode*> array;
	vector<int> nums;
public:
	radixSort(vector<int> temp);
	int getIndex(int num, int step);
	void sort();
	void show();
	int maxStep();
	//void sort(int* begin, int* end);
};
//构造函数，初始化桶数组为一个含有10个链表元素的数组
radixSort::radixSort(vector<int> temp)
{
	array = vector<ListNode*>(10);
	nums = temp;
}

//获得数字num第step位的数字大小，如果不存在，则直接返回0
int radixSort::getIndex(int num, int step)
{
	int result = 0;
	while (step != 0)
	{
		num = num / 10;
		step--;
		if (num == 0)
			return 0;
	}
	result = num % 10;
	return result;
}
//将待排序数组中的元素按照第step位依次放到桶中，并挨个桶取出返回新的数组
void radixSort::sort()
{
	int step = 0;
	//依次进行个位、十位、百位... ...的基数排序
	while (step< maxStep())
	{
		vector<int> result;
		auto start = nums.begin();
		while (start != nums.end())
		{
			//将元素*start包装成一个链表节点
			ListNode* node = new ListNode(*start);

			//计算该元素在第step位的索引
			int index = getIndex(*start, step);

			//将包装好的节点查到数组对应索引的链表中，尾插法
			if (array[index] == nullptr)
				array[index] = node;
			else
			{
				ListNode* temp = array[index];
				while (temp != nullptr)
				{
					if (temp->next == nullptr)
					{
						temp->next = node;
						break;
					}
					temp = temp->next;
				}
			}
			start++;
		}
		//将数组中对应索引链表中的元素重新放入一个新的数组result中返回
		for (int i = 0; i < array.size(); i++)
		{
			while (array[i] != nullptr)
			{
				result.push_back(array[i]->val);
				array[i] = array[i]->next;
			}
		}
		nums = result;
		step++;
	}
}
//获取待排序数组中最大元素的位数
int radixSort::maxStep()
{
	int step = 0;
	int Max = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		int temp = nums[i];
		while (temp != 0)
		{
			temp = temp / 10;
			step++;
		}
		Max = max(Max, step);
	}
	return Max;
}
//打印排序后的数组
void radixSort::show()
{
	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << " ";
	cout << endl;
}

////待排序数组
//vector<int> Temp = { 1,5,2,3,4,8,9,6,5,23,5,65,32,12,0 };
//int main()
//{
//	radixSort A(Temp);
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