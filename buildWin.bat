mkdir out
cd .\out\
cmake ..
cd ..
cmake --build .\out\
::cd out\ByteEater\Debug

:: for VisualStudio use this
cd out\build\x64-Debug\ByteEater\

:: ByteEater.exe <FileName.extension> <> ...
ByteEater.exe
:: .\ByteEater.exe