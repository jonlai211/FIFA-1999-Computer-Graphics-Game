cmake_minimum_required(VERSION 3.23)
project(CPT205)

set(CMAKE_CXX_STANDARD 14)

# GLUT
find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIR})

# OpenGL
find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIR})

# Assessment2
file(GLOB A2src "Assessment2/src/*.cpp" "Assessment2/include/*.h")
add_executable(A2src ${A2src}
        Assessment2/src/RenderScene.cpp Assessment2/src/Camera.cpp Assessment2/include/Camera.h Assessment2/src/Lighting.cpp Assessment2/include/Lighting.h Assessment2/include/Helper.h Assessment2/src/Items.cpp Assessment2/include/Items.h Assessment2/src/Texture.cpp Assessment2/include/Texture.h Assessment2/include/stb_image.h Assessment2/include/stb_image.h Assessment2/src/Football.cpp Assessment2/include/Football.h Assessment2/include/Vector3.h Assessment2/src/Transform.cpp Assessment2/include/Transform.h)
target_link_libraries(A2src ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} glut)
foreach (_var $(A2src))
    include_directories(${PROJECT_SOURCE_DIR})
endforeach ()