/*
 * PokemonList.cpp
 *
 *  Created on: 2013-11-02
 *      Author: Jagath
 */

#include "pokemonlist.h"


#include <iostream>
#include <bb/cascades/DataModelChangeType>
#include <string>
#include <sstream>
#include <string.h>
#include <QString>


using std::cerr;
using std::endl;
using namespace bb::cascades;
using namespace std;


//values for sizes of all types
//number of all types
static int numberOfAllTypes = 718;


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
		return 718;//original code
		//return 718;	// TODO: Return the correct number of pokemon

	// No sub levels
	if (type_number == 1){

		return 105;
	}
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
	//static QString pokemon_type[718]={"Grass, Poison", "Grass, Poison", "Grass, Poison", "Fire", "Fire", "Fire, Flying"}; //this causes memory leak somewhere probably due to return 718 above
	//static QString pokemon_abilities[718] ={}; //how to access abilities for respective pokemon?

		/* Testing only
		static QString pokemon_hp[718];
		static QString pokemon_attack[718];
		static QString pokemon_defence[718];
		static QString pokemon_specialattack[718];
		static QString pokemon_specialdefence[718];
		static QString pokemon_speed[718];
		static QString pokemon_totalpoints[718];
		static QString pokemon_height[718];
		static QString pokemon_weight[718];
		static QString pokemon_type_1[718];
		static QString pokemon_type_2[718];
		static QString pokemon_description[718];
		*/

	QVariantMap data;

	//testing only
	//static QString pokemon_hp[718]={"45"};//stat_id = 1
	//static QString pokemon_attack[718]= {"49"}; //stat_id = 2
	//static QString pokemon_defence[718]={"49"}; //stat_id = 3
	//static QString pokemon_specialattack[718]={"65"}; //stat_id = 4
	//static QString pokemon_specialdefence[718]={"65"}; //stat_id = 5
	//static QString pokemon_speed[718] = {"45"}; //stat_id = 6


	//TODO: also need total stat points
	//TODO: also need description (from earliest appearance)
	//static QString pokemon_totalstats[718] = hp + attack + defence + special attack + special defence + speed






	//testing indexPath
	//int level = indexPath.size();
	//cout << "size of level is " << level << endl;
	//cout << "indexPath[0] to int is : " << indexPath[0].toInt() << endl;
	//cout <<"indexpath[1,0] to int is: " << indexPath[1,0].toInt() << endl;




	if (type_number == 1){ //select normal
		cout <<"you selected normal " << endl;

		//count the number of pokemon
		QFile file_normal("app/native/assets/data/pokemon_types.csv");
		//static QString pokemon_list[719];
		QStringList list_normal; //this list will separate the line input by commas
		counter_normal = 0;
		//static int numberOfNormalTypes = 97;


		if (file_normal.open(QIODevice::ReadOnly | QIODevice::Text)) {
			QTextStream in(&file_normal);
			while (!in.atEnd()) {
				QString line = in.readLine();
				list_normal = line.split(",");

				if (list_normal[1] == "1" && (list_normal[0].toInt() < numberOfAllTypes)){
					counter_normal++;
				}
			}
		}
		else
			cerr << "Failed to open pokemon_types.csv: " << file_normal.error() << endl;

		cout << "counter_normal is: " << counter_normal << endl;
		//emit itemsChanged( bb::cascades::DataModelChangeType::Init);








	}
	else if (type_number == 2){
		cout <<"you selected Fighting" << endl;

	}
	else if (type_number == 3){
		cout <<"you selected Flying" << endl;
	}


	else{ //selected all types
		cout <<"You selected all types!!!" << endl;
		//pokemon_species_name is required for multiple languages!

		static QString pokemon_hp[718];
		static QString pokemon_attack[718];
		static QString pokemon_defence[718];
		static QString pokemon_specialattack[718];
		static QString pokemon_specialdefence[718];
		static QString pokemon_speed[718];
		static QString pokemon_totalpoints[718];
		static QString pokemon_height[718];
		static QString pokemon_weight[718];
		static QString pokemon_type_1[718];
		static QString pokemon_type_2[718];
		static QString pokemon_description[718];

		QFile file("app/native/assets/data/pokemon_species_names.csv");
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
				//cout << list3[1] << endl;

				//convert char to int
				//char* language_number_typecast = (char*)language_number;


				if (counter < numberOfAllTypes ){
					//obsolete by the use of pokemon_species_names
					//if (list3[1] != "identifier" && ){
					if (list3[2]!="name" && list3[1]==language_number){
						pokemon_list[counter] = list3[2];

						//for testing purposes only
						//cerr<<"list3[1]:" << list3[1].toStdString() << endl;
						//cerr << "pokemon_list[counter]: " << pokemon_list[counter].toStdString() << endl;

						counter++;

					}

				}

			}

		}
		else
			cerr << "Failed to open pokemon_species_names.csv" << file.error() << endl;


		//correct number for pokemon HP, attack
		QFile file1("app/native/assets/data/pokemon_stats.csv");
		QStringList list_stats;
		static int counter_hp = 0;
		static int counter_attack = 0;
		static int counter_defence = 0;
		static int counter_specialattack = 0;
		static int counter_specialdefence = 0;
		static int counter_speed = 0;
		static int counter_totalpoints = 0;//should be the same as counter_speed

		int hp_convert = 0;
		int attack_convert = 0;
		int defence_convert = 0;
		int specialattack_convert = 0;
		int specialdefence_convert = 0;
		int speed_convert = 0;


		if (file1.open(QIODevice::ReadOnly | QIODevice::Text)) {
			// Successfully opened
			QTextStream in(&file1);

			while (!in.atEnd()) {
				QString line = in.readLine();

				list_stats = line.split(QRegExp("\\W+"), QString::SkipEmptyParts);
				//cerr <<"list stats: " << list_stats[1].toStdString() << endl;

				if(counter_speed < numberOfAllTypes){ //NOTE: should really use counter_whichever is the last one
					//if hp
					if (list_stats[1]=="1"){
						pokemon_hp[counter_hp]= list_stats[2];

						//convert to int for total points
						hp_convert = pokemon_hp[counter_hp].toInt();

						counter_hp++;

					}
					//if attack
					if (list_stats[1]=="2"){
						pokemon_attack[counter_attack]=list_stats[2];

						//convert to int for total points
						attack_convert = pokemon_attack[counter_attack].toInt();

						counter_attack++;

					}
					//if defence
					if (list_stats[1]=="3"){
						pokemon_defence[counter_defence]=list_stats[2];

						//convert to int for total points
						defence_convert = pokemon_defence[counter_defence].toInt();

						counter_defence++;
					}
					//if specialattack
					if (list_stats[1]=="4"){
						pokemon_specialattack[counter_specialattack]=list_stats[2];

						//convert to int for total points
						specialattack_convert = pokemon_specialattack[counter_specialattack].toInt();

						counter_specialattack++;

					}
					//if specialdefence
					if (list_stats[1]=="5"){
						pokemon_specialdefence[counter_specialdefence]=list_stats[2];

						//convert to int for total point
						specialdefence_convert = pokemon_specialdefence[counter_specialdefence].toInt();

						counter_specialdefence++;
					}
					//if speed and total points exist
					if (list_stats[1]=="6"){
						pokemon_speed[counter_speed]=list_stats[2];

						//convert to int for total points
						speed_convert = pokemon_speed[counter_speed].toInt();

						counter_speed++;

						//add total points
						int total_points_int = hp_convert + attack_convert + defence_convert + specialattack_convert + specialdefence_convert + speed_convert ;
						//convert total_points to QString
						QString total_points_qstring = QString::number(total_points_int);

						pokemon_totalpoints[counter_totalpoints] = total_points_qstring;

						counter_totalpoints++;
					}


					emit itemsChanged( bb::cascades::DataModelChangeType::Update);//used to indicate items have chagned

				}


			}
		}
		else
			cerr << "Failed to open pokemon_stats.csv" << file1.error() << endl;

		//mass and height
		//open file2 to access mass and height for each pokemon
		QFile file2("app/native/assets/data/pokemon.csv");
		QStringList pokemon_stats;
		static int stats_counter= 0;

		if (file2.open(QIODevice::ReadOnly | QIODevice::Text)) {
			QTextStream in(&file2);

			while (!in.atEnd()) {
				QString line = in.readLine();
				pokemon_stats= line.split(QRegExp("\\W+"), QString::SkipEmptyParts);

				if ((stats_counter < numberOfAllTypes) && pokemon_stats[0]!="id"){
					double height = pokemon_stats[3].toDouble();
					double weight = pokemon_stats[4].toDouble();

					height = height/10;
					weight = weight/10;

					//pokemon_height[stats_counter] = pokemon_stats[3];
					//pokemon_weight[stats_counter] = pokemon_stats[4];

					pokemon_height[stats_counter] = QString::number(height);
					pokemon_weight[stats_counter] = QString::number(weight);

					stats_counter++;
				}

			}

		}
		else
			cerr << "Failed to open pokemon.csv" << file2.error() << endl;

		//pokemon_types
		QFile file3("app/native/assets/data/pokemon_types.csv");
		QStringList pokemon_types;
		static int types_counter_1= 0;
		static int types_counter_2= 0 ;

		 if (file3.open(QIODevice::ReadOnly | QIODevice::Text)) {
			 // Successfully opened
			 QTextStream in(&file3); // create a text stream from the file
			 while (!in.atEnd()) { // Read until EOF
				 QString line = in.readLine(); // Read a line as a QString
				 pokemon_types= line.split(QRegExp("\\W+"), QString::SkipEmptyParts);

				 if (types_counter_2 < numberOfAllTypes){//should be stats_counter_2
					 if ((pokemon_types[0]!="pokemon_id")){
						 if (pokemon_types[2]=="1"){



							 QFile file_types("app/native/assets/data/type_names.csv");
							 	QStringList list;

							 	if (file_types.open(QIODevice::ReadOnly | QIODevice::Text)) {
							 		// Successfully opened
							 		QTextStream in(&file_types); // create a text stream from the file
							 		while (!in.atEnd()) { // Read until EOF
							 			QString line = in.readLine(); // Read a line as a QString
							 			//cerr << line.toStdString() << endl;

							 			list= line.split(QRegExp("\\W+"), QString::SkipEmptyParts);

							 			if (list[1] == language_number && list[0]==pokemon_types[1]){
							 				pokemon_type_1[types_counter_1] =list[2];
							 				types_counter_2= types_counter_1;
							 				types_counter_1++;
							 			}
							 		}

							 	}
							 	 else
							 		 cerr << "Failed to open types_names.csv: " << file.error() << endl;


							 //types_counter_1++;

							 //TODO: create a function that takes in language QString and pokemon_types[1] QString and translate it into the appropriate type with respect to language
						 }

						 if (pokemon_types[2]=="2"){
							 //pokemon_type_2[types_counter_2] = pokemon_types[1];


							 	QFile file_types2("app/native/assets/data/type_names.csv");
							 	QStringList list2;

							 	if (file_types2.open(QIODevice::ReadOnly | QIODevice::Text)) {
							 		// Successfully opened
							 		QTextStream in(&file_types2); // create a text stream from the file
							 		while (!in.atEnd()) { // Read until EOF
							 			QString line = in.readLine(); // Read a line as a QString
							 			//cerr << line.toStdString() << endl;

							 			list2= line.split(QRegExp("\\W+"), QString::SkipEmptyParts);

							 			if (list2[1] == language_number && list2[0]==pokemon_types[1]){
							 				pokemon_type_2[(types_counter_2)] = list2[2];
							 				//types_counter_2++;
							 			}
							 		}

							 	}
							 	 else
							 		 cerr << "Failed to open types_names.csv: " << file.error() << endl;

							 types_counter_2++;

							 //TODO: create a function that takes in language QString and pokemon_types[1] QString and translate it into the appropriate type with respect to language
						 }


					 }

				 }

			 }
		 }
		 else
			 cerr << "Failed to open pokemon_types.csv: " << file3.error() << endl;


		//description
		//open different file to access description
		 QFile file4("app/native/assets/data/pokemon_species_flavor_text.csv");
		 QStringList description_list;
		 static int description_counter = 1;

		 if (file4.open(QIODevice::ReadOnly | QIODevice::Text)) {
			  // Successfully opened
			  QTextStream in(&file4); // create a text stream from the file
			  while (!in.atEnd()) { // Read until EOF
				  QString line = in.readLine(); // Read a line as a QString
				  description_list= line.split("," );

				  if (description_list[0].toInt() == description_counter && description_list[2]== language_number){
					  pokemon_description[(description_counter-1)] = description_list[3];
					  description_counter++;

				  }
			  }
		  }
		  else
			  cerr << "pokemon_species_flavor_text.csv " << file4.error() << endl;




		int i = indexPath[0].toInt(); 		// Get the menu index
		//added to the top
		//QVariantMap data;

		data["aaa"] = pokemon_list[i];	// Get the name of pokemon for this index
		data["type1"] = pokemon_type_1[i];
		data["type2"] = pokemon_type_2[i];



		//data["ability"] = pokemon_abilities[i];
		data["hp"]=pokemon_hp[i];
		//return other types of data, such as ability, hit points, attack, defence, special attack, special defence, speed, total stat points, height (m), weight (kg), and description (from earliest appearance/version)
		//TODO: how do I return ability?
		data["attack"] = pokemon_attack[i];
		data["defence"]=pokemon_defence[i];
		data["specialattack"]=pokemon_specialattack[i];
		data["specialdefence"]= pokemon_specialdefence[i];
		data["speed"]=pokemon_speed[i];
		data["totalpoints"]= pokemon_totalpoints[i];
		data["height"]=pokemon_height[i];
		data["weight"]=pokemon_weight[i];
		data["description"]=pokemon_description[i];





		return data;			// Return the name as a QVariant object
	}




}

void PokemonList::typeSelected(int type){
	cerr <<"type in pokemon_list " << type << "has been selected" << endl;
	type_number = type;
	emit itemsChanged( bb::cascades::DataModelChangeType::Update);
}


void PokemonList::languageSelected(int language){
	cerr << "language " << language << " selected "<< endl;
	//language_number = language;

	//convert int language to char const *language_number
	/*
	stringstream strs;
	strs << language;
	string temp_string = strs.str();
	language_number = (char*) temp_string.c_str();
	cout << language_number << endl;
	*/
	//convert int to QString
	language_number = QString::number(language);
	emit itemsChanged( bb::cascades::DataModelChangeType::Update);
	//emit itemsChanged(bb::cascades::DataModelChangeType::Init);

}






PokemonList::~PokemonList() {
	// TODO: Delete any object that were created
}

