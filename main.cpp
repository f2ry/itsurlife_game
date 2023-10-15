#include <iostream>
#include <random>
#include <time.h>
#include <io.h>
#include <fcntl.h>
#include <thread>
#include <string>
#include "Colors.h" // тут надо будет побаловаться, вся документацуия прописана в файле-заголовке
#include "classes.h" 

using namespace std;

// необходимые переменные для основного кода, не имеющие отношения ни к одному из классов
bool cat_translator = false;
bool is_having_child = false;
wstring ans;

// несколько необходимостей
void home_info()
{
    home_info(money, food, cat_food, dirtiness);
};
void start_inputting()
{
    // присказка...
    wcout << L"Добро пожаловать в наш симулятор домашней жизни!" << endl
        << L"В представленной игре в ваших руках окажется жизнь семьи, которая состоит из мужа, жены и кота \n(возможно, позже появится больше опций). " << endl
        << L"При достижении определенных условий вы сможете завести ребенка (как по мне, он сильно усложняет игру)." << endl
        << L"Цель довольно проста: прожить год. " << endl
        << L"Для этого вам понадобится следить за голодом персонажей, уровнем их счастья и грязью в доме." << endl;
    while (ans != L"152")
    {
        wcout << L"\nВведите 152, чтобы продолжить." << endl
            << L"Обратите внимание: окно будет очищено (вы и дальше будете получать такие предупреждения)." << endl
            << L"Ввод: ";
        wcin >> ans;
    }
    system("cls");

    rules();
    wcout << L"\nКажется, это всё, что стоит упомянуть здесь. Внимательно всё прочитайте (перечитайте, если необходимо)" << endl
        << L"и введите 152, чтобы продолжить (введите 648, чтобы узнать, почему ответы должны быть такими странными)" << endl
        << L"В дальнейшем вы можете использовать '2u135', чтобы вызвать правила снова." << endl;
    continue_func();

    wcout << L"Пора создавать персонажей! Чтобы никого не обидеть, мы начнем с кота." << endl
        << L"Введите имя кота: ";
    wcin >> cat.name;
    while (cat.name == L"1" || cat.name == L"2" || cat.name == L"3")
    {
        wcout << L"Нет." << endl
            << L"Введите имя кота: ";
        wcin >> cat.name;
    }
    wcout << L"Отлично! Теперь у вас есть кот." << endl;
    wcout << L"\nВведите имя мужа: ";
    wcin >> husband.name;
    while (husband.name == cat.name || husband.name == L"1" || husband.name == L"2" || husband.name == L"3")
    {
        wcout << L"Нет." << endl
            << L"Введите имя мужа: ";
        wcin >> husband.name;
    }
    wcout << L"Если вы видите это сообщение, значит муж тоже был успешно создан!" << endl;
    wcout << L"\nКак же в доме без женской помощи." << endl
        << L"Введите имя жены: ";
    wcin >> wife.name;
    while ((wife.name == cat.name) || (wife.name == husband.name) || wife.name == L"1" || wife.name == L"2" || wife.name == L"3")
    {
        wcout << L"Нет." << endl
            << L"Введите имя жены: ";
        wcin >> wife.name;
    }
    wcout << L"Wife has been c... Короче, теперь в доме и жена имеется. Можно начинать! Наверное..." << endl;
    continue_func();

}

