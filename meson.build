project('macOpenGL', ['cpp','c'],
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++14'])

# PUT glfw3.dll IN THE BUILD DIRECTORY
# USE https://mesonbuild.com/Build-targets.html FOR DOING THIS AUTOMATICALLY

project_dir = meson.current_source_dir()

inc = [include_directories('Libraries/include')]
inc += project_dir / 'Libraries/lib'

cpp = meson.get_compiler('cpp')
c = meson.get_compiler('c')

deps = []
deps += cpp.find_library('glfw3dll', dirs : project_dir / 'Libraries/lib', static : true)
deps += cpp.find_library('glfw3', dirs : project_dir / 'Libraries/lib', static : false)
deps += cpp.find_library('glfw3', dirs : project_dir / 'Libraries/lib', static : true)
deps += cpp.find_library('glfw3_mt', dirs : project_dir / 'Libraries/lib', static : true)

source_files = ['main.cpp', 'glad.c']

deps += declare_dependency(
  dependencies : cpp.find_library('glfw3', dirs : project_dir / 'Libraries/lib', static : false),
  include_directories : include_directories(project_dir / 'Libraries/include'))



exe = executable('macOpenGL', source_files,
    include_directories : inc,
    dependencies : deps)
    #link_with : links)