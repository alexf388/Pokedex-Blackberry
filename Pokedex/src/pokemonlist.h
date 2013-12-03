/*
 * PokemonList.h
 *
 *  Created on: 2013-11-02
 *      Author: Jagath
 */

#ifndef POKEMONLIST_H_
#define POKEMONLIST_H_

#include <QString>

#include <bb/cascades/DataModel>

class PokemonList: public bb::cascades::DataModel {
	Q_OBJECT
public:
	PokemonList(QObject *parent = 0);

	// Required interface implementation
	virtual int childCount(const QVariantList& indexPath);
	virtual bool hasChildren(const QVariantList& indexPath);
	virtual QVariant data(const QVariantList& indexPath);



	//added recently
	Q_INVOKABLE void languageSelected(int language);
	Q_INVOKABLE void typeSelected(int type);




	virtual ~PokemonList();

private:
	//char const *language_number;
	QString language_number;
	int type_number;

	int counter_normal;
};
#endif /* POKEMONLIST_H_ */
