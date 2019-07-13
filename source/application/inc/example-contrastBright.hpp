#ifndef __EXAMPLE_CONTRAST_BRIGHT_HPP__
#define __EXAMPLE_CONTRAST_BRIGHT_HPP__

/********************************************************************************
* @文件名: example-sharpen.hpp example-sharpen.cpp
* @作者: caixiwen
* @时间: 2019-7-11
* @说明: example_contrast_and_bright：调节亮度和对比度，本质原理是对每个像素
*		进行公式计算得到新的值：g(x) = a * f(x) + b
*		g(x)表示新的值，a表示对比度常量，b表示亮度常量
*		对比度取值范围在0-3就可以看到很明显的效果，但是本程序中使用了进度条
*		进行调节，如果进度步长在0-3，进度条使用不是很好，故而本程序把步长
*		调节最大为300，而在公式计算时把调节的步长再乘以0.01进行还原，也就是
*		说：g(x) = (a * 0.01) * f(x) + b
*		本例子主要学会亮度和对比度调节原理，巩固前面学的像素遍历以及进度条的
*		使用
********************************************************************************/


/*
* 函数: example_contrast_and_bright
* 功能: 亮度对比度调节
* 参数: img_file 		原图文件
*		level		锐化程度
* 返回: bool
*		- false		失败
* 说明: 
*/
bool example_contrast_and_bright(const char *img_file);

#endif

