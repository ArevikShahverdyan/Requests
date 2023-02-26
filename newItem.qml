import QtQuick 2.0
import QtLocation 5.8

MapQuickItem {
    sourceItem: Image {
        id: name
        source: "/Satellite/1042820.png"
        width: 40;
        height: 40;
        transformOrigin:Item.Center
        transform: Rotation
    }
    opacity:1.0
    anchorPoint: Qt.point(sourceItem.width/2, sourceItem.height/2)
    property string name: "";
}
