#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Mall.h"
#include "Customer.h"
#include "ShoeStore.h"
#include "GameStore.h"
#include "BookStore.h"
#include "Store.h"
#include "Item.h"
#include "Book.h"
#include "Game.h"
#include "Shoe.h"
#include "Payment.h"
#include "Cash.h"
#include "Check.h"
#include "CreditCard.h"

using namespace std;

#define CUSTOMER_ACCOUNT_LIMIT 1000

Mall mall;

void getCharFromUserandStore(char& ch);

void getStringFromUserandStore(string& str);

void toLowerCaseSTD(string &str);

void printMainMenuText()
{
	cout << "\nMain Menu" << endl;
    cout << "1. Mall" << endl;
    cout << "2. Stores" << endl;
    cout << "3. Customer" << endl;
    cout << "4. Item" <<endl;
    cout << "5. Quit" << endl;
    cout << "Choose one : " << endl;
}

void printMallMenuText()
{
    cout << "\nMall Menu" << endl;
    cout << "1. A customer enters to mall" << endl;
    cout << "2. A customer exits the mall" << endl;
    cout << "3. Show the customers in the mall" << endl;
    cout << "4. Show the stores in the mall" <<endl;
    cout << "5. Add a store" << endl;
    cout << "6. Back" << endl;
    cout << "Choose one : " << endl;
}

void printStoreMenuText()
{	
    cout << "\nStore Menu" << endl;
    cout << "1. A customer enters to store" << endl;
    cout << "2. A customer exits store" << endl;
    cout << "3. Show the customers in the store" << endl;
    cout << "4. Show items in the store" <<endl;
    cout << "5. Back" << endl;
    cout << "Choose one : " << endl;
}

void printCustomerMenuText()
{
    cout << "\nCustomer Menu" << endl;
    cout << "1. Add item to shopping card" << endl;
    cout << "2. Remove item from shopping card" << endl;
    cout << "3. Show items at the shopping card" << endl;
    cout << "4. Place Order" << endl;
    cout << "5. Cancel Order" << endl;
    cout << "6. Back" << endl;
    cout << "Choose one : " << endl;
}

void printItemMenuText()
{	
    cout << "\nItem Menu" << endl;
    cout << "1. Add a new item to system" << endl;
    cout << "2. Show the items in system" << endl;
    cout << "3. Back" << endl;
}

