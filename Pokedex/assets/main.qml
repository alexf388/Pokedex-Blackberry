import bb.cascades 1.2
NavigationPane {
    id: nav
    Page {
        Container {
            Container {
                background: Color.create("#4F2683")
                horizontalAlignment: HorizontalAlignment.Fill
                Label {
                    id: title
                    text: "SE 2250 Project - Pokédex"
                    textStyle.fontSize: FontSize.Medium
                    textStyle.color: Color.White
                    textStyle.fontWeight: FontWeight.Bold
                    horizontalAlignment: HorizontalAlignment.Center
                    objectName: "title"
                }
            }
            
            DropDown {
                id: pokedex_languages
                title: "Language"
                onSelectedIndexChanged: {
                    pokedex.languageSelected(selectedValue)
                }
                objectName: "pokedex_languages"
            }
            DropDown {
                id: pokemon_types
                title: "Pokémon Type"
                onSelectedIndexChanged: {
                    pokedex.typeSelected(selectedValue)
                }
                options: Option {
                    text: "All Types"
                    value: -1
                    selected: true
                }
                objectName: "pokemon_types"
            }
            ListView {
                dataModel: pokemon_list
                onTriggered: {

                    if (indexPath.length == 1) {
                        var chosenItem = dataModel.data(indexPath);
                        var contentpage = itemPageDefinition.createObject();

                        contentpage.itemPageTitle = chosenItem
                        nav.push(contentpage);
                    }
                }
            }

        }

    }
    attachedObjects: [
        ComponentDefinition {
            id: itemPageDefinition
            source: "ItemPage.qml"
        }
    ]
    onPopTransitionEnded: {
        page.destroy();
    }
}
