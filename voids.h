#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <thread>
#include <conio.h>
#include <stdio.h>
#include <locale>
#include <codecvt>

using namespace std;

// функция выводит в консоль правила
void rules()
{
   
    system("cls");
    wifstream rules_text("rules.txt", ios::binary);
    rules_text.imbue(locale(rules_text.getloc(), new codecvt_utf8<wchar_t>));
    wstring w;
    while (getline(rules_text, w))
    {
        wcout << w << endl;
    }
    rules_text.close();

};

// функция продолжения с очисткой консоли
void continue_func()
{
    srand(time(0));
    wstring ans;
    while (ans != L"152")
    {
        wcout << L"\nВведите 152, чтобы продолжить..." << endl
            << L"Обратите внимание: окно будет очищено." << endl
            << L"Ввод: ";
        wcin >> ans;
        if (ans == L"648")
        {
            int a;
            a = rand() % 100;
            if (a % 3 == 0)
            {
                wcout << L"Честно говоря, объяснения этому нет. Просто так всё выглядит более загадочно..." << endl;
            }
            else if (a % 3 == 1)
            {
                wcout << L"У разработчиков очень не вовремя началось фантазийное обострение." << endl;
            }
            else
            {
                wcout << L"Рандом благоволит верным. Не задавайте лишних вопросов." << endl;
            }
        }
        if (ans == L"2u135")
        {
            rules();
        }

    }
    system("cls");
};

// функция вызова информации о доме
void home_info(int money, int food, int cat_food, int dirtiness)
{
    wcout << L"Информация о доме." << endl;
    wcout << L"Количество денег: " << money << endl
        << L"Еда: " << food << endl
        << L"Еда кота: " << cat_food << endl
        << L"Уровень грязи: " << dirtiness << endl;
};

// функция выбора цвета текста в консоли при запуске игры
void color_choosing()
{
    int key{};
    while (key != 13)
    {
        wcout << L"Поочередно нажимайте указанные ниже клавиши, чтобы поменять цвет текста." << endl
            << L"Пример текста, который будет появляться на экране." << endl
            << L"Пожалуйста, выберите комфортный для себя стиль, не торопитесь." << endl
            << L"Вариантов не так много, но вы не торопитесь." << endl
            << L"1, q, a - белый и его оттенки \n2, w, 3, e - синий и его оттенки \n4, r, 5, t - красный и его оттенки \n6, 7 - зеленый/ярко-зеленый \n8, 9 - желтый/ярко-желтый" << endl;
        wcout << L"\nЕсли вы закончили, нажмите Enter. \nОбратите внимание: вы не сможете изменить цвет текста до перезапуска.";
        key = _getch();
        switch (key)
        {
        case ('1'):
            system("color 08");
            system("cls");
            break;
        case ('q'):
            system("color 07");
            system("cls");
            break;
        case ('a'):
            system("color 0F");
            system("cls");
            break;
        case ('2'):
            system("color 01");
            system("cls");
            break;
        case ('3'):
            system("color 09");
            system("cls");
            break;
        case ('w'):
            system("color 03");
            system("cls");
            break;
        case ('e'):
            system("color 0b");
            system("cls");
            break;
        case ('4'):
            system("color 04");
            system("cls");
            break;
        case ('r'):
            system("color 05");
            system("cls");
            break;
        case ('5'):
            system("color 0c");
            system("cls");
            break;
        case ('t'):
            system("color 0d");
            system("cls");
            break;
        case ('6'):
            system("color 02");
            system("cls");
            break;
        case ('7'):
            system("color 0A");
            system("cls");
            break;
        case ('8'):
            system("color 06");
            system("cls");
            break;
        case ('9'):
            system("color 0E");
            system("cls");
            break;
        default:
            system("cls");
            break;
        }
    }
    system("cls");
}

// функция "перекура" до выполнения следующей команды, т.н. пауза (да, существует Sleep из "windows.h", но этот вариант мне показался более гибким)
void wait_ms(int time)
{
    this_thread::sleep_for(chrono::milliseconds(time));
};

