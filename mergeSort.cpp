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

//�������ֳɵȷ֣��ݹ飬���ڻ����ڼ������������Ĺ鲢
vector<int> mergeSort::mergeArray(vector<int>& nums1, vector<int>& nums2)
{
	//�ݹ��˳�����������Ҫ�ϲ������������У�����һ������Ϊ�գ��򷵻���һ������
	if (nums1.size() == 0 || nums2.size() == 0)
		return nums1.size() ? nums1 : nums2;

	//��ÿ���������������鶼�ָ��������������ݹ�
	int mid1 = nums1.size() / 2;
	vector<int> nums11 = vector<int>(nums1.begin(), nums1.begin() + mid1);
	vector<int> nums12 = vector<int>(nums1.begin() + mid1, nums1.end());
	int mid2 = nums2.size() / 2;
	vector<int> nums21 = vector<int>(nums2.begin(), nums2.begin() + mid2);
	vector<int> nums22 = vector<int>(nums2.begin() + mid2, nums2.end());

	nums1 = mergeArray(nums11, nums12);
	nums2 = mergeArray(nums21, nums22);

	//��ÿ��ݹ飬���������������е�Ԫ�ؽ��й鲢���ϳ�һ������󷵻�
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
	//����������������ĺϳ�����
	return temp;
}

//��ԭ�����ֳ����ȷݣ����еݹ飬����ʱ�鲢
void mergeSort::sort()
{
	int mid = array.size() / 2;
	vector<int> nums1 = vector<int>(array.begin(), array.begin() + mid);
	vector<int> nums2 = vector<int>(array.begin() + mid, array.end());
	array = mergeArray(nums1, nums2);
}

//��ӡ����������
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