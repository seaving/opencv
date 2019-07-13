#ifndef __EXAMPLE_CHANNEL_SPLIT_HPP__
#define __EXAMPLE_CHANNEL_SPLIT_HPP__

/********************************************************************************
* @文件名: example-channelSplit.hpp example-channelSplit.cpp
* @作者: caixiwen
* @时间: 2019-7-11
* @说明: example_chennel_split：通道分离，把多通道矩阵分离成单通道矩阵
*		example_chennel_split_and_merge：通道分离后再把分离后的通道重新合并成多通道
*		通过本例子学会使用split分离通道，以及merge重新合并通道，顺便巩固线性混合叠加
*		addWeighted的使用
********************************************************************************/

/*
* 函数: example_chennel_split
* 功能: 分离通道
* 参数: img_file 		原图文件
* 返回: bool
*		- false		失败
* 说明: 
*/
bool example_chennel_split(const char *img_file);

/*
* 函数: example_chennel_split_and_merge
* 功能: 分离通道以及通道合并
* 参数: img1_file 	原图1文件
*		img2_file	原图2文件
* 返回: bool
*		- false		失败
* 说明: 
*/
bool example_chennel_split_and_merge(const char *img1_file, const char *img2_file);

#endif

