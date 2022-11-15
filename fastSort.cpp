#include<iostream>
#include<vector>

using namespace std;

/*��������*/
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
	int left = start;//��ע�⣡�������˴�����left=start+1; ����left=start;
	int right = end;
	while (right > left)
	{
		//���ÿ�αȽϵ�ֵȡ��������ߵĵ�һ��������ô�ڽ��бȽϷ�������������ʱ��Ӧ�����������ȿ�ʼ����֮��Ȼ��
		while (nums[right] > nums[start] && right > left)
			right--;
		while (nums[left] <= nums[start] && right > left)
			left++;
		if (left == right)
		{
			//��left��right�غ�ʱ��������ߵ�һ�������غϵ���н���
			swap(nums[start], nums[left]);
			break;
		}
		else
		{   //���ұ߳���С����ߵ�һ������Ԫ�أ���߳��ִ�����ߵ�һ��Ԫ�ص������򽻻�����������λ�á�
			swap(nums[left], nums[right]);
		}
	}
	sort(start, left - 1);
	sort(left + 1, end);

}

//��ӡ����������
void fastSort::show()
{
	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << " ";
	cout << endl;
}

////����������
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