cmake_minimum_required(VERSION 3.20)
project(net_trace LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(cmake/sanitizer.cmake)

option(ENABLE_WERROR "Treat warnings as errors" ON)

add_library(nettrace_objs OBJECT
  src/cli/args.h
  src/core/types.h
  src/core/layout_model.h
  src/core/rule_model.h
  src/core/result_model.h
  src/io/layout_reader.h
  src/io/layout_reader.cpp
  src/io/rule_reader.h
  src/io/rule_reader.cpp
  src/io/result_writer.h
  src/io/result_writer.cpp
  src/geom/manhattan_poly.h
  src/geom/manhattan_poly.cpp
  src/geom/intersect.h
  src/geom/intersect.cpp
  src/geom/point_in_poly.h
  src/geom/point_in_poly.cpp
  src/geom/grid_index.h
  src/geom/grid_index.cpp
  src/geom/cutter.h
  src/geom/cutter.cpp
  src/trace/via_graph.h
  src/trace/via_graph.cpp
  src/trace/ufds.h
  src/trace/ufds.cpp
  src/trace/flood_fill.h
  src/trace/flood_fill.cpp
  src/trace/gate_rule.h
  src/trace/gate_rule.cpp
  src/trace/pipeline.h
  src/trace/pipeline.cpp
  src/parallel/thread_pool.h
  src/parallel/thread_pool.cpp
  src/parallel/par_algos.h
  src/parallel/par_algos.cpp
  src/utils/span.h
  src/utils/timer.h
  src/utils/logging.h
  src/utils/small_vec.h
)

add_executable(trace src/main.cpp $<TARGET_OBJECTS:nettrace_objs>)
target_compile_options(trace PRIVATE -O3 -fno-omit-frame-pointer -Wall -Wextra -Wpedantic)
if(ENABLE_WERROR)
  target_compile_options(trace PRIVATE -Werror)
endif()

target_enable_sanitizers(trace)
