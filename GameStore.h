#include "Store.h"


class GameStore : public Store {


public:

	
    GameStore(string name) : Store(name){};

	
	void printItems();
};
