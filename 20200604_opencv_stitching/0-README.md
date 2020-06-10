# 关于图像的全景拼接

ops：扒了一堆例子，结果还是opencv 官方文档强

原理介绍：https://zhuanlan.zhihu.com/p/71777362

官方例子：https://docs.opencv.org/4.0.0/d9/dd8/samples_2cpp_2stitching_detailed_8cpp-example.html

opencv手册：https://docs.opencv.org/4.0.0/examples.html

若要用surf还是额外装：https://github.com/opencv/opencv_contrib/releases?after=4.0.0-beta

本机环境：opencv 4.0 ， 暂时先用orb试试效果



----

### 知乎——个人理解的步骤

1. 读入图像处理

2. 提点、算描述符、匹配

3. RANSAC去外点、算单应矩阵H 

4. 多对内点的话，算单应矩阵是一个非线性优化问题，即  x‘ - Hx 误差小

5. 有了单应矩阵H后，可以分解获得两帧图像之间的相对Pose，R/t

    ==稍微复习一下： E = t^R , $F = K ^{-T}E K ^{-1}$== 

    ==$x_{c2} ^T E x_{c1}  = p_{2} ^T E p_{1} = 0$,  $p_2 = H p_1$==

6. 孤立求解两幅图像之间的位置，如果直接进行多幅图像的拼接会造成误差的累积，因此使用光束平差法进行联合优化，可以同时优化多个相机参数，从而得到更准确的图像位置，竟然发现opencv 也有ba的代码
7. **水平矫正**： 由于相机拍摄时候往往不是沿着水平方向的，那么就会导致拼接结果出现波纹状，为了解决这个问题，需要进行水平矫正。 ==这块的原理还不懂waveCorrect？==

8. 图像投影：在得到相机的相对位置，如果直接进行拼接会破坏视场的一致性，使得拼接得到的全景图看起来不够连贯，因此需要通过投影变换将所有图像都投影在球面，柱面等，投影平面的选择与相机拍摄的方式有关系，一般来说**球面投影，柱面投影是最为常用的投影方式。

9.  曝光补偿 :如果在拍摄过程中，由于未固定曝光，就会导致不同时刻拍摄得到的图片的整体亮度不同，那么直接进行拼接就会出现明显的明暗上的变化，因此需要设置曝光补偿，使得不同照片的整体亮度一致. 感觉就是权值控制

10. 拼缝计算： 拼缝就是指图像之间重叠区域中最为相似的那条线，在得到相邻两幅图像的拼缝位置后，在拼缝附近的若干个像素使用融合算法，对于重叠区域中远离拼缝的位置只选择一侧的图像，通过这样的方法，可以有效的去除图像之间的错位，伪像，得到更好的拼接结果 。（哈哈哈 ，刷题动态规划的应用）

    类似文章： https://www.cxyxiaowu.com/10055.html

11. 图像融合：常用的**融合算法**有羽化融合和拉普拉斯融合算法，==羽化融合就是对拼缝附近的位置根据与接缝的距离求出权重，加权融合，而拉普拉斯融合算法相当于求出图像不同频率的分量，然后按频率进行融合，显然拉普拉斯融合算法效果更好，但计算复杂度也更高。==OpenCV代码为：



-----

### opencv 官方例子

我改成了用orb，具体默认参数没对齐，两个出来的结果又一些不一样 



## 输入

test_source

![image-20200604150211860](/Users/test/Downloads/7-TestCode/__DailyTestSummary/20200604_opencv_stitching/image-20200604150211860.png)



## 输出

BundleAdjusterBase

知乎例子：

![image-20200604150255302](/Users/test/Downloads/7-TestCode/__DailyTestSummary/20200604_opencv_stitching/image-20200604150255302.png)

官方例子：

![image-20200604150237720](/Users/test/Downloads/7-TestCode/__DailyTestSummary/20200604_opencv_stitching/image-20200604150237720.png)



----

别的：opencv 4.0 的一些资料 方便查找

https://zhuanlan.zhihu.com/p/89337975