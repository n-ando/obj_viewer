/**
 * @file obj_viewer.cpp
 * @author Noriaki Ando (noriaki.a dno@gmail.com)
 * @brief OBJ file viewer
 * @version 0.1
 * @date 2021-10-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <string>
#include <pcl/point_types.h>
#include <pcl/common/io.h>
#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>
#include <pcl/io/obj_io.h>
#include <pcl/io/vtk_lib_io.h>
#include <pcl/visualization/pcl_visualizer.h>
//#include <pcl/visualization/cloud_viewer.h>


const char filename[] = "../model/midorinotanuki_mini/mesh_texture_packed.obj";

void usage(const std::string command_name)
{
    std::cout << std::endl;
    std::cout << "OBJ file viewer" << std::endl;
    std::cout << "Usage:" << std::endl;
    std::cout << "    " << command_name << " <obj_file_name>" << std::endl;
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        usage(argv[0]);
        return -1;
    }

    std::string filename(argv[1]);

    pcl::TextureMesh mesh1;
    if (pcl::io::loadPolygonFileOBJ(filename, mesh1) == -1)
    {
        std::cout << "Loading file: " << filename << " failed." << std::endl;
        return -1;
    }

    pcl::TextureMesh mesh2;
    pcl::io::loadOBJFile(filename, mesh2);
    
    mesh1.tex_materials = mesh2.tex_materials;
    pcl::visualization::PCLVisualizer viewer("OBJ viewer");
    viewer.addTextureMesh (mesh1, "texture");
    while (!viewer.wasStopped())
    {
        viewer.spinOnce(0);
    }
    return 0;
//    // OBJファイルを読み込む
//    pcl::PolygonMesh::Ptr mesh(new pcl::PolygonMesh());
//    pcl::PointCloud<pcl::PointXYZ>::Ptr 
//                                obj_pcd(new pcl::PointCloud<pcl::PointXYZ>());
//    if (pcl::io::loadPolygonFileOBJ(filename, *mesh) != -1)
//    {   // PolygonMesh -> PointCloud<PointXYZ>
//        pcl::fromPCLPointCloud2(mesh->cloud, *obj_pcd);
//    }
//    pcl::visualization::PCLVisualizer viewer ("Cluster viewer");
//    viewer.addPointCloud<pcl::PointXYZ>(obj_pcd, "result");
//    viewer.addTextureMesh(*mesh, "texture");
//    while (!viewer.wasStopped())
//    {
//        viewer.spinOnce(0);
//    }
}
