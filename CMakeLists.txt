project(Khipu)
cmake_minimum_required(VERSION 2.8)

find_package(Qt5 REQUIRED COMPONENTS Core Quick Qml Widgets Gui)
find_package(Analitza5 REQUIRED)

SET(CMAKE_INCLUDE_CURRENT_DIR ON)
SET(CMAKE_AUTORCC ON)
SET(CMAKE_AUTOMOC ON)

add_executable(khipu3
	khipudata.cpp  
	khipuspace.cpp  
	khipuspacemodel.cpp  
	main.cpp
	qml.qrc
)

target_link_libraries(khipu3 
	Qt5::Core 
	Qt5::Quick 
	Qt5::Qml 
	Qt5::Widgets 
	Qt5::Gui
	KF5::Analitza 
	KF5::AnalitzaPlot
)

