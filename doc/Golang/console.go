package main

import (
	"github.com/therecipe/qt/gui"
	"github.com/therecipe/qt/widgets"
)

func newConsole() *widgets.QTextBrowser {
	textbrowser := widgets.NewQTextBrowser(nil)
	textbrowser.SetMinimumHeight(100)
	textbrowser.SetTextBackgroundColor(gui.NewQColor3(0, 0, 0, 0))
	textbrowser.SetStyleSheet(`QTextBrowser { 
	background-color: #000000;
color:#FFFFFF;
	font-size:15px;
font-family:"verdana,Arial,Helvetica,sans-serif",
}`)
	textbrowser.Append(`The software that is available for png/jpg/jpeg is developed based on the apis offering by tinypng.png.
Usage:
  To compress your images, Click the button to choose directory or drag directly the folder to the widget of table area.
`)
	return textbrowser
}
