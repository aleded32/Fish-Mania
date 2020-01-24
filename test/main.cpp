#include <iostream>
#include <SFML/Graphics.hpp>
#include <stdlib.h>


using namespace std;
using namespace sf;

int playerX = 0;
const int playerY = 11;
int tempFish = 7;
int currentFish =7;
int Fishheld = 0;
int score = 0;



int fishX;
int fishY;
int gamefield[12][10];


Color fishColour[5] = { Color::Blue, Color::Red, Color::Green, Color::Yellow, Color::Transparent};







RenderWindow app(sf::VideoMode(600, 600), "Fish Mania");





//searches for a fish colour then retrieves it and holds that value
void search(int currentY)
{
	

	if(gamefield[currentY-1][playerX] == 7 )
	{
		
		
		

		search(currentY - 1);
		return;
		

	}
	if ( Fishheld <= 0 && gamefield[currentY - 1][playerX] != 7 );
	{
		tempFish = gamefield[currentY - 1][playerX];
		
		

	}
	

	
	}
	
	
	
	
	
//retrieves the fish to the player
void retieve(int currentY)
{
	
	if (gamefield[currentY - 1][playerX] == 7)
	{




		retieve(currentY - 1);
		return;


	}
	if (gamefield[currentY - 1][playerX] != currentFish)
	{
		Fishheld = Fishheld;

	}
	else if(Fishheld != 4 || Fishheld == 0 && gamefield[currentY - 1][playerX] == currentFish)
	{
		Fishheld +=  1;
		gamefield[currentY - 1][playerX] = 7;
	}

	else if (Fishheld == 4 && gamefield[currentY - 1][playerX] == currentFish)
	{
		
			Fishheld = 4;
			currentFish = currentFish;
			
		
	}
	
	
}

//throws the fish
void release(int currentY, int currentX)
{

	if (gamefield[currentY - 1][playerX] == 7)
	{




		release(currentY - 1, currentX);
		return;


	}


	if (Fishheld != 0) {
		if (Fishheld != 0) {
			if (gamefield[currentY - 1][currentX] != currentFish && gamefield[currentY][currentX] == 7 && Fishheld != 0)
			{
				gamefield[currentY][currentX] = currentFish;
				score = score;

				Fishheld -= 1;



			}


			if (gamefield[currentY - 1][currentX] == currentFish)
			{
				gamefield[currentY - 1][currentX] = 7;
				score += Fishheld * 10;

				Fishheld -= Fishheld;

				currentFish = 7;
				tempFish = 7;

			}

		}

		if (Fishheld == 0)
		{
			tempFish = 7;
			currentFish = 7;
			score = score;

		}







	}
}

//adds a new row colours
void rowAdd(int gamefield[12][10])
{

	srand(time(NULL));
	for (int i = 11 - 1; i > 0; i--) {
		for (int j = 0; j < 10; j++) {
			gamefield[i][j] = gamefield[i - 1][j];

		}


	}


	for (int i = 0; i < 10; i++) {
		int randCol; // generates a number to assagin new colours to the fishes
		do {
			randCol = rand() % 4;
		} while (randCol == 0);

		gamefield[0][i] = randCol;



	}

	
}


