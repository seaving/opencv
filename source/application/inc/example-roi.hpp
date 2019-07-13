#ifndef __EXAMPLE_ROI_HPP__
#define __EXAMPLE_ROI_HPP__

/********************************************************************************
* @文件名: example-roi.hpp example-roi.cpp
* @作者: caixiwen
* @时间: 2019-7-11
* @说明: 图像叠加操作，
*			example_roi_add_img ：主要是学会用Rect标记一块区域，然后对该区域进行覆盖
*			example_roi_linearBlending ：主要学会使用addWeighted，该函数主要对两幅图像进行
*				加权混合，权重范围0-1，可以根据权重实现两幅图叠加更平滑，比如电视画面切换，
*				电影情节过度等，从例子中可以看到，实际是两幅图进行叠加，但是事先给两幅
*				图做了透明度的处理，在动态变化过程中，图2慢慢出现(由透明到原图)，而同时
*				图像1慢慢消失(由原图慢慢透明)
*				这里要注意，混合区域图1和混合区域图2必须是相同尺寸和通道
*
********************************************************************************/

/*
* 函数: example_roi_add_img
* 功能: 把图像2掩膜叠加到图像1中
* 参数: img1_file 	原图文件
*		img2_file	原图文件
* 返回: bool
*		- false		失败
* 说明: 
*/
bool example_roi_add_img(const char *img1_file, const char *img2_file);

/*
* 函数: example_roi_linearBlending
* 功能: 把图像2线性混合到图像1中
* 参数: img1_file 	原图文件
*		img2_file	原图文件
* 返回: bool
*		- false		失败
* 说明: 
*/
bool example_roi_linearBlending(const char *img1_file, const char *img2_file);

#endif

