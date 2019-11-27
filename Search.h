#include "Drink.h"
#include "Ingredient.h"
#include <iostream>
#include <map>
#include <string>
using namespace std;

//typedef for maps and pairs for easier reading
typedef map<string, Drink> DrinkMap;
typedef pair<string, Drink> DrinkPair;

//Declaring Search Class
class Search: public Recipe
{
private:
	DrinkMap drinkStorage; //Storage of all drinks
	DrinkMap foundDrink; //any drink that matches what was found in search, used to return multiple drinks
	string search; //what drink or ingredient the user is searching for
public:
	void searchDrink(DrinkMap drinkStorage, const string& search, DrinkMap& foundDrink); //searches for drink(s) based on user input and will return drink(s) in a map by reference.
	void searchIngredient(DrinkMap drinkStorage, const string& search, DrinkMap& foundDrink); //searches for ingredient(s) based on user input and will return 
																												  //ingredient(s) in a map by reference.
	void getSearch(DrinkMap drinkStorage, string& search, DrinkMap& drinkFound); //gets what drink or ingredient the user wants to search. Will be used in both searchDrink and searchIngredient.
	friend class Recipie;
};

