cmake_minimum_required(VERSION 3.6.0)
project(Subproject)
include_directories(
	${PROJECT_SOURCE_DIR}/include
	${PROJECT_SOURCE_DIR}/src
)
file(GLOB SRCS
	"${PROJECT_SOURCE_DIR}/include/*"
	"${PROJECT_SOURCE_DIR}/src/*"
)
add_library(Subproject ${SRCS})
target_include_directories( Subproject PUBLIC ${PROJECT_SOURCE_DIR}/include)