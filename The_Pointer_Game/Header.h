#include <iostream> 
#include <vector> 
#include <string> 
#include <conio.h> 
#include <fstream> 

class Menu
{
    int selected_item;
    std::vector<std::string> menu_items;
    void printMenu();
    void executeOption(int option);

    void control();
    void controlInversion(bool& _is_inverted);
    int control_value;
    bool is_inverted;

    std::vector<std::string> cursor_options;
    std::vector<std::string> color_options;
    std::vector<std::string> save_options;

    int total_score;
    void quests();
    void questSuccesful(std::vector<std::string>& _menu_items, std::vector<std::string>& _color_options, std::vector<std::string>& _cursor_options);
    int getTotalScore();
    Menu& setTotalScore(int _totalScore);

    Menu& setColorConsole();

    std::string cursor;
    Menu& setCursor(std::string& _cursor);

    void saveSettings();
    void save();
    Menu& loadSave(std::vector<std::string>& _menu_items, std::vector<std::string>& _color_options, std::vector<std::string>& _cursor_options, std::string& _cursor, int& _total_score);
    
    Menu& shopMenu();
    std::vector<std::string> goods_options;
    double points;
    double getPoints();
    Menu& setPoints(double _points);
    bool is_miracle_pointer;
    bool is_NotePad;
    bool is_evolution_fragment;
    bool is_first_buy;

public:

    Menu();
    void displayMenu();
};

//Теория эволюции указателей

/*
    :_> | :_>> | :x:_>>
     ~> | ~>>  | -<x>>
     ~# | ~<#> | -<<#>
     +  | (+)  | -(+)>
*/
