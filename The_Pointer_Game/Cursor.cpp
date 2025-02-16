#include "Header.h"

Menu& Menu::setCursor(std::string& _cursor)
{
    int selected_cursor = 0;
    bool is_set_cursor = true;

    while (is_set_cursor)
    {
        system("cls");
        std::cout << "Выберите курсор:\n";
        for (size_t i = 0; i < cursor_options.size(); i++)
        {
            if (i == selected_cursor)
            {
                std::cout << cursor << cursor_options.at(i) << std::endl;
            }
            else
            {
                std::cout << "   " << cursor_options.at(i) << std::endl;
            }
        }

        char ch = _getch();

        switch (ch)
        {
            case 72: if (selected_cursor > 0) selected_cursor--; break;
            case 80: if (selected_cursor < cursor_options.size() - 1) selected_cursor++; break;
            case 13:
                switch (selected_cursor)
                {
                    case 0: _cursor = "~> "; break;
                    case 1: _cursor = "* "; break;
                    case 2: _cursor = "~$ "; if (getTotalScore() == 3)  questSuccesful(menu_items, color_options, cursor_options);  break;
                    case 3: _cursor = ":_> "; break;
                    case 4: _cursor = "+ "; if (getTotalScore() == 5 && is_inverted == false) questSuccesful(menu_items, color_options, cursor_options);  break;
                    case 5: _cursor = "~ "; break;
                    case 6: _cursor = "-<x<o>> "; break;
                    case 7: _cursor = "~@ "; break;
                    case 8: _cursor = "~% "; break;
                    case 9: _cursor = "~# "; break;
                }
                selected_item = 0; // Сброс выделения
                is_set_cursor = false;
                break;
            case 27: is_set_cursor = false; break;
        }
    }
    return *this;
}