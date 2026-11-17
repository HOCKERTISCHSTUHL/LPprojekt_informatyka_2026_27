#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Zadanie - Scena statyczna");

	sf::RectangleShape ziemia(sf::Vector2f(800.f, 150.f));
	ziemia.setFillColor(sf::Color(34, 139, 34));
	ziemia.setPosition(0.f, 450.f);

	sf::RectangleShape dom(sf::Vector2f(200.f, 150.f));
	dom.setFillColor(sf::Color(253, 245, 230));
	dom.setPosition(150.f, 300.f);

	sf::ConvexShape dach;
	dach.setPointCount(3);
	dach.setPoint(0, sf::Vector2f(130.f, 300.f));
	dach.setPoint(1, sf::Vector2f(250.f, 180.f));
	dach.setPoint(2, sf::Vector2f(370.f, 300.f));
	dach.setFillColor(sf::Color(178, 34, 34));

	sf::RectangleShape drzwi(sf::Vector2f(50.f, 80.f));
	drzwi.setFillColor(sf::Color(139, 69, 19));
	drzwi.setPosition(250.f, 370.f);

	sf::RectangleShape okno(sf::Vector2f(50.f, 50.f));
	okno.setFillColor(sf::Color(135, 206, 250));
	okno.setPosition(170.f, 340.f);

	sf::RectangleShape pien(sf::Vector2f(40.f, 120.f));
	pien.setFillColor(sf::Color(101, 67, 33));
	pien.setPosition(600.f, 330.f);

	sf::CircleShape liscie(70.f);
	liscie.setFillColor(sf::Color(0, 100, 0));
	liscie.setPosition(550.f, 210.f);

	sf::CircleShape slonce(50.f);
	slonce.setFillColor(sf::Color::Yellow);
	slonce.setPosition(650.f, 50.f);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color(135, 206, 235));

		window.draw(slonce);
		window.draw(ziemia);
		window.draw(pien);
		window.draw(liscie);
		window.draw(dom);
		window.draw(dach);
		window.draw(drzwi);
		window.draw(okno);

		window.display();
	}

	return 0;
}