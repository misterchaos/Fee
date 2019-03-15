Set WshShell = CreateObject("Wscript.Shell")
WshShell.CurrentDirectory="DOSBox-0.74"
WshShell.Run "dosbox.exe -conf hyc.conf -noconsole"
