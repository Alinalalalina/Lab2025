#include <iostream>
#include <string>

// Узел списка
template <typename T>
struct Node {
    T data;         // Данные узла
    Node* next;     // Указатель на следующий узел

    // Конструктор узла
    Node(T data) : data(data), next(nullptr) {}
};

// Класс односвязного списка
template <typename T>
class SimpleList {
private:
    Node<T>* head;  // Указатель на первый узел

public:
    // Конструктор - создает пустой список
    SimpleList() : head(nullptr) {}

    // Деструктор - освобождает память
    ~SimpleList() {
        clear();
    }

    // Добавление элемента в конец списка
    void append(T value) {
        Node<T>* newNode = new Node<T>(value);

        if (!head) {
            // Если список пуст, новый узел становится головой
            head = newNode;
        }
        else {
            // Ищем последний узел
            Node<T>* current = head;
            while (current->next) {
                current = current->next;
            }
            // Добавляем новый узел в конец
            current->next = newNode;
        }
    }

    // Удаление элемента из списка
    void remove(T value) {
        if (!head) return;

        Node<T>* current = head;
        Node<T>* prev = nullptr;

        // Ищем узел с заданным значением
        while (current && current->data != value) {
            prev = current;
            current = current->next;
        }

        if (!current) return; // Узел не найден

        if (!prev) {
            // Удаляем голову списка
            head = current->next;
        }
        else {
            // Удаляем узел из середины/конца
            prev->next = current->next;
        }

        delete current;
    }

    // Проверка наличия элемента в списке
    bool has(T value) const {
        Node<T>* current = head;
        while (current) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // Вывод списка
    void print() const {
        Node<T>* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Очистка списка
    void clear() {
        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }
};