int main()
{
	char ch_choice;
    string temp_str;
    double total_debt;

	string temp, temp_id, temp_id1, temp_id2, temp_id3;
    string item_prop1, item_prop2, item_prop3, item_prop4;

	Store* ptr_store;
	Store* temp_store;

    mall.setMallName("SHOPPING MALL");
    cout << "Welcome to the " << mall.getMallName() << " ! " << endl;

    // Create and initialize customers at system
    Customer* temp_customer = new Customer("");

	Customer* customer1 = new Customer("suheda");
	Customer* customer2 = new Customer("erman");
	Customer* customer3 = new Customer("ahmet");
	Customer* customer4 = new Customer("gokhan");
	Customer* customer5 = new Customer("mehmet");

    // Create and initialize stores at system
    Store* shoe_store = new ShoeStore("Steve Madden");
	Store* game_store = new GameStore("Gameland");
	Store* book_store = new BookStore("D&R");

    // Create and initialize shoe items
    Item* shoe_item1 = new Shoe("high heels", 150, 37, "female");
    Item* shoe_item2 = new Shoe("ankle boot", 200, 38, "female");
    Item* shoe_item3 = new Shoe("sport shoe", 120, 45, "male");
    Item* shoe_item4 = new Shoe("slipper", 45, 39, "female");
    Item* shoe_item5 = new Shoe("sandal", 110, 43, "male");

    //Create and initialize book items
    Item* book_item1 = new Book("Calikusu", 24, "Resat Nuri Guntekin", "Inkılap Kitabevi");
    Item* book_item2 = new Book("Kinyas ve Kayra", 25, "Hakan Gunday", "Om Yayınevi");
    Item* book_item3 = new Book("Karamazov Kardesler", 30, "Dostoyevski", "The Russian Messenger");
    Item* book_item4 = new Book("Ask", 23, "Elif safak", "Dogan Kitabevi");
    Item* book_item5 = new Book("Kurk Mantolu Madonna", 15, "Sabahattin Ali", "Yapı Kredi Yay.");

    //Create and initialize game items
    Item* game_item1 = new Game("Guitar Hero", 80, "audio/video", "Musical");
    Item* game_item2 = new Game("Football Manager", 90, "audio/video", "Football");
    Item* game_item3 = new Game("Sims", 100, "audio/video", "Role Playing");
    Item* game_item4 = new Game("World of Worcraft", 130, "audio/video", "Strategy");
    Item* game_item5 = new Game("Puzzle", 50, "Paper", "Puzzle");

    // Add shoe items to the shoe store
    shoe_store->addItemtoStore(*shoe_item1);
    shoe_store->addItemtoStore(*shoe_item2);
    shoe_store->addItemtoStore(*shoe_item3);
    shoe_store->addItemtoStore(*shoe_item4);
    shoe_store->addItemtoStore(*shoe_item5);

    // Add book items to the book store
    book_store->addItemtoStore(*book_item1);
    book_store->addItemtoStore(*book_item2);
    book_store->addItemtoStore(*book_item3);
    book_store->addItemtoStore(*book_item4);
    book_store->addItemtoStore(*book_item5);

    //Add game items to the item store
    game_store->addItemtoStore(*game_item1);
    game_store->addItemtoStore(*game_item2);
    game_store->addItemtoStore(*game_item3);
    game_store->addItemtoStore(*game_item4);
    game_store->addItemtoStore(*game_item5);

    // Create and initialize credit card object at the system
    // Account Limit is set to 1000 optionally.
    Payment* credit_card = new CreditCard(0, "4020230411018987", "visa", "03/15");
    credit_card->setLimit(CUSTOMER_ACCOUNT_LIMIT);

    // Create and initialize cash object at the system
    // Account Limit is set to 1000 optionally.
    Payment* cash = new Cash(0);
    cash->setLimit(CUSTOMER_ACCOUNT_LIMIT);

    // Create and initialize check object at the system
    // Account Limit is set to 1000 optionally.
    Payment* check = new Check(0, "Garanti Bankası", 220);
    check->setLimit(CUSTOMER_ACCOUNT_LIMIT);

    Item* temp_item;
    ItemToPurchase itpurchase;

    ShoppingCard* shopping_card = new ShoppingCard;

	mainmenu:
	printMainMenuText();
    getCharFromUserandStore(ch_choice);

    vector <ItemToPurchase> its;

	switch(ch_choice)
	{
	// Mall Menu
	case '1':
		mallmenu:
		printMallMenuText();

        getCharFromUserandStore(ch_choice);

		while (ch_choice != '6')
		{
			switch(ch_choice)
			{
			case '1':
				cout << "Customers which are waiting to enter mall. Choose one by typing its number.."<<endl;
                if(!customer1->getEntertoMallStatus())
					cout << "1. Suheda" << endl;

				if(!customer2->getEntertoMallStatus())
					cout << "2. Erman"  << endl;
				
				if(!customer3->getEntertoMallStatus())
					cout << "3. Ahmet" << endl;

				if(!customer4->getEntertoMallStatus())
					cout << "4. Gokhan" << endl;

				if(!customer5->getEntertoMallStatus())
					cout << "5. Mehmet"<< endl;

                getCharFromUserandStore(ch_choice);

				if (ch_choice == '1')
					mall.enter(*customer1);
				else if (ch_choice == '2')
					mall.enter(*customer2);
				else if (ch_choice == '3')
					mall.enter(*customer3);
				else if (ch_choice == '4')
					mall.enter(*customer4);
				else if (ch_choice == '5')
					mall.enter(*customer5);

				break;
			case '2':
				cout << "Enter the name of customer which will exit: ";
			    getStringFromUserandStore(temp_str);
                toLowerCaseSTD(temp_str);

                if(mall.getCustomerFromMall(temp_str, temp_customer))
                {			
					mall.exit(*temp_customer);
					cout << "Customer " << temp_str << " has exit the mall" << endl;
				}

				break;
			case '3':
				mall.printCustomers();
				break;
			case '4':
                if((mall.getStores()).size() != 0)
                {
				    mall.printStores();
                }
                else
                {
                    cout << "There are no stores at the mall right now! Please add store from main menu!" << endl;
                }
				break;
			case '5':
				cout << "\nChoose the type of store : (ShoeStore / GameStore / BookStore) : ";
		        getStringFromUserandStore(temp_str);
				if (temp_str == "ShoeStore")
				{
					mall.addStore(*shoe_store);
				}
				else if (temp_str == "GameStore")
				{
					mall.addStore(*game_store);
				}
				else if (temp_str == "BookStore")
				{
					mall.addStore(*book_store);
				}
                else
                {
                    cout << "You have entered invalid store type. Be careful about case sensitivity !" << endl;
                }
				break;
				
			default:
				break;
			}

			cin.clear();
			cin.sync();
			goto mallmenu;
		}

		cin.clear();
		cin.sync();

		goto mainmenu;

		break;
	// Store Menu
	case '2':
		storemenu:
		printStoreMenuText();

		getCharFromUserandStore(ch_choice);

		while(ch_choice != '5')
		{
			switch(ch_choice)
			{
			case '1':
            if((mall.getStores()).size() != 0)
            {
			    mall.printStores();

			    cout << "Which store do you want to enter ? Type its ID.." << endl;
                getStringFromUserandStore(temp_str);

			    if(mall.getStoreviaId(atoi(temp_str.c_str()), temp_store))
			    {
                    cout << "These are the customers which are currently at the mall :" << endl;
                    mall.printCustomers();
				    cout << "Enter your name :" << endl;
                    getStringFromUserandStore(temp_str);
                    toLowerCaseSTD(temp_str);

                    if(mall.getCustomerFromMall(temp_str, temp_customer))
				    {
					    (*temp_store).enter(*temp_customer);
				    }
			    }
            }
            else
            {
                cout << "There are no stores at the mall right now! Please add store from main menu!" << endl;
            }
			cin.clear();
			cin.sync();
				break;
			case '2':
            if((mall.getStores()).size() != 0)
            {
			    mall.printStores();

			    cout << "Which store do you want to exit ? Type its ID.." << endl;
			
                getStringFromUserandStore(temp_str);
			    if(mall.getStoreviaId(atoi(temp_str.c_str()), temp_store))
			    {
				    cout << "Enter your name :" << endl;

                    getStringFromUserandStore(temp_str);
                    toLowerCaseSTD(temp_str);

                    if(temp_store->getCustomerFromStore(temp_str, temp_customer))
				    {
					    (*temp_store).exit(*temp_customer);
				    }
			    }
            }
            else
            {
                cout << "There are no stores at the mall right now! Please add store from main menu!" << endl;
            }
			cin.clear();
			cin.sync();
				break;
			case '3':
                if((mall.getStores()).size() != 0)
                {
				    mall.printStores();
				    cout << "Choose a store. type its ID.." << endl;

				    cin >> temp;

				    if(mall.getStoreviaId(atoi(temp.c_str()), temp_store))
				    {
					    (*temp_store).printCustomers();
				    }
                }
                else
                {
                    cout << "There are no stores at the mall right now! Please add store from main menu!" << endl;
                }
				break;
			case '4':
                cout << "\nWhich store items do you want to show? : (ShoeStore / GameStore / BookStore) : ";

                getStringFromUserandStore(temp_str);
				if (temp_str == "ShoeStore")
				{
                    (*shoe_store).printItems();
				}
				else if (temp_str == "GameStore")
				{
                    (*game_store).printItems();
				}
				else if (temp_str == "BookStore")
				{
                    (*book_store).printItems();
				}
                else
                {
                    cout << "You have entered invalid store type. Be careful about case sensitivity !" << endl;
                }

				break;
			default:
				break;
			}
			goto storemenu;
		}
		goto mainmenu;
		break;
    // Customer menu
	case '3':
        customermenu:
        printCustomerMenuText();

        getCharFromUserandStore(ch_choice);
        switch(ch_choice)
        {
        case '1':
            cout << "Customers which are currently at a store now. Type a customer name.."<<endl;

            shoe_store->printCustomers();
            book_store->printCustomers();
            game_store->printCustomers();

            getStringFromUserandStore(temp_str);
            toLowerCaseSTD(temp_str);

            if((shoe_store->getCustomers()).size() == 0 && (shoe_store->getCustomers()).size() == 0 && (shoe_store->getCustomers()).size() == 0)
            {
                goto customermenu;
            }

            if(temp_store->getCustomerFromStore(temp_str, temp_customer))
            {
                if(mall.getStoreviaId((temp_customer->getCStoreId()),temp_store))
                {
                    cout << temp_str << " is in " << temp_store->getStoreName() << endl;
                }
            }

            temp_store->printItems();

            cout << "Type Id of item which will be added to shopping card.." << endl;
            getStringFromUserandStore(temp_str);

            temp_store->getItemviaId(atoi(temp_str.c_str()), temp_item);

            cout << "How many item do you want to buy" << endl;
            getStringFromUserandStore(temp_str);       

            itpurchase.setItem(*temp_item);
            itpurchase.setQuantity(atoi(temp_str.c_str()));
            //its.push_back(itpurchase);
            //(temp_customer->getShoppingCard())->addItemToCard(itpurchase);
            shopping_card->addItemToCard(itpurchase);
            temp_customer->setShoppingCard(shopping_card);
            break;
        case '2':
            if((shoe_store->getCustomers()).size() == 0 && (shoe_store->getCustomers()).size() == 0 && (shoe_store->getCustomers()).size() == 0)
            {
                cout << "Firstly add customer" << endl;
                goto customermenu;
            }
            cout << "Type your name to display your shopcard : ";
            getStringFromUserandStore(temp_str);
            toLowerCaseSTD(temp_str);

            if(temp_store->getCustomerFromStore(temp_str, temp_customer))
            {
                (temp_customer->getShoppingCard())->printItems();
            }

            cout << "Type id for the item which will be removed : ";
            getStringFromUserandStore(temp_str);

            (temp_customer->getShoppingCard())->removeItemFromCard(atoi(temp_str.c_str()));

            break;
        case '3':
            if((shoe_store->getCustomers()).size() == 0 && (shoe_store->getCustomers()).size() == 0 && (shoe_store->getCustomers()).size() == 0)
            {
                cout << "Firstly add customer" << endl;
                goto customermenu;
            }
            cout << "Customers which are currently at a store now. Type a customer name.."<<endl;

            shoe_store->printCustomers();
            book_store->printCustomers();
            game_store->printCustomers();

            getStringFromUserandStore(temp_str);
            toLowerCaseSTD(temp_str);

            if(temp_store->getCustomerFromStore(temp_str, temp_customer))
            {
                (temp_customer->getShoppingCard())->printItems();
            }
            break;
        case '4':
            if((shoe_store->getCustomers()).size() == 0 && (shoe_store->getCustomers()).size() == 0 && (shoe_store->getCustomers()).size() == 0)
            {
                cout << "Firstly add customer" << endl;
                goto customermenu;
            }
            cout << "Type your name : ";
            getStringFromUserandStore(temp_str);
            toLowerCaseSTD(temp_str);

            if(temp_store->getCustomerFromStore(temp_str, temp_customer))
            {
                total_debt = (temp_customer->getShoppingCard())->calculateTotalPrice();
                cout << "Your total debt is : " << total_debt << endl;

                cout << "Choose a payment method (cash / credit card / check) : " << endl;

                getStringFromUserandStore(temp_str);

                if(temp_str == "cash")
                {
                    cout << "Your cash is : " << cash->getLimit() << endl;
                    cash->setAmount(total_debt);
                    cash->performPayment();
                    cout << "After payment your cash is : " << cash->getLimit() << endl;
                }
                else if (temp_str == "credit card")
                {
                    cout << "Your cash is : " << credit_card->getLimit();
                    credit_card->setAmount(total_debt);
                    credit_card->performPayment();
                    cout << "After payment your cash is : " << credit_card->getLimit() << endl;
                }
                else if (temp_str == "check")
                {
                    cout << "Your cash is : " << check->getLimit();
                    check->setAmount(total_debt);
                    check->performPayment();
                    cout << "After payment your cash is : " << check->getLimit() << endl;
                }
            }
            break;
        case '5':
            (temp_customer->getShoppingCard())->cancelOrder();
            cout << "Your shopping card is empty now!" << endl;
            break;
        case '6':
            goto mainmenu;
            break;
        default:
            break;
        }

        goto customermenu;
		break;
	// Item Menu
	case '4':
        itemmenu:
        printItemMenuText();

        getCharFromUserandStore(ch_choice);
        switch(ch_choice)
        {
        case '1':
            cout << "Choose the type of item (Shoe / Book / Game) : ";
   
            getStringFromUserandStore(temp_str);
			if (temp_str == "Shoe")
			{
                cout << "Enter shoe name : ";
                getStringFromUserandStore(item_prop1);
                cout << "Enter shoe price : ";
                getStringFromUserandStore(item_prop2);
                cout << "Enter shoe size : ";
                getStringFromUserandStore(item_prop3);
                cout << "Enter shoe gender : ";
                getStringFromUserandStore(item_prop4);

                temp_item = new Shoe(item_prop1.c_str(), atof(item_prop3.c_str()), atoi(item_prop3.c_str()), item_prop4.c_str());
                (*shoe_store).addItemtoStore(*temp_item); 
			}
			else if (temp_str == "Game")
			{
				cout << "Enter game name : ";
                getStringFromUserandStore(item_prop1);
                cout << "Enter game price : ";
                getStringFromUserandStore(item_prop2);
                cout << "Enter media type : ";
                getStringFromUserandStore(item_prop3);
                cout << "Enter game type : ";
                getStringFromUserandStore(item_prop4);

                temp_item = new Game(item_prop1.c_str(), atof(item_prop2.c_str()), item_prop3.c_str(), item_prop4.c_str());
                (*game_store).addItemtoStore(*temp_item); 
			}
			else if (temp_str == "Book")
			{
				cout << "Enter book name : ";
                getStringFromUserandStore(item_prop1);
                cout << "Enter book price : ";
                getStringFromUserandStore(item_prop2);
                cout << "Enter author : ";
                getStringFromUserandStore(item_prop3);
                cout << "Enter publisher : ";
                getStringFromUserandStore(item_prop4);

                temp_item = new Game(item_prop1.c_str(), atof(item_prop2.c_str()), item_prop3.c_str(), item_prop4.c_str());
                (*book_store).addItemtoStore(*temp_item); 
			}
            else
            {           
                cout << "You have entered invalid item type. Be careful about case sensitivity !" << endl;
            }
            break;
        case '2':
            cout << "Choose the type of item (Shoe / Book / Game) : ";

            getStringFromUserandStore(temp_str);
            if (temp_str == "Shoe")
			{
                cout << "Shoe items in system : " << endl;
                (*shoe_store).printItems();

                cout << "Enter item's id : ";
                getStringFromUserandStore(temp_id1);
                if((*shoe_store).getItemviaId((atoi(temp_id1.c_str())), temp_item))
                {
                    (*temp_item).printProperties();
                }                   
            }
            else if (temp_str == "Book")
            {
                cout << "Book items in system : " << endl;
                (*book_store).printItems();

                cout << "Enter item's id : ";
                getStringFromUserandStore(temp_id2);
                if((*book_store).getItemviaId((atoi(temp_id2.c_str())), temp_item))
                {
                    (*temp_item).printProperties();
                }
            }
            else if (temp_str == "Game")
            {
                cout << "Game items in system : " << endl;
                (*game_store).printItems();

                cout << "Enter item's id : ";
                getStringFromUserandStore(temp_id3);
                if((*game_store).getItemviaId((atoi(temp_id3.c_str())), temp_item))
                {
                    (*temp_item).printProperties();
                }
            }
            else
            {           
                cout << "You have entered invalid item type. Be careful about case sensitivity !" << endl;
            }
            break;
        case '3':
            goto mainmenu;
            break;
        default:
            break;
        }
    
        goto itemmenu;
		break;
	// Quit - exit the program
	case '5':
		break;
	default:
		cout << "Enter a valid choice from range 1-5 !" << endl;
        goto mainmenu;
		break;

	}
}

void getCharFromUserandStore(char& ch)
{
    cin.sync();
    cin.clear();
    ch = getchar();
}

void getStringFromUserandStore(string& str)
{
    cin.sync();
    cin.clear();
    getline(cin, str);
}

void toLowerCaseSTD(string &str)
{
	transform(str.begin(), str.end(), str.begin(), tolower);
}
