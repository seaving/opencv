#ifndef __EXAMPLE_SHARPEN_HPP__
#define __EXAMPLE_SHARPEN_HPP__

/********************************************************************************
* @文件名: example-sharpen.hpp example-sharpen.cpp
* @作者: caixiwen
* @时间: 2019-7-11
* @说明: 矩阵掩膜操作例子，矩阵掩膜操作可以提高图片对比度，也就是所谓的锐化
*
********************************************************************************/

/*
* 函数: example_sharpen
* 功能: 图片锐化，提高对比度例子
* 参数: img_file 		原图文件
*		level		锐化程度
* 返回: bool
*		- false		失败
* 说明: 
*/
bool example_sharpen(const char *img_file, unsigned int level);

#endif

