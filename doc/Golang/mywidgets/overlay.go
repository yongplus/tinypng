package mywidgets

import (
	"github.com/therecipe/qt/core"
	"github.com/therecipe/qt/widgets"
)

func NewDragOverlay() *widgets.QWidget {
	overlay := widgets.NewQWidget(nil, 0)
	overlay.SetObjectName("overlay")
	overlay.SetStyleSheet(`#overlay{background-color:rgba(0,0,0,0.3);}`)

	label := widgets.NewQLabel(nil, 0)
	label.SetStyleSheet("color:#FFFFFF;background-color:rgba(0,0,0,0);")
	//label.SetAttribute(core.Qt__WA_TranslucentBackground,true)
	label.SetAttribute(core.Qt__WA_TransparentForMouseEvents, true)
	label.SetText("松开读取目录资源")

	layout := widgets.NewQVBoxLayout()
	layout.AddWidget(label, 1, core.Qt__AlignHCenter)
	//overlay.SetAttribute(core.Qt__WA_TranslucentBackground,true)
	overlay.SetAttribute(core.Qt__WA_TransparentForMouseEvents, true)
	overlay.SetLayout(layout)

	return overlay
}
