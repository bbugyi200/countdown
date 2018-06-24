project(alarm)

function(prog_opts target)
    find_package(Boost COMPONENTS program_options REQUIRED)
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(${target} ${Boost_LIBRARIES})
endfunction()