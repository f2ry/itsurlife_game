#pragma once


/* struct Wife :
    public People
{
    int buy_products()
    {
        unsigned ans;
        wcout << name << L" � ����������� ��������." << endl
            << L"� ��� " << money << L" �����." << endl
            << L"������� ��� ������? (���:������ = 1:1)" << endl
            << L"����: ";
        wcin >> ans;
        if (ans > money)
        {
            wcout << L"� ����� �� ������� �����!";
            buy_products();
        }
        else
        {
            money -= ans;
            food += ans;
            feed -= 10;
            wcout << name << L" ������ " << ans << L" ������ ���." << endl
                << L"� ����� �������� " << money << L" �����." << endl
                << L"���������� ���: " << food << endl;
            day += 1;
            dirtiness += 5;
            spent_money += ans;
        }
        return money, food, feed, day, dirtiness, spent_money;
    };
    int buy_cat_products()
    {
        unsigned ans;
        wcout << name << L" � �����������." << endl
            << L"� ��� " << money << L" �����." << endl
            << L"������� ��� ��� ���� ������? (���:������ = 1:1)" << endl
            << L"����: ";
        wcin >> ans;
        if (ans > money)
        {
            wcout << L"� ����� �� ������� �����!";
            buy_cat_products();
        }
        else
        {
            money -= ans;
            cat_food += ans;
            feed -= 10;
            wcout << name << L" ������ " << ans << L" ������ ��� ��� ����." << endl
                << L"� ����� �������� " << money << L" �����." << endl
                << L"���������� ��� ��� ����: " << cat_food << endl;
            day += 1;
            dirtiness += 5;
            spent_money += ans;
        }
        return money, cat_food, feed, day, dirtiness, spent_money;
    }
    int buy_fur_coat()
    {
        wcout << name << L" ����� �� �����." << endl;
        if (money < 350)
        {
            wcout << L"���� ��� �� ������" << endl;
        }
        else
        {
            wcout << L"������� ����������." << endl;
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
        wcout << L"����� ������! " << name << L" ���������..." << endl;
        if (dirtiness > 100)
        {
            dirtiness -= 100;
        }
        else
        {
            dirtiness = 0;
        }
        wcout << L"����� ������� ����� � ����: " << dirtiness << endl;
        feed -= 10;
        happiness -= 5;
        day += 1;
        return dirtiness, feed, happiness, day;
    }
    int goto_children_shop()
    {
        wstring ans{};
        unsigned num_ans;
        wcout << L"���� � ������� ��������." << endl
            << L"������: " << money << endl
            << L"��� ����� ������?" << endl
            << L"1) ����������" << endl
            << L"2) ��� ��� �������" << endl
            << L"����: ";
        wcin >> ans;
        if (ans == L"1")
        {
            system("cls");
            wcout << L"���� ��������� ����� 15 ����� � ������� ������� ����� ������� �� 10. ������� �����?" << endl
                << L"����: ";
            wcin >> num_ans;
            if (money < num_ans)
            {
                wcout << L"�����, �� �� ������ ��������� ���� ����� �������������� �����.";
            }
            else
            {
                diapers += num_ans;
                money -= (num_ans * 15);
                spent_money += (num_ans * 15);
                day += 1;
                wcout << L"���!" << endl;
                return diapers, money, spent_money, day;
            }
        }
        else if (ans == L"2")
        {
            system("cls");
            wcout << L"������� ��� ������ ���� �������. ���������: 2 � 1 (���������� ����� � ������� ���). ������� �����?" << endl
                << L"����: ";
            wcin >> num_ans;
            if (money < num_ans)
            {
                wcout << L"�����, �� �� ������ ��������� ���� ����� �������������� �����.";
            }
            else
            {
                children_food += num_ans;
                money -= (num_ans * 2);
                spent_money += (num_ans * 2);
                wcout << L"������ ���������!" << endl;
                day += 1;
                return children_food, money, spent_money, day;
                continue_func();
            }
        }
        else
        {
            wcout << L"�������, ���-�� ������� �� ���. ��������� ��� ���." << endl;
            continue_func();
            goto_children_shop();
        }
    }
}; */

