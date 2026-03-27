#include "FilmArray.h"
#include <iomanip>
#include <limits>

FilmArray::FilmArray() {
    // Вектор уже пуст, ничего не нужно делать
}

void FilmArray::addFilm(const Film& film) {
    films.push_back(film);  // Вектор сам расширяется!
    std::cout << "Фильм успешно добавлен!\n";
}

void FilmArray::removeFilm(int id) {
    auto it = std::find_if(films.begin(), films.end(),
                           [id](const Film& f) { return f.getId() == id; });
    
    if (it != films.end()) {
        films.erase(it);
        std::cout << "Фильм с ID " << id << " удален.\n";
    } else {
        std::cout << "Фильм с ID " << id << " не найден.\n";
    }
}

Film* FilmArray::findFilm(int id) {
    auto it = std::find_if(films.begin(), films.end(),
                           [id](const Film& f) { return f.getId() == id; });
    
    if (it != films.end()) {
        return &(*it);  // Возвращаем указатель на найденный фильм
    }
    return nullptr;
}

int FilmArray::getSize() const {
    return films.size();
}

bool FilmArray::isEmpty() const {
    return films.empty();
}

void FilmArray::displayAll() const {
    if (isEmpty()) {
        std::cout << "База данных пуста.\n";
        return;
    }
    
    std::cout << "\n=== Список всех фильмов ===\n";
    std::cout << "ID  | Название                     | Жанр         | Длит. | Рейтинг | Год\n";
    std::cout << "----|------------------------------|--------------|-------|---------|-----\n";
    
    for (const auto& film : films) {
        film.display();
        std::cout << "\n";
    }
    std::cout << "Всего фильмов: " << films.size() << "\n";
}

void FilmArray::searchByGenre(const std::string& genre) const {
    std::cout << "\nРезультаты поиска по жанру '" << genre << "':\n";
    std::cout << "ID  | Название                     | Жанр         | Длит. | Рейтинг | Год\n";
    std::cout << "----|------------------------------|--------------|-------|---------|-----\n";
    
    int found = 0;
    for (const auto& film : films) {
        if (film.getGenre().find(genre) != std::string::npos) {
            film.display();
            std::cout << "\n";
            found++;
        }
    }
    std::cout << "\nНайдено фильмов: " << found << "\n";
}

void FilmArray::searchByRating(double minRating) const {
    std::cout << "\nРезультаты поиска с рейтингом >= " << minRating << ":\n";
    std::cout << "ID  | Название                     | Жанр         | Длит. | Рейтинг | Год\n";
    std::cout << "----|------------------------------|--------------|-------|---------|-----\n";
    
    int found = 0;
    for (const auto& film : films) {
        if (film.getRating() >= minRating) {
            film.display();
            std::cout << "\n";
            found++;
        }
    }
    std::cout << "\nНайдено фильмов: " << found << "\n";
}

void FilmArray::searchByYear(int year) const {
    std::cout << "\nРезультаты поиска за " << year << " год:\n";
    std::cout << "ID  | Название                     | Жанр         | Длит. | Рейтинг | Год\n";
    std::cout << "----|------------------------------|--------------|-------|---------|-----\n";
    
    int found = 0;
    for (const auto& film : films) {
        if (film.getYear() == year) {
            film.display();
            std::cout << "\n";
            found++;
        }
    }
    std::cout << "\nНайдено фильмов: " << found << "\n";
}

void FilmArray::editFilm(int id) {
    Film* film = findFilm(id);
    if (!film) {
        std::cout << "Фильм с ID " << id << " не найден.\n";
        return;
    }
    
    std::cout << "\nРедактирование фильма (ID: " << id << ")\n";
    std::cout << "Оставьте поле пустым (нажмите Enter), чтобы не изменять его.\n\n";
    
    std::string input;
    std::cin.ignore();
    
    // Редактирование названия
    std::cout << "Текущее название: " << film->getTitle() << "\n";
    std::cout << "Новое название: ";
    std::getline(std::cin, input);
    if (!input.empty()) {
        film->setTitle(input);
    }
    
    // Редактирование жанра
    std::cout << "Текущий жанр: " << film->getGenre() << "\n";
    std::cout << "Новый жанр: ";
    std::getline(std::cin, input);
    if (!input.empty()) {
        film->setGenre(input);
    }
    
    // Редактирование длительности
    std::cout << "Текущая длительность: " << film->getDuration() << "\n";
    std::cout << "Новая длительность (0 чтобы не менять): ";
    std::getline(std::cin, input);
    if (!input.empty() && std::stoi(input) != 0) {
        film->setDuration(std::stoi(input));
    }
    
    // Редактирование рейтинга
    std::cout << "Текущий рейтинг: " << film->getRating() << "\n";
    std::cout << "Новый рейтинг (0 чтобы не менять): ";
    std::getline(std::cin, input);
    if (!input.empty() && std::stod(input) != 0) {
        film->setRating(std::stod(input));
    }
    
    // Редактирование года
    std::cout << "Текущий год: " << film->getYear() << "\n";
    std::cout << "Новый год (0 чтобы не менять): ";
    std::getline(std::cin, input);
    if (!input.empty() && std::stoi(input) != 0) {
        film->setYear(std::stoi(input));
    }
    
    std::cout << "Фильм успешно отредактирован!\n";
}

const std::vector<Film>& FilmArray::getAllFilms() const {
    return films;
}

int FilmArray::getNextId() const {
    if (films.empty()) return 1;
    return films.back().getId() + 1;
}