int main(){


	app.setFramerateLimit(15);
	int secondsRow = 5;
	bool addedRow = false;
	int seconds;
	sf::Clock gameClock;

	//player
	sf::Texture texturePlayer;
	texturePlayer.loadFromFile("player.png");
	sf::Sprite player;
	player.setTexture(texturePlayer);
	player.setScale(0.05f, 0.05f);
	player.setColor(fishColour[5]);

	//fish
	sf::Texture fishText;
	fishText.loadFromFile("fish.png");
	sf::Sprite fish;
	fish.setTexture(fishText);

	//background
	sf::Texture textureBackground;
	textureBackground.loadFromFile("background.jpg");
	sf::Sprite background;
	background.setTexture(textureBackground);
	background.setPosition(0, 0);
	background.setScale(1.6f, 1.6f);

	
	
	//creates gamefield
	Event e;
	srand(time(NULL));
for (int i = 0; i < 12; i++) 
{
	for (int j = 0; j < 10; j++) 
	{
		gamefield[i][j] = 7;
		

		if (i < 9 - 6)
		{		
			
			gamefield[i][j] = rand() % 4;
			

		}
		gamefield[playerY][playerX] = 4;
		cout << gamefield[i][j] << ' ';

		
		
	}
	cout << endl;

}
cout << endl;



while (app.isOpen()) {


	while (app.pollEvent(e))
	{
		//start

  		switch (e.type) {

		case sf::Event::Closed:
			app.close();

		}

		
	}
	if (Keyboard::isKeyPressed(Keyboard::S)) {

		if (Fishheld != 4) {

			if (tempFish == 7)
			{
				search(playerY);
			}
			else if (tempFish != 7|| Fishheld <= 0) {

				currentFish = tempFish;
				retieve(playerY);
			}

		}
		
		cout << Fishheld << endl;
		
	}
	

	if (Keyboard::isKeyPressed(Keyboard::D)) {
		if (playerX < 9) {
			playerX += 1;
			gamefield[playerY][playerX - 1] = 7;
			gamefield[playerY][playerX] = 4;
		}

		else if (playerX > 9)
		{
			playerX = 9;
			
			gamefield[playerY][playerX] = 4;

		}
		
		

	}

	if (Keyboard::isKeyPressed(Keyboard::A)) {
		if (playerX <= 9) {
			if (playerX >= 1) {
				playerX -= 1;
				gamefield[playerY][playerX + 1] = 7;
				gamefield[playerY][playerX] = 4;


			}
		}
		else if (playerX < 1)

		{
			
			playerX = 0;
			

			gamefield[playerY][playerX] = 5;

		}



	}

	if (Keyboard::isKeyPressed(Keyboard::W)) 
	
	{
		if (Fishheld <= 4 || Fishheld > 0 )
		{
		
			release(playerY, playerX);
			
			
			
		}
		else 
		{
		
			search(playerY);
		}
		
		
	
	}

	for (int i = 0;  i < 4; i++)
	{
		for (int j = 0; j < 9; j++) {
			if (fishColour[gamefield[playerY -1][j]] == fishColour[i]) {

				app.close();

			}
		}

	}

	

	Text Score;
	Font font;
	font.loadFromFile("BebasNeue-Regular.ttf");
	Score.setFont(font);
	Score.setCharacterSize(18);
	Score.setPosition(0, 0);
	Score.setFillColor(Color::White);
	Score.setString("Score: " + to_string(score));
	Text fishes;
	
	font.loadFromFile("BebasNeue-Regular.ttf");
	fishes.setFont(font);
	fishes.setCharacterSize(18);
	fishes.setPosition(0, 500);
	fishes.setFillColor(Color::White);
	 string fishColourStr[8]= { "Blue", "Red", "Green", "Yellow" };
	fishes.setString("fish Type: " + fishColourStr[currentFish]);

	Text fishNum;
	font.loadFromFile("BebasNeue-Regular.ttf");
	fishNum.setFont(font);
	fishNum.setCharacterSize(18);
	fishNum.setPosition(0, 550);
	fishNum.setFillColor(Color::White);
	string fishNumStr[5] = {"0", "1", "2", "3" "4"};
	fishNum.setString("fishes held: " + fishNumStr[Fishheld]);

	
		//draw
		app.clear();
		app.draw(background);

		
		

		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				
				
				
				//spawn(gamefield[i][j], j, i, fishColour[gamefield[i][j]]);
				fish.setColor(fishColour[gamefield[i][j]]);


				fish.setPosition(fishX = j * 45 + 100, fishY = i * 45);

				player.setColor(fishColour[5]);
				player.setPosition(playerX * 45 + 100, playerY * 45);


				app.draw(player);



				
				app.draw(fish);

			}
		

		}

		seconds = (int)gameClock.getElapsedTime().asSeconds();
		if (seconds % secondsRow == 0 && !addedRow) {

			rowAdd(gamefield);
			addedRow = true;

		}
		else if (seconds % secondsRow == secondsRow - 1) {

			gameClock.restart();
			addedRow = false;
		}

		
		app.draw(fishNum);
		app.draw(fishes);
		app.draw(Score);
		
		app.display();

	

	
	

}

return 0;
}


