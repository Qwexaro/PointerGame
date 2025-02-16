#include "Header.h"

Menu::Menu()
{
    goods_options = {"-<x<o>> - 9 points", "Блокнот - 3 points", "Части для улучшения указателя (любого) - 25 points"};
    save_options = {"Сохранить текущий прогресс", "Загрузить прогресс"};
    menu_items = { "Настройки инверсии", "Просмотреть квест", "Настройки сохранения"};
    color_options = { "Белый", "Зеленый" };
    cursor_options = { "~>", "*" };

    cursor = "~> "; selected_item = 0, is_inverted = false; points = 0.0;

    total_score = 0;
    control_value = 0;

    is_miracle_pointer = true;
    is_NotePad = true;
    is_evolution_fragment = true;
    is_first_buy = false;
}

void Menu::displayMenu()
{
    bool is_running = true;

    while (is_running)
    {
        printMenu();
        char ch = _getch();

        if (is_inverted)
        {
            switch (ch)
            {
                case 72: if (selected_item < menu_items.size() - 1)  selected_item++; break;
                case 80: if (selected_item > 0) selected_item--; break;
            }
        }
        else
        {
            switch (ch)
            {
                case 72: if (selected_item > 0) selected_item--; break;
                case 80: if (selected_item < menu_items.size() - 1) selected_item++; break;
            }
        }
        switch (ch)
        {
            case 13: executeOption(selected_item); break;
            case 27: is_running = false; break;
        }
    }
}

void Menu::printMenu()
{
    system("cls");
    for (size_t i = 0; i < menu_items.size(); i++)
    {
        if (i == selected_item)
        {
            std::cout << cursor << menu_items.at(i) << std::endl; 
        }
        else
        {
            std::cout << "   " << menu_items.at(i) << std::endl;
        }
    }
}

void Menu::executeOption(int option)
{
    switch (option)
    {
        case 0: control(); break;
        case 1: quests(); break;
        case 2: saveSettings(); break;
        case 3: setColorConsole(); break;
        case 4: setCursor(cursor); break;
        case 5: shopMenu(); break;
       
        default: std::cout << "Данное меню пустое" << std::endl; break;
    }
    system("pause");
}
