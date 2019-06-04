#include "inc.h"
#include "Game.h"
#include <stdlib.h>


#define FRAMES_PER_SECOND 1000




Game::Game(std::string window, std::string mapSize, int numEnemies, int numAmmo) :
	windowSize(new Vector2d(std::stoi(window.substr(0, window.find("x"))), std::stoi(window.substr(window.find("x") + 1, window.size())))),
	mapSize(new Vector2d(std::stoi(mapSize.substr(0, mapSize.find("x"))), std::stoi(mapSize.substr(mapSize.find("x") + 1, mapSize.size())))),
	numEnemies(numEnemies),
	numAmmo(numAmmo)
{
	std::cout << "Size of window: " << *this->windowSize << std::endl;
	std::cout << "Size of map: " << *this->mapSize << std::endl;
	std::cout << "Number of enemies: " << this->numEnemies << std::endl;
	std::cout << "Number of ammo: " << this->numAmmo << std::endl;

}
Game::~Game() {

}

	void Game::PreInit(int& width, int& height, bool& fullscreen)
	{
		width = static_cast<int>(windowSize->getX());
		height = static_cast<int>(windowSize->getY());
		fullscreen = false;
	}

	bool Game::Init() {
		showCursor(0);
		timer = Timer::Instance();
		textrMan = TextureManager::Instance();
		gameObj = new GameObjects();
		fpsTimer = Timer();

		gameObj->Init(*mapSize, numEnemies, numAmmo);

		return true;
	}

	void Game::Close() {
		
		Timer::Release();
		timer = nullptr;

		delete gameObj;
		delete windowSize;
		delete mapSize;
		textrMan->Close("all");

		gameObj->Close();

	}

	bool Game::Tick() {

		fpsTimer.Update();

		fps_frames++;
		if (fps_lasttime < getTickCount() - FPS_INTERVAL * 1000)
		{
			fps_lasttime = getTickCount();
			fps_current = fps_frames;
			fps_frames = 0;
		}
		if (fps_current > 60)

		timer->Update();

		gameObj->Tick();
		gameObj->LateTick();

		if (timer->DeltaTime() >= 1.0f / FRAMES_PER_SECOND) {

			gameObj->draw();
			timer->Reset();
		}
		return false;
	}

	void Game::onMouseMove(int x, int y, int xrelative, int yrelative) {
		 gameObj->mouse->onMouseMove(x, y, xrelative, yrelative); 
	}

	void Game::onMouseButtonClick(FRMouseButton button, bool isReleased) {
		 gameObj->mouse->onMouseButtonClick(button, isReleased);
	}

	void Game::onKeyPressed(FRKey k) {
		gameObj->player->onKeyPressed(k);
		
	}

	void Game::onKeyReleased(FRKey k) {
		gameObj->player->onKeyReleased(k);
	}


int main(int argc, char *argv[]) {
		std::string window = "";
		std::string map = "";
		std::string num_enemies = "";
		std::string num_ammo = "";


		for (int i = 1; i < argc; i++) {
			if (std::string(argv[i]) == "-window") {
				i++;
				window = std::string(argv[i]);
				continue;
			}
			if (std::string(argv[i]) == "-map") {
				i++;
				map = std::string(argv[i]);
				continue;
			}
			if (std::string(argv[i]) == "-num_enemies") {
				i++;
				num_enemies = std::string(argv[i]);
				continue;
			}
			if (std::string(argv[i]) == "-num_ammo") {
				i++;
				num_ammo = std::string(argv[i]);
				continue;
			}
		}

		if (window == "") {
			window = "720x480";
		}
		if (map == "") {
			map = "1000x1000";
		}
		if (num_enemies == "") {
			num_enemies = "6";
		}
		if (num_ammo == "") {
			num_ammo = "10";
		}

		return run(new Game(window, map, std::stoi(num_enemies), std::stoi(num_ammo)));
}

