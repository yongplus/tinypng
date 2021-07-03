@echo "starting sign"
"C:/Program Files (x86)/Windows Kits/10/bin/10.0.17134.0/x64/signtool.exe" sign /f D:/workspace/qt/tinypng/yong.pfx /p 123456 D:/workspace/qt/tinypng/x64/Release/tinypng.exe
@echo "add timestamp"
"C:/Program Files (x86)/Windows Kits/10/bin/10.0.17134.0/x64/signtool.exe" timestamp /t http://timestamp.digicert.com/scripts/timestamp.dll D:/workspace/qt/tinypng/x64/Release/tinypng.exe
@echo "complete"

