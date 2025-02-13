#include "Header.h" 

void Menu::questSuccesful(std::vector<std::string>& menu_items, std::vector<std::string>& color_options, std::vector<std::string>& cursor_options)
{
    switch (getTotalScore())
    {
        case 0: setTotalScore(1); menu_items.push_back("Поменять цвет меню"); break;
        case 1: setTotalScore(1); menu_items.push_back("Курсоры"); color_options.push_back("Пурпурный"); break;
        case 2: setTotalScore(1); cursor_options.push_back("~$"); break;
        case 3: setTotalScore(1); cursor_options.push_back(":_>"); color_options.push_back("Бирюзовый"); break;
        case 4: setTotalScore(1); cursor_options.push_back("+");  break;
        case 5: setTotalScore(1); cursor_options.push_back("~"); color_options.push_back("Светло-синий"); menu_items.push_back("Магазин"); break;
        case 6: setTotalScore(1); cursor_options.push_back("~@"); break;
        case 7: setTotalScore(1); cursor_options.push_back("~%"); color_options.push_back("Синий"); break;
        case 8: setTotalScore(1); cursor_options.push_back("~#"); color_options.push_back("Жёлтый"); break;
        default: break;
    }
}

void Menu::quests()
{
    system("cls");
    switch (getTotalScore())
    {
        case 0: std::cout << "Квест (открыть меню с квестами) выполнен!" << std::endl; break;
        case 1: std::cout << "поменяйте инверсию" << std::endl; break;
        case 2: std::cout << "Нажмите на кнопку 'зеленый'" << std::endl; break;
        case 3: std::cout << "Поменяйте курсор на ~$" << std::endl; break;
        case 4: std::cout << "Нажмите на кнопку 'пурпурный'" << std::endl; break;
        case 5: std::cout << "Выключите инверсию и выберите курсор '+'" << std::endl; break;
        case 6: std::cout << "Купите необычный указатель: '-<x<o>>'" << std::endl; break;
        case 7: std::cout << "Выберите указатель '~>', включите инверсию и в конце выберите 'бирюзовый'" << std::endl; break;
        case 8: std::cout << "Наберите 100 points в магазине" << std::endl; break;
        default: std::cout << "Вы выполнили все квесты!" << std::endl; break;
    }

    if (getTotalScore() == 0) questSuccesful(menu_items, color_options, cursor_options);
}

int Menu::getTotalScore()
{
    return total_score;
}

Menu& Menu::setTotalScore(int _totalScore)
{
    if (total_score >= 0) total_score += _totalScore;
    return *this;
}
