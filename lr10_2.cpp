#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Структура для хранения информации об автобусе
struct Bus {
    int number;         // Номер автобуса
    std::string driver; // Имя водителя
    int route;         // Номер маршрута

    // Оператор сравнения для поиска по номеру
    bool operator==(const Bus& other) const {
        return number == other.number;
    }

    // Оператор вывода для удобного отображения
    friend std::ostream& operator<<(std::ostream& os, const Bus& bus) {
        os << "Автобус №" << bus.number
            << " (Водитель: " << bus.driver
            << ", Маршрут: " << bus.route << ")";
        return os;
    }
};

// Класс для управления автобусным парком
class BusPark {
private:
    std::vector<Bus> inPark;   // Автобусы в парке
    std::vector<Bus> onRoute;  // Автобусы на маршруте

public:
    // Добавить новый автобус в парк
    void addBus(int number, const std::string& driver, int route) {
        Bus newBus{ number, driver, route };
        inPark.push_back(newBus);
        std::cout << "Добавлен " << newBus << std::endl;
    }

    // Отправить автобус на маршрут
    void sendBus(int number) {
        auto it = std::find(inPark.begin(), inPark.end(), Bus{ number, "", 0 });

        if (it != inPark.end()) {
            onRoute.push_back(*it);
            inPark.erase(it);
            std::cout << "Автобус №" << number << " вышел на маршрут" << std::endl;
        }
        else {
            std::cout << "Ошибка: Автобус №" << number << " не найден в парке" << std::endl;
        }
    }

    // Вернуть автобус в парк
    void returnBus(int number) {
        auto it = std::find(onRoute.begin(), onRoute.end(), Bus{ number, "", 0 });

        if (it != onRoute.end()) {
            inPark.push_back(*it);
            onRoute.erase(it);
            std::cout << "Автобус №" << number << " вернулся в парк" << std::endl;
        }
        else {
            std::cout << "Ошибка: Автобус №" << number << " не найден на маршруте" << std::endl;
        }
    }

    // Показать автобусы в парке
    void showParked() const {
        std::cout << "\nАвтобусы в парке (" << inPark.size() << "):\n";
        for (const auto& bus : inPark) {
            std::cout << "  " << bus << std::endl;
        }
    }

    // Показать автобусы на маршруте
    void showOnRoute() const {
        std::cout << "\nАвтобусы на маршруте (" << onRoute.size() << "):\n";
        for (const auto& bus : onRoute) {
            std::cout << "  " << bus << std::endl;
        }
    }
};

int main() {
    BusPark park;

    // Добавляем автобусы в парк
    park.addBus(101, "test1", 5);
    park.addBus(102, "test2", 10);
    park.addBus(103, "test3", 15);

    // Показываем текущее состояние
    park.showParked();
    park.showOnRoute();

    // Отправляем автобус на маршрут
    park.sendBus(101);
    park.showParked();
    park.showOnRoute();

    // Возвращаем автобус в парк
    park.returnBus(101);
    park.showParked();
    park.showOnRoute();

    // Пробуем отправить несуществующий автобус
    park.sendBus(999);

    return 0;
}