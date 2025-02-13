#include "Header.h"

void Menu::control()
{
    bool is_control_running = true;
    
    while (is_control_running)
    {
        system("cls");
        std::cout << "Инверсия: " << (is_inverted ? "Включена" : "Выключена") << std::endl;
        std::cout << "1. Переключить инверсию\nEsc для возврата." << std::endl;

        char ch = _getch();
        switch (ch) 
        {
        case '1': controlInversion(is_inverted);  break;
            case 27: is_control_running = false; break;
        }
    }
}

void Menu::controlInversion(bool& _is_inverted)
{
    is_inverted = !is_inverted;
    std::cout << "Инверсия " << (is_inverted ? "включена" : "выключена") << std::endl;
    
    if (getTotalScore() == 1) questSuccesful(menu_items, color_options, cursor_options); 
}
