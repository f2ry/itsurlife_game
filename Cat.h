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
		wcout << L"������: " << name << endl
			<< L"������� �������: " << feed << endl;
	};
	int cat_feed()
	{
		unsigned ans;
		wcout << L"� ������� " << cat_food << L" ������ ��� ��� ����." << endl
			<< L"��� ��� � ��� ���� ������ ����� (1 ������� ��� ������������ 2 ������� �������)." << endl
			<< L"������� ��������? (�� ������ 10 ������)" << endl
			<< L"����: ";
		wcin >> ans;
		if (ans > 10)
		{
			wcout << L"�� ������ 10 ������";
			cat_feed();
		}
		else
		{
			feed += ans * 2;
			cat_food -= ans;
			wcout << L"��� ����. �������� " << cat_food << L" ������ ���." << endl
				<< L"������� ������� ����: " << feed << endl;
			day += 1;
			eaten_cat_food += ans;
			dirtiness += 5;
		}
		return feed, cat_food, day, eaten_cat_food, dirtiness;
	};
	int sleep()
	{
		wcout << L"������ ��� - ����� � �����. ��� ����..." << endl;
		feed -= 10;
		day += 1;
		dirtiness += 5;
		return feed, day, dirtiness;
	}
	int wall_bash()
	{
		wcout << L"� ���� ����� ������� ����������. �� ����� ������� ����." << endl;
		dirtiness += 10;
		day += 1;
		feed -= 10;
		return dirtiness, day, feed;
	}
}; */

