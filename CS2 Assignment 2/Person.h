#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
using namespace std;


class Person {
public: 
	string ID;
	string Name;
	int age;
	Person();
	Person(string x, string y, int z);
	void virtual printinfo();


}; //Abstract Class with Virtual Print Info



struct appointment {

	int hours = 0;
	int  minutes = 0;
	
};


class Customer : public Person {

private:
	string mechanicID;
	appointment CM;

public:
	void setMID(string x);
	string getMID();

	int hrs = 0,  mins = 0;
	void setAP(int x, int y);
	appointment getAP();

	void  printinfo();

	bool operator>(Customer& section);
	bool operator<(Customer& section);
	bool operator==(Customer& section);






};


class Mechanic : public Person {

private:
	int index = 0;
	appointment ap[24];

public:

	int counter = 0;
	void setcounter(int x);
	int getcounter();

	void setAP(appointment a);
	appointment getAP(int index);
	appointment getLatestAP();

	void  printinfo();

	bool isAvailable(appointment b);




};



template<class T>
class queue
{
private:
	T* array;
	int size;
	int top;
	int front;

public:
	queue(int s = 30) {

		size = s;
		array = new T[size];
		top = -1;
		front = -1;

	}

	void push(T value) {

		if (top == size - 1) {

			cout << "Queue is full" << endl;


		}
		else {
			front = 0;
			top++;
			array[top] = value;
		}


	}

	void pop() {

		if (front == -1) {
			cout << "Queues is empty" << endl;
		}
		else {

			front++;
			cout << "Customer Appointment Details: " << endl;

		}
	}

	T Top() {

			return array[front];
	}

	~queue() {

		delete[]array;

	}

};