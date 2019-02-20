if( VULKANENGINE_WITH_EXAMPLES )
  include( glsl2spv )

  glsl2spv( )
  
  include_directories(
    ${PROJECT_BINARY_DIR}/include
    ${PROJECT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
  )

  configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/routes.h.in
    ${CMAKE_CURRENT_BINARY_DIR}/routes.h)

  set( VULKANENGINEVKINFO_HEADERS )
  set( VULKANENGINEVKINFO_SOURCES prueba.cpp )
  set( VULKANENGINEVKINFO_LINK_LIBRARIES vulkanEngine )
  common_application( vulkanEngineInfo )
    
endif( VULKANENGINE_WITH_EXAMPLES )