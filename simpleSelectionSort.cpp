#include<iostream>
#include<vector>
using namespace std;

/*��ѡ������*/
class simpleSelectionSort {
private:
	vector<int> nums;
public:
	simpleSelectionSort(vector<int> temp) :nums(temp){};

	void sort();
	void show();
};
//ÿһ�δ�δ����Ĳ�����ѡȡ��С��Ԫ�أ��ŵ������򲿷���β
//���õ���swap(�����򲿷�β��+1��δ���򲿷�����СԪ��)�ķ�ʽ������
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
		//swap(�����򲿷�β�� + 1��δ���򲿷�����СԪ��)
		swap(nums[i], nums[index]);
	}
}
//��ӡ����������
void simpleSelectionSort::show()
{
	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << " ";
	cout << endl;
}

////����������
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