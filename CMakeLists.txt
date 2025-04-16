cmake_minimum_required(VERSION 3.16)
include($ENV{IDF_PATH}/tools/cmake/project.cmake)

# Organized component directories
set(EXTRA_COMPONENT_DIRS
    components
    components/TFT_eSPI
)

project(template_esp_idf)