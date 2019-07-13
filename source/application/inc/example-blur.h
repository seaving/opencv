#ifndef __EXAMPLE_BLUR_H__
#define __EXAMPLE_BLUR_H__

/********************************************************************************
* @文件名: example-blur.hpp example-blur.cpp
* @作者: caixiwen
* @时间: 2019-7-13
* @说明: 线性滤波-均值滤波
*			example_blur ：主要是学会均值滤波的原理，以及blur函数的使用方法
*			example_gaussian_blur：主要学会高斯滤波原理，以及高斯滤波API使用
*
*			滤波其实对图片的像素点以及该点周边的像素进行求和再取平均值，
*			把该平均值作为该点的新值，公式如下
*			--
*			\	
* (1/(m*m))* -  {[m*m的矩阵，元素值全部为1]与[以f(x,y)为中心周边m*m的像素矩阵]对应重叠的点相乘}
*			/
*			-- 
*			m*m
*
*			也就是说每个参与计算的像素权重都是1（[m*m的矩阵，元素值全部为1]）
*		----------------------------------------------------------------------------
*		我们叫[m*m的矩阵，元素值全部为1]为“核”也叫加权系数，m*m为“核”的尺寸SIZE，
*		SIZE范围越大，模糊效果越明显，因为一个像素点的领域范围内，距离该点越近的周
*		边像素值与该点的值是越来越相近的，所以SIZE取值很小，周边像素求和的均值也是与
*		目标像素值相近的，可以想象下照相机拍照头发和头皮，头发局部是很靠近的，
*		如果范围扩大的头皮，那头发中的目标点的值与头皮处的值相加求和到的结果与原值会出入比较大
*
*		--------------------------------------------------
*		均值滤波也有缺陷，因为加权系数为1，也就是说参与计算的像素值是本色出演参与计算，
*		这样不能很好的保护图像细节，如果把每个像素按照合适权重来进行参与计算，
*		图像细节可以更好的保护，高斯滤波就是这种服从高斯分布的“核”按照权重来分配像素计算，
*		高斯核中各个权值是由高斯公式计算出来的，比如当前尺寸为3*3的核，以中心位置做坐标轴，
*		得到坐标为:
*			(-1, 1) (0, 1) (1, 1)
*			(-1, 0) (0, 0) (1, 0)
*			(-1,-1) (0,-1) (1,-1)
*			把各个坐标值得带入到高斯公式，就得到了高斯核中对应位置的权值
*			高斯公式如下:
*				G(x,y)=(1/(2PI*a^2))*e^(-(x^2+y^2)/(2a^2))
*				a表示标准差，代表着数据离散程度，如果a较小，生成模板中心系数越大，
*			而周围的系数系数越小，这样对图像平滑效果不是很明显，相反a较大时，生成
*			模板的各个系数相差就不是很大，比较类似于均值模板，对图像平滑效果比较明显
********************************************************************************/

/*
* 函数: example_blur
* 功能: 线性滤波-均值滤波
* 参数: img_file 		原图文件
* 返回: bool
*		- false		失败
* 说明: 
*/
bool example_blur(const char *img_file);

/*
* 函数: example_gaussian_blur
* 功能: 线性滤波-高斯滤波
* 参数: img_file 		原图文件
* 返回: bool
*		- false		失败
* 说明: 
*/
bool example_gaussian_blur(const char *img_file);

#endif

