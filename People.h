#pragma once
#include <iostream>
using namespace std;

int day = 1;
int dirtiness = 0;
int food = 50;
int eaten_food = 0;
int money = 100;
int cat_food = 30;
int spent_money = 0;
int diapers = 2;
int children_food = 20;

struct People
{
public:
	wstring name;
	int happiness = 80;
	int feed = 30;
	void info()
	{
		wcout << L"���: " << name << endl
			<< L"������� �������: " << happiness << endl
			<< L"�������: " << feed << endl;
	};
	int cat_pet()
	{
		wcout << name << L" ������ ����. � " << name << L" ����������� ����������." << endl;
		if (happiness < 95)
		{
			happiness += 5;
		}
		else
		{
			happiness = 100;
		}
		feed -= 10;
		dirtiness += 5;
		day += 1;
		return happiness, feed, dirtiness, day;
	};
	int eat()
	{
		unsigned num_ans;
		if (food == 0)
		{
			wcout << L"���� ��� ���. ��� �� ��������� ����?" << endl
				<< L"P.S.: �� ���� ������ �������" << endl;
		}
		else 
		{
			wcout << L"� ������� " << food << L" ������ ���." << endl
				<< L"������� �� ������ ������? (�� ����� 30 ������) " << endl
				<< L"����: ";
			wcin >> num_ans;
			if (num_ans > 30)
			{
				wcout << L"�� ������ 30 ������!" << endl;
				continue_func();
				eat();
			}
			else
			{
				wcout << L"�� ����� " << num_ans << L" ������ ���." << endl;
				food -= num_ans;
				feed += num_ans;
				wcout << L"�������� " << food << L" ������ ���." << endl;
				day += 1;
				eaten_food += num_ans;
				dirtiness += 5;
			}
		}
		return food, feed, day, eaten_food, dirtiness;
	}
};

