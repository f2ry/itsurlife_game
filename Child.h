#pragma once
struct Child
{
	wstring name;
	int feed = 15;
	int happiness = 15;
	int child_dirtiness = 0;

	void info()
	{
		wcout << L"Имя: " << name << endl
			<< L"Сытость: " << feed << endl
			<< L"Счастье: " << happiness << endl
			<< L"Грязь: " << child_dirtiness << endl;
	};

	int wall_paint()
	{
		wcout << L"Дети - цветы жизни. Эта позиция заставила ребенка разрисовать стены в доме.";
		dirtiness += 5;
		feed -= 5;
		happiness += 10;
		return dirtiness, feed;
	}

	int poop()
	{
		wcout << L"Кажется, ребенку нужна помощь. Он испачкался.";
		child_dirtiness += 10;
		feed -= 5;
	}

	int eat()
	{
		int num_ans;
		wcout << L"Гендерно-нейтральный карапуз проголодался? Покормите его." << endl << endl
			<< L"Детского питания в наличии (ед.): " << children_food << endl
			<< L"Сколько вы хотите скормить ему? (не более 25 единиц!)" << endl
			<< L"Ввод: ";
		wcin >> num_ans;
		if (num_ans > 25)
		{
			system("cls");
			wcout << L"Не нужно приживать ребенку чревоугодие. Не более 25 единиц!";
			continue_func();
			eat();
		}
		else if (num_ans > children_food) 
		{
			system("cls");
			wcout << L"Боюсь, что в доме нет столько детского питания." << endl
				<< L"Вы будете возвращены к меню выбора персонажа." << endl;
			continue_func();
		}
		else
		{
			system("cls");
			wcout << L"Чадо сыто и довольно. Можете спать спокойно... пока что." << endl << endl
				<< L"Осталось " << children_food << L" единиц детского питания." << endl
				<< L"Новый уровень сытости ребенка: " << feed << endl;
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
		wcout << L"Пора убирать за ребенком! Смена подгузника полностью его очистит..." << endl;
		wait_ms(1500);
		if (diapers == 0)
		{
			wcout << L"Но у вас их нет. Вот незадача..." << endl;
		}
		else
		{
			child_dirtiness = 0;
			day += 1;
			diapers -= 1;
			feed -= 10;
			wcout << L"Готово!" << endl;
			return day, diapers, feed, child_dirtiness;
		}

	}
	// ребенку нужно сделать помывку (wash_kid)
};

