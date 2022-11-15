#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*��������*/
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
//���캯������ʼ��Ͱ����Ϊһ������10������Ԫ�ص�����
radixSort::radixSort(vector<int> temp)
{
	array = vector<ListNode*>(10);
	nums = temp;
}

//�������num��stepλ�����ִ�С����������ڣ���ֱ�ӷ���0
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
//�������������е�Ԫ�ذ��յ�stepλ���ηŵ�Ͱ�У�������Ͱȡ�������µ�����
void radixSort::sort()
{
	int step = 0;
	//���ν��и�λ��ʮλ����λ... ...�Ļ�������
	while (step< maxStep())
	{
		vector<int> result;
		auto start = nums.begin();
		while (start != nums.end())
		{
			//��Ԫ��*start��װ��һ������ڵ�
			ListNode* node = new ListNode(*start);

			//�����Ԫ���ڵ�stepλ������
			int index = getIndex(*start, step);

			//����װ�õĽڵ�鵽�����Ӧ�����������У�β�巨
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
		//�������ж�Ӧ���������е�Ԫ�����·���һ���µ�����result�з���
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
//��ȡ���������������Ԫ�ص�λ��
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
//��ӡ����������
void radixSort::show()
{
	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << " ";
	cout << endl;
}

////����������
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