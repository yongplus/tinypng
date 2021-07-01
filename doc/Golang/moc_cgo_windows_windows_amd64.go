package main

/*
#cgo CFLAGS: -fno-keep-inline-dllexport -O2 -Wall -W -Wextra -DUNICODE -D_UNICODE -DWIN32 -DMINGW_HAS_SECURE_API=1 -DQT_NEEDS_QMAIN -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_QML_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB
#cgo CXXFLAGS: -fno-keep-inline-dllexport -O2 -Wall -W -Wextra -fexceptions -mthreads -DUNICODE -D_UNICODE -DWIN32 -DMINGW_HAS_SECURE_API=1 -DQT_NEEDS_QMAIN -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_QML_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB
#cgo CXXFLAGS: -I../../heyong -I. -ID:/workspace/go/src/github.com/therecipe/env_windows_amd64_513/5.13.0/mingw73_64/include -ID:/workspace/go/src/github.com/therecipe/env_windows_amd64_513/5.13.0/mingw73_64/include/QtWidgets -ID:/workspace/go/src/github.com/therecipe/env_windows_amd64_513/5.13.0/mingw73_64/include/QtGui -ID:/workspace/go/src/github.com/therecipe/env_windows_amd64_513/5.13.0/mingw73_64/include/QtANGLE -ID:/workspace/go/src/github.com/therecipe/env_windows_amd64_513/5.13.0/mingw73_64/include/QtQml -ID:/workspace/go/src/github.com/therecipe/env_windows_amd64_513/5.13.0/mingw73_64/include/QtNetwork -ID:/workspace/go/src/github.com/therecipe/env_windows_amd64_513/5.13.0/mingw73_64/include/QtCore -Irelease -I/include -ID:/workspace/go/src/github.com/therecipe/env_windows_amd64_513/5.13.0/mingw73_64/mkspecs/win32-g++
#cgo LDFLAGS:         -mthreads -L D:/workspace/go/src/github.com/therecipe/env_windows_amd64_513/5.13.0/mingw73_64/lib
#cgo LDFLAGS:        -lQt5Widgets -lQt5Gui -lQt5Qml -lQt5Network -lQt5Core  -lmingw32 -lqtmain
#cgo LDFLAGS: -Wl,--allow-multiple-definition
#cgo CFLAGS: -Wno-unused-parameter -Wno-unused-variable -Wno-return-type
#cgo CXXFLAGS: -Wno-unused-parameter -Wno-unused-variable -Wno-return-type
*/
import "C"
