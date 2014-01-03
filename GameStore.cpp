#include "GameStore.h"
#include <iostream>
#include <algorithm>
using namespace std;


void GameStore::printItems() {

	vector <Item*>::iterator it_item;

	for(it_item = items.begin(); it_item != items.end(); it_item++)
	{
		cout << "ID : " << (**it_item).getItemId() << "-" << (**it_item).getItemName() << endl; 
	}
}
