package model

import (
	"github.com/therecipe/qt/core"
	"heyong/ecommerce/module/util"
)

type KeyItem struct {
	Mail string
	Key  string
	Proxy string
	OutputMode int
}
type Key struct {
	Qset *core.QSettings
}

func InitKey(parent core.QObject_ITF) *Key {
	key := &Key{
		Qset: core.NewQSettings("com.jky.achun", "tinypng", parent),
	}
	key.init()
	return key

}

func (m *Key) init() {

	m.Qset.BeginGroup("Property")
	if !m.Qset.Contains("mail") {
		one := m.randDefault()
		m.Qset.SetValue("mail", core.NewQVariant15(one.Mail))
		m.Qset.SetValue("key", core.NewQVariant15(one.Key))
	}
	m.Qset.EndGroup()
}

func (m *Key) Get() *KeyItem {
	m.Qset.BeginGroup("Property")

	mail := m.Qset.Value("mail", core.NewQVariant15("")).ToString()
	key := m.Qset.Value("key", core.NewQVariant15("")).ToString()
	proxy := m.Qset.Value("proxy", core.NewQVariant15("")).ToString()
	output := m.Qset.Value("outputMode", core.NewQVariant15("")).ToInt(nil)
	m.Qset.EndGroup()
	return &KeyItem{Mail: mail, Key: key,Proxy:proxy,OutputMode:output}
}

func (m *Key) Set(mail, key string,proxy string,mode int) {
	m.Qset.BeginGroup("Property")
	m.Qset.SetValue("mail", core.NewQVariant15(mail))
	m.Qset.SetValue("key", core.NewQVariant15(key))
	m.Qset.SetValue("proxy", core.NewQVariant15(proxy))
	m.Qset.SetValue("outputMode", core.NewQVariant5(mode))
	m.Qset.EndGroup()
}

func (m *Key) randDefault() KeyItem {
	keys := []KeyItem{
		KeyItem{Mail: "icq81519890@163.com", Key: "jVYx0NmkvmBqbLMDlhW7vj7C6fS3l5q4"},
		KeyItem{Mail: "jacinth_chou@163.com", Key: "l8mz1mx09H76XsD4qptrd9pmHzYNx5QN"},
		KeyItem{Mail: "zhoujianxin@120.net", Key: "KJDpTGKnSB2VZTMt5xZsCmXlg1kXgTqW"},
	}
	return keys[util.RandInt(0, len(keys)-1)]
}
