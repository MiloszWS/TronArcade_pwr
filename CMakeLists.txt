
cmake_minimum_required(VERSION 3.15)
project(TronArcade)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 14)
add_compile_options(-Wall -Wextra)

if (UNIX)
    # konfiguracja dla systemów Unix/Linux/MacOS
    # proszę nie modyfkować pierwszego wpisu, można dopisać kolejne katalogi
    # wpis dla antycznego Ubuntu (dla SFML 2.4)
    set ( CMAKE_MODULES_PATH "/usr/share/SFML/cmake/Modules" ${CMAKE_MODULES_PATH})

    # katalog, w którym jest plik SFMLConfig.cmake
    # nowe Ubuntu (SFML 2.5)
    # NIE ZMIENIAĆ, NIE KASOWAĆ !!!
    set ( CMAKE_PREFIX_PATH "/usr/lib/x86_64-linux-gnu/cmake/SFML" ${CMAKE_PREFIX_PATH})

    # dla MacOS lub innej dystrybucji Linuksa - można dopisać DODATKOWY CMAKE_PREFIX_PATH
    # set ( CMAKE_PREFIX_PATH "/usr/lib/x86_64-linux-gnu/cmake/SFML" ${CMAKE_PREFIX_PATH})
endif(UNIX)

if (WIN32)
    # próbujemy linkować statycznie (nie trzeba kopiować plików dll do katalogu projektu)
    set( SFML_STATIC_LIBRARIES TRUE )

    # Jeśli zainstalowaliście w innym miejscu to trzeba tu zmienić katalog na właściwy
    set ( SFML_DIR "C:/SFML-2.5.1/lib/cmake/SFML/")

#    set(SDL2_PATH "D:/CLion/Projects/SDL/")
#    # Dodanie ścieżek do plików nagłówkowych i bibliotek SDL
#    include_directories(${SDL2_PATH}/include)
#    link_directories(${SDL2_PATH}/lib)
endif(WIN32)


find_package(SFML 2 COMPONENTS graphics audio REQUIRED)

add_executable(TronArcade main.cpp boardTextView.h boardTextView.cpp motorsTextView.h motorsTextView.cpp Timer.h Timer.cpp SFMLView.h SFMLView.cpp SFMLController.h SFMLController.cpp Integrator.h Integrator.cpp menuScreen.h menuScreen.cpp motor2.h motor2.cpp modeChoose.h modeChoose.cpp EASYbot.h)
target_link_libraries(TronArcade sfml-graphics sfml-audio  winMM.Lib)