void good_end()
{
    system("cls");
    wcout << L"Если вы видите это сообщение, значит прошел год и вы достигли логического завершения игры." << endl;
    wait_ms(2000);
    wcout << L"Никто не умер, никто не пострадал и все остались счастливы." << endl;
    wait_ms(2000);
    wcout << L"Подведем итоги:" << endl;
    wait_ms(1000);
    wcout << L"\n1) За время игры было съедено " << eaten_food << L" единиц еды. Не многовато ли?" << endl;
    wait_ms(1000);
    wcout << L"2) Кошачье удовлетворение. За время игры котом было съедено " << eaten_cat_food << L" единиц еды." << endl;
    wait_ms(1000);
    wcout << L"3) Если шуб было куплено больше 3, а их куплено " << fur_coats << L", то у меня вопрос : зачем ?" << endl;
    wait_ms(2000);
    wcout << L"Впрочем, это всё не важно. Мои поздравления!" << endl;
    wcout << L"\nЕсли желаете, можете повторить свой подвиг ещё раз. Ещё один год с самого начала!" << endl
        << L"Введите 152, чтобы начать всё сначала." << endl
        << L"Введите всё, что угодно, чтобы закончить." << endl
        << L"Ввод: ";
    wcin >> ans;
    if (ans == L"152")
    {
        main();
    }
    else
    {
        wcout << L"Спасибо за уделенное время!";
        wait_ms(3000);
    }

}
void bad_end()
{
    system("cls");
    wifstream bad_end("bad_end.txt", ios::binary);
    bad_end.imbue(locale(bad_end.getloc(), new codecvt_utf8<wchar_t>));
    wstring w;
    while (getline(bad_end, w))
    {
        wcout << w << endl;
        wait_ms(1500);
    }
    bad_end.close();
    wcout << L"Ввод: ";
    wcin >> ans;
    if (ans == L"152") {
        main();
    }
    else
    {
        wcout << L"Спасибо за уделенное время!";
        wait_ms(3000);
    }
}


// основной код игры

int main()
{   
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stderr), _O_U16TEXT);
    system("mode con cols=120 lines=50");
    srand(time(0));
    rand();
    color_choosing();
    ifstream save("currents.txt");
    if (save.is_open()) 
    {
        wcout << L"Обнаружено сохранение. Желаете загрузить?" << endl
            << L"Чтобы загрузить сохранение, введите load. Введите всё, что угодно, чтобы ничего не загружать и начать сначала." << endl << L"Ввод: ";
        wstring ans;
        wcin >> ans;
        if (ans == L"load") 
        { 
            save.close();
            read_save(); 
            wcout << L"Немного нюансов" << endl << L"Введите кличку кота : ";
            wcin >> cat.name;
            while (cat.name == L"1" || cat.name == L"2" || cat.name == L"3")
            {
                wcout << L"Нет." << endl
                    << L"Введите кличку кота: ";
                wcin >> cat.name;
            }
            wcout << L"Кличка кота восстановлена!" << endl;
            wcout << L"\nВведите имя мужа: ";
            wcin >> husband.name;
            while (husband.name == cat.name || husband.name == L"1" || husband.name == L"2" || husband.name == L"3")
            {
                wcout << L"Нет." << endl
                    << L"Введите имя мужа: ";
                wcin >> husband.name;
            }
            wcout << L"Если вы видите это сообщение, значит имя мужа восстановлено!" << endl;
            wcout << L"\nКак же в доме без женской помощи." << endl
                << L"Введите имя жены: ";
            wcin >> wife.name;
            while ((wife.name == cat.name) || (wife.name == husband.name) || wife.name == L"1" || wife.name == L"2" || wife.name == L"3")
            {
                wcout << L"Нет." << endl
                    << L"Введите имя жены: ";
                wcin >> wife.name;
            }
            wcout << L"Wife has been r... Короче, имя жены восстановлено. Можно начинать! Наверное..." << endl;
            continue_func();
            
        }
        else 
        { system("cls"); start_inputting(); }
    }
    
    else 
    { start_inputting(); }


