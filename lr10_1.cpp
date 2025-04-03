#include <iostream>
#include <string>

// ���� ������
template <typename T>
struct Node {
    T data;         // ������ ����
    Node* next;     // ��������� �� ��������� ����

    // ����������� ����
    Node(T data) : data(data), next(nullptr) {}
};

// ����� ������������ ������
template <typename T>
class SimpleList {
private:
    Node<T>* head;  // ��������� �� ������ ����

public:
    // ����������� - ������� ������ ������
    SimpleList() : head(nullptr) {}

    // ���������� - ����������� ������
    ~SimpleList() {
        clear();
    }

    // ���������� �������� � ����� ������
    void append(T value) {
        Node<T>* newNode = new Node<T>(value);

        if (!head) {
            // ���� ������ ����, ����� ���� ���������� �������
            head = newNode;
        }
        else {
            // ���� ��������� ����
            Node<T>* current = head;
            while (current->next) {
                current = current->next;
            }
            // ��������� ����� ���� � �����
            current->next = newNode;
        }
    }

    // �������� �������� �� ������
    void remove(T value) {
        if (!head) return;

        Node<T>* current = head;
        Node<T>* prev = nullptr;

        // ���� ���� � �������� ���������
        while (current && current->data != value) {
            prev = current;
            current = current->next;
        }

        if (!current) return; // ���� �� ������

        if (!prev) {
            // ������� ������ ������
            head = current->next;
        }
        else {
            // ������� ���� �� ��������/�����
            prev->next = current->next;
        }

        delete current;
    }

    // �������� ������� �������� � ������
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

    // ����� ������
    void print() const {
        Node<T>* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // ������� ������
    void clear() {
        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }
};