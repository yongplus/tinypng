package setting

import (
	"fmt"
	"github.com/therecipe/qt/core"
	"github.com/therecipe/qt/gui"
	"github.com/therecipe/qt/widgets"
	"heyong/ecommerce/test/heyong/qt/model"
)

type SettingWindow struct {
	MW      *widgets.QWidget
	mailIpt *widgets.QLineEdit
	keyIpt  *widgets.QLineEdit
	proxyIpt  *widgets.QLineEdit
	outputCheckBox *widgets.QButtonGroup
	KeyTiny *model.Key
	config *model.KeyItem
}

func (m *SettingWindow) init() {
	m.MW.SetFixedSize(core.NewQSize2(400, 290))
	m.MW.SetWindowModality(core.Qt__ApplicationModal)
	m.MW.SetWindowFlag(core.Qt__WindowContextHelpButtonHint, false)
	m.MW.SetWindowTitle("API账号设置")
	m.config = m.KeyTiny.Get()

	m.MW.SetContentsMargins(20, 20, 20, 20)
	m.buildUi()
	m.MW.Show()
}

func (m *SettingWindow) buildUi() {

	layout := widgets.NewQVBoxLayout()
	layout.AddStretch(1)
	layout.AddLayout(m.buildInputLine(0), 0)
	layout.AddSpacing(30)
	layout.AddLayout(m.buildInputLine(1), 0)
	layout.AddSpacing(30)
	layout.AddLayout(m.buildInputLine(2), 0)
	layout.AddSpacing(30)
	layout.AddLayout(m.buildCheckBox(), 0)
	layout.AddSpacing(30)
	layout.AddWidget(m.buildBtn(), 0, core.Qt__AlignCenter)
	layout.AddSpacing(30)
	layout.AddWidget(m.buildLinkLabel(), 0, core.Qt__AlignRight)
	layout.AddStretch(1)
	m.MW.SetLayout(layout)
	layout.AddSpacing(10)

}

func (m *SettingWindow) buildTitleLabel() *widgets.QLabel {
	label := widgets.NewQLabel(nil, 0)
	label.SetStyleSheet(`font-size:16px;`)
	label.SetText("API Key配置")
	return label
}

func (m *SettingWindow) buildInputLabel(text string) *widgets.QLabel {
	label := widgets.NewQLabel(nil, 0)
	label.SetMinimumWidth(80)
	font := gui.NewQFont()
	font.SetPointSize(14)
	label.SetText(text)
	return label
}

func (m *SettingWindow) buildInputLine(flag int) *widgets.QHBoxLayout {
	var label string
	var tmp *widgets.QLineEdit

	if flag == 0 {
		label = "Mail:"
		m.mailIpt = m.buildInputPart(m.config.Mail)
		tmp = m.mailIpt
	} else if flag==1 {
		label = "Key:"
		m.keyIpt = m.buildInputPart(m.config.Key)
		tmp = m.keyIpt
	}else{
		label = "Proxy:"
		m.proxyIpt = m.buildInputPart(m.config.Proxy)
		tmp = m.proxyIpt
	}

	layout := widgets.NewQHBoxLayout()
	layout.AddWidget(m.buildInputLabel(label), 0, 0)

	layout.AddWidget(tmp, 1, 0)
	layout.SetStretch(1, 2)
	return layout
}

func (m *SettingWindow) buildCheckBox() *widgets.QHBoxLayout {

	layout := widgets.NewQHBoxLayout()

	group := widgets.NewQButtonGroup(nil)

	layout.AddWidget(m.buildInputLabel("输出:"),0,core.Qt__AlignLeft)
	checkbox := widgets.NewQCheckBox(nil)
	checkbox.SetText("新目录")
	layout.AddWidget(checkbox, 1, 0)
	layout.AddSpacing(40)

	checkbox2 := widgets.NewQCheckBox(nil)
	checkbox2.SetText("覆盖")

	checkbox2.ConnectSetChecked(func(checked bool){
		if checked {
			checkbox.SetCheckState(2)
		}
	})

	if m.config.OutputMode==0{
		checkbox.SetChecked(true)
	}else{
		checkbox2.SetChecked(true)
	}


	group.AddButton(checkbox,0)
	group.AddButton(checkbox2,1)
	group.SetExclusive(true)
	m.outputCheckBox = group

	layout.AddWidget(checkbox2, 1, 0)
	return layout
}

func (m *SettingWindow) buildBtn() *widgets.QPushButton {
	button := widgets.NewQPushButton2("保 存", nil)
	button.SetFixedSize(core.NewQSize2(110, 45))

	button.ConnectClicked(func(bool) {
		mail := m.mailIpt.Text()
		key := m.keyIpt.Text()
		proxy := m.proxyIpt.Text()
		if len(mail) == 0 || len(key) == 0 {
			widgets.QMessageBox_Warning(m.MW, "提 示", "Mail和Key值不能为空", 0, 0)
			return
		}

		var mode = m.outputCheckBox.CheckedId()
		fmt.Println(mode)
		m.KeyTiny.Set(mail, key, proxy, mode)
		widgets.QMessageBox_Information(m.MW, "提 示", "保存成功", widgets.QMessageBox__Ok, 0)
		m.MW.Close()
		return
	})

	//button.SetMinimumHeight(65)
	return button
}

func (m *SettingWindow) buildInputPart(value string) *widgets.QLineEdit {
	input := widgets.NewQLineEdit(nil)
	input.SetText(value)
	input.SetMinimumHeight(35)
	input.SetSizePolicy2(widgets.QSizePolicy__Expanding, widgets.QSizePolicy__Fixed)
	return input
}

func (m *SettingWindow) buildLinkLabel() *widgets.QLabel {
	link := widgets.NewQLabel2("<a href=\"https://tinypng.com/developers\">Go Applying Key</a>", nil, 0)
	link.SetOpenExternalLinks(true)
	return link
}

func OpenSettingWindow(keytiny *model.Key, parent widgets.QWidget_ITF) *SettingWindow {
	window := &SettingWindow{
		MW:      widgets.NewQWidget(parent, core.Qt__Dialog),
		KeyTiny: keytiny,
	}
	window.init()
	return window
}
