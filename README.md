# obj_viewer
OBJ file viewer

This command visualizes OBJ file with texture.

## Requirement

- PCL (point cloud library)
- VTK (Visualization Tool Kit)

## Build

Checkout source code.

```shell
$ git clone https://github.com/n-ando/obj_viewer.git
$ cd  obj_viewer
```

Edit src/CMakeLists.txt to specify PCL include directory.

```cmake
include_directories(${PCL_INCLUDE_DIRS} /usr/local/Cellar/vtk/9.0.3/include/vtk-9.0/)
```

And, build project.

```shell
$ mkdir build ; cd build
$ make
$ src/obj_viewer ../model/akaikitsune/mesh_texture_packed.obj
```
## Usage

```
obj_vewier <obj_file_name>
```

