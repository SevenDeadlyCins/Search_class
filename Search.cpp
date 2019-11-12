#include "Search.h"

/*map<string, Drink>::const_iterator searchDrink(const map<string, Drink>& drinkS,const string& name)
{
	map<string, Drink>::const_iterator i = drinkS.lower_bound(name);
	if (i != drinkS.end())
	{
		const string& key = i->first;
		if (key.compare(0, name.size(), name) == 0)
			return i;
	}
		return drinkS.end();
}*/

//anything commented out I am still working on.

string Search::getSearch() //gets what the user wants to searh for and puts it into search.
{
	cin >> search;
}

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
}