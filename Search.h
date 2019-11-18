#include "Drink.h"
#include "Ingredient.h"
#include <iostream>
#include <map>
#include <string>
using namespace std;

//typedef for maps and pairs for easier reading
typedef map<string, Drink> DrinkMap;
typedef map<string, Ingredient> IngredientMap;
typedef pair<string, Drink> DrinkPair;
typedef pair<string, Ingredient> IngredientPair;

//Declaring Search Class
class Search
{
private:
	DrinkMap drinkStorage; //Storage of all drinks
	IngredientMap ingredientStorage; //Storage of all ingredients
	DrinkMap foundDrink; //any drink that matches what was found in search, used to return multiple drinks
	IngredientMap foundIngredient; //any Ingredient that matches what was found in search, used to return multiple ingredients 
	string search; //what drink or ingredient the user is searching for
public:
	void searchDrink(DrinkMap drinkStorage, const string& search, DrinkMap foundDrink); //searches for drink(s) based on user input and will return drink(s) in a map by reference.
	void searchIngredient(IngredientMap ingredientStorage, const string& search, IngredientMap foundIngredient); //searches for ingredient(s) based on user input and will return 
																												  //ingredient(s) in a map by reference.
	void getSearch(string& search); //gets what drink or ingredient the user wants to search. Will be used in both searchDrink and searchIngredient.
	//Drink searchDrinks(string drName); //old version of searchDrink.
	//Ingredient searchIngredient(string inName); //old version of searchIngredient.

};

