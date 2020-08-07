cmake_minimum_required(VERSION 3.5)
project(Tests)


set(SOURCES
        Tests.cpp
        # Test_AddElements()
        Push_Front.cpp
        Push_Back.cpp
        Insert_In_TheMiddle.cpp
            # - Associative(Unordered)Container
        Insert_Into_Associative&&UnorderedAssociative_Container.cpp
        # Test_WithElement()
        FindElement&&CalculateAmount.cpp
        # Test_Merging()
        MergingContainers.cpp
        # Test_DeleteElements()
        Delete_From_Associative&&UnorderedAssociative_Container.cpp
        Delete_FromTheMiddle.cpp
        Pop_Front.cpp
        Pop_Back.cpp
        )
set(HEADERS
        Tests.h
)

add_library(Tests ${SOURCES} ${HEADERS}) # Создали статическую библиотеку
set_target_properties(
        Tests PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED ON
        CMAKE_CXX_FLAGS "-O0"
)

add_subdirectory(Timer)
target_link_libraries(Tests Timer)


target_include_directories(Tests PUBLIC .) #Добавления путей поиска заголовков