// теперь точно основной код игры
    while (day < 365)
    {
        if (!rand_is_done) { day += 1; }
        wcout << L"День " << day << L"." << endl;
        if (husband.happiness < 10)
        {
            wcout << L"Стоило лучше следить за состоянием " << husband.name << L"." << endl
                << L"Он умер от депрессии." << endl
                << L"Вам придется начать всё сначала." << endl;
            continue_func();
            break;
        }
        if (husband.feed <= 0)
        {
            wcout << L"Очень грустно, что " << husband.name << L" умер от голода. Вам должно быть стыдно." << endl
                << L"Вам придется начать сначала." << endl;
            continue_func();
            break;
        }
        if (wife.happiness < 10)
        {
            wcout << L"Своими действиями вы довели " << wife.name << L"до депрессии." << endl
                << L"Она умерла." << endl
                << L"Вам придется начать всё сначала." << endl;
            continue_func();
            break;
        }
        if (wife.feed <= 0)
        {
            wcout << L"Шуба и кот могут осчастливить женщину, но не сделают её сытой." << endl
                << wife.name << L" умерла от голода." << endl
                << L"Вам придется начать сначала." << endl;
            continue_func();
            break;
        }
        if (cat.feed <= 0)
        {
            wcout << L"В мире, в котором живут " << husband.name << L", " << wife.name << L" и жил " << cat.name << L" нельзя жить без кота." << endl
                << L"Своими действиями Вы довели " << cat.name << L" до смерти от голода. Это очень жестоко!" << endl
                << L"Вам придется начать сначала. Если вы планируете это повторить, то лучше не начинайте." << endl;
            continue_func();
            break;
        }
        if (child.feed <= 0)
        {
            wcout << L"Не стоило заводить ребёнка без четкого осознания данного действия. Он умер от голода.";
            continue_func();
            break;
        }
        if (dirtiness >= 90)
        {
            husband.happiness -= 10;
            wife.happiness -= 10;
            if (is_having_child == true) 
            {
                child.happiness -= 10;
            };
        }
        if (!rand_is_done)
        {
            if (cat.happiness <= 40)
            {
                int random_doing = 1 + rand() % 200;
                if (101 < random_doing < 150)
                {
                    cat.wall_bash();
                }
            }
            else { cat.sleep(); }
            if (is_having_child)
            {
                int random_doing = 1 + rand() % 150;
                if (random_doing < 36) { child.poop(); }
                else if (167 < random_doing) { child.wall_paint(); }
                else { wcout << L"Сегодня ребёнок ничего не сделал..." << endl; }
            };
            rand_is_done = true;
        }

        wcout << L"Выберите персонажа: " << endl
            << L"1) " << husband.name << L" (муж) (введите '1' или имя мужа)" << endl
            << L"2) " << wife.name << L" (жена) (введите '2' или имя жены)" << endl
            << L"3) " << cat.name << L" (кот) (введите '3' или кличку кота)" << endl;
        if (is_having_child == true)
        {
            wcout << L"4) Ребёнок (введите '4' или имя ребенка)" << endl;
        }
        wcout << L"Вы можете посмотреть правила (2u135), узнать состояние дома (303)." << endl
            << L"Вы можете сохраниться (save). ";
        if ((is_having_child == false) && (husband.happiness == 100) && (wife.happiness == 100) && (money >= 600))
        {
            wcout << L"Вы можете завести ребенка (7363)." << endl;
        }
        else
        {
            wcout << L"Больше вы ничего не можете." << endl;
        }
        wcout << L"Ввод: ";
        wcin >> ans;

        if (ans == L"2u135")
        {
            rules();
            continue_func();
        }

        else if (ans == L"303")
        {
            system("cls");
            home_info();
            continue_func();
        }

        else if (ans == L"save")
        {
            system("cls");
            rewrite_save();
            continue_func();
        }

        else if ((ans == L"7363") && (is_having_child == false) && (husband.happiness == 100) && (wife.happiness == 100) && (money >= 600))
        {
            system("cls");
            wcout << L"Не знаю, желая того или нет, но..." << endl
                << L"Поздравляю, вы завели гендерно-нейтрального ребёнка. Выберите ему имя." << endl
                << L"Ввод: ";
            wcin >> child.name;
            while (child.name == husband.name || child.name == wife.name || child.name == cat.name ||
                child.name == L"1" || child.name == L"2" || child.name == L"3" || child.name == L"4")
            {
                wcout << L"Нет." << endl
                     << L"Введите имя ребёнка: ";
                wcin >> child.name;
            }
            wcout << L"Какое прекрасное имя... Отлично!" << endl;
            is_having_child = true;
            day += 1;
            continue_func();

        }

        else if ((ans == L"1") || (ans == husband.name))
        {
            system("cls");
            wcout << L"Выбран " << husband.name << L". Список действий:" << endl
                << L"1) Поиграть в игры" << endl
                << L"2) Сходить на работу" << endl
                << L"3) Поесть" << endl
                << L"4) Погладить кота" << endl
                << L"Введите 1, 2, 3 или 4 для выбора действия или введите 'info_номер_действия', чтобы увидеть его описание." << endl
                << L"Введите 3450 для просмотра информации о муже." << endl;
            if (husband.happiness <= 20)
            {
                wcout << L"Введите end_this_shit, чтобы покинуть этот бренный мир и закончить своё томное существование." << endl;
                }
                wcout << L"Обратите внимание: при просмотре информации о действиях или персонаже вы будете возвращаться к выбору персонажа." << endl
                << L"Ввод: ";
            wcin >> ans;
            if (ans == L"3450")
            {
                system("cls");
                husband.info();
                continue_func();
            }
            
            else if (ans == L"1")
            {
                system("cls");
                husband.play();
                rand_is_done = false;
                continue_func();
            }
            else if (ans == L"info 1")
            {
                system("cls");
                wcout << L"Первое действие мужа. Повышает его уровень счастья на 20." << endl;
                continue_func();
            }

            else if (ans == L"2")
            {
                system("cls");
                husband.work();
                rand_is_done = false;
                continue_func();
            }
            else if (ans == L"info_2")
            {
                system("cls");
                wcout << L"Второе действие мужа. Приносит в дом 150 денег, снижает уровень счастья на 5 единиц." << endl;
                continue_func();

            }

            else if (ans == L"3")
            {
                system("cls");
                husband.eat();
                rand_is_done = false;
                continue_func();
            }
            else if (ans == L"info_3")
            {
                system("cls");
                wcout << L"Третье действие мужа. Повышает уровень сытости не более, чем на 30 единиц." << endl;
                continue_func();
            }

            else if (ans == L"4")
            {
                system("cls");
                husband.cat_pet();
                if (cat.happiness < 90)
                {
                    cat.happiness += 10;
                }
                else
                {
                    cat.happiness = 100;
                }
                rand_is_done = false;
                continue_func();
            }
            else if (ans == L"info_4")
            {
                system("cls");
                wcout << L"Четвертое действие мужа. Повышает уровень счастья на 5 единиц.";
                continue_func();
            }

            else if ((husband.happiness < 15) && (ans == L"end_this_shit"))
            {
                rand_is_done = false;
                system("cls");
                self_destruct();
            }

            else
            {
                system("cls");
                wcout << L"Некорректный ввод. Вы будете возвращены в меню выбора персонажа.";
                continue_func();
            }

        }

        else if ((ans == L"2") || (ans == wife.name))   
        {
            system("cls");
            wcout << L"Выбрана " << wife.name << L". Список действий:" << endl;
            wcout << L"1) Уборка в доме " << endl
                << L"2) Купить еды" << endl
                << L"3) Поесть" << endl
                << L"4) Купить еды для кота" << endl
                << L"5) Купить шубу" << endl
                << L"6) Погладить кота" << endl;
            if (is_having_child == true)
            {
                wcout << L"7) Пойти в детский магазин" << endl;
            }

            wcout << L"Введите 1, 2, 3, 4, 5";
            if (is_having_child == true)
            {
                wcout << L", 6, или 7 ";
            }
            else
            {
                wcout << L" или 6 ";
            }
            wcout << L"для выбора действия или введите 'info_номер_действия', чтобы увидеть его описание." << endl
                << L"Введите 1613 для просмотра информации о жене." << endl
                << L"При просмотре информации о действиях или персонаже вы будете возвращаться к выбору персонажа." << endl
                << L"Ввод: ";
            wcin >> ans;

            if (ans == L"1613")
            {
                system("cls");
                wife.info();
                continue_func();
            }

            else if (ans == L"1")
            {
                system("cls");
                wife.cleaning();
                rand_is_done = false;
                continue_func();
            }
            else if (ans == L"info_1")
            {
                system("cls");
                wcout << L"Первое действие жены. Понижает уровень грязи в доме не более, чем на 100 единиц." << endl
                    << L"Также снижает уровень счастья жены на 5 единиц." << endl;
                continue_func();
            }

            else if (ans == L"2")
            {
                system("cls");
                wife.buy_products();
                rand_is_done = false;
                continue_func();
            }
            else if (ans == L"info_2")
            {
                system("cls");
                wcout << L"Второе действие жены. Повышает уровень еды в доме на указанное количество единиц." << endl
                    << L"Также уменьшает количество денег в доме на то же число." << endl;
                continue_func();
            }

            else if (ans == L"3")
            {
                system("cls");
                wife.eat();
                rand_is_done = false;
                continue_func();
            }
            else if (ans == L"info_3")
            {
                system("cls");
                wcout << L"Третье действие жены. Повышает уровень сытости жены не более, чем на 30 единиц.";
                continue_func();
            }

            else if (ans == L"4")
            {
                system("cls");
                wife.buy_cat_products();
                rand_is_done = false;
                continue_func();

            }
            else if (ans == L"info_4")
            {
                system("cls");
                wcout << L"Четвертое действие жены. Повышает уровень кошачьей еды в доме на указанное количество." << endl
                    << L"Также уменьшает количество денег в доме на то же число." << endl;
                continue_func();
            }

            else if (ans == L"5")
            {
                system("cls");
                if (wife.happiness < 75)
                {
                    wife.buy_fur_coat();
                    rand_is_done = false;
                    continue_func();
                }
                else
                {
                    wcout << L"Дважды подумайте прежде, чем трижды подумать. Не то." << endl
                        << L"Секундочку..." << endl;
                    wait_ms(1500);
                    system("cls");
                    wcout << L"Вам точно это необходимо? (y - да, n - нет)" << endl
                        << L"Ввод: ";
                    wcin >> ans;
                    if (ans == L"y")
                    {
                        system("cls");
                        wife.buy_fur_coat();
                        rand_is_done = false;
                        continue_func();
                    }
                    else
                    {
                        wcout << L"То-то же." << endl;
                        continue_func();
                    }

                }
            }
            else if (ans == L"info_5")
            {
                system("cls");
                wcout << L"Пятое действие жены. Повышает уровень счастья жены на 60 единиц." << endl
                    << L"Уменьшает количество денег в доме на 350 единиц." << endl;
                continue_func();
            }

            else if (ans == L"6")
            {
                system("cls");
                wife.cat_pet();
                if (cat.happiness < 90)
                {
                    cat.happiness += 10;
                }
                else
                {
                    cat.happiness = 100;
                }
                rand_is_done = false;
                continue_func();
            }
            else if (ans == L"info_6")
            {
                system("cls");
                wcout << L"Шестое действие жены. Повышает уровень счастья жены на 5 единиц." << endl;
                continue_func();
            }

            else if ((ans == L"7") && (is_having_child == true))
            {
                system("cls");
                wife.goto_children_shop();
                rand_is_done = false;
                continue_func();
            }
            else if ((ans == L"info_7") && (is_having_child == true))
            {
                system("cls");
                wcout << L"Седьмое действие жены. Отправляет её в детский магазин за необходимыми ребенку товарами." << endl
                    << L"Дальнейшие инструкции получаются после выбора действия." << endl;
                continue_func();
            }

            else
            {
                system("cls");
                wcout << L"Некорректный ввод. Вы будете возвращены в меню выбора персонажа.";
                continue_func();
            }
        }

        else if ((ans == L"3") || (ans == cat.name))
        {
            system("cls");
            if (cat_translator == false)
            {
                wcout << L"Мяу! " << cat.name << L" мяу, мяу! Мяу: " << endl;
                wcout << L"1) Мяу" << endl
                    << L"2) Мяу" << endl
                    << L"3) Мрряу" << endl
                    << L"Мяу м, я, мяу у мяу-мяу." << endl
                    << L"Мяу-мяу 3351, мяу." << endl
                    << L"Вы можете включить или выключить переводчик с кошачьего. Для этого введите True или False (вкл/выкл)." << endl
                    << L"Ввод: ";
            }
            else
            {
                wcout << L"Выбран " << cat.name << L". Список действий: " << endl;
                wcout << L"1) Поесть" << endl
                    << L"Введите 1, 2 или 3 для выбора действия или введите 'info_номер_действия', чтобы увидеть его описание." << endl
                    << L"Введите 3351 для просмотра информации о коте." << endl
                    << L"При просмотре информации о персонаже или действии вы будете возвращаться к выбору персонажа." << endl
                    << L"Вы можете включить или выключить переводчик с кошачьего. Для этого введите True или False (вкл/выкл)." << endl
                    << L"Ввод: ";
            }
                wcin >> ans;
                if (ans == L"True")
                {
                    if (cat_translator == false)
                    {
                        system("cls");
                        cat_translator = true;
                        wcout << L"Включен переводчик с кошачьего." << endl;
                        continue_func();
                    }
                    else
                    {
                        system("cls");
                        wcout << L"Переводчик с кошачьего уже был включен!" << endl;
                        continue_func();
                    }
                }
                else if (ans == L"False")
                {
                    if (cat_translator == true)
                    {
                        system("cls");
                        cat_translator = false;
                        wcout << L"Мяу-мяу мяу." << endl;
                        continue_func();
                    }
                    else
                    {
                        system("cls");
                        wcout << L"Мяу-мяу мяу!!!" << endl;
                        continue_func();
                    }
                }

                else if (ans == L"1")
                {
                    system("cls");
                    cat.cat_feed();
                    rand_is_done = false;
                    continue_func();
                }
                else if (ans == L"info_1")
                {
                    system("cls");
                    wcout << L"Третье действие кота. Повышает уровень сытости кота не более, чем на 20 единиц." << endl;
                    continue_func();
                }

                else if (ans == L"3351")
                {
                    system("cls");
                    cat.info();
                    continue_func();
                }

                else
                {
                    system("cls");
                    wcout << L"Что-то не то. Вы будете возвращены к меню выбора персонажа." << endl;
                    continue_func();
                }
        }

        else if (((ans == L"4") || (ans == child.name)) && (is_having_child == true))
        {
            system("cls");
            wcout << L"Выбран " << child.name << L". Действия: " << endl;
            wcout << L"1) Посмотреть информацию" << endl
                << L"2) Поесть" << endl
                << L"3) Привести ребенка в порядок" << endl
                << L"Введите 1, 2 или 3 для выбора действия или введите 'info_номер_действия', чтобы увидеть его описание." << endl
                << L"Информация о ребенке, как вы могли заметить, не вызывается каким-то хитрым сочетанием. " << endl
                << L"Ввод: ";
            wcin >> ans;

            if (ans == L"1")
            {
                system("cls");
                child.info();
                continue_func();
            }
            else if (ans == L"info_1")
            {
                system("cls");
                wcout << L"Первое действие ребенка. Отображает информацию о ребенке." << endl;
                continue_func();
            }
            
            else if (ans == L"2")
            {
                system("cls");
                child.eat();
                rand_is_done = false;
                continue_func();
            }
            else if (ans == L"info_2")
            {
                system("cls");
                wcout << L"Второе действие ребенка. Повышает уровень сытости не более, чем на 25 единиц." << endl;
                continue_func();
            }
            
            else if (ans == L"3")
            {
                system("cls");
                child.wash_kid();
                rand_is_done = false;
                continue_func();
            }
            else if (ans == L"info_3")
            {
                system("cls");
                wcout << L"Третье действие ребенка. Понижает уровень его загрязненности до нуля, если это возможно." << endl;
                continue_func();
            }

            else
            {
                system("cls");
                wcout << L"Вы неправильно понимаете словосочетание 'корректный ввод'. Попробуйте ещё раз." << endl;
                continue_func();
            }
        }

        else
        {
            system("cls");
            wcout << L"Попробуйте что-то, что имеет смысл. " << endl;
            continue_func();
        }

    }
    
    if (day != 365)
    {
        bad_end();
    }

    else
    {
        good_end();

    }
    
    return 0;
} 
