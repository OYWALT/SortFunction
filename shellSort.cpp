#include <iostream>
#include <vector>
using namespace std;
/*ϣ������*/
class shellSort {
private:
	vector<int> array;
	int length;

public:
	shellSort(vector<int> nums) :array(nums), length(nums.size()) {};
	void makeRoom(int i, int j, int s);
	void sort();
	void show();
};

void shellSort::sort()
{
	//��ԭʼ����ֳ�sp��
	int sp = length / 2;
	for (int s = sp; s >= 1; s /= 2)
	{
		cout <<"s: " << s << endl;
		//����Ҫ����ÿ�ݵĵ�1��Ԫ��
		for (int i = s; i < length; i++)
		{
			//�˴���Ҫע�����ÿ�αȽϵĲ���Ϊs
			for (int j = i - s; j >= 0; j-=s)
			{
				if (array[i] >= array[j])
				{
					//������i��Ԫ����䵽����j+s,��Ԫ��j�����ݵ���һ����������
					makeRoom(j+s, i, s);
					break;//��ע�⣺���������break��
				}
				else if(j==0)
					makeRoom(0, i ,s);
			}
		}
		show();
	}
}

//������Ϊnum��Ԫ�ز��뵽����index��
//��ס��λ�ƵĲ���Ϊs
void shellSort::makeRoom(int index, int num, int s)
{
	int temp = array[num];
	if (num > index)
	{
		for (int i = num; i >= (index + s); i -= s)
		{
			array[i] = array[i - s];
		}
		array[index] = temp;
	}
}
//��ӡ����������
void shellSort::show()
{
	for (int i = 0; i < array.size(); i++)
		cout << array[i] << " ";
	cout << endl;
}
//int main()
//{
//	vector<int> nums = { 0, 14, 9, 6, 13, 21, 7, 16,  33, 4, 5, 6, 10 };
//
//	shellSort temp(nums);
//	temp.show();
//	temp.sort();
//	temp.show();
//	cin.get();
//	return 0;
//}