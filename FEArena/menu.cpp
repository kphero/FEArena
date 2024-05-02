#include "menu.h"

void Menu::load() {
    std::ifstream fin("classes.txt");

    if (fin.is_open()) {
        for (int i = 0; i < TOTAL_CLASSES; i++) {
            baseClasses[i].importClass(fin);
        }
        std::cout << TOTAL_CLASSES << " classes imported..\n" << std::endl;
        fin.close();
    }
}

void Menu::header() {
    load();

    std::cout << "   _____           ____      __   __        \n";
    std::cout << "  / __(_)______   / __/_ _  / /  / /__ __ _ \n";
    std::cout << " / _// / __/ -_) / _//  ' \\/ _ \\/ / -_)  ' \\ \n";
    std::cout << "/_/ /_/_/_/ \\__/ /___/_/_/_/.__/_/\\__/_/_/_/ \n";
    std::cout << "      / _ | _______ ___  ___ _              \n";
    std::cout << "     / __ |/ __/ -_) _ \\/ _ `/              \n";
    std::cout << "    /_/ |_/_/  \\__/_//_/\\_,_/               \n" << std::endl;
}


void Menu::mainMenu() {
    int input;

    do {
        std::cout << "|-------- MAIN MENU --------|\n";
        std::cout << "| (1) New Character         |\n";
        std::cout << "| (2) Load Character        |\n";
        std::cout << "| (3) Convoy                |\n";
        std::cout << "| (0) Exit                  |\n";
        std::cout << "|---------------------------|\n" << std::endl;

        std::cout << "> ";
        std::cin >> input;
        std::cin.ignore(1000, '\n');

        switch (input) {
        case 0:
            std::cout << "Exiting game.." << std::endl;
            break;
        case 1:
            ncMenu();
            break;
        case 2:
            //lcMenu();
            break;
        case 3:
            //convoyMenu();
            break;
        default:
            std::cout << "Inalid choice. Please try again." << std::endl;
            break;
        }
    } while (input != 0);
}

void Menu::ncMenu() {
    current.createChar(baseClasses, TOTAL_CLASSES);
    //gameMenu(current);
}

//void Menu::lcMenu() {
//
//}


