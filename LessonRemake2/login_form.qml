import QtQuick 2.0
import QtQuick.Window 2.13
import QtQuick.Controls 2.12

Item {

    id:login_form
    anchors.top: parent.top
    anchors.horizontalCenter: parent.horizontalCenter
    Text {
               id: title_text
               text: qsTr("Sign in")
               color: "purple"
               font.pixelSize: 20
               anchors.top:login_form.top
               anchors.topMargin: 10
               anchors.horizontalCenter: login_form.horizontalCenter
           }
    TextField{
        id:text_login
        placeholderText: qsTr("login")
        anchors.horizontalCenter:login_form.horizontalCenter
        anchors.topMargin: 10
        anchors.top:title_text.bottom

    }
    TextField{
        id:text_passin
        placeholderText: qsTr("password")
        anchors.horizontalCenter:login_form.horizontalCenter
        anchors.topMargin: 10
        anchors.top:text_login.bottom
    }
    Text {
        id: title_inf1
        text: qsTr("_")
        visible: false
        anchors.horizontalCenter:login_form.horizontalCenter
        anchors.topMargin: 10
        anchors.top:text_passin.bottom
    }
    Button{
        id:button_sighin
        anchors.top: title_inf1.bottom
        anchors.topMargin: 10
        anchors.horizontalCenter: login_form.horizontalCenter
        text: qsTr("sign in")
        visible: text_login.text.length>=5 && text_passin.text.length>=5
        onClicked: {
            title_inf1.visible=true
            title_inf1.text="Please wait..."
        }
    }

}
