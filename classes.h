#pragma once
#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>
#include "voids.h"
using namespace std; 


// т.н. глобальные переменные-показатели
unordered_map<wstring, int> defaults =
{
{L"day", 0},
{L"dirtiness", 0},
{L"food", 50},
{L"eaten_food", 0},
{L"money", 100},
{L"cat_food", 30},
{L"spent_money", 0},
{L"diapers", 2},
{L"children_food", 20},
{L"fur_coats", 0},
{L"eaten_cat_food", 0},
{L"rand_is_done", 0 }
};
unordered_map<wstring, int> currents = defaults;
int day = defaults[L"day"];
int dirtiness = defaults[L"dirtiness"];
int food = defaults[L"food"];
int eaten_food = defaults[L"eaten_food"];
int money = defaults[L"money"];
int spent_money = defaults[L"spent_money"];
int cat_food = defaults[L"cat_food"];
int eaten_cat_food = defaults[L"eaten_cat_food"];
int diapers = defaults[L"diapers"];
int children_food = defaults[L"children_food"];
int fur_coats = defaults[L"fur_coats"];
bool rand_is_done = defaults[L"rand_is_done"];


struct People
{
    wstring name;
    int happiness = 80;
    int feed = 30;

    void info()
    {
        wcout << L"Имя: " << name << endl
            << L"Уровень счастья: " << happiness << endl
            << L"Сытость: " << feed << endl;
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
                eaten_food += num_ans;
                dirtiness += 5;
            }
        }
        return food, feed, eaten_food, dirtiness;
    }
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
        return happiness, feed, dirtiness;
    };

};

struct Husband :
	public People
{
	int play()
	{
		wcout << name << L" играет в игры." << endl;
		if (happiness < 80)
		{
			happiness += 20;
		}
		else
		{
			happiness = 100;
		}
		feed -= 10;
		dirtiness += 5;
		return happiness, feed, dirtiness;
	};
	int work()
	{
		wcout << name << L" ушел на работу.." << endl;
		feed -= 10;
		happiness -= 5;
		money += 150;
		dirtiness += 5;
		return feed, happiness, money, dirtiness;
	};

};
Husband husband;

struct Wife :
    public People
{
    int buy_products()
    {
        unsigned ans;
        wcout << name << L" в продуктовом магазине." << endl
            << L"У вас " << money << L" денег." << endl
            << L"Сколько еды купить? (еда:деньги = 1:1)" << endl
            << L"Ввод: ";
        wcin >> ans;
        if (ans > money)
        {
            wcout << L"В семье не хватает денег!";
            buy_products();
        }
        else
        {
            money -= ans;
            food += ans;
            feed -= 10;
            wcout << name << L" купила " << ans << L" единиц еды." << endl
                << L"В семье осталось " << money << L" денег." << endl
                << L"Количество еды: " << food << endl;
            dirtiness += 5;
            spent_money += ans;
        }
        wcin.clear();
        return money, food, feed, dirtiness, spent_money;
    };
    int buy_cat_products()
    {
        unsigned ans;
        wcout << name << L" в зоомагазине." << endl
            << L"У вас " << money << L" денег." << endl
            << L"Сколько еды для кота купить? (еда:деньги = 1:1)" << endl
            << L"Ввод: ";
        wcin >> ans;
        if (ans > money)
        {
            wcout << L"В семье не хватает денег!" << endl;
            buy_cat_products();
        }
        else 
        {
            money -= ans;
            cat_food += ans;
            feed -= 10;
            wcout << name << L" купила " << ans << L" единиц еды для кота." << endl
                << L"В семье осталось " << money << L" денег." << endl
                << L"Количество еды для кота: " << cat_food << endl;
            dirtiness += 5;
            spent_money += ans;
        }
        wcin.clear();
        return money, cat_food, feed, dirtiness, spent_money;
    }
    int buy_fur_coat()
    {
        wcout << name << L" пошла за шубой." << endl;
        if (money < 350)
        {
            wcout << L"Шубу она не купила" << endl;
        }
        else
        {
            wcout << L"Покупка состоялась." << endl;
            money -= 350;
            if (happiness <= 40)
            {
                happiness += 60;
            }
            else
            {
                happiness = 100;
            }
            feed -= 10;
            fur_coats += 1;
            dirtiness += 5;
            spent_money += 350;
        }
        return money, feed, fur_coats, dirtiness, spent_money;
    }
    int cleaning()
    {
        wcout << L"Время уборки! " << name << L" убирается..." << endl;
        if (dirtiness > 100)
        {
            dirtiness -= 100;
        }
        else
        {
            dirtiness = 0;
        }
        wcout << L"Новый уровень грязи в доме: " << dirtiness << endl;
        feed -= 10;
        happiness -= 5;
        return dirtiness, feed, happiness;
    }
    int goto_children_shop()
    {
        wstring ans{};
        unsigned num_ans;
        wcout << L"Жена в детском магазине." << endl
            << L"Деньги: " << money << endl
            << L"Что нужно купить?" << endl
            << L"1) Подгузники" << endl
            << L"2) Еды для ребенка" << endl
            << L"Ввод: ";
        wcin >> ans;
        if (ans == L"1")
        {
            system("cls");
            wcout << L"Один подгузник стоит 15 денег и снижает уровень грязи ребенка на 10. Сколько нужно?" << endl
                << L"Ввод: ";
            wcin >> num_ans;
            if (money < num_ans)
            {
                wcout << L"Боюсь, вы не можете позволить себе такую расточительную трату.";
            }
            else
            {
                diapers += num_ans;
                money -= (num_ans * 15);
                spent_money += (num_ans * 15);
                day += 1;
                wcout << L"Гуд!" << endl;
                return diapers, money, spent_money, day;
            }
        }
        else if (ans == L"2")
        {
            system("cls");
            wcout << L"Детская еда всегда была дорогой. Стоимость: 2 к 1 (количество денег к единице еды). Сколько нужно?" << endl
                << L"Ввод: ";
            wcin >> num_ans;
            if (money < num_ans)
            {
                wcout << L"Боюсь, вы не можете позволить себе такую расточительную трату.";
            }
            else
            {
                children_food += num_ans;
                money -= (num_ans * 2);
                spent_money += (num_ans * 2);
                wcout << L"Запасы пополнены!" << endl;
                day += 1;
                return children_food, money, spent_money, day;
                continue_func();
            }
        }
        else
        {
            wcout << L"Кажется, что-то введено не так. Подумайте ещё раз." << endl;
            continue_func();
            goto_children_shop();
        }
    }
};
Wife wife;

