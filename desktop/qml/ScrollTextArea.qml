/* Copyright (C) 2023 Michal Kosciesza <michal@mkiol.net>
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

import QtQuick 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3

Item {
    id: root

    property alias textArea: _textArea
    property alias textFormatCombo: _textFormatCombo
    property alias textFormatInvalid: _textFormatComboRedBorder.visible
    property color textColor: palette.text
    property bool canUndo: true
    property bool canUndoFallback: false
    property bool canRedo: true
    property bool canClear: true
    property bool canPaste: true
    property bool canPushAdd: false
    property bool canPushReplace: false
    readonly property bool _fitContent: scrollView.availableHeight - 4 * appWin.padding >= scrollView.contentHeight
    readonly property bool _contextActive: _textFormatCombo.hovered || copyButton.hovered || clearButton.hovered ||
                                           undoButton.hovered || redoButton.hovered || pasteButton.hovered ||
                                           textPushButtonAdd.hovered || textPushButtonReplace.hovered ||
                                           _fitContent
    signal clearClicked()
    signal copyClicked()
    signal undoFallbackClicked()
    signal pushAddClicked()
    signal pushReplaceClicked()

    function scrollToBottom() {
        var position = (scrollView.contentHeight - scrollView.availableHeight) / scrollView.contentHeight
        if (position && position > 0)
            scrollView.ScrollBar.vertical.position = position
    }

    ScrollView {
        id: scrollView

        anchors.fill: parent
        enabled: root.enabled
        clip: true

        opacity: enabled ? 1.0 : 0.8
        Behavior on opacity { OpacityAnimator { duration: 100 } }

        ScrollBar.horizontal.policy: ScrollBar.AlwaysOff

        TextArea {
            id: _textArea

            enabled: root.enabled
            color: {
                if (root._contextActive && !root._fitContent) {
                    var c = root.textColor
                    return Qt.rgba(c.r, c.g, c.b, 0.4)
                }
                return root.textColor
            }
            wrapMode: TextEdit.WordWrap
            verticalAlignment: TextEdit.AlignTop
            font: _settings.notepad_font
            Keys.onUpPressed: scrollView.ScrollBar.vertical.decrease()
            Keys.onDownPressed: scrollView.ScrollBar.vertical.increase()
        }
    }

    RowLayout {
        opacity: root.enabled && root._contextActive ? 1.0 : 0.4
        Behavior on opacity { OpacityAnimator { duration: 100 } }
        visible: opacity > 0.0

        anchors {
            bottom: parent.bottom
            bottomMargin: appWin.padding
            left: parent.left
            leftMargin: appWin.padding
            right: parent.right
            rightMargin: appWin.padding + (scrollView.ScrollBar.vertical.visible ?
                                               scrollView.ScrollBar.vertical.width : 0)
        }

        ComboBox {
            id: _textFormatCombo

            Layout.alignment: Qt.AlignLeft
            visible: model !== undefined && model.length !== 0

            ToolTip.delay: Qt.styleHints.mousePressAndHoldInterval
            ToolTip.visible: hovered
            ToolTip.text: root.textFormatInvalid ? qsTr("The text format may be incorrect!") : qsTr("Text format")
            hoverEnabled: true

            Rectangle {
                id: _textFormatComboRedBorder

                visible: false
                border.width: 1
                border.color: "red"
                radius: 2
                anchors.fill: parent
                color: "transparent"
            }
        }

        Row {
            Layout.alignment: Qt.AlignLeft
            spacing: appWin.padding

            Button {
                id: textPushButtonAdd

                text: qsTr("Add")
                visible: root.canPushAdd
                onClicked: root.pushAddClicked()
                ToolTip.delay: Qt.styleHints.mousePressAndHoldInterval
                ToolTip.visible: hovered
                ToolTip.text: qsTr("Add the translated text to the note.")
                hoverEnabled: true
            }

            Button {
                id: textPushButtonReplace

                text: qsTr("Replace")
                visible: root.canPushReplace
                onClicked: root.pushReplaceClicked()
                ToolTip.delay: Qt.styleHints.mousePressAndHoldInterval
                ToolTip.visible: hovered
                ToolTip.text: qsTr("Replace the note with translated text and switch languages.")
                hoverEnabled: true
            }
        }

        Item {
            Layout.fillWidth: true
        }

        ToolButton {
            id: copyButton

            Layout.alignment: Qt.AlignRight
            icon.name: "edit-copy-symbolic"
            onClicked: root.copyClicked()
            visible: root.textArea.text.length !== 0

            ToolTip.visible: hovered
            ToolTip.delay: Qt.styleHints.mousePressAndHoldInterval
            ToolTip.text: qsTr("Copy")
            hoverEnabled: true
        }
        ToolButton {
            id: pasteButton

            Layout.alignment: Qt.AlignRight
            icon.name: "edit-paste-symbolic"
            onClicked: root.textArea.paste()
            visible: root.canPaste && root.textArea.canPaste

            ToolTip.visible: hovered
            ToolTip.delay: Qt.styleHints.mousePressAndHoldInterval
            ToolTip.text: qsTr("Paste")
            hoverEnabled: true
        }
        ToolButton {
            id: clearButton

            Layout.alignment: Qt.AlignRight
            icon.name: "edit-delete-symbolic"
            onClicked: root.clearClicked()
            visible: root.canClear && !root.textArea.readOnly && root.textArea.text.length !== 0

            ToolTip.visible: hovered
            ToolTip.delay: Qt.styleHints.mousePressAndHoldInterval
            ToolTip.text: qsTr("Clear")
            hoverEnabled: true
        }
        ToolButton {
            id: undoButton

            Layout.alignment: Qt.AlignRight
            icon.name: "edit-undo-symbolic"
            onClicked: {
                if (root.textArea.canUndo)
                    root.textArea.undo()
                else
                    root.undoFallbackClicked()
            }
            visible: !root.textArea.readOnly && root.canUndo && (root.textArea.canUndo || root.canUndoFallback)

            ToolTip.visible: hovered
            ToolTip.delay: Qt.styleHints.mousePressAndHoldInterval
            ToolTip.text: qsTr("Undo")
            hoverEnabled: true
        }
        ToolButton {
            id: redoButton

            Layout.alignment: Qt.AlignRight
            icon.name: "edit-redo-symbolic"
            onClicked: root.textArea.redo()
            visible: !root.textArea.readOnly && root.canRedo && root.textArea.canRedo

            ToolTip.visible: hovered
            ToolTip.delay: Qt.styleHints.mousePressAndHoldInterval
            ToolTip.text: qsTr("Redo")
            hoverEnabled: true
        }
    }
}
