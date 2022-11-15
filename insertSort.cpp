#include<iostream>
#include<vector>
using namespace std;
/*��������*/
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
	//�ӵڶ���Ԫ�ؿ�ʼ����һ��Ԫ�ؾ���Ϊ���Ѿ��źõ�����
	for (int i = 1; i < nums.size(); i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			//Ѱ�����кõ������дӴ�С�ĵ�һ��С��num[i]��Ԫ��nums[j]����nums[i]���뵽j+1λ��
			if (nums[i] >= nums[j])
			{
				makRoom(j + 1, i);
				break;//��ע�⣡���������������break;
			}
			//��nums[i]С���������кõ�����Ԫ��ʱ���������λ��0
			else if (j == 0)
				makRoom(0, i);
		}
	}
}
//������Ϊnum��Ԫ�ز��뵽����index��
void insertSort::makRoom(int index, int num)
{
	int temp = nums[num];
	for (int i = num; i >= index+1; i--)
	{
		nums[i] = nums[i - 1];
	}
	nums[index] = temp;
}
//��ӡ����������
void insertSort::show()
{
	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << " ";
	cout << endl;
}

//����������
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