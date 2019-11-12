#include "Drink.h"
#include "Ingredient.h"
#include <iostream>
#include <map>
#include <string>
using namespace std;

class Search
{
private:
	map<string, int> drinkStorage;
	map<string, Ingredient> ingredientStorage;
	string search;
public:
	//Drink searchDrink(const map<string, Drink>& drinkS, const string& name);
	string getSearch();
	Drink searchDrinks(string drName);
	Ingredient searchIngredient(string inName);

};

