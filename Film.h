#ifndef FILM_H
#define FILM_H

#include <string>
#include <iostream>

class Film {
private:
    int id;
    std::string title;
    std::string genre;
    int duration;     // в минутах
    double rating;    // 0.0-10.0
    int year;

public:
    // Конструкторы
    Film();
    Film(int id, const std::string& title, const std::string& genre, 
         int duration, double rating, int year);
    
    // Геттеры (получение данных)
    int getId() const;
    std::string getTitle() const;
    std::string getGenre() const;
    int getDuration() const;
    double getRating() const;
    int getYear() const;
    
    // Сеттеры (изменение данных)
    void setId(int newId);
    void setTitle(const std::string& newTitle);
    void setGenre(const std::string& newGenre);
    void setDuration(int newDuration);
    void setRating(double newRating);
    void setYear(int newYear);
    
    // Ввод/вывод
    void input();           // Запрос данных у пользователя
    void display() const;   // Вывод фильма на экран
    
    // Операторы сравнения
    bool operator==(int filmId) const;  // Сравнение по ID
};

#endif
