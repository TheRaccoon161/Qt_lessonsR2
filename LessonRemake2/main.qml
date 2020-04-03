import QtQuick 2.13
import QtQuick.Window 2.13
import QtQuick.Controls 2.12

Window {
    visible: true
    width: 250
    height: 500
    title: qsTr("Hello World")

    property string currentForm: "sign_in"

    Loader{
        id:login_form
        anchors.fill: parent
        source: "qrc:/login_form.qml"
        visible: currentForm == "sign_in"
    }
    Loader{
        id:registrate_form
        anchors.fill: parent
        source: "qrc:/reg_form.qml"
        visible: currentForm == "sign_up"
    }
    Text {
        id: slash
        text: qsTr("/")
        color: "black"
        font.pixelSize: 15
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
    }
    Text {
        id: sign_in
        text: qsTr("sign in")
        font.pixelSize: 15
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        anchors.left: slash.right
        anchors.leftMargin: 5
        MouseArea{

                cursorShape:Qt.PointingHandCursor
                anchors.fill: parent
                onClicked: {
                    if(currentForm=="sign_up")
                        currentForm = "sign_in"
                }
        }
    }
    Text {
        id: sign_up
        text: qsTr("sign up")
        font.pixelSize: 15
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        anchors.right: slash.left
        anchors.rightMargin: 5
        MouseArea{
                cursorShape:Qt.PointingHandCursor
                anchors.fill: parent
                onClicked: {
                    if(currentForm=="sign_in")
                        currentForm = "sign_up"
                }
        }
    }

}
