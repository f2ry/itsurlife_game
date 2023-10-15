#pragma once


/* struct Wife :
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
            day += 1;
            dirtiness += 5;
            spent_money += ans;
        }
        return money, food, feed, day, dirtiness, spent_money;
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
            wcout << L"В семье не хватает денег!";
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
            day += 1;
            dirtiness += 5;
            spent_money += ans;
        }
        return money, cat_food, feed, day, dirtiness, spent_money;
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
            day += 1;
            fur_coats += 1;
            dirtiness += 5;
            spent_money += 350;
        }
        return money, feed, day, fur_coats, dirtiness, spent_money;
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
        day += 1;
        return dirtiness, feed, happiness, day;
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
}; */

