#ifndef FILMARRAY_H
#define FILMARRAY_H

#include "Film.h"
#include <vector>
#include <algorithm>

class FilmArray {
private:
    std::vector<Film> films;  // Вектор вместо ручного управления памятью!
    
public:
    // Конструктор
    FilmArray();
    
    // Основные операции
    void addFilm(const Film& film);
    void removeFilm(int id);
    Film* findFilm(int id);
    int getSize() const;
    bool isEmpty() const;
    
    // Поиск и вывод
    void displayAll() const;
    void searchByGenre(const std::string& genre) const;
    void searchByRating(double minRating) const;
    void searchByYear(int year) const;
    
    // Редактирование
    void editFilm(int id);
    
    // Получение всех фильмов (для сохранения)
    const std::vector<Film>& getAllFilms() const;
    
    // Следующий ID
    int getNextId() const;
};

#endif
