# Nous voulons un cmake "récent" pour utiliser les dernières fonctionnalités
cmake_minimum_required(VERSION 3.5)

# La version du C++ que l'on souhaite utiliser (dans notre cas C++17)
set(CMAKE_CXX_STANDARD 17)

# Le nom du projet
project(IMAC_project)

# On indique que l'on veut créer un exécutable "exo_1" compilé à partir du fichier exo_1.cpp
add_executable(exo_1 src/exo_1.cpp)

# On indique que l'on veut créer un exécutable "exo_2" compilé à partir du fichier exo_2.cpp
add_executable(exo_2 src/exo_2.cpp)
