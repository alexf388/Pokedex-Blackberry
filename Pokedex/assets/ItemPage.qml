import bb.cascades 1.2

Page {
    property alias aaa: titlebar.title
    property alias type1: type_label_1.text // "type" property of this screen is mapped to the text field of the UI element with the id of "type_label"
    property alias type2: type_label_2.text
    
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
    property alias description : description.text
    
    titleBar: TitleBar {
        id: titlebar
    }
    Container {
        Container { // Make a container to show pokemon type
            layout: StackLayout { // Lay out sub items left-to-right
                orientation: LayoutOrientation.LeftToRight
            }
            
            layoutProperties: StackLayoutProperties {
                spaceQuota: 1
            }
            //Type labels
            Label { 
                text: "Type: "
                textStyle.fontWeight: FontWeight.Bold
                textStyle.color: Color.DarkRed // Show this text
                
            } 
	        Label {
                id: type_label_1 // Name this as type_label so that the property alias above can set the text property of this item
            } 
	        
            Label { 
                text: "  "
                textStyle.fontWeight: FontWeight.Bold
                textStyle.color: Color.DarkRed // Show this text
            } 
            Label {
                id: type_label_2 // Name this as type_label so that the property alias above can set the text property of this item
            } 
	        
            
            
	        
	        
        }
        
        Container{
            layout: StackLayout { // Lay out sub items left-to-right
                orientation: LayoutOrientation.TopToBottom
            }
            
            
            Label { 
                text: "Description:"
                textStyle.fontWeight: FontWeight.Normal
                textStyle.fontSize: FontSize.Small
                textStyle.color: Color.DarkRed // Show this text
            } 
            Label {
                id: description // Name this as type_label so that the property alias above can set the text property of this item
                //textStyle.fontSize: FontSize.Small
                multiline: true
                
                
                autoSize.maxLineCount: 5
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
                textStyle.fontSize: FontSize.Small
            }
            Label{
                id: hp
                textStyle.fontSize: FontSize.Small
            }
            //ATTACK label
            Label {
                text: "Attack: "
                textStyle.fontWeight: FontWeight.Bold
                textStyle.color: Color.DarkRed 
                textStyle.fontSize: FontSize.Small
            }
            Label{
                id: attack
                textStyle.fontSize: FontSize.Small
            }
            //DEFENCE label 
            Label {
                text: "Defence: "
                textStyle.fontWeight: FontWeight.Bold
                textStyle.color: Color.DarkRed 
                textStyle.fontSize: FontSize.Small
            }
            Label{
                id: defence
                textStyle.fontSize: FontSize.Small
            }
            //SPECIAL ATTACK label 
            Label {
                text: "Special Attack: "
                textStyle.fontWeight: FontWeight.Bold
                textStyle.color: Color.DarkRed 
                textStyle.fontSize: FontSize.Small
            }
            Label{
                id: specialattack
                textStyle.fontSize: FontSize.Small
            }
            //SPECIAL DEFENCE label 
            Label {
                text: "Special Defence: "
                textStyle.fontWeight: FontWeight.Bold
                textStyle.color: Color.DarkRed
                textStyle.fontSize: FontSize.Small 
            }
            Label{
                id: specialdefence
                textStyle.fontSize: FontSize.Small
            }
            //SPEED label 
            Label {
                text: "Speed: "
                textStyle.fontWeight: FontWeight.Bold
                textStyle.color: Color.DarkRed 
                textStyle.fontSize: FontSize.Small
            }
            Label{
                id: speed
                textStyle.fontSize: FontSize.Small
            }
            //TOTALPOINTS label 
            Label {
                text: "Total points: "
                textStyle.fontWeight: FontWeight.Bold
                textStyle.color: Color.DarkRed 
                textStyle.fontSize: FontSize.Small
            }
            Label{
                id: totalpoints
                textStyle.fontSize: FontSize.Small
            }
            
            
            
        }
        
        
    }
}