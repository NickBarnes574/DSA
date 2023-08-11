set(LIBRARY_SOURCES
    src/utilities.c
    src/comparisons.c
    )

add_library(Common ${LIBRARY_SOURCES})

target_include_directories(Common PUBLIC include/)