import QtQuick 2.9
import QtQuick.Controls 2.0
import QtQuick.Window 2.2
import QtLocation 5.6
import QtPositioning 5.6
import ReadAllData_class 1.0
ApplicationWindow {

    visible: true
    width:  Screen.width
    height: Screen.height
    title: qsTr("Satellite")

    property double start_latitude: 40.18111
    property double start_longitude: 44.51361
    property string satellite_name: ""
    property int satellite_ID: 0
    property double satellite_latitude: 0.0
    property double satellite_longitude: 0.0
    property double satellite_altitude: 0.0
    property var quickitem;
    property var info_Label;
    property bool newchild: false
    property string object_Info_text_color:"green"
    property int object_Info_text_size: 20
    property int info_text_height:15
    property int info_text_width:50

    Plugin {
            id: mapPlugin
            name: "osm"
    }

    Map {
        id: map
        anchors.fill: parent
        plugin: mapPlugin
        center: QtPositioning.coordinate(start_latitude, start_longitude)
        zoomLevel: 9
        Component.onCompleted: {
            map.activeMapType = map.supportedMapTypes[0]
        }
    }
    Connections {
        target: Read_data
        onTarget_data:{
            satellite_name = satellitePositions_object.name
            satellite_ID = satellitePositions_object.norad_ID
            satellite_longitude = satellitePositions_object.longitude
            satellite_latitude = satellitePositions_object.latitude
            satellite_altitude = satellitePositions_object.altitude
            console.log("Name: " + satellite_name)
            console.log("ID: " + satellite_ID)
            console.log("Latitude: " + satellite_latitude)
            console.log("Longitude: " + satellite_longitude)
            console.log("Altitude: " + satellite_altitude)

            newchild = true;
            var stop_lat = satellitePositions_object.latitude
            var stop_long = satellitePositions_object.longitude

            for(var child in map.children){
                if(map.children[child].objectName === satellite_name) {
                    newchild = false;
                    var start_lat = map.children[child].coordinate.latitude
                    var start_long = map.children[child].coordinate.longitude
                    map.children[child].coordinate.latitude = stop_lat
                    map.children[child].coordinate.longitude = stop_long
                }
            }
            if(newchild == true){
                createNewQuickitem(satellite_name, satellite_ID, satellite_latitude, satellite_longitude, satellite_altitude, map)
                create_Info_Label("Name: " + satellite_name, object_Info_text_color, object_Info_text_size, info_text_width, info_text_height, map.children[child], map)
            }
        }
    }
    function createNewQuickitem(name, id, latitude, longitude, altitude, map)
    {
        var component = Qt.createComponent("newItem.qml");
        if( component.status !== Component.Ready )
        {
            if( component.status === Component.Error )
            {
                console.debug("Error:"+ component.errorString() );
            }
        }
        else
        {
            quickitem = component.createObject(map)
            if(quickitem !== null )
            {
                quickitem.coordinate.latitude = latitude
                quickitem.coordinate.longitude = longitude
                quickitem.z = 260;
                quickitem.objectName = name;
                console.log(quickitem.objectName)
                map.addMapItem(quickitem)
            }
        }
    }
    function create_Info_Label(name, color, size, width, height, parent, map)
    {
        var infoPanelComponent = Qt.createComponent("infoPanel.qml");
        var child = map.children
        if( infoPanelComponent.status !== Component.Ready )
        {
            if( infoPanelComponent.status === Component.Error )
                console.debug("Error:" + infoPanelComponent.errorString());
        }
        else
        {
            info_Label = infoPanelComponent.createObject(map)
            if(info_Label !== null )
            {
                info_Label.text = name;
                info_Label.color = color
                info_Label.font.pointSize = size;
                info_Label.width = width;
                info_Label.height = height;
                info_Label.anchors.horizontalCenter = child.horizontalCenter
                info_Label.anchors.bottom = child.top
                info_Label.z = 460;
                map.addMapItem(info_Label)
            }
        }
    }
}
