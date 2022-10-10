#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <vector>
#include <regex>


std::unordered_map<std::string, int> fileToMap(std::string path);
int main(int argc, char* argv[]) {
    std::string pathToGenFrom;
    if(argc == 1) {
        std::cout << "Wprowadź ścieżkę do pliku z listą do przetworzenia: ";
        std::cin >> pathToGenFrom;
    } else if(argc == 2) {
        pathToGenFrom = std::string(argv[1]);
    } else {
        std::cerr << "Zła ilość argumentów, sprawdź plik readme.md!\n";
        return 1;
    }

    std::regex pathRegex(".+\\.txt");
    if(!std::regex_match(pathToGenFrom, pathRegex)) {
        std::cerr << "Błąd w ścieżce do pliku!!!\nUpewnij się, że twój plik jest w odpowiednim formacie!";
        return 1;
    }
    std::unordered_map<std::string, int> toGenMap = fileToMap(pathToGenFrom);
    std::vector<std::string> list{};

    for(const auto& [key, value] : toGenMap) {
        for(int i = 1; i <= value; i++) {
            list.push_back(key);
        }
    }

    int i = 1;

    std::ofstream file;
    file.open("list.lottery");
    for(auto& el : list) {
        file << i++ << " " << el<< '\n';
    }
    std::clog << "Plik został wygenerowany pomyślnie!\n";

    return 0;
}
std::unordered_map<std::string, int> fileToMap(std::string path) {
    std::ifstream file;
    file.open(path);
    if(!file.is_open()) {
        std::cerr << "Błąd wczytywania pliku!!!\nUpewnij się, że plik istnieje!";
    }
    std::unordered_map<std::string, int> map;
    std::string line;
    while(std::getline(file, line)) {
        map.emplace(std::make_pair(line.substr(0, line.find_first_of('\t')), std::stoi(line.substr(line.find_first_of('\t'), line.find_first_of('\n')))));
    }

    return map;
}
