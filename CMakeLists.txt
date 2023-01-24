cmake_minimum_required(VERSION 3.24)
project(untitled)

set(CMAKE_CXX_STANDARD 17)
set(SFML_DIR "${CMAKE_SOURCE_DIR}/SFML-2.5.1/lib/cmake/SFML")

add_executable(untitled main.cpp visual/start_menu.h model/game.h controller/controller.h visual/view.h
        model/hero.h model/petr.h model/projectile.h model/world_map.h model/world_object.h
        model/bullet.h model/creature.h model/enemy.h visual/main_menu.h visual/view_game.h
        visual/start_menu.cpp model/game.cpp visual/view.cpp
        model/hero.cpp model/petr.cpp model/projectile.cpp model/world_map.cpp model/world_object.cpp
        model/bullet.cpp model/creature.cpp model/enemy.cpp visual/main_menu.cpp visual/view_game.cpp controller/controller.cpp)

find_package(SFML 2.5 COMPONENTS graphics audio window system REQUIRED)
target_link_libraries(untitled sfml-graphics sfml-audio sfml-window sfml-system)