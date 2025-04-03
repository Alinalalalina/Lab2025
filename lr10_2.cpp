#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// ��������� ��� �������� ���������� �� ��������
struct Bus {
    int number;         // ����� ��������
    std::string driver; // ��� ��������
    int route;         // ����� ��������

    // �������� ��������� ��� ������ �� ������
    bool operator==(const Bus& other) const {
        return number == other.number;
    }

    // �������� ������ ��� �������� �����������
    friend std::ostream& operator<<(std::ostream& os, const Bus& bus) {
        os << "������� �" << bus.number
            << " (��������: " << bus.driver
            << ", �������: " << bus.route << ")";
        return os;
    }
};

// ����� ��� ���������� ���������� ������
class BusPark {
private:
    std::vector<Bus> inPark;   // �������� � �����
    std::vector<Bus> onRoute;  // �������� �� ��������

public:
    // �������� ����� ������� � ����
    void addBus(int number, const std::string& driver, int route) {
        Bus newBus{ number, driver, route };
        inPark.push_back(newBus);
        std::cout << "�������� " << newBus << std::endl;
    }

    // ��������� ������� �� �������
    void sendBus(int number) {
        auto it = std::find(inPark.begin(), inPark.end(), Bus{ number, "", 0 });

        if (it != inPark.end()) {
            onRoute.push_back(*it);
            inPark.erase(it);
            std::cout << "������� �" << number << " ����� �� �������" << std::endl;
        }
        else {
            std::cout << "������: ������� �" << number << " �� ������ � �����" << std::endl;
        }
    }

    // ������� ������� � ����
    void returnBus(int number) {
        auto it = std::find(onRoute.begin(), onRoute.end(), Bus{ number, "", 0 });

        if (it != onRoute.end()) {
            inPark.push_back(*it);
            onRoute.erase(it);
            std::cout << "������� �" << number << " �������� � ����" << std::endl;
        }
        else {
            std::cout << "������: ������� �" << number << " �� ������ �� ��������" << std::endl;
        }
    }

    // �������� �������� � �����
    void showParked() const {
        std::cout << "\n�������� � ����� (" << inPark.size() << "):\n";
        for (const auto& bus : inPark) {
            std::cout << "  " << bus << std::endl;
        }
    }

    // �������� �������� �� ��������
    void showOnRoute() const {
        std::cout << "\n�������� �� �������� (" << onRoute.size() << "):\n";
        for (const auto& bus : onRoute) {
            std::cout << "  " << bus << std::endl;
        }
    }
};

int main() {
    BusPark park;

    // ��������� �������� � ����
    park.addBus(101, "test1", 5);
    park.addBus(102, "test2", 10);
    park.addBus(103, "test3", 15);

    // ���������� ������� ���������
    park.showParked();
    park.showOnRoute();

    // ���������� ������� �� �������
    park.sendBus(101);
    park.showParked();
    park.showOnRoute();

    // ���������� ������� � ����
    park.returnBus(101);
    park.showParked();
    park.showOnRoute();

    // ������� ��������� �������������� �������
    park.sendBus(999);

    return 0;
}