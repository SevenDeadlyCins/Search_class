#include "test.h"
#include <iostream>
#include <string>
#include <map>
using namespace std;

typedef int val;

void searchDrinks(map<string, val>& drinkS, const string& name, map<string, val>& res)
{
	map<string, val>::iterator i; //creates an iterator to access the key and value in the map
	for (i = drinkS.begin(); i != drinkS.end(); i++) //while there are still values to check in the map
	{
		const string& key = i->first; //sets the key to the current key in the map
		if (key.compare(0, name.size(), name, 0, name.size()) == 0) //if the first name.size() characters in key are the same as the first name.size() characters in name, then...
		{
			res.insert(pair<string, val>(i->first, i->second)); //...the current key and value in drinkS will be stored into res, and will be returned by reference at the end of the loop.
		}
	}
}

int main()
{
	//test map
	map<string, val> teststore =
	{
		{"test123", 123},
		{"test134", 134},
		{"test245", 245},
		{"test256", 256}
	};
	map<string, val> result; //returned maps
	string na; //user input
	cout << "Search: ";
	cin >> na; //asks user for input
	while (na != "exit") //while the value is not exit
	{
		searchDrinks(teststore, na, result); //search is called with the test map, the search and any maps that match the search will be returned to result
		map<string, val>::iterator it; //iterator to go through the result map
		if (result.empty() == false) //if there was anything that matched the search
		{
			for (it = result.begin(); it != result.end(); it++) //output all of the values in result
			{
				cout << it->first << " => " << it->second << endl;
			}
			cout << endl;
		}
		else //no results were found durring the search
		{
			cout << "No results found. \n \n";
		}
		cout << "Search: ";
		cin >> na;
		result.clear(); //clear all of the results when a new search begins
	}
}