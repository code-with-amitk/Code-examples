#pragma once
#include "common.h"

#define CTEST_ASSERT_THROW( condition )                               \
{                                                                   \
  if( !( condition ) )                                              \
  {                                                                 \
    throw std::runtime_error(   std::string( __FILE__ )             \
                              + std::string( ":" )                  \
                              + std::to_string( __LINE__ )          \
                              + std::string( " in " )               \
                              + std::string( __PRETTY_FUNCTION__ )  \
    );                                                              \
  }                                                                 \
}

#define CTEST_ASSERT_EQUAL( x, y )                                    \
{                                                                   \
  if( ( x ) != ( y ) )                                              \
  {                                                                 \
    throw std::runtime_error(   std::string( __FILE__ )             \
                              + std::string( ":" )                  \
                              + std::to_string( __LINE__ )          \
                              + std::string( " in " )               \
                              + std::string( __PRETTY_FUNCTION__ )  \
                              + std::string( ": " )                 \
                              + std::to_string( ( x ) )             \
                              + std::string( " != " )               \
                              + std::to_string( ( y ) )             \
    );                                                              \
  }                                                                 \
}
