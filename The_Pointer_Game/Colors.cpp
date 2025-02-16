#include "Header.h"

Menu& Menu::setColorConsole()
{
    int selected_color = 0;
    bool is_set_color = true;

    while (is_set_color)
    {

        if (getTotalScore() == 2) { questSuccesful(menu_items, color_options, cursor_options); }
        if (getTotalScore() == 4) { questSuccesful(menu_items, color_options, cursor_options); }

        system("cls");
        std::cout << "Выберите цвет:\n";
        for (size_t i = 0; i < color_options.size(); i++)
        {
            if (i == selected_color)
            {
                std::cout << cursor << color_options.at(i) << std::endl;
            }
            else
            {
                std::cout << "   " << color_options.at(i) << std::endl;
            }
        }

        char ch = _getch();

        switch (ch)
        {
            case 72: if (selected_color > 0) selected_color--; break;
            case 80: if (selected_color < color_options.size() - 1) selected_color++; break;
            case 13: 
                switch (selected_color)
                {
                    case 0: system("color 7"); break;
                    case 1: system("color 2"); break;
                    case 2: system("color 5"); break;
                    case 3: system("color 3"); if (getTotalScore() == 7 && is_inverted == true && cursor == "~> ") { questSuccesful(menu_items, color_options, cursor_options); }break;
                    case 4: system("color 9"); break;
                    case 5: system("color 1"); break;
                    case 6: system("color 6"); break;
                }
                selected_item = 0;
                is_set_color = false; 
                break;
            case 27: // Esc
                is_set_color = false;
                break;
        }
    }
    return *this;
}
