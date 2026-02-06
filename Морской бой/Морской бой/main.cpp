#include "func_main.h"
#include <cstdlib>  

int main()
{
    setlocale(0, "");
    srand(time(NULL));


    int* array_shots_computer = new int[100] ;
    int* array_shots_player = new int[100];
    string coordinates_ships_player[3];
    int coordinates_computer_ships[3];
    bool victory = false;

    computer_melts_the_ships(coordinates_computer_ships);
    ship_coordinates_player(coordinates_ships_player);
    cout << endl << "Поля игрока: " << endl;
    print_map_player(coordinates_ships_player, array_shots_computer, 0);
    cout << endl << "Поля компьютера: " << endl;
    print_map_computer(coordinates_computer_ships, array_shots_player, 0);

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Нажмите Enter для того чтобы продолжить ";
    cin.get();
    system("cls");

    cout << endl;
    for (int j = 0; j < 37; j++) {
        playrs_shots(array_shots_player, j);
        system("cls");
        computer_shots(array_shots_computer, j);
        cout << endl << "Поля игрока: " << endl;
        print_map_player(coordinates_ships_player, array_shots_computer, j);
        cout << endl << "Поля компьютера: " << endl;
        print_map_computer(coordinates_computer_ships, array_shots_player, j + 1);
        bool winner_player = victory_player(array_shots_player, coordinates_computer_ships, j);
        if (winner_player == true) {
            cout << endl << "Игрок победил!!";
            victory = true;
            break;
        }
        bool winner_pc = victory_computer(array_shots_computer, coordinates_ships_player, j);
        if (winner_pc == true) {
            cout << endl << "Компьютер победил!!";
            victory = true;
            break;
        }
    }
    delete[]array_shots_computer;
    delete[]array_shots_player;
}










