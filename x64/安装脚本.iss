; 脚本由 Inno Setup 脚本向导 生成！
; 有关创建 Inno Setup 脚本文件的详细资料请查阅帮助文档！

#define MyAppName "图片压缩"
#define MyAppVerName "1.5"
#define MyAppPublisher "Yong++"
#define MyAppExeName "tinypng.exe"

[Setup]
; 注: AppId的值为单独标识该应用程序。
; 不要为其他安装程序使用相同的AppId值。
; (生成新的GUID，点击 工具|在IDE中生成GUID。)
AppId={{3EB7DACF-EA48-429F-B4E6-76826000E6E4}
AppName={#MyAppName}
AppVerName={#MyAppVerName}
AppPublisher={#MyAppPublisher}
DefaultDirName={pf}\tinypng
DefaultGroupName={#MyAppName}
OutputDir=D:\workspace\qt\tinypng\x64\
OutputBaseFilename=图片压缩安装程序
SetupIconFile=D:\workspace\qt\tinypng\tinypng\icon.ico
Compression=lzma
SolidCompression=yes

[Languages]
Name: "chinesesimp"; MessagesFile: "compiler:Default.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]
Source: "D:\workspace\qt\tinypng\x64\Release\tinypng.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\workspace\qt\tinypng\x64\Release\*"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs
; 注意: 不要在任何共享系统文件上使用“Flags: ignoreversion”

[Icons]
Name: "{group}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{commondesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon

[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#MyAppName}}"; Flags: nowait postinstall skipifsilent

[Code]
procedure CurUninstallStepChanged(CurUninstallStep: TUninstallStep);
begin
if CurUninstallStep = usUninstall then
  RegDeleteKeyIncludingSubkeys(HKEY_CURRENT_USER, 'Software\lane')
end;



