add_library(actions
  rest.cpp 
  move.cpp
  closedoor.cpp
  opendoor.cpp
  wander.cpp
  attack.cpp
  )

target_include_directories(actions PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(actions PUBLIC engine events)
