; 脚本由 Inno Setup 脚本向导 生成！
; 有关创建 Inno Setup 脚本文件的详细资料请查阅帮助文档！

#define MyAppName "Tinypng图片批量压缩"
#define MyAppVerName "图片压缩 1.0"
#define MyAppPublisher "Yong++"
#define MyAppURL "http://www.yzrshop.com/"
#define MyAppExeName "main.exe"

[Setup]
; 注: AppId的值为单独标识该应用程序。
; 不要为其他安装程序使用相同的AppId值。
; (生成新的GUID，点击 工具|在IDE中生成GUID。)
AppId={{8820D067-FAF5-4EFE-81E3-D1D0842CDD67}
AppName={#MyAppName}
AppVerName={#MyAppVerName}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
DefaultDirName={pf}\图片批量压缩
DefaultGroupName={#MyAppName}
OutputDir=C:\Users\yongp\Desktop\qt
OutputBaseFilename=tinypng图片压缩
SetupIconFile=D:\workspace\go\src\heyong\ecommerce\test\heyong\qt\icon.ico
Compression=lzma
SolidCompression=yes

[Languages]
Name: "chinesesimp"; MessagesFile: "compiler:Default.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked
Name: "quicklaunchicon"; Description: "{cm:CreateQuickLaunchIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]
Source: "D:\workspace\go\src\heyong\ecommerce\test\heyong\qt\deploy\windows\main.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\workspace\go\src\heyong\ecommerce\test\heyong\qt\deploy\windows\*"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "D:\workspace\go\src\heyong\ecommerce\test\heyong\qt\deploy\windows\Qt5Core.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\workspace\go\src\heyong\ecommerce\test\heyong\qt\deploy\windows\Qt5Gui.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\workspace\go\src\heyong\ecommerce\test\heyong\qt\deploy\windows\Qt5Network.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\workspace\go\src\heyong\ecommerce\test\heyong\qt\deploy\windows\Qt5Quick.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\workspace\go\src\heyong\ecommerce\test\heyong\qt\deploy\windows\Qt5Widgets.dll"; DestDir: "{app}"; Flags: ignoreversion
; 注意: 不要在任何共享系统文件上使用“Flags: ignoreversion”

[Icons]
Name: "{group}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{commondesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon
Name: "{userappdata}\Microsoft\Internet Explorer\Quick Launch\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: quicklaunchicon

[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#MyAppName}}"; Flags: nowait postinstall skipifsilent

[Code]
procedure CurUninstallStepChanged(CurUninstallStep: TUninstallStep);
begin
if CurUninstallStep = usUninstall then
  RegDeleteKeyIncludingSubkeys(HKEY_CURRENT_USER, 'Software\com.jky.achun')
end;




