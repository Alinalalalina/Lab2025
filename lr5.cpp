#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

class FileProcessor {
private:
    string inputFilename;
    string outputFilename;
    string key;

public:
    // Конструктор
    FileProcessor() = default;

    // Установка имени входного файла
    void setInputFilename(const string& filename) {
        inputFilename = filename;
    }

    // Установка имени выходного файла
    void setOutputFilename(const string& filename) {
        outputFilename = filename;
    }

    // Установка ключа шифрования
    void setKey(const string& k) {
        key = k;
    }

    // Вывод содержимого файла на экран
    void printFileContents() const {
        ifstream file(inputFilename);
        if (!file.is_open()) {
            cerr << "Ошибка: не удалось открыть файл " << inputFilename << endl;
            return;
        }

        char ch;
        while (file.get(ch)) {
            cout << ch;
        }

        file.close();
    }

    // Подсчет "пустых" и "непустых" символов
    void countCharacters() const {
        ifstream file(inputFilename);
        if (!file.is_open()) {
            cerr << "Ошибка: не удалось открыть файл " << inputFilename << endl;
            return;
        }

        int empty = 0, nonEmpty = 0;
        char ch;

        while (file.get(ch)) {
            if (isspace(ch) || iscntrl(ch)) {
                empty++;
            }
            else {
                nonEmpty++;
            }
        }

        cout << "Пустых символов: " << empty << endl;
        cout << "Непустых символов: " << nonEmpty << endl;

        file.close();
    }

    // Поиск подстроки в файле
    void searchSubstring(const string& substring) const {
        ifstream input(inputFilename);
        ofstream output(outputFilename);

        if (!input.is_open()) {
            cerr << "Ошибка: не удалось открыть файл " << inputFilename << endl;
            return;
        }

        if (!output.is_open()) {
            cerr << "Ошибка: не удалось создать файл " << outputFilename << endl;
            return;
        }

        string line;
        int lineNumber = 0;
        bool found = false;

        while (getline(input, line)) {
            lineNumber++;
            size_t pos = line.find(substring);
            if (pos != string::npos) {
                found = true;
                output << "Строка " << lineNumber << ", позиция " << pos << ": " << line << endl;
            }
        }

        if (!found) {
            output << "Подстрока '" << substring << "' не найдена в файле." << endl;
        }

        input.close();
        output.close();
    }

    // Обработка номеров страниц
    void processPageNumbers() const {
        ifstream input(inputFilename);
        ofstream output(outputFilename);

        if (!input.is_open() || !output.is_open()) {
            cerr << "Ошибка открытия файлов" << endl;
            return;
        }

        string pageNumber;
        string pageContent;
        string line;
        bool firstLine = true;

        while (getline(input, line)) {
            if (firstLine) {
                // Извлекаем номер страницы (формат: - 34 -)
                size_t start = line.find_first_of("0123456789");
                size_t end = line.find_last_of("0123456789");
                if (start != string::npos && end != string::npos) {
                    pageNumber = line.substr(start, end - start + 1);
                }
                firstLine = false;
            }
            else if (line.find('\t') != string::npos) {
                // Конец страницы - записываем номер в конец
                output << pageContent;
                output << pageNumber << endl;
                pageContent.clear();
                firstLine = true;
            }
            else {
                pageContent += line + "\n";
            }
        }

        // Записываем последнюю страницу
        if (!pageContent.empty()) {
            output << pageContent;
            output << pageNumber << endl;
        }

        input.close();
        output.close();
    }

    // Шифрование файла
    void encryptFile() const {
        ifstream input(inputFilename, ios::binary);
        ofstream output(outputFilename, ios::binary);

        if (!input.is_open() || !output.is_open()) {
            cerr << "Ошибка открытия файлов" << endl;
            return;
        }

        char ch;
        size_t keyIndex = 0;

        while (input.get(ch)) {
            // Шифруем символ: XOR с символом ключа
            char encrypted = ch ^ key[keyIndex % key.length()];
            output.put(encrypted);
            keyIndex++;
        }

        input.close();
        output.close();
    }
};

// Функция для отображения меню
void showMenu() {
    system("cls"); // Очистка экрана (для Windows)

    cout << "Лабораторная работа 5: Работа с файлами" << endl;
    cout << "1. Вывести содержимое файла" << endl;
    cout << "2. Подсчитать пустые и непустые символы" << endl;
    cout << "3. Найти подстроку в файле" << endl;
    cout << "4. Обработать номера страниц" << endl;
    cout << "5. Зашифровать файл" << endl;
    cout << "0. Выход" << endl;
    cout << "Выберите действие: ";
}

int main(int argc, char* argv[]) {
    FileProcessor processor;

    // Режим командной строки для шифратора
    if (argc == 4) {
        processor.setInputFilename(argv[1]);
        processor.setOutputFilename(argv[2]);
        processor.setKey(argv[3]);
        processor.encryptFile();
        cout << "Файл успешно зашифрован." << endl;
        return 0;
    }

    // Интерактивный режим
    while (true) {
        showMenu();
        int choice;
        cin >> choice;
        cin.ignore(); // Очищаем буфер ввода

        string filename, filename2, substring, key;

        switch (choice) {
        case 1:
            cout << "Введите имя файла: ";
            cin >> filename;
            processor.setInputFilename(filename);
            processor.printFileContents();
            break;

        case 2:
            cout << "Введите имя файла: ";
            cin >> filename;
            processor.setInputFilename(filename);
            processor.countCharacters();
            break;

        case 3:
            cout << "Введите имя файла: ";
            cin >> filename;
            processor.setInputFilename(filename);
            cout << "Введите подстроку для поиска: ";
            getline(cin, substring);
            cout << "Введите имя выходного файла: ";
            cin >> filename2;
            processor.setOutputFilename(filename2);
            processor.searchSubstring(substring);
            break;

        case 4:
            cout << "Введите имя исходного файла: ";
            cin >> filename;
            processor.setInputFilename(filename);
            cout << "Введите имя выходного файла: ";
            cin >> filename2;
            processor.setOutputFilename(filename2);
            processor.processPageNumbers();
            break;

        case 5:
            cout << "Введите имя исходного файла: ";
            cin >> filename;
            processor.setInputFilename(filename);
            cout << "Введите имя выходного файла: ";
            cin >> filename2;
            processor.setOutputFilename(filename2);
            cout << "Введите ключ шифрования: ";
            cin >> key;
            processor.setKey(key);
            processor.encryptFile();
            break;

        case 0:
            return 0;

        default:
            cout << "Неверный выбор. Попробуйте снова." << endl;
        }

        cout << "\nНажмите Enter для продолжения...";
        cin.ignore();
        cin.get();
    }

    return 0;
}