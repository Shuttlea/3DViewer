# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.28.3/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.28.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/shuttlea/TryGitHub/3DViewer_2_0/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/shuttlea/TryGitHub/3DViewer_2_0/build-src-Desktop_x86_darwin_generic_mach_o_64bit-Debug

# Utility rule file for QOpenGLWidget_autogen_timestamp_deps.

# Include any custom commands dependencies for this target.
include CMakeFiles/QOpenGLWidget_autogen_timestamp_deps.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/QOpenGLWidget_autogen_timestamp_deps.dir/progress.make

CMakeFiles/QOpenGLWidget_autogen_timestamp_deps: /usr/local/lib/QtOpenGL.framework/Versions/A/QtOpenGL
CMakeFiles/QOpenGLWidget_autogen_timestamp_deps: /usr/local/lib/QtWidgets.framework/Versions/A/QtWidgets
CMakeFiles/QOpenGLWidget_autogen_timestamp_deps: /usr/local/lib/QtOpenGLWidgets.framework/Versions/A/QtOpenGLWidgets
CMakeFiles/QOpenGLWidget_autogen_timestamp_deps: /usr/local/share/qt/libexec/uic
CMakeFiles/QOpenGLWidget_autogen_timestamp_deps: /usr/local/share/qt/libexec/moc
CMakeFiles/QOpenGLWidget_autogen_timestamp_deps: /usr/local/lib/QtCore.framework/Versions/A/QtCore

QOpenGLWidget_autogen_timestamp_deps: CMakeFiles/QOpenGLWidget_autogen_timestamp_deps
QOpenGLWidget_autogen_timestamp_deps: CMakeFiles/QOpenGLWidget_autogen_timestamp_deps.dir/build.make
.PHONY : QOpenGLWidget_autogen_timestamp_deps

# Rule to build all files generated by this target.
CMakeFiles/QOpenGLWidget_autogen_timestamp_deps.dir/build: QOpenGLWidget_autogen_timestamp_deps
.PHONY : CMakeFiles/QOpenGLWidget_autogen_timestamp_deps.dir/build

CMakeFiles/QOpenGLWidget_autogen_timestamp_deps.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/QOpenGLWidget_autogen_timestamp_deps.dir/cmake_clean.cmake
.PHONY : CMakeFiles/QOpenGLWidget_autogen_timestamp_deps.dir/clean

CMakeFiles/QOpenGLWidget_autogen_timestamp_deps.dir/depend:
	cd /Users/shuttlea/TryGitHub/3DViewer_2_0/build-src-Desktop_x86_darwin_generic_mach_o_64bit-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/shuttlea/TryGitHub/3DViewer_2_0/src /Users/shuttlea/TryGitHub/3DViewer_2_0/src /Users/shuttlea/TryGitHub/3DViewer_2_0/build-src-Desktop_x86_darwin_generic_mach_o_64bit-Debug /Users/shuttlea/TryGitHub/3DViewer_2_0/build-src-Desktop_x86_darwin_generic_mach_o_64bit-Debug /Users/shuttlea/TryGitHub/3DViewer_2_0/build-src-Desktop_x86_darwin_generic_mach_o_64bit-Debug/CMakeFiles/QOpenGLWidget_autogen_timestamp_deps.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/QOpenGLWidget_autogen_timestamp_deps.dir/depend

