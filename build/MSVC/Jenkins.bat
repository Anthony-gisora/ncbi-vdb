del /F /S /Q devel 1>nul
rd /s /q devel
if exist devel rd /s /q devel

mkdir devel
cd devel
git clone -b engineering https://github.com/ncbi/ngs.git
git clone -b engineering https://github.com/ncbi/ncbi-vdb.git

call "C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\Common7\Tools\VsDevCmd.bat"

set path=C:\apache-ant\bin;C:\Program Files\Java\jdk-13.0.2\bin;C:\Users\Administrator\AppData\Local\Programs\Python\Python38;%PATH%

call ant -f ngs\ngs-sdk\win build
call ant -f ngs\ngs-java build
call ant -f ngs\ngs-python build
call ant -f ncbi-vdb\build\MSVC runtests

