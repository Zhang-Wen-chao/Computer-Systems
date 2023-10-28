# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/lib/python3.10/dist-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /usr/local/lib/python3.10/dist-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /workspace/home/student001/zhangwch/Computer-Systems/CUDA/CUDA_Freshman

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspace/home/student001/zhangwch/Computer-Systems/CUDA/CUDA_Freshman/build

# Include any dependencies generated for this target.
include 29_reduce_shfl/CMakeFiles/reduce_shfl.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include 29_reduce_shfl/CMakeFiles/reduce_shfl.dir/compiler_depend.make

# Include the progress variables for this target.
include 29_reduce_shfl/CMakeFiles/reduce_shfl.dir/progress.make

# Include the compile flags for this target's objects.
include 29_reduce_shfl/CMakeFiles/reduce_shfl.dir/flags.make

29_reduce_shfl/CMakeFiles/reduce_shfl.dir/reduce_shfl.cu.o: 29_reduce_shfl/CMakeFiles/reduce_shfl.dir/flags.make
29_reduce_shfl/CMakeFiles/reduce_shfl.dir/reduce_shfl.cu.o: 29_reduce_shfl/CMakeFiles/reduce_shfl.dir/includes_CUDA.rsp
29_reduce_shfl/CMakeFiles/reduce_shfl.dir/reduce_shfl.cu.o: /workspace/home/student001/zhangwch/Computer-Systems/CUDA/CUDA_Freshman/29_reduce_shfl/reduce_shfl.cu
29_reduce_shfl/CMakeFiles/reduce_shfl.dir/reduce_shfl.cu.o: 29_reduce_shfl/CMakeFiles/reduce_shfl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/workspace/home/student001/zhangwch/Computer-Systems/CUDA/CUDA_Freshman/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CUDA object 29_reduce_shfl/CMakeFiles/reduce_shfl.dir/reduce_shfl.cu.o"
	cd /workspace/home/student001/zhangwch/Computer-Systems/CUDA/CUDA_Freshman/build/29_reduce_shfl && /usr/local/cuda/bin/nvcc -forward-unknown-to-host-compiler $(CUDA_DEFINES) $(CUDA_INCLUDES) $(CUDA_FLAGS) -MD -MT 29_reduce_shfl/CMakeFiles/reduce_shfl.dir/reduce_shfl.cu.o -MF CMakeFiles/reduce_shfl.dir/reduce_shfl.cu.o.d -x cu -c /workspace/home/student001/zhangwch/Computer-Systems/CUDA/CUDA_Freshman/29_reduce_shfl/reduce_shfl.cu -o CMakeFiles/reduce_shfl.dir/reduce_shfl.cu.o

29_reduce_shfl/CMakeFiles/reduce_shfl.dir/reduce_shfl.cu.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CUDA source to CMakeFiles/reduce_shfl.dir/reduce_shfl.cu.i"
	$(CMAKE_COMMAND) -E cmake_unimplemented_variable CMAKE_CUDA_CREATE_PREPROCESSED_SOURCE

29_reduce_shfl/CMakeFiles/reduce_shfl.dir/reduce_shfl.cu.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CUDA source to assembly CMakeFiles/reduce_shfl.dir/reduce_shfl.cu.s"
	$(CMAKE_COMMAND) -E cmake_unimplemented_variable CMAKE_CUDA_CREATE_ASSEMBLY_SOURCE

# Object files for target reduce_shfl
reduce_shfl_OBJECTS = \
"CMakeFiles/reduce_shfl.dir/reduce_shfl.cu.o"

# External object files for target reduce_shfl
reduce_shfl_EXTERNAL_OBJECTS =

29_reduce_shfl/reduce_shfl: 29_reduce_shfl/CMakeFiles/reduce_shfl.dir/reduce_shfl.cu.o
29_reduce_shfl/reduce_shfl: 29_reduce_shfl/CMakeFiles/reduce_shfl.dir/build.make
29_reduce_shfl/reduce_shfl: 29_reduce_shfl/CMakeFiles/reduce_shfl.dir/linkLibs.rsp
29_reduce_shfl/reduce_shfl: 29_reduce_shfl/CMakeFiles/reduce_shfl.dir/objects1.rsp
29_reduce_shfl/reduce_shfl: 29_reduce_shfl/CMakeFiles/reduce_shfl.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/workspace/home/student001/zhangwch/Computer-Systems/CUDA/CUDA_Freshman/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CUDA executable reduce_shfl"
	cd /workspace/home/student001/zhangwch/Computer-Systems/CUDA/CUDA_Freshman/build/29_reduce_shfl && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/reduce_shfl.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
29_reduce_shfl/CMakeFiles/reduce_shfl.dir/build: 29_reduce_shfl/reduce_shfl
.PHONY : 29_reduce_shfl/CMakeFiles/reduce_shfl.dir/build

29_reduce_shfl/CMakeFiles/reduce_shfl.dir/clean:
	cd /workspace/home/student001/zhangwch/Computer-Systems/CUDA/CUDA_Freshman/build/29_reduce_shfl && $(CMAKE_COMMAND) -P CMakeFiles/reduce_shfl.dir/cmake_clean.cmake
.PHONY : 29_reduce_shfl/CMakeFiles/reduce_shfl.dir/clean

29_reduce_shfl/CMakeFiles/reduce_shfl.dir/depend:
	cd /workspace/home/student001/zhangwch/Computer-Systems/CUDA/CUDA_Freshman/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspace/home/student001/zhangwch/Computer-Systems/CUDA/CUDA_Freshman /workspace/home/student001/zhangwch/Computer-Systems/CUDA/CUDA_Freshman/29_reduce_shfl /workspace/home/student001/zhangwch/Computer-Systems/CUDA/CUDA_Freshman/build /workspace/home/student001/zhangwch/Computer-Systems/CUDA/CUDA_Freshman/build/29_reduce_shfl /workspace/home/student001/zhangwch/Computer-Systems/CUDA/CUDA_Freshman/build/29_reduce_shfl/CMakeFiles/reduce_shfl.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : 29_reduce_shfl/CMakeFiles/reduce_shfl.dir/depend
