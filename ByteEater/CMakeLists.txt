# CMakeList.txt: progetto CMake per ByteEater. Includere l'origine e definire
# qui la logica specifica del progetto.
#

# Aggiungere l'origine all'eseguibile di questo progetto.
add_executable (ByteEater "ByteEater.cpp" "ByteEater.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ByteEater PROPERTY CXX_STANDARD 20)
endif()

# TODO: Aggiungere i test e, se necessario, installare le destinazioni.
