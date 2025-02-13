#include "Header.h"

void Menu::control()
{
    bool is_control_running = true;
    
    while (is_control_running)
    {
        system("cls");
        std::cout << "��������: " << (is_inverted ? "��������" : "���������") << std::endl;
        std::cout << "1. ����������� ��������\nEsc ��� ��������." << std::endl;

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
    std::cout << "�������� " << (is_inverted ? "��������" : "���������") << std::endl;
    
    if (getTotalScore() == 1) questSuccesful(menu_items, color_options, cursor_options); 
}
