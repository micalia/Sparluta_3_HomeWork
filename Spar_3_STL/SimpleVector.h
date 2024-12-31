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
	void resize(int newCapacity); //도전
	void push_back(const T& value);
	void pop_back();
	int size() {return currentSize;}; // 현재 원소갯수 반환
	int capacity(){return currentCapacity;}; // 현재 내부 크기
	void sortData(){
		sort(data, data + currentSize);
	}; // 도전
};

template <typename T>
void SimpleVector<T>::resize(int newCapacity)
{ // 현재 할당된 크기가 새로 할당하려고 하는 크기보다 작다
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