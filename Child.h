#pragma once
struct Child
{
	wstring name;
	int feed = 15;
	int happiness = 15;
	int child_dirtiness = 0;

	void info()
	{
		wcout << L"���: " << name << endl
			<< L"�������: " << feed << endl
			<< L"�������: " << happiness << endl
			<< L"�����: " << child_dirtiness << endl;
	};

	int wall_paint()
	{
		wcout << L"���� - ����� �����. ��� ������� ��������� ������� ����������� ����� � ����.";
		dirtiness += 5;
		feed -= 5;
		happiness += 10;
		return dirtiness, feed;
	}

	int poop()
	{
		wcout << L"�������, ������� ����� ������. �� ����������.";
		child_dirtiness += 10;
		feed -= 5;
	}

	int eat()
	{
		int num_ans;
		wcout << L"��������-����������� ������� ������������? ��������� ���." << endl << endl
			<< L"�������� ������� � ������� (��.): " << children_food << endl
			<< L"������� �� ������ �������� ���? (�� ����� 25 ������!)" << endl
			<< L"����: ";
		wcin >> num_ans;
		if (num_ans > 25)
		{
			system("cls");
			wcout << L"�� ����� ��������� ������� �����������. �� ����� 25 ������!";
			continue_func();
			eat();
		}
		else if (num_ans > children_food) 
		{
			system("cls");
			wcout << L"�����, ��� � ���� ��� ������� �������� �������." << endl
				<< L"�� ������ ���������� � ���� ������ ���������." << endl;
			continue_func();
		}
		else
		{
			system("cls");
			wcout << L"���� ���� � ��������. ������ ����� ��������... ���� ���." << endl << endl
				<< L"�������� " << children_food << L" ������ �������� �������." << endl
				<< L"����� ������� ������� �������: " << feed << endl;
			day += 1;
			feed += num_ans;
			children_food -= num_ans;
			child_dirtiness += 5;
			happiness += 8;
			return day, children_food, child_dirtiness, feed, happiness;
		}
	}

	int wash_kid()
	{
		wcout << L"���� ������� �� ��������! ����� ���������� ��������� ��� �������..." << endl;
		wait_ms(1500);
		if (diapers == 0)
		{
			wcout << L"�� � ��� �� ���. ��� ��������..." << endl;
		}
		else
		{
			child_dirtiness = 0;
			day += 1;
			diapers -= 1;
			feed -= 10;
			wcout << L"������!" << endl;
			return day, diapers, feed, child_dirtiness;
		}

	}
	// ������� ����� ������� ������� (wash_kid)
};

