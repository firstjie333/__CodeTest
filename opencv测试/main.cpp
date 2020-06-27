#include <iostream>
#include "opencv2/opencv_modules.hpp"
// #include <opencv2/core/utility.hpp>
// #include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
// #include "opencv2/stitching/detail/autocalib.hpp"
// #include "opencv2/stitching/detail/blenders.hpp"
// #include "opencv2/stitching/detail/timelapsers.hpp"
// #include "opencv2/stitching/detail/camera.hpp"
// #include "opencv2/stitching/detail/exposure_compensate.hpp"
// #include "opencv2/stitching/detail/matchers.hpp"
// #include "opencv2/stitching/detail/motion_estimators.hpp"
// #include "opencv2/stitching/detail/seam_finders.hpp"
// #include "opencv2/stitching/detail/warpers.hpp"
// #include "opencv2/stitching/warpers.hpp"
// #include<opencv2/xfeatures2d.hpp>

int main(int argc, char* argv[])
{
    std::string imgPath = argv[1];
    cv::Mat img = cv::imread(imgPath);
    cv::imshow("img",img);
    cv::waitKey();
    return 0;
}