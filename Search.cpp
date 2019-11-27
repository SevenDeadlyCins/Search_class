#include "Search.h"

//this function is given a map containing all drinks, a name of a drink to search for and will return anything that partially or completely matches 
//what the user was searching for. This is returned by reference in a map of drinks.
void Search::searchDrink(DrinkMap drinkStorage, const string& search, DrinkMap& foundDrink)
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
void Search::searchIngredient(DrinkMap drinkStorage, const string& search, DrinkMap& foundIngredient)
{
	int j;
	bool found;
	DrinkMap::iterator i; //creates an iterator to easily access the key and value in ingredientStorage
	for (i = drinkStorage.begin(); i != drinkStorage.end(); i++) //loop that goes through the begining of ingredientStorage to the end of ingredientStorage
	{
		j = 0;
		found = false;
		do //loops to check the user input matches any of the ingredients in a drink  
		{
			const string& key = ingredientList.at(j).getName; //gets the current ingredient in the drink to compare with the search
			if (key.compare(0, search.size(), search, 0, search.size()) == 0) //compares the user input with the current key. explenation of what is happening below
																		//if the first search.size() values in key are the same as the first search.size()values in name, then...
			{
				foundIngredient.insert(DrinkPair(i->first, i->second)); //...insert the key and ingredient of the current point on map ingredientStorage into the map foundIngredient
				found == true; //sets found to true, meaning that the current drink contains the ingredient searched for 
			}
			j++; //incrument j for the loop
		}while (j < ingredientList.size && found == false); //if the number of ingredients is less than j (ingredient not found) or found == true (ingredient was found), exit loop
	}
}

void Search::getSearch(DrinkMap drinkStorage, string& search, DrinkMap& drinkFound) //gets what the user wants to searh for and searches both for ingredients and drink names
{
	cin >> search;//gets the users search
	searchIngredient(drinkStorage, search, drinkFound); //searches for the drinks based on their ingredients
	searchDrink(drinkStorage, search, drinkFound); //searches for the drinks based on the drink names, based on ingredient will be stored first
}