import QtQuick 2.0
import QtQuick.Window 2.13
import QtQuick.Controls 2.12

Item {
    id:reg_form
    anchors.top: parent.top
    anchors.horizontalCenter: parent.horizontalCenter

    Text {
        id: title_text
        text: qsTr("Sign up")
        color: "purple"
        font.pixelSize: 20
        anchors.top:reg_form.top
        anchors.topMargin: 10
        anchors.horizontalCenter: reg_form.horizontalCenter
    }

    TextField{
        id:text_logup
        placeholderText: qsTr("login")
        anchors.horizontalCenter:reg_form.horizontalCenter
        anchors.topMargin: 10
        anchors.top:title_text.bottom
    }
    TextField{
        id:text_passup1
        placeholderText: qsTr("password")
        anchors.horizontalCenter:reg_form.horizontalCenter
        anchors.topMargin: 10
        anchors.top:text_logup.bottom
    }
    TextField{
        id:text_passup2
        placeholderText: qsTr("repeat your password")
        anchors.horizontalCenter:reg_form.horizontalCenter
        anchors.topMargin: 10
        anchors.top:text_passup1.bottom
    }
    TextField{
        id:text_nickname
        placeholderText: qsTr("nickname")
        anchors.horizontalCenter:reg_form.horizontalCenter
        anchors.topMargin: 10
        anchors.top:text_passup2.bottom
    }
    Text {
        id: title_inf2
        text: qsTr("_")
        visible: false
        anchors.horizontalCenter:reg_form.horizontalCenter
        anchors.topMargin: 10
        anchors.top:text_nickname.bottom
    }
    Button{
        id:button_sighup
        anchors.top: title_inf2.bottom
        anchors.topMargin: 10
        anchors.horizontalCenter: reg_form.horizontalCenter
        text: qsTr("sign up")
        visible: text_logup.text.length>=5 && text_passup1.text.length>=5 && text_passup2.text.length>=5 && text_nickname.text.length>=5
        onClicked: {
            if(text_passup1.text!=text_passup2.text)
                title_inf2.text="Error. Password doesn't much"
            else
                title_inf2.text="Cheack your mail"
            title_inf2.visible=true
        }
    }

}
