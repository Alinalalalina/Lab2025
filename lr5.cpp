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
    // �����������
    FileProcessor() = default;

    // ��������� ����� �������� �����
    void setInputFilename(const string& filename) {
        inputFilename = filename;
    }

    // ��������� ����� ��������� �����
    void setOutputFilename(const string& filename) {
        outputFilename = filename;
    }

    // ��������� ����� ����������
    void setKey(const string& k) {
        key = k;
    }

    // ����� ����������� ����� �� �����
    void printFileContents() const {
        ifstream file(inputFilename);
        if (!file.is_open()) {
            cerr << "������: �� ������� ������� ���� " << inputFilename << endl;
            return;
        }

        char ch;
        while (file.get(ch)) {
            cout << ch;
        }

        file.close();
    }

    // ������� "������" � "��������" ��������
    void countCharacters() const {
        ifstream file(inputFilename);
        if (!file.is_open()) {
            cerr << "������: �� ������� ������� ���� " << inputFilename << endl;
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

        cout << "������ ��������: " << empty << endl;
        cout << "�������� ��������: " << nonEmpty << endl;

        file.close();
    }

    // ����� ��������� � �����
    void searchSubstring(const string& substring) const {
        ifstream input(inputFilename);
        ofstream output(outputFilename);

        if (!input.is_open()) {
            cerr << "������: �� ������� ������� ���� " << inputFilename << endl;
            return;
        }

        if (!output.is_open()) {
            cerr << "������: �� ������� ������� ���� " << outputFilename << endl;
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
                output << "������ " << lineNumber << ", ������� " << pos << ": " << line << endl;
            }
        }

        if (!found) {
            output << "��������� '" << substring << "' �� ������� � �����." << endl;
        }

        input.close();
        output.close();
    }

    // ��������� ������� �������
    void processPageNumbers() const {
        ifstream input(inputFilename);
        ofstream output(outputFilename);

        if (!input.is_open() || !output.is_open()) {
            cerr << "������ �������� ������" << endl;
            return;
        }

        string pageNumber;
        string pageContent;
        string line;
        bool firstLine = true;

        while (getline(input, line)) {
            if (firstLine) {
                // ��������� ����� �������� (������: - 34 -)
                size_t start = line.find_first_of("0123456789");
                size_t end = line.find_last_of("0123456789");
                if (start != string::npos && end != string::npos) {
                    pageNumber = line.substr(start, end - start + 1);
                }
                firstLine = false;
            }
            else if (line.find('\t') != string::npos) {
                // ����� �������� - ���������� ����� � �����
                output << pageContent;
                output << pageNumber << endl;
                pageContent.clear();
                firstLine = true;
            }
            else {
                pageContent += line + "\n";
            }
        }

        // ���������� ��������� ��������
        if (!pageContent.empty()) {
            output << pageContent;
            output << pageNumber << endl;
        }

        input.close();
        output.close();
    }

    // ���������� �����
    void encryptFile() const {
        ifstream input(inputFilename, ios::binary);
        ofstream output(outputFilename, ios::binary);

        if (!input.is_open() || !output.is_open()) {
            cerr << "������ �������� ������" << endl;
            return;
        }

        char ch;
        size_t keyIndex = 0;

        while (input.get(ch)) {
            // ������� ������: XOR � �������� �����
            char encrypted = ch ^ key[keyIndex % key.length()];
            output.put(encrypted);
            keyIndex++;
        }

        input.close();
        output.close();
    }
};

// ������� ��� ����������� ����
void showMenu() {
    system("cls"); // ������� ������ (��� Windows)

    cout << "������������ ������ 5: ������ � �������" << endl;
    cout << "1. ������� ���������� �����" << endl;
    cout << "2. ���������� ������ � �������� �������" << endl;
    cout << "3. ����� ��������� � �����" << endl;
    cout << "4. ���������� ������ �������" << endl;
    cout << "5. ����������� ����" << endl;
    cout << "0. �����" << endl;
    cout << "�������� ��������: ";
}

int main(int argc, char* argv[]) {
    FileProcessor processor;

    // ����� ��������� ������ ��� ���������
    if (argc == 4) {
        processor.setInputFilename(argv[1]);
        processor.setOutputFilename(argv[2]);
        processor.setKey(argv[3]);
        processor.encryptFile();
        cout << "���� ������� ����������." << endl;
        return 0;
    }

    // ������������� �����
    while (true) {
        showMenu();
        int choice;
        cin >> choice;
        cin.ignore(); // ������� ����� �����

        string filename, filename2, substring, key;

        switch (choice) {
        case 1:
            cout << "������� ��� �����: ";
            cin >> filename;
            processor.setInputFilename(filename);
            processor.printFileContents();
            break;

        case 2:
            cout << "������� ��� �����: ";
            cin >> filename;
            processor.setInputFilename(filename);
            processor.countCharacters();
            break;

        case 3:
            cout << "������� ��� �����: ";
            cin >> filename;
            processor.setInputFilename(filename);
            cout << "������� ��������� ��� ������: ";
            getline(cin, substring);
            cout << "������� ��� ��������� �����: ";
            cin >> filename2;
            processor.setOutputFilename(filename2);
            processor.searchSubstring(substring);
            break;

        case 4:
            cout << "������� ��� ��������� �����: ";
            cin >> filename;
            processor.setInputFilename(filename);
            cout << "������� ��� ��������� �����: ";
            cin >> filename2;
            processor.setOutputFilename(filename2);
            processor.processPageNumbers();
            break;

        case 5:
            cout << "������� ��� ��������� �����: ";
            cin >> filename;
            processor.setInputFilename(filename);
            cout << "������� ��� ��������� �����: ";
            cin >> filename2;
            processor.setOutputFilename(filename2);
            cout << "������� ���� ����������: ";
            cin >> key;
            processor.setKey(key);
            processor.encryptFile();
            break;

        case 0:
            return 0;

        default:
            cout << "�������� �����. ���������� �����." << endl;
        }

        cout << "\n������� Enter ��� �����������...";
        cin.ignore();
        cin.get();
    }

    return 0;
}