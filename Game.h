#include "Item.h"



class Game : public Item {

private:
	string mediatype;
	string gametype;

public:
	
    Game(string it_name, double it_price, string mediatype, string gametype);

    //setter functions
    void setMediaType(string m) { mediatype = m;}
    void setGameType(string g) { gametype = g;}

    //getter functions
    string getMediaType() { return mediatype;}
    string getGameType() { return gametype;}


	void printProperties();
};
