/*
 * PokemonList.cpp
 *
 *  Created on: 2013-11-02
 *      Author: Jagath
 */

#include "pokemonlist.h"
#include <iostream>

using std::cerr;
using std::endl;
using namespace bb::cascades;

/*
 * PokemonList is derive from DataModel which provides the base class for the "model"
 * in the model-view-controller pattern used by the ListView UI control
*/

PokemonList::PokemonList(QObject* parent) : bb::cascades::DataModel(parent) {
}

// Return the number of child items contained in a given entry
// Since we only implement a flat list, we must return 0 for any sub item.
int PokemonList::childCount(const QVariantList& indexPath) {
	// For indexPath, See http://developer.blackberry.com/native/reference/cascades/bb__cascades__datamodel.html

	// Return the item count if asking for top level count
	if (indexPath.empty())
		//return 6;//original code
		return 718;	// TODO: Return the correct number of pokemon

	// No sub levels
	return 0;
}

// Used for displaying multi-level lists
bool PokemonList::hasChildren(const QVariantList& indexPath) {
	if (indexPath.empty())
		return true; // The root node always has children
	else
		return false; //
}

// Return the data for the item given by indexPath
QVariant PokemonList::data(const QVariantList& indexPath) {
	// TODO: Load the list from db/pokemon.csv file
	//static QString pokemon_list[6]={"#001 Bulbasaur [Grass, Poison]", "Ivysaur", "Venusaur", "Charmander", "Charmeleon", "Charizard"};
	//static QString pokemon_type[6]={"Grass, Poison", "Grass, Poison", "Grass, Poison", "Fire", "Fire", "Fire, Flying"}; //this causes memory leak somewhere probably due to return 718 above

	QFile file("app/native/assets/data/pokemon.csv");
	static QString pokemon_list[719];
	QStringList list3; //this list will separate the line input by commas
	int counter = 0; //counts the number of pokemon until 718

	if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {

		// Successfully opened
		QTextStream in(&file); // create a text stream from the file
		while (!in.atEnd()) { // Read until EOF
			QString line = in.readLine(); // Read a line as a QString
			//cerr << line.toStdString() << endl;

			//splits string between commas
			list3 = line.split(QRegExp("\\W+"), QString::SkipEmptyParts);

			if (counter < 718){
				if (list3[1] != "identifier"){
					pokemon_list[counter] = list3[1];

					//for testing purposes only
					cerr<<"list3[1]:" << list3[1].toStdString() << endl;
					cerr << "pokemon_list[counter]: " << pokemon_list[counter].toStdString() << endl;

					counter++;

				}

			}

		}

	}

	else
		cerr << "Failed to open types.csv: " << file.error() << endl;


	int i = indexPath[0].toInt(); 		// Get the menu index
	QVariantMap data;
	data["name"] = pokemon_list[i];	// Get the name of pokemon for this index
	//data["type"] = pokemon_type[i]; //this causes memory leak somewhere probably due to return 718 above
	return data;			// Return the name as a QVariant object
}

PokemonList::~PokemonList() {
	// TODO: Delete any object that were created
}

