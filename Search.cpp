#include "Search.h"

//this function is given a map containing all drinks, a name of a drink to search for and will return anything that partially or completely matches 
//what the user was searching for. This is returned by reference in a map of drinks.
void Search::searchDrink(DrinkMap drinkStorage, const string& search, DrinkMap foundDrink)
{
	DrinkMap::iterator i; //creates an iterator to easily access the key and value in drinkStorage. 
	for (i = drinkStorage.begin(); i != drinkStorage.end(); i++) //loop that goes through the begining of drinkStorage to the end of drinkStorage.
	{
		const string& key = i->first; //gets the key of the current point in drinkStorage.  used to compare the key with the user input
		if (key.compare(0, search.size(), search, 0, search.size()) == 0) //compares the user input with the current key. explenation of what is happening below
																	//if the first search.size() values in key are the same as the first search.size() values in search, then...
		{
			foundDrink.insert(DrinkPair(i->first, i->second)); //...insert the key and drink of the current point on map drinkStorage into the map foundDrink
		}
	}
}

//this function is given a map containing all ingredients, a name of an ingredient to search for and will return anything that partially or completely matches 
//what the user was searching for. This is returned by reference in a map of ingredients.
void Search::searchIngredient(IngredientMap ingredientStorage, const string& search, IngredientMap foundIngredient)
{
	IngredientMap::iterator i; //creates an iterator to easily access the key and value in ingredientStorage
	for (i = ingredientStorage.begin(); i != ingredientStorage.end(); i++) //loop that goes through the begining of ingredientStorage to the end of ingredientStorage
	{
		const string& key = i->first; //gets the key of the current point in ingredientStorage. used to compare the key with the user input
		if (key.compare(0, search.size(), search, 0, search.size()) == 0) //compares the user input with the current key. explenation of what is happening below
																	//if the first search.size() values in key are the same as the first search.size()values in name, then...
		{
			foundIngredient.insert(IngredientPair(i->first, i->second)); //...insert the key and ingredient of the current point on map ingredientStorage into the map foundIngredient
		}
	}
}

void Search::getSearch(string& search) //gets what the user wants to searh for and puts it into search.
{
	cin >> search;
}

//Old versions of the search functions
/*
Drink Search::searchDrinks(string name) //Searches through a map of Drinks returning the first Drink that matches search, or nothing if it's not found.
{
	if (drinkStorage.count(name) == true)
	{
		return drinkStorage[name];
	}
	else
		;
}


Ingredient Search::searchIngredient(string name) //Searhes through a map of Ingredients returning the first Ingredient that matches search, or nothing if not found.
{
	if (ingredientStorage.count(name) == true)
	{
		return ingredientStorage[name];
	}
	else
		;
}*/