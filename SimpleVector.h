#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
class SimpleVector
{
public:
	SimpleVector(){	};
	SimpleVector(int capacity): currentCapacity(capacity){
	cout<< "SimpleVector(int capacity): currentCapacity(capacity)"<<endl;
		data = new T[capacity];
	};
	~SimpleVector() {
		if(data)
			delete[] data;
	};

private:
	int currentSize = 0;
	int currentCapacity = 0;
	T* data;

public:
	void resize(int newCapacity); //����
	void push_back(const T& value);
	void pop_back();
	int size() {return currentSize;}; // ���� ���Ұ��� ��ȯ
	int capacity(){return currentCapacity;}; // ���� ���� ũ��
	void sortData(){
		sort(data, data + currentSize);
	}; // ����
};

template <typename T>
void SimpleVector<T>::resize(int newCapacity)
{ // ���� �Ҵ�� ũ�Ⱑ ���� �Ҵ��Ϸ��� �ϴ� ũ�⺸�� �۴�
	if(currentCapacity > newCapacity) return;
	if (data) {
		currentCapacity = newCapacity;
		T* tempNewData = new T[newCapacity];
		
		for (int i =0; i < size(); i ++)
		{
			tempNewData[i] = data[i];
		}

		delete[] data;
		data = tempNewData;
	}
}

template <typename T>
void SimpleVector<T>::pop_back()
{
	currentSize--;
	if (currentSize < 0) {
		currentSize = 0;
	}
}

template <typename T>
void SimpleVector<T>::push_back(const T& value)
{
	if (currentSize >= currentCapacity) {
		resize(currentCapacity + 5);
	}
	data[currentSize] = value; 
	currentSize++;
}