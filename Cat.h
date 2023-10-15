#pragma once
#include <iostream>
using namespace std;

int eaten_cat_food = 0;
/* struct Cat
{
	wstring name;
	int feed = 30;
	void info()
	{
		wcout << L"Кличка: " << name << endl
			<< L"Уровень сытости: " << feed << endl;
	};
	int cat_feed()
	{
		unsigned ans;
		wcout << L"В наличии " << cat_food << L" единиц еды для кота." << endl
			<< L"Кот ест в два раза меньше людей (1 единица еды эквивалентна 2 пунктам сытости)." << endl
			<< L"Сколько скормить? (не больше 10 единиц)" << endl
			<< L"Ввод: ";
		wcin >> ans;
		if (ans > 10)
		{
			wcout << L"Не больше 10 единиц";
			cat_feed();
		}
		else
		{
			feed += ans * 2;
			cat_food -= ans;
			wcout << L"Кот поел. Осталось " << cat_food << L" единиц еды." << endl
				<< L"Уровень сытости кота: " << feed << endl;
			day += 1;
			eaten_cat_food += ans;
			dirtiness += 5;
		}
		return feed, cat_food, day, eaten_cat_food, dirtiness;
	};
	int sleep()
	{
		wcout << L"Спящий кот - покой в семье. Кот спит..." << endl;
		feed -= 10;
		day += 1;
		dirtiness += 5;
		return feed, day, dirtiness;
	}
	int wall_bash()
	{
		wcout << L"У кота очень игривое настроение. Он решил подрать обои." << endl;
		dirtiness += 10;
		day += 1;
		feed -= 10;
		return dirtiness, day, feed;
	}
}; */

