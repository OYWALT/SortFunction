#include <iostream>
#include <vector>
using namespace std;

/*������*/
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
 * �ӽڵ�k��ʼ�������Խڵ�kλ���ڵ������Ϊ�����
 */
void maxHeapSort::heapAdjust(int k,int len)
{
	int temp = 0;
	for (int i = 2 * k; i <= len; i *= 2)
	{
		//�ҵ��ڵ�k�����ӽڵ��нϴ���Ǹ�
		if (i < len && array[i] < array[i + 1])
		{
			i++;
		}
		//�Ƚϵ�ǰ�ڵ���������Ҷ�ӽڵ������Ǹ�Ԫ��֮��Ĵ�С��ϵ
		//�����ǰ�ڵ�>Ҷ�ӽڵ�����ֵ��ֱ������ѭ��
		//�����ǰ�ڵ�<Ҷ�ӽڵ�����ֵ���򽻻���ǰ�ڵ���Ҷ�ӽڵ�ֵ��
		if (array[k] < array[i])
		{
			temp = array[k];
			array[k] = array[i];
			array[i] = temp;
			//��ע�⡿��ʱ���ڵ�ǰ�ڵ���Ҷ�ӽڵ��ֵ�������������ܻᵼ�±�������Ҷ���������������ѵ�Ҫ��
			//�����Ҫ����ǰ�ڵ�������ƶ�����������Ҷ�����������������¼��ÿ���ڵ��ֵ�Ƿ񶼴���������Ҷ���ӽڵ�
			k = i;
		}
		else
			break;
	}
}
/*
 * ��ʼ����������Ԫ�ع���ɴ����
 * ǰ��֪ʶ����һ������len���ڵ㣬���ڵ�����Ϊ1���������һ����Ҷ�ӽڵ��������е�����Ϊlen/2
 */
void maxHeapSort::maxHeap()
{
	//��õ�ǰ�������һ����Ҷ�ӽڵ�
	int k = length / 2;
	//�����һ����Ҷ�ӽڵ�������ʼ����������������ڵ��ƣ���֤�Խڵ�iΪ���ڵ����������������
	for (int i = length / 2; i >= 1; i--)
	{
		heapAdjust(i, length);
	}
}

void maxHeapSort::heapSort()
{
	//����Ҫ����˳������鹹���һ�������
	maxHeap();

	//������Ҫ��֤��nums[1]Ϊ���ڵ������Ϊ�����
	for (int i = array.size() - 1; i >= 1; i--)
	{
		heapAdjust(1,i);
		//�������鳤��Ϊlen�Ĵ���ѣ�����num[1]���������һ��Ԫ�ؽ��������ڹ������ѵ���������һ��Ԫ��
		//���Ԫ�ر�������ԭ�����nums[i]��
		int temp = array[1];
		array[1] = array[i];
		array[i] = temp;


	}

}
//��ӡ����������
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