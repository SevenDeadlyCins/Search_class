#include "test.h"
#include <iostream>
#include <string>
#include <map>
using namespace std;
//this file is primarily to test a simpler version of that I'm trying to do, not related to the Search class, but here for anyone that wants to see it.
void searchDrinks(map<string, int>& drinkS, const string& name, map<string, int>& res)
{
	map<string, int>::iterator i = drinkS.begin();
	map<string, int>::iterator it = drinkS.end();
	for (i = drinkS.begin(); i != drinkS.end(); i++)
	{
		const string& key = i->first;
		if (key.compare(0, key.length(), name, name.length()) == 0)
		{
			res.insert(pair<string, int>(i->first, i->second));
		}
	}
}

int main()
{
	map<string, int> teststore =
	{
		{"test123", 123},
		{"test134", 134},
		{"test245", 245},
		{"test256", 256}
	};
	map<string, int> result;
	string na;
	while (na != "done")
	{
		cin >> na;
		searchDrinks(teststore, na, result);
		map<string, int>::const_iterator it = result.lower_bound(na);
		while (result.empty() == false)
		{
			cout << it->first << " => " << it->second << endl;
			result.erase(result.begin());
		}
	}
}
