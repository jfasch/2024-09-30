# Set environment variables
.\setEnvironmentVariables.ps1

$mutex = New-Object System.Threading.Mutex($false, "Global\VCPKG_ACTIVATE_MUTEX")

$vcpkg_activated = 0

while ($vcpkg_activated -eq 0) {
    if ($mutex.WaitOne(10000)) {
        Invoke-Expression (Invoke-WebRequest -useb https://aka.ms/vcpkg-init.ps1)
        vcpkg x-update-registry fronius
        vcpkg activate        
        vcpkg-shell activate
        $mutex.ReleaseMutex()
        $vcpkg_activated = 1
    }
}

if ($args[0] -ne "novscode") {
    code .
}