struct Cat
{
    wstring name;
    int feed = 30;
    int happiness = 70;
    void info()
    {
        wcout << L"Кличка: " << name << endl
            << L"Уровень сытости: " << feed << endl
            << L"Уровень счастья: " << happiness << endl;
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
            happiness += 10;
        }
        return feed, cat_food, day, eaten_cat_food, dirtiness, happiness;
    };
    int sleep()
    {
        wcout << L"Спящий кот - покой в семье. Кот спит..." << endl;
        feed -= 10;
        happiness -= 5;
        return feed, happiness;
    }
    int wall_bash()
    {
        wcout << L"У кота очень игривое настроение. Он решил подрать обои." << endl;
        dirtiness += 10;
        feed -= 10;
        wife.happiness -= 5;
        husband.happiness -= 5;
        happiness += 5;
        return dirtiness, day, feed, wife.happiness, husband.happiness, happiness;
    }
};
Cat cat;

struct Child
{
    wstring name;
    int feed = 15;
    int happiness = 40;
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
        wcout << L"Дети - цветы жизни. Эта позиция заставила ребенка разрисовать стены в доме." << endl;
        dirtiness += 5;
        feed -= 5;
        happiness += 10;
        return dirtiness, feed;
    }

    int poop()
    {
        wcout << L"Кажется, ребенку нужна помощь. Он испачкался." << endl;
        child_dirtiness += 10;
        feed -= 5;
        return child_dirtiness, feed;
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
Child child;



// функция считывания значений из файла
void read_save()
{
    wifstream currents_file;
    wstring path = L"currents.txt";
    currents_file.open(path);
    wcout << L"Reading from: " << path << endl;
    wstring input;
    while (input != L" ")
    {
        getline(currents_file, input);
        size_t equalpos = input.find(L'=');
        if (equalpos != wstring::npos)
        {
            wstring variable = input.substr(0, equalpos);
            wstring value = input.substr(equalpos + 1);
            variable.erase(remove_if(variable.begin(), variable.end(), ::isspace), variable.end());
            value.erase(remove_if(value.begin(), value.end(), ::isspace), value.end());
            int numericvalue = stoi(value);
            currents[variable] = numericvalue;
        }
    }
    wcout << L"Read successfully!" << endl << endl;
    currents_file.close();
    day = currents[L"day"];
    dirtiness = currents[L"dirtiness"];
    food = currents[L"food"];
    eaten_food = currents[L"eaten_food"];
    money = currents[L"money"];
    spent_money = currents[L"spent_money"];
    cat_food = currents[L"cat_food"];
    eaten_cat_food = currents[L"eaten_cat_food"];
    diapers = currents[L"diapers"];
    children_food = currents[L"children_food"];
    fur_coats = currents[L"fur_coats"];
    husband.happiness = currents[L"husband_happiness"];
    husband.feed = currents[L"husband_feed"];
    wife.happiness = currents[L"wife_happiness"];
    wife.feed = currents[L"wife_feed"];
    cat.happiness = currents[L"cat_happiness"];
    cat.feed = currents[L"cat_feed"];
    child.happiness = currents[L"child_happiness"];
    child.feed = currents[L"child_feed"];
    rand_is_done = currents[L"rand_is_done"];
}

// функция сохранения значений в файл
void rewrite_save()
{
    currents[L"day"] = day;
    currents[L"dirtiness"] = dirtiness;
    currents[L"food"] = food;
    currents[L"eaten_food"] = eaten_food;
    currents[L"money"] = money;
    currents[L"spent_money"] = spent_money;
    currents[L"cat_food"] = cat_food;
    currents[L"eaten_cat_food"] = eaten_cat_food;
    currents[L"diapers"] = diapers;
    currents[L"children_food"] = children_food;
    currents[L"fur_coats"] = fur_coats;
    currents[L"husband_happiness"] = husband.happiness;
    currents[L"husband_feed"] = husband.feed;
    currents[L"wife_happiness"] = wife.happiness;
    currents[L"wife_feed"] = wife.feed;
    currents[L"cat_happiness"] = cat.happiness;
    currents[L"cat_feed"] = cat.feed;
    currents[L"child_happiness"] = child.happiness;
    currents[L"child_feed"] = child.feed;
    currents[L"rand_is_done"] = rand_is_done;
    wofstream currents_file;
    wstring path = L"currents.txt";
    wcout << L"Saving to: " << path << endl;
    currents_file.open(path);
    for (const auto& variable : currents) { currents_file << variable.first << " = " << variable.second << endl; }
    currents_file << L" " << endl;
    wcout << L"Rewrited!" << endl;
    currents_file.close();
}