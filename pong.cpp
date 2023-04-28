#include "Bat.cpp"
#include "Ball.cpp"
#include <sstream>
#include <cstdlib>
// SFML/Graphics already included in Bat.h

int main()
{
	// Create a video mode object
	VideoMode vm(1920, 1080);

	// Create and open a window for the game
	RenderWindow window(vm, "Pong", Style::Fullscreen);

	int score = 0;
	int lives = 3;

	// Create a bat at the bottom of the screen
	Bat bat(1920/2, 1080 - 20);

	// Create a ball
	Ball ball(1920/2, 0);

	// We will add the ball in the next chapter
	
	// Create a text object called HUD
	Text hud;

	// Import the font
	Font font;
	font.loadFromFile("fonts/DS-DIGI.TTF");
	
	// set the hud font 
	hud.setFont(font);
	hud.setCharacterSize(75);
	hud.setFillColor(Color::White);
	hud.setPosition(20, 20);

	// Here is the clock for timing
	Clock clock;

	while (window.isOpen())
	{
		/* 
		 Handle the player input
		 * ********************
		 * ********************
		 * ********************
		 */

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				// Quit the game when the window is closed
				window.close();
		}

		// Handle the player quitting
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		// Handle the pressing and releasing of arrow keys
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			bat.moveLeft();
		}
		else
		{
			bat.stopLeft();
		}

		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			bat.moveRight();
		}
		else
		{
			bat.stopRight();
		}


		/* 
		 Update the bat, ball, and HUD.
		 * ********************
		 * ********************
		 * ********************
		 */
		
		// Update the delta time
		Time dt = clock.restart();
		bat.update(dt);
		ball.update(dt);

		// Update the HUD
		std::stringstream ss;
		ss << "Score: " << score << "    Lives: " << lives;
		hud.setString(ss.str());

		/* 
		 Draw the bat, ball, and HUD.
		 * ********************
		 * ********************
		 * ********************
		 */

		window.clear();
		window.draw(hud);
		window.draw(bat.getShape());
		window.draw(ball.getShape());
		window.display();

	} // while (window Open)

	return 0;

}
