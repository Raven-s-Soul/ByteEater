mkdir out
cd .\out\
cmake ..
cd ..
cmake --build .\out\

:: for VisualStudio use this
::cd out\build\x64-Debug\ByteEater\

:: for other
cd out\ByteEater\Debug

:: ByteEater.exe <FileName.extension> <> ...
ByteEater.exe
:: .\ByteEater.exe