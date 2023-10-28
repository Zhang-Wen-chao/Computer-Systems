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
include 8_divergence/CMakeFiles/divergence.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include 8_divergence/CMakeFiles/divergence.dir/compiler_depend.make

# Include the progress variables for this target.
include 8_divergence/CMakeFiles/divergence.dir/progress.make

# Include the compile flags for this target's objects.
include 8_divergence/CMakeFiles/divergence.dir/flags.make

8_divergence/CMakeFiles/divergence.dir/divergence.cu.o: 8_divergence/CMakeFiles/divergence.dir/flags.make
8_divergence/CMakeFiles/divergence.dir/divergence.cu.o: 8_divergence/CMakeFiles/divergence.dir/includes_CUDA.rsp
8_divergence/CMakeFiles/divergence.dir/divergence.cu.o: /workspace/home/student001/zhangwch/Computer-Systems/CUDA/CUDA_Freshman/8_divergence/divergence.cu
8_divergence/CMakeFiles/divergence.dir/divergence.cu.o: 8_divergence/CMakeFiles/divergence.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/workspace/home/student001/zhangwch/Computer-Systems/CUDA/CUDA_Freshman/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CUDA object 8_divergence/CMakeFiles/divergence.dir/divergence.cu.o"
	cd /workspace/home/student001/zhangwch/Computer-Systems/CUDA/CUDA_Freshman/build/8_divergence && /usr/local/cuda/bin/nvcc -forward-unknown-to-host-compiler $(CUDA_DEFINES) $(CUDA_INCLUDES) $(CUDA_FLAGS) -MD -MT 8_divergence/CMakeFiles/divergence.dir/divergence.cu.o -MF CMakeFiles/divergence.dir/divergence.cu.o.d -x cu -c /workspace/home/student001/zhangwch/Computer-Systems/CUDA/CUDA_Freshman/8_divergence/divergence.cu -o CMakeFiles/divergence.dir/divergence.cu.o

8_divergence/CMakeFiles/divergence.dir/divergence.cu.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CUDA source to CMakeFiles/divergence.dir/divergence.cu.i"
	$(CMAKE_COMMAND) -E cmake_unimplemented_variable CMAKE_CUDA_CREATE_PREPROCESSED_SOURCE

8_divergence/CMakeFiles/divergence.dir/divergence.cu.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CUDA source to assembly CMakeFiles/divergence.dir/divergence.cu.s"
	$(CMAKE_COMMAND) -E cmake_unimplemented_variable CMAKE_CUDA_CREATE_ASSEMBLY_SOURCE

# Object files for target divergence
divergence_OBJECTS = \
"CMakeFiles/divergence.dir/divergence.cu.o"

# External object files for target divergence
divergence_EXTERNAL_OBJECTS =

8_divergence/divergence: 8_divergence/CMakeFiles/divergence.dir/divergence.cu.o
8_divergence/divergence: 8_divergence/CMakeFiles/divergence.dir/build.make
8_divergence/divergence: 8_divergence/CMakeFiles/divergence.dir/linkLibs.rsp
8_divergence/divergence: 8_divergence/CMakeFiles/divergence.dir/objects1.rsp
8_divergence/divergence: 8_divergence/CMakeFiles/divergence.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/workspace/home/student001/zhangwch/Computer-Systems/CUDA/CUDA_Freshman/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CUDA executable divergence"
	cd /workspace/home/student001/zhangwch/Computer-Systems/CUDA/CUDA_Freshman/build/8_divergence && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/divergence.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
8_divergence/CMakeFiles/divergence.dir/build: 8_divergence/divergence
.PHONY : 8_divergence/CMakeFiles/divergence.dir/build

8_divergence/CMakeFiles/divergence.dir/clean:
	cd /workspace/home/student001/zhangwch/Computer-Systems/CUDA/CUDA_Freshman/build/8_divergence && $(CMAKE_COMMAND) -P CMakeFiles/divergence.dir/cmake_clean.cmake
.PHONY : 8_divergence/CMakeFiles/divergence.dir/clean

8_divergence/CMakeFiles/divergence.dir/depend:
	cd /workspace/home/student001/zhangwch/Computer-Systems/CUDA/CUDA_Freshman/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspace/home/student001/zhangwch/Computer-Systems/CUDA/CUDA_Freshman /workspace/home/student001/zhangwch/Computer-Systems/CUDA/CUDA_Freshman/8_divergence /workspace/home/student001/zhangwch/Computer-Systems/CUDA/CUDA_Freshman/build /workspace/home/student001/zhangwch/Computer-Systems/CUDA/CUDA_Freshman/build/8_divergence /workspace/home/student001/zhangwch/Computer-Systems/CUDA/CUDA_Freshman/build/8_divergence/CMakeFiles/divergence.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : 8_divergence/CMakeFiles/divergence.dir/depend
