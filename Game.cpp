#include "Game.h"
#include <iostream>


Game::Game(string it_name, double it_price, string g_mediatype, string g_gametype) : Item(it_name, it_price) {
    mediatype = g_mediatype;
    gametype = g_gametype;
}

void Game::printProperties() {
	cout << "Game name : " << getItemName() << endl;
    cout << "Game price : " << getItemPrice() << " TL" << endl;
    cout << "Media type : " << getMediaType() << endl;
    cout << "Game type : " << getGameType() << endl;
}
