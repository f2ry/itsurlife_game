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
		wcout << L"Имя: " << name << endl
			<< L"Уровень счастья: " << happiness << endl
			<< L"Сытость: " << feed << endl;
	};
	int cat_pet()
	{
		wcout << name << L" гладит кота. У " << name << L" поднимается настроение." << endl;
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
			wcout << L"Дома нет еды. Что вы собрались есть?" << endl
				<< L"P.S.: не надо грызть плинтус" << endl;
		}
		else 
		{
			wcout << L"В наличии " << food << L" единиц еды." << endl
				<< L"Сколько вы хотите съесть? (не более 30 единиц) " << endl
				<< L"Ввод: ";
			wcin >> num_ans;
			if (num_ans > 30)
			{
				wcout << L"Не больше 30 единиц!" << endl;
				continue_func();
				eat();
			}
			else
			{
				wcout << L"Вы съели " << num_ans << L" единиц еды." << endl;
				food -= num_ans;
				feed += num_ans;
				wcout << L"Осталось " << food << L" единиц еды." << endl;
				day += 1;
				eaten_food += num_ans;
				dirtiness += 5;
			}
		}
		return food, feed, day, eaten_food, dirtiness;
	}
};

