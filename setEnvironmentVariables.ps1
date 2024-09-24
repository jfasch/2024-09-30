Write-Output "Set environment variables [HTTP_PROXY(S)][NO_PROXY][VCPKG_ROOT]"

$test = Test-Path Env:HTTP_PROXY
if($test -eq $false)
{
	[Environment]::SetEnvironmentVariable('HTTP_PROXY', 'http://127.0.0.1:9000', 'User')
}
$Env:HTTP_PROXY = "http://127.0.0.1:9000"

$test = Test-Path Env:HTTPS_PROXY
if($test -eq $false)
{
	[Environment]::SetEnvironmentVariable('HTTPS_PROXY', 'http://127.0.0.1:9000', 'User')
}
$Env:HTTPS_PROXY = "http://127.0.0.1:9000"

$test = Test-Path Env:NO_PROXY
if($test -eq $false)
{
	[Environment]::SetEnvironmentVariable('NO_PROXY', 'jiradc.fronius.com,*.fronius.com,127.0.0.1', 'User')
}
$Env:NO_PROXY = "jiradc.fronius.com,*.fronius.com,127.0.0.1"

$test = Test-Path Env:VCPKG_ROOT
if($test -eq $false)
{
	[Environment]::SetEnvironmentVariable('VCPKG_ROOT', 'C:\Workspaces\vcpkg', 'User')
}
$Env:VCPKG_ROOT = "C:\Workspaces\vcpkg"

$test = Test-Path Env:SONAR_SCANNER_OPTS
if($test -eq $false)
{
	[Environment]::SetEnvironmentVariable('SONAR_SCANNER_OPTS', '-Djavax.net.ssl.trustStoreType=WINDOWS-ROOT', 'User')
}
$Env:SONAR_SCANNER_OPTS = "-Djavax.net.ssl.trustStoreType=WINDOWS-ROOT"
