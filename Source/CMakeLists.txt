set(PROJECT_SOURCES Main.cpp
    Read/FileReader.cpp
    Application/Application.cpp
)

target_sources(${PROJECT_NAME}
    PRIVATE ${PROJECT_SOURCES})

target_include_directories(${PROJECT_NAME}
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
