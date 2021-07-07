aux_source_directory(./src PRB_SRCs)
set(CMAKE_CXX_STANDARD 11)
add_library(prockbit ${PRB_SRCs})