// эта функция выводит на экран результат действия самоуничтожения мужа
void self_destruct()
{
    wcout << L"                                               .." << endl;
    wait_ms(200);
    wcout << L"                                              .5Y" << endl;
    wait_ms(200);
    wcout << L"                                        ...   .55" << endl;
    wait_ms(200);
    wcout << L"                                     .75YY5 ^ .55" << endl;
    wait_ms(200);
    wcout << L"                                   .7G5!::YB7 .55" << endl;
    wait_ms(200);
    wcout << L"                                :5G7.   .7GY : 55" << endl;
    wait_ms(200);
    wcout << L"                                 ^PP~    .  ~BY5Y" << endl;
    wait_ms(200);
    wcout << L"                                 7P.         ~G&Y" << endl;
    wait_ms(200);
    wcout << L"                                 ~G7.        .P@Y" << endl;
    wait_ms(200);
    wcout << L"                                 .7G57^.    ^YB&Y" << endl;
    wait_ms(200);
    wcout << L"                                   .~?5G?^^7G@PG5." << endl;
    wait_ms(200);
    wcout << L"                                      .~YYY?~P@@&G!" << endl;
    wait_ms(200);
    wcout << L"                                            .Y&@#G!" << endl;
    wait_ms(200);
    wcout << L"                                             .JB~." << endl;
    wait_ms(200);
    wcout << L"                                            .~PG:" << endl;
    wait_ms(200);
    wcout << L"                                           .?BB&J" << endl;
    wait_ms(200);
    wcout << L"                                          .JG!J&BY^" << endl;
    wait_ms(200);
    wcout << L"                                         .JB! JG!J5?:" << endl;
    wait_ms(200);
    wcout << L"                                        .?G~  JG: ~G5." << endl;
    wait_ms(200);
    wcout << L"                                       .?#7   J#!  ~G?." << endl;
    wait_ms(200);
    wcout << L"                                       .YJ.   ^G5.  ?#!" << endl;
    wait_ms(200);
    wcout << L"                                        :.     7G:  :PG:" << endl;
    wait_ms(200);
    wcout << L"                                               ~P:   :?^" << endl;
    wait_ms(200);
    wcout << L"                                               !P:" << endl;
    wait_ms(200);
    wcout << L"                                              ^GB:" << endl;
    wait_ms(200);
    wcout << L"                                             .J@B:" << endl;
    wait_ms(200);
    wcout << L"                                            .YPJG:" << endl;
    wait_ms(200);
    wcout << L"                                           .JB~~P:" << endl;
    wait_ms(200);
    wcout << L"                                           ~G7 !P: L" << endl;
    wait_ms(200);
    wcout << L"                                          .JG: !G:" << endl;
    wait_ms(200);
    wcout << L"                                          !#J. ^G7" << endl;
    wait_ms(200);
    wcout << L"                                         :55.  .5?" << endl;
    wait_ms(200);
    wcout << L"                                         ~#7   .5Y.          .^7777!~~^:." << endl;
    wait_ms(200);
    wcout << L"                                        .JP^   .?5:        .. .^^~7?YYYYYY5Y^" << endl;
    wait_ms(200);
    wcout << L"                                        .::     ...        .7Y7~~~~~~~~!?#@&~" << endl;
    wait_ms(200);
    wcout << L"                                                           .:!JYYJJJJJJJYG@#^" << endl;
    wait_ms(200);
    wcout << L"                                                                        :B@#^" << endl;
    wait_ms(200);
    wcout << L"                                                                        ?&@#^" << endl;
    wait_ms(200);
    wcout << L"                                                          .!J???7^^^^^^~G@@#^" << endl;
    wait_ms(200);
    wcout << L"                                                         ..~???J55555555&@G7." << endl;
    wait_ms(200);
    wcout << L"                                                          .7??????????JP#Y:" << endl;
    wait_ms(200);
    system("color 04");
    wcout << L"Надеюсь, вы довольны своим выбором." << endl;
    wcout << L"Нажмите Ctrl+C, чтобы закончить игру." << endl;
    while (true)
    {
        system("color 04");
        wait_ms(500);
        system("color 02");
        wait_ms(500);
        system("color 0f");
        wait_ms(500);
    }
}

// эта шляпка тут живёт, чтобы работали функции good_end и bad_end, объявленные в main.cpp (функция переопределяется в самом main.cpp)
int main();