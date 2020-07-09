// 评测题目2： 实现一个点云采样算法，按质心采样
// 输入：1000W点的一个无序点云
// 输出：一个10cm分辨率的采样点云


#include <iostream>
#include <map> 

#include <pcl/octree/octree.h>
#include <pcl/octree/octree_impl.h>
bool downSampleWithPCL(Eigen::vector<Eigen::Vector3f>& inputPoint3ds, const float resolution)
{
    pcl::octree::OctreePointCloudPointVector<pcl::PointXYZ> ocTreeVec(resolution);
    pcl::PointCloud<pcl::PointXYZ>::Ptr pCloud(new pcl::PointCloud<pcl::PointXYZ>());

    //1. create cloud
    for (auto & pt : inputPoint3ds)
    {
        pCloud->points.emplace_back(pt.x(), pt.y(), pt.z());
    }
    pCloud->width = static_cast<int>(inputPoint3ds.size());
    pCloud->height = 1;

    //2. create octree structure
    ocTreeVec.setInputCloud(pCloud);
    ocTreeVec.defineBoundingBox();
    ocTreeVec.addPointsFromInputCloud();

    //3. get downsampled 
    Eigen::vector<Eigen::Vector3f> outPoint3ds;
    for (auto it = ocTreeVec.leaf_begin(); it != ocTreeVec.leaf_end(); it++)
    {
        Eigen::Vector3f pt = Eigen::Vector3f::Zero();

        //1.get the point Indices of this voxel 
        pcl::octree::OctreeContainerPointIndices container = it.getLeafContainer();
        std::vector<int> pointCloudIdxs;
        container.getPointIndices(pointCloudIdxs);

        //2.get centroid
        for (int idx : pointCloudIdxs)
        {
            pt += inputPoint3ds[idx];
        }
        pt /= (float)pointCloudIdxs.size();

        outPoint3ds.emplace_back(pt);
    }

    inputPoint3ds = outPoint3ds;
    return true;
}



bool downSampleWithPCL(Eigen::vector<Eigen::Vector3f>& point3ds, const float resolution)
{
    // 1. get data range
    float minX = point3ds.front()[0]; 
    float minY = point3ds.front()[1]; 
    float minZ = point3ds.front()[2]; 

    float maxX = point3ds.front()[0]; 
    float maxY = point3ds.front()[1]; 
    float maxZ = point3ds.front()[2]; 

    for(auto &pts : point3ds)
    {
        minX = std::min(minX, pts[0] );
        minY = std::min(minY, pts[1] );
        minZ = std::min(minY, pts[2] );

        maxX = std::max(maxX, pts[0] );
        maxY = std::max(maxY, pts[1] );
        maxZ = std::max(maxZ, pts[2] );
    }

    // 2. get num 
    int numX = (maxX-minX)/resolution + 1;
    int numY = (maxY-minY)/resolution + 1;
    int numZ = (maxZ-minZ)/resolution + 1;

    // 3. resign data 
    std::map<int, std::map<int, std::map<int, std::pair<int,Eigen::Vector3f> >  > > mapX2Y2X2Data; 
    for(auto &pts : point3ds)
    {
        int idx = (pts[0] - minX)/resolution;
        int idy = (pts[1] - minX)/resolution;
        int idz = (pts[2] - minX)/resolution;

        // save sum of data position  & count 
        if(mapX2Y2X2Data.count(idx) && mapX2Y2X2Data[idx].count(idy)  &&  mapX2Y2X2Data[idx][idy].count(idz)) 
        {
            int count = mapX2Y2X2Data[idx][idy][idz].first + 1;
            Eigen::Vector3f sum = mapX2Y2X2Data[idx][idy][idz].second + pts;

            std::pair<int,Eigen::Vector3f>  newPair = std::make_pair(count, sum);
            mapX2Y2X2Data[idx][idy][idz] = newPair;
        }
        else
        {
            std::pair<int,Eigen::Vector3f>  newPair = std::make_pair(１, pts);
            mapX2Y2X2Data[idx][idy][idz] = newPair;
        }
    }

    // 4. compute center 
    Eigen::vector<Eigen::Vector3f> outPoints;
    std::map<int, std::map<int, std::map<int, Eigen::Vector3f >  > > mapVoxel; // result 
    for(auto &itX: mapX2Y2X2Data)
    {
        for(auto &itY : itX.second)
        {
            for(auto &itZ : itX.second)
            {
                auto pairInfo = itZ.second;
                Eigen::Vector3d center = pairInfo.second/ pairInfo.first;

                outPoints.push_back(center); 
            }
        }
    }

    outPoints.swap(point3ds);


}
