#include "Header.h"

Menu& Menu::shopMenu()
{
    
    int selected_good = 0;
    bool is_set_good = true;

    bool is_stonks = false;


    while (is_set_good)
    {
    if ( getTotalScore() == 8 && is_stonks == false && getPoints() > 100)
    {
        is_stonks = true;
        questSuccesful(menu_items, color_options, cursor_options);
    }
        system("cls");
        std::cout << "Количество ваших поинтов: " << getPoints() << std::endl;
        for (size_t i = 0; i < goods_options.size(); i++)
        {
            if (i == selected_good)
            {
                setPoints(0.1);
                std::cout << cursor << goods_options.at(i) << std::endl; 
            }
            else
            {
                std::cout << "   " << goods_options.at(i) << std::endl;
            }
        }

        char ch = _getch();

        switch (ch)
        {
            case 72: if (selected_good > 0) selected_good--; break;
            case 80: if (selected_good < goods_options.size() - 1) selected_good++; break;
            case 13:
                switch (selected_good)
                {
                    case 0:  
                        if (is_miracle_pointer == true && points >= 9) 
                        {
                            
                            std::cout << "\nВы купили уникальный указатель" << std::endl;

                            points -= 9;
                            is_miracle_pointer = false;

                            cursor_options.push_back("-<x<o>>");

                            questSuccesful(menu_items, color_options, cursor_options);
                        }
                        else
                        {
                            std::cout << "Вы уже покупали этот предмет" << std::endl;
                        }
                        break;
                    case 1:
                        if (is_NotePad == true && points >= 3)
                        {
                            std::cout << "\nВы купили блокнот" << std::endl;

                            points -= 3;
                            is_NotePad = false;

                            questSuccesful(menu_items, color_options, cursor_options);
                        }
                        else
                        {
                            std::cout << "Вы уже покупали этот предмет" << std::endl;
                        }
                        break;
                    case 2:  
                        std::cout << "В данный момент мы не можем продать вам фрагмент эволюции." << std::endl;
                        break;
                    default:
                        std::cout << "В данный момент времени вы не можете купить этот товар." << std::endl;
                }
                selected_item = 0;
                is_set_good = false;
                break;
            case 27: is_set_good = false; break;
        }
    }
    return *this;
}


double Menu::getPoints()
{
    return points;
}

Menu& Menu::setPoints(double _points)
{
    if (_points > 0 && points <= 100) points += _points;
    return *this;
}
