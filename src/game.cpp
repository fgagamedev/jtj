#include <iostream>
#include "game.h"
#include "enemy.h"
#include "box.h"

using namespace std;

void Game::initGUI() {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_WM_SetCaption("Jack, The Janitor", NULL);
    SDL_WM_SetIcon(IMG_Load("resources/Logo_WareHouse_64x64.png"), NULL);
    this->screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_HWSURFACE | SDL_DOUBLEBUF);
    return;
}

void Game::closeGUI() {
    SDL_Quit();
    return;
}

void Game::loadCommonResources() {
    return;
}

void Game::releaseCommonResources() {
    return;
}

void Game::loadProfile() {
    return;
}

void Game::saveProfile() {
    return;
}

void Game::updateTimeStep() {
    frameTime.start();
    return;
}

void Game::handle_event_keydown (SDL_Event& event) {
    switch (event.key.keysym.sym) {
        case (SDLK_ESCAPE):
            this->quitLevel = true;
            break;

        case (SDLK_w):
            if(jack->jumping == true) {
                break;
            }
            jack->verticalSpeed = -11;
            jack->jumping = true;
            break;

        case (SDLK_a):
            jack->speed = -3;
            break;

        case (SDLK_s):
            this->quitLevel = true;
            break;

        case (SDLK_d):
            jack->speed = 3;
            break;

        default:
            break;
    }
}

void Game::handle_event_keyup (SDL_Event& event) {
    switch (event.key.keysym.sym) {
        case (SDLK_a):
            if(jack->speed==-3)
                jack->speed = 0;
            break;

        case (SDLK_d):
            if(jack->speed==3)
                jack->speed = 0;
            break;

        default:
            break;
    }
}

void Game::handle_event_mouse_button_up (SDL_Event& event) {
    switch (event.button.button) {

    case SDL_BUTTON_LEFT:
//		printf("Posicao onde o botao foi liberado: (%d, %d)\n", event.button.x, event.button.y);
        break;

    default:
        break;
    }

    return;
}


void Game::handle_event_mouse_button_down (SDL_Event& event) {
    switch (event.button.button) {

    case SDL_BUTTON_LEFT:
//        printf("Posicao onde o botao foi apertado: (%d, %d)\n", event.button.x, event.button.y);
        break;

    default:
        break;
    }

    return;
}

void Game::handle_event_type (SDL_Event& event)
{
    switch (event.type)
    {
    case SDL_QUIT:
        this->quitLevel = true;
        break;

    case SDL_KEYDOWN:
        handle_event_keydown (event);
        break;

    case SDL_KEYUP:
        handle_event_keyup (event);
        break;

    case SDL_MOUSEBUTTONDOWN:
        handle_event_mouse_button_down (event);
        break;

    case SDL_MOUSEBUTTONUP:
        handle_event_mouse_button_up (event);
        break;

    default:
        break;
    }
}

void Game::handleEvents() {
    while (SDL_PollEvent (&event)) {
        handle_event_type (event);
    }
    return;
}

void Game::runAI() {
    return;
}

void Game::runPhysics() {
    jack->move();
    jack->jump();
    return;
}

void Game::update() {
    return;
}

void Game::recieveNetworkData() {
    return;
}

void Game::sendNetworkData() {
    return;
}

int Game::checkIfSkip() {
    if (frameTime.get_ticks() < FRAME_MILISECOND) {
        frameTime.waitDiff(FRAME_MILISECOND);
        return 0;
    }
    else {
        return 1;
    }
}

void Game::draw() {
    if(checkIfSkip() == 0) {
        level->draw(this->screen);
        SDL_Flip(this->screen);
    }
    return;
}

void Game::loadLevel() {
    level = new Level("resources/level_1.png");

    jack = new Jack("resources/jack.png");
    level->addChild(jack);

    Enemy* enemy = new Enemy("resources/enemy_1.png");
    level->addChild(enemy);

    Box* box[5];
    for(int i = 0; i < 5; i++) {
        box[i] = new Box("resources/box.png");
    }
    box[0]->setPosition(Level::LEVEL_X_OFFSET, 250);
    box[1]->setPosition(Level::LEVEL_X_OFFSET + 10*38, 200);
    box[2]->setPosition(Level::LEVEL_X_OFFSET + 4*38, Level::LEVEL_Y_OFFSET + Level::LEVEL_HEIGHT - 38);
    box[3]->setPosition(Level::LEVEL_X_OFFSET + 5*38, Level::LEVEL_Y_OFFSET + Level::LEVEL_HEIGHT - 38);
    box[4]->setPosition(Level::LEVEL_X_OFFSET + 5*38, Level::LEVEL_Y_OFFSET + Level::LEVEL_HEIGHT - 38*2);
    for(int i = 0; i < 5; i++) {
        level->addChild(box[i]);
    }
    return;
}

void Game::releaseLevel() {
    if(level) {
        delete level;
    }
    return;
}

bool Game::isGameFinished() {
    return this->quitGame;
}

bool Game::isLevelFinished() {
    return this->quitLevel;
}

void Game::initScreenDraw() {
    initScreen = new InitScreen("resources/backgroundinitscreen.png");

    labelPlay = new Label("resources/startbutton.png", 483, 68);
    initScreen->addChild(labelPlay);

    labelOptions = new Label("resources/optionsbutton.png", 483, 191);
    initScreen->addChild(labelOptions);

    labelQuit = new Label("resources/exitbutton.png", 483, 314);
    initScreen->addChild(labelQuit);

    return;
}

void Game::initScreenLoop()
{
    bool playButton = false;
    bool quitButton = false;
    bool optionsButton = false;
    this->quitGame = false;

    do {
        while (SDL_PollEvent (&event)) {
            switch (event.type) {
            case SDL_QUIT:
                this->quitGame = true;
                break;

            case SDL_MOUSEBUTTONDOWN:
                switch (event.button.button) {
                case SDL_BUTTON_LEFT:
                    if (labelPlay->wasClicked(event.button.x, event.button.y)) {
                        playButton = true;
                        this->quitLevel = false;
                    } else if (labelOptions->wasClicked(event.button.x, event.button.y)) {
                        optionsButton = true;
                    } else if (labelQuit->wasClicked(event.button.x, event.button.y)) {
                        this->quitGame = true;
                        quitButton = true;
                    }
                    break;

                default:
                    break;
                }
                break;

            default:
                break;
            }
        }
        initScreen->draw(this->screen);
        SDL_Flip(this->screen);
    } while (playButton == false && optionsButton == false && quitButton == false);

    return ;
}

void Game::init() {
    initGUI();

    FRAME_MILISECOND = 1000 / SCREEN_FPS;
    this->quitGame = false;
    this->quitLevel = false;

    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));

    return;
}

void Game::initializingScreen()
{
    initScreenDraw();
    initScreenLoop();

    return ;
}

void Game::shutdown() {
    closeGUI();
    return;
}

void Game::loop() {
    while(isGameFinished() == false) {
	    initializingScreen();
        loadLevel();
        while(isLevelFinished() == false) {
            updateTimeStep();
            recieveNetworkData();
            handleEvents();
            runAI();
            runPhysics();
            update();
            sendNetworkData();
            draw();
        }
        releaseLevel();
    }
    return;
}

