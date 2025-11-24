// import QtQuick 2.15

// Item {

// }



import QtQuick
import QtQuick.Controls

ApplicationWindow {
    width: 480
    height: 640
    visible: true
    title: "即时聊天客户端 (QML版)"

    Column {
        anchors.fill: parent
        spacing: 8

        // 聊天显示区
        ListView {
            id: chatView
            anchors.horizontalCenter: parent.horizontalCenter
            width: parent.width
            height: parent.height - inputRow.height - 20
            model: ListModel { id: chatModel }
            delegate: MessageBubble {
                text: model.text
                isSelf: model.isSelf
            }
        }

        // 输入区
        Row {
            id: inputRow
            width: parent.width
            spacing: 6
            TextField {
                id: inputField
                width: parent.width - sendBtn.width - 20
                placeholderText: "输入消息..."
            }
            Button {
                id: sendBtn
                text: "发送"
                onClicked: {
                    if (inputField.text !== "") {
                        chatModel.append({ "text": "我: " + inputField.text, "isSelf": true })
                        inputField.text = ""
                    }
                }
            }
        }
    }
}
