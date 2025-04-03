#include <graphics.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

class Point {
protected:
    float X, Y;
    sf::Color Color;

public:
    Point(float XN = 0, float YN = 0, const sf::Color& Color = sf::Color::Black)
        : X(XN), Y(YN), Color(Color) {
    }

    virtual void Show(sf::RenderWindow& window) {}
    virtual void Hide() {} // � SFML ��� ������� "�������", ����������� ����������

    void Move(float Cost, sf::RenderWindow& window) {
        float XX, YY;
        while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            // ������� ����
            window.clear(sf::Color::Blue);

            // ���������� ����� ���������
            XX = X + ((rand() % 2 == 0) ? -Cost : Cost);
            YY = Y + ((rand() % 2 == 0) ? -Cost : Cost);

            // ��������� ������� ����
            if (XX > 0 && XX < window.getSize().x && YY > 0 && YY < window.getSize().y) {
                X = XX;
                Y = YY;
            }

            // ������������ ������
            Show(window);
            window.display();

            // ��������
            sf::sleep(sf::milliseconds(300));
        }
    }
};

class Circle : public Point {
protected:
    float Radius;

public:
    Circle(float XN = 0, float YN = 0, float R = 0, const sf::Color& Color = sf::Color::Black)
        : Point(XN, YN, Color), Radius(R) {
    }

    void Show(sf::RenderWindow& window) override {
        sf::CircleShape shape(Radius);
        shape.setPosition(X - Radius, Y - Radius);
        shape.setFillColor(Color);
        window.draw(shape);
    }
};

class Ring : public Circle {
private:
    float Width;

public:
    Ring(float XN = 0, float YN = 0, float R = 0, const sf::Color& Color = sf::Color::Black, float Wid = 0)
        : Circle(XN, YN, R, Color), Width(Wid) {
    }

    void Show(sf::RenderWindow& window) override {
        // ������� ����
        sf::CircleShape outerCircle(Radius);
        outerCircle.setPosition(X - Radius, Y - Radius);
        outerCircle.setFillColor(Color);
        window.draw(outerCircle);

        // ���������� "����������" ����
        sf::CircleShape innerCircle(Radius - Width);
        innerCircle.setPosition(X - (Radius - Width), Y - (Radius - Width));
        innerCircle.setFillColor(sf::Color::Blue); // ���� ����
        window.draw(innerCircle);
    }
};

int main() {
    srand(time(0));

    // ������� ����
    sf::RenderWindow window(sf::VideoMode(800, 600), "Graphics Demo");
    window.setFramerateLimit(60);

    // ������� �������
    Circle TestCircle(150, 40, 50, sf::Color::Red);
    Ring TestRing(450, 80, 90, sf::Color::Green, 10);

    // ������� ���� ����������
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // ������� ����
        window.clear(sf::Color::Blue);

        // ������� � ������������ �������
        if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            TestCircle.Move(10, window);
            TestRing.Move(6, window);
            TestCircle.Move(6, window);
        }

        // ������������ �������
        TestCircle.Show(window);
        TestRing.Show(window);

        // ���������� ���
        window.display();
    }

    return 0;
}