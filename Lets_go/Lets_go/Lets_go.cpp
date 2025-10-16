#include <iostream>
//#include <time.h>
#include <string>
#include <windows.h>
#include <vector>
#include <string.h>
#include <cctype>


using namespace std;

struct Todo_list {
public:
    vector <string> tasks;
    string new_todo;

    vector <string> adding_to_the_list(string new_todo) {
        this->tasks = tasks;
        this->new_todo = new_todo;

        tasks.push_back(new_todo);
        return tasks;
    }
    void deleting_a_list(vector <string> tasks) {
        this->tasks = tasks;
        tasks.clear();
    }
    
};



int main() {
    setlocale(LC_ALL, "RU"); // исправлено: setlocale вместо setLocale
    

    char choosing_actions;

    cout << "Выберите что хотите сделать(выбрать число рядом с действием которое хотите выбрать)" << endl << "1.Добавить список дел" << endl << "2.Удалить список дел" << endl;
    cin >> choosing_actions;

    if (!isdigit(choosing_actions)) {

        cout << "Введите число";
    }
    else if(choosing_actions == '1'){
        cout << "Что хотите записать в спсок дел?" << endl;
        string zapros;
        cin >> zapros;
        Todo_list adding;
        vector <string> tasks = adding.adding_to_the_list(zapros);
        cout << tasks[0];

    }


    return 0;
}