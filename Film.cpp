#include "Film.h"
#include <limits>

// Конструктор по умолчанию
Film::Film() : id(0), duration(0), rating(0.0), year(0) {}

// Конструктор с параметрами
Film::Film(int id, const std::string& title, const std::string& genre,
           int duration, double rating, int year)
    : id(id), title(title), genre(genre), duration(duration), 
      rating(rating), year(year) {}

// Геттеры
int Film::getId() const { return id; }
std::string Film::getTitle() const { return title; }
std::string Film::getGenre() const { return genre; }
int Film::getDuration() const { return duration; }
double Film::getRating() const { return rating; }
int Film::getYear() const { return year; }

// Сеттеры
void Film::setId(int newId) { id = newId; }
void Film::setTitle(const std::string& newTitle) { title = newTitle; }
void Film::setGenre(const std::string& newGenre) { genre = newGenre; }
void Film::setDuration(int newDuration) { duration = newDuration; }
void Film::setRating(double newRating) { rating = newRating; }
void Film::setYear(int newYear) { year = newYear; }

// Ввод данных от пользователя
void Film::input() {
    std::cout << "Введите название фильма: ";
    std::cin.ignore();
    std::getline(std::cin, title);
    
    std::cout << "Введите жанр: ";
    std::getline(std::cin, genre);
    
    std::cout << "Введите длительность (в минутах): ";
    std::cin >> duration;
    
    std::cout << "Введите рейтинг (0.0-10.0): ";
    std::cin >> rating;
    
    std::cout << "Введите год выпуска: ";
    std::cin >> year;
}

// Вывод фильма на экран
void Film::display() const {
    std::cout << id << " | " 
              << title;
    // Выравнивание для красивой таблицы
    for (int i = title.length(); i < 28; i++) std::cout << " ";
    std::cout << " | " << genre;
    for (int i = genre.length(); i < 12; i++) std::cout << " ";
    std::cout << " | " << duration << "  | " << rating << "   | " << year;
}

// Оператор сравнения по ID
bool Film::operator==(int filmId) const {
    return id == filmId;
}
