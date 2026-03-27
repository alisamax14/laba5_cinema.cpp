#include "FilmArray.h"
#include "File_Operations.h"
#include <iostream>
#include <limits>

void printMenu() {
    std::cout << "\n=== Управление базой данных кинотеатра ===\n";
    std::cout << "1. Вывести все фильмы\n";
    std::cout << "2. Найти фильмы\n";
    std::cout << "3. Добавить новый фильм\n";
    std::cout << "4. Удалить фильм\n";
    std::cout << "5. Редактировать фильм\n";
    std::cout << "6. Сохранить изменения в файл\n";
    std::cout << "0. Выйти из программы\n";
    std::cout << "Выберите действие: ";
}

void searchMenu(FilmArray& films) {
    if (films.isEmpty()) {
        std::cout << "База данных пуста.\n";
        return;
    }
    
    std::cout << "\n=== Поиск фильмов ===\n";
    std::cout << "1. По жанру\n";
    std::cout << "2. По рейтингу (выше указанного)\n";
    std::cout << "3. По году выпуска\n";
    std::cout << "Выберите критерий поиска: ";
    
    int choice;
    std::cin >> choice;
    
    switch (choice) {
        case 1: {
            std::string genre;
            std::cout << "Введите жанр для поиска: ";
            std::cin.ignore();
            std::getline(std::cin, genre);
            films.searchByGenre(genre);
            break;
        }
        case 2: {
            double minRating;
            std::cout << "Введите минимальный рейтинг: ";
            std::cin >> minRating;
            films.searchByRating(minRating);
            break;
        }
        case 3: {
            int year;
            std::cout << "Введите год выпуска: ";
            std::cin >> year;
            films.searchByYear(year);
            break;
        }
        default:
            std::cout << "Неверный выбор.\n";
    }
}

int main() {
    const std::string FILENAME = "cinema_database.bin";
    
    // Загрузка данных
    FilmArray films = FileOperations::loadFromFile(FILENAME);
    
    int choice;
    
    do {
        printMenu();
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                films.displayAll();
                break;
                
            case 2:
                searchMenu(films);
                break;
                
            case 3: {
                Film newFilm;
                newFilm.setId(films.getNextId());
                newFilm.input();
                films.addFilm(newFilm);
                FileOperations::saveToFile(FILENAME, films);
                break;
            }
                
            case 4: {
                int id;
                std::cout << "Введите ID фильма для удаления: ";
                std::cin >> id;
                films.removeFilm(id);
                FileOperations::saveToFile(FILENAME, films);
                break;
            }
                
            case 5: {
                int id;
                std::cout << "Введите ID фильма для редактирования: ";
                std::cin >> id;
                films.editFilm(id);
                FileOperations::saveToFile(FILENAME, films);
                break;
            }
                
            case 6:
                FileOperations::saveToFile(FILENAME, films);
                break;
                
            case 0:
                std::cout << "Выход из программы...\n";
                break;
                
            default:
                std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
        
    } while (choice != 0);
    
    // Финальное сохранение
    FileOperations::saveToFile(FILENAME, films);
    
    return 0;
}
