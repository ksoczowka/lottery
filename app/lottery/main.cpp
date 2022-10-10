#include <chrono>
#include <fstream>
#include <iostream>
#include <map>
#include <regex>
#include <string>
#if defined(__linux__)
#include <cstdlib>
#define clr() system("clear")
#elif defined(_WIN32)
#include <windows.h>
#define clr() system("cls")
#endif

// takes list from file in given path and puts it in the int-string map
std::map<int, std::string> fileToMap(std::string path);
// takes int-string map and puts it in the file in given path
void mapToFile(std::string path, std::map<int, std::string> map);
int main() {
    std::string input;
    int number;

    std::regex numbersRegex("[0-9]+");
    std::regex quitRegex("q|quit|x|exit", std::regex_constants::icase);
    std::regex saveRegex("s|save|w|write", std::regex_constants::icase);
    std::regex confirmRegex("t|tak|y|yes", std::regex_constants::icase);

    const std::map<int, std::string> mainList = fileToMap("list.lottery");
    std::map<int, std::string> remainingList = fileToMap("remainingItems.lottery");
    std::map<int, std::string> usedList = fileToMap("usedItems.lottery");
    std::map<int, std::string> logs = fileToMap("logs.lottery");

    // if there is no items in the remainingItems.lottery and no items in usedItems.lottery it means that all items should be remaining
    if(remainingList.empty() && usedList.empty()){
        remainingList = mainList;
        mapToFile("remainingItems.lottery", remainingList);
    } 

    while(true) {
        clr();
        std::cout << "Wpisz numer lub operację: ";
        std::cin >> input;
        // exit
        if(std::regex_match(input, quitRegex)) {
            logs.emplace(std::make_pair(logs.size() + 1, " -- application: exit"));
            mapToFile("./logs.lottery", logs);
            auto save = std::string();
            std::cout << "Potwierdź zapis list ([y]es/[t]ak lub [n]ie/[n]o): ";
            std::cin >> save;
            // save on exit
            if(std::regex_match(save, confirmRegex)) {
                mapToFile("./remainingItems.lottery", remainingList);
                mapToFile("./usedItems.lottery", usedList);
                std::clog << "Zapisano listy!\n";
                logs.emplace(std::make_pair(logs.size() + 1, " -- application: exit-save"));
                mapToFile("./logs.lottery", logs);
                getchar(); getchar();
            }
            break;
        }
        // save
        if(std::regex_match(input, saveRegex)) {
            mapToFile("./remainingItems.lottery", remainingList);
            mapToFile("./usedItems.lottery", usedList);
            std::clog << "Zapisano listy!\n";
            logs.emplace(std::make_pair(logs.size() + 1, " -- application: save"));
            mapToFile("./logs.lottery", logs);
            getchar(); getchar();
        }
        // search
        if(std::regex_match(input, numbersRegex)) {
            number = std::stoi(input);
            if(number > mainList.size() || !remainingList.contains(number)) { 
                std::clog << "Nie ma takiego numer!!!\n";
                getchar(); getchar();
                continue; 
            }
            std::cout << "Numer: " << number << '\n';
            std::cout << "Przedmiot: " << remainingList[number];
            std::cout << "\nPotwierdź usunięcie przedmiotu z wyszukiwania ([y]es/[t]ak lub [n]ie/[n]o): ";
            std::string out;
            std::cin >> out;
            if(std::regex_match(out, confirmRegex)) {
                std::cout << "Przedmiot usunięty z wyszukiwania";
                usedList.emplace(std::make_pair(number, remainingList[number]));
                logs.emplace(std::make_pair(logs.size() + 1, " -- item: " + input + " --" + remainingList[number] + " | saved"));
                remainingList.erase(number);
            } else {
                std::cout << "Przedmiot zachowany do dalszego wyszukiwania";
                logs.emplace(std::make_pair(logs.size() + 1, " -- item: " + input + " --" + remainingList[number] + " | not saved"));
            }
            getchar(); getchar();
        }

    }

    return 0;
}

std::map<int, std::string> fileToMap(std::string path) {
    std::map<int, std::string> ret;

    std::ifstream file;
    file.open(path);
    if(!file.is_open()) {
        std::cerr << "Błąd wczytywania pliku!!!\nUpewnij się, że plik istnieje!";
    }
    std::string line;
    while(std::getline(file, line)) {
        int key = std::stoi(line.substr(0, line.find_first_of(' '))); // a number from list.lottery
        std::string value = line.substr(line.find_first_of(' '), line.find_first_of('\n')); // a name from list.lottery
        ret.emplace(std::make_pair(key, value));
    }
    file.close();

    return ret;
}
void mapToFile(std::string path, std::map<int, std::string> map) {
    std::ofstream file;
    file.open(path);
    if(!file.is_open()) {
        std::cerr << "Błąd wczytywania pliku!!!\nUpewnij się, że plik istnieje!";
    }
    for(const auto& [key, value] : map) {
        file << key <<  value << '\n';
    }
    file.close();
}
