#include <iostream>
#include <string>
#include <vector>
using namespace std;
template<class T>
void AdjustDown(vector<T> &vec, int k, int len){
	//����k��Ԫ�����µ���
	vec[0] = vec[k];			//�ݴ�
	int i;
	for (i = 2*k; i <= len; i*=2)
	{
		if (i < len&&vec[i] < vec[i + 1])	i++; //ȡkey�ϴ���ӽڵ���±�
		if (vec[0] >= vec[i]) break;			 //ɸѡ����
		else{
			vec[k] = vec[i];
			k = i;
		}
	}
	vec[k] = vec[0];//��ɸѡ�ڵ��ֵ��������λ��
}
template<class T>
void BuildMaxHeap(vector<T> &vec,int len){
	//������
	int i;
	//int len = vec.size()-1;
	for (i = len / 2; i > 0; i--){	//��n/2~1����������
		AdjustDown(vec,i,len);
	}
}
template<class T>
void Swap(T &a, T &b){
	a = a + b;
	b = a - b;
	a = a - b;
}
template<class T>
void HeapSort(vector<T> &vec){
	//�����������0��Ԫ�ز���������
	int i,len = vec.size()-1;
	BuildMaxHeap(vec,len);
	for (i = len; i > 1; i--){
		Swap(vec[1],vec[i]);
		AdjustDown(vec,1,i-1);
	}
}


int main(){
	float array[] = { 1, 2.4, 8.8, 4, 1, 4, 6, 8 };
	vector<float> vec(array, array + 8);
	HeapSort(vec);
	for each (float var in vec)
	{
		cout << var << endl;
	}
	return 0;
}