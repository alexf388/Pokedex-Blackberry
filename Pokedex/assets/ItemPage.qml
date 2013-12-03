import bb.cascades 1.2

Page {
    property alias aaa: titlebar.title
    property alias type: type_label.text // "type" property of this screen is mapped to the text field of the UI element with the id of "type_label"
    // TODO: create other aliases that will be set from main.qml
    property alias hp: hp.text
    property alias attack: attack.text
    property alias defence: defence.text
    property alias specialattack: specialattack.text
    property alias specialdefence: specialdefence.text
    property alias speed: speed.text 
    property alias totalpoints: totalpoints.text 
    property alias height : height.text
    property alias weight : weight.text
    
    titleBar: TitleBar {
        id: titlebar
    }
    Container {
        Container { // Make a container to show pokemon type
            layout: StackLayout { // Lay out sub items left-to-right
                orientation: LayoutOrientation.LeftToRight
            }
            //Type label 
            Label { 
                text: "Type: "
                textStyle.fontWeight: FontWeight.Bold
                textStyle.color: Color.DarkRed // Show this text
            } 
	        Label {
                id: type_label // Name this as type_label so that the property alias above can set the text property of this item
            } 
	             
	        
	        
	        
        }
        // TODO: Add other containers to display other stats of the pokemon
        Container{
            layout:StackLayout { // Lay out sub items top to bottom
                orientation: LayoutOrientation. LeftToRight
            }
            
            //height label 
            Label {
                text: "Height(m): "
                textStyle.fontWeight: FontWeight.Normal
                textStyle.fontSize: FontSize.Small
                textStyle.color: Color.Black 
            }
            Label{
                id: height
                textStyle.fontSize: FontSize.Small
            }
            
            //weight label 
            Label {
                text: "Weight(kg): "
                textStyle.fontWeight: FontWeight.Normal
                textStyle.fontSize: FontSize.Small
                textStyle.color: Color.Black 
            }
            Label{
                id: weight
                textStyle.fontSize: FontSize.Small
            }
            
        }
        
        
        Container{
            layout: StackLayout { // Lay out sub items top to bottom
                orientation: LayoutOrientation.TopToBottom
            }
           
            
            //HP label 
            Label {
                text: "HP: "
                textStyle.fontWeight: FontWeight.Bold
                textStyle.color: Color.DarkRed 
            }
            Label{
                id: hp
            }
            //ATTACK label
            Label {
                text: "Attack: "
                textStyle.fontWeight: FontWeight.Bold
                textStyle.color: Color.DarkRed 
            }
            Label{
                id: attack
            }
            //DEFENCE label 
            Label {
                text: "Defence: "
                textStyle.fontWeight: FontWeight.Bold
                textStyle.color: Color.DarkRed 
            }
            Label{
                id: defence
            }
            //SPECIAL ATTACK label 
            Label {
                text: "Special Attack: "
                textStyle.fontWeight: FontWeight.Bold
                textStyle.color: Color.DarkRed 
            }
            Label{
                id: specialattack
            }
            //SPECIAL DEFENCE label 
            Label {
                text: "Special Defence: "
                textStyle.fontWeight: FontWeight.Bold
                textStyle.color: Color.DarkRed 
            }
            Label{
                id: specialdefence
            }
            //SPEED label 
            Label {
                text: "Speed: "
                textStyle.fontWeight: FontWeight.Bold
                textStyle.color: Color.DarkRed 
            }
            Label{
                id: speed
            }
            //TOTALPOINTS label 
            Label {
                text: "Total points: "
                textStyle.fontWeight: FontWeight.Bold
                textStyle.color: Color.DarkRed 
            }
            Label{
                id: totalpoints
            }
            
            
            
        }
        
        
    }
}