add_library(weapons
  none.cpp
  staff_red.cpp
  knife.cpp
  sword.cpp
  sword_big.cpp
  )

target_include_directories(weapons PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(weapons PUBLIC engine events)
