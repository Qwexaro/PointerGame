#include "Header.h" 

void Menu::saveSettings()
{
    int selected_setting = 0;
    bool is_set_save = true;

    while (is_set_save)
    {
        system("cls");
        
        for (int i = 0; i < save_options.size(); i++)
        {
            if (i == selected_setting)
            {
                std::cout << cursor << save_options.at(i) << std::endl;
            }
            else
            {
                std::cout << "   " << save_options.at(i) << std::endl;
            }
        }

        char ch = _getch();

        switch (ch)
        {
            case 72: if (selected_setting > 0) selected_setting--; break;
            case 80: if (selected_setting < save_options.size() - 1) selected_setting++; break;
            case 13:
                switch (selected_setting)
                {
                    case 0: save(); break;
                    case 1: loadSave(menu_items, color_options, cursor_options, cursor, total_score); break;
                    default: std::cout << "da." << std::endl;
                }
                selected_item = 0; // Сброс выделения
                is_set_save = false;
                break;
            case 27: is_set_save = false; break;
        }
    }
}

void Menu::save()
{
    std::ofstream save_file("Save.txt");
    if (save_file.is_open())
    {
        save_file << selected_item << std::endl;
        save_file << is_inverted << std::endl;
        save_file << cursor << std::endl;
        save_file << total_score << std::endl;
        save_file << is_miracle_pointer << std::endl;
        save_file << is_NotePad << std::endl;

        int menu_size = menu_items.size();
        save_file << menu_size << std::endl;

        for (int i = 0; i < menu_items.size(); i++)
        {
            save_file << menu_items.at(i) << std::endl;
        }

        int size_color = color_options.size();
        save_file << size_color << std::endl;

        for (int i = 0; i < color_options.size(); i++)
        {
            save_file << color_options.at(i) << std::endl;
        }

        int cursor_size = cursor_options.size();
        save_file << cursor_size << std::endl;

        for (int i = 0; i < cursor_options.size(); i++)
        {
            save_file << cursor_options.at(i) << std::endl; 
        }

        save_file.close();
    }
    else
    {
        std::cout << "Ошибка подключения к файлу" << std::endl;
    }
}

Menu& Menu::loadSave(std::vector<std::string>& _menu_items, std::vector<std::string>& _color_options, std::vector<std::string>& _cursor_options, std::string& _cursor, int& _total_score)
{
    std::ifstream load_progress_from_save_file("Save.txt");
    if (load_progress_from_save_file.is_open())
    {
        load_progress_from_save_file >> selected_item;
        load_progress_from_save_file >> is_inverted;
        load_progress_from_save_file >> cursor;
        load_progress_from_save_file >> total_score;
        load_progress_from_save_file >> is_miracle_pointer;
        load_progress_from_save_file >> is_NotePad;
        load_progress_from_save_file.ignore();

        int menu_size;
        load_progress_from_save_file >> menu_size;
        load_progress_from_save_file.ignore(); 
        menu_items.clear();
        for (int i = 0; i < menu_size; i++)
        {
            std::string item;
            std::getline(load_progress_from_save_file, item);
            menu_items.push_back(item);
        }

        int size_color;
        load_progress_from_save_file >> size_color;
        load_progress_from_save_file.ignore();
        color_options.clear();
        for (int i = 0; i < size_color; i++)
        {
            std::string color;
            std::getline(load_progress_from_save_file, color);
            color_options.push_back(color);
        }

        int cursor_size;
        load_progress_from_save_file >> cursor_size;
        load_progress_from_save_file.ignore();
        cursor_options.clear();
        for (int i = 0; i < cursor_size; i++)
        {
            std::string cursor_item;
            std::getline(load_progress_from_save_file, cursor_item);
            cursor_options.push_back(cursor_item);
        }

        load_progress_from_save_file.close();
    }
    else
    {
        std::cout << "Файл сохранения отсутствует" << std::endl;
    }
    
    system("color 7");
    return *this;
}