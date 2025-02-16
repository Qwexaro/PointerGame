#include "Header.h" 

void Menu::questSuccesful(std::vector<std::string>& menu_items, std::vector<std::string>& color_options, std::vector<std::string>& cursor_options)
{
    switch (getTotalScore())
    {
        case 0: setTotalScore(1); menu_items.push_back("�������� ���� ����"); break;
        case 1: setTotalScore(1); menu_items.push_back("�������"); color_options.push_back("���������"); break;
        case 2: setTotalScore(1); cursor_options.push_back("~$"); break;
        case 3: setTotalScore(1); cursor_options.push_back(":_>"); color_options.push_back("���������"); break;
        case 4: setTotalScore(1); cursor_options.push_back("+");  break;
        case 5: setTotalScore(1); cursor_options.push_back("~"); color_options.push_back("������-�����"); menu_items.push_back("�������"); break;
        case 6: setTotalScore(1); cursor_options.push_back("~@"); break;
        case 7: setTotalScore(1); cursor_options.push_back("~%"); color_options.push_back("�����"); break;
        case 8: setTotalScore(1); cursor_options.push_back("~#"); color_options.push_back("Ƹ����"); break;
        default: break;
    }
}

void Menu::quests()
{
    system("cls");
    switch (getTotalScore())
    {
        case 0: std::cout << "����� (������� ���� � ��������) ��������!" << std::endl; break;
        case 1: std::cout << "��������� ��������" << std::endl; break;
        case 2: std::cout << "������� �� ������ '�������'" << std::endl; break;
        case 3: std::cout << "��������� ������ �� ~$" << std::endl; break;
        case 4: std::cout << "������� �� ������ '���������'" << std::endl; break;
        case 5: std::cout << "��������� �������� � �������� ������ '+'" << std::endl; break;
        case 6: std::cout << "������ ��������� ���������: '-<x<o>>'" << std::endl; break;
        case 7: std::cout << "�������� ��������� '~>', �������� �������� � � ����� �������� '���������'" << std::endl; break;
        case 8: std::cout << "�������� 100 points � ��������" << std::endl; break;
        default: std::cout << "�� ��������� ��� ������!" << std::endl; break;
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
