#include "includes.h"

/*
* 函数: example_blur
* 功能: 线性滤波-均值滤波
* 参数: img_file 		原图文件
* 返回: bool
*		- false		失败
* 说明: 
*/
bool example_blur(const char *img_file)
{
	cv::Mat image;
	cv::Mat imageRoi;
	cv::Mat imageBlur;
	image = cv::imread(img_file, cv::IMREAD_COLOR);
	if (image.empty())
	{
		LOG_TRACE_ERROR("imread %s error !\n", img_file);
		return false;
	}
	cv::imshow("均值滤波-原图", image);

	imageRoi = image(cv::Rect_<int>(image.cols / 2, image.rows / 2, 100, 100));

	//SIZE范围越大，模糊效果越明显，因为一个像素点的领域范围内，
	//距离该点越近的周边像素值与该点的值是越来越相近的，所以SIZE取值很小，
	//周边像素求和的均值也是与目标像素值相近的，可以想象下照相机拍照头发和头皮，
	//头发局部是很靠近的，如果范围扩大的头皮，那头发中的目标点的值与头皮处的值
	//相加求和到的结果与原值会出入比较大
	cv::blur(image, imageBlur, cv::Size_<int>(5, 5), cv::Point_<int>(-1, - 1));
	cv::imshow("均值滤波-全新图", imageBlur);

	cv::blur(imageRoi, imageRoi, cv::Size_<int>(15, 15), cv::Point_<int>(-1, - 1));
	cv::imshow("均值滤波-局部新图", image);

	return true;
}

/*
* 函数: example_gaussian_blur
* 功能: 线性滤波-高斯滤波
* 参数: img_file 		原图文件
* 返回: bool
*		- false		失败
* 说明: 
*/
bool example_gaussian_blur(const char *img_file)
{
	cv::Mat image;
	cv::Mat imageRoi;
	cv::Mat imageBlur;
	image = cv::imread(img_file, cv::IMREAD_COLOR);
	if (image.empty())
	{
		LOG_TRACE_ERROR("imread %s error !\n", img_file);
		return false;
	}
	cv::imshow("高斯滤波-原图", image);

	imageRoi = image(cv::Rect_<int>(image.cols / 2, image.rows / 2, 100, 100));

	//SIZE范围越大，模糊效果越明显，因为一个像素点的领域范围内，
	//距离该点越近的周边像素值与该点的值是越来越相近的，所以SIZE取值很小，
	//周边像素求和的均值也是与目标像素值相近的，可以想象下照相机拍照头发和头皮，
	//头发局部是很靠近的，如果范围扩大的头皮，那头发中的目标点的值与头皮处的值
	//相加求和到的结果与原值会出入比较大
	cv::GaussianBlur(image, imageBlur, cv::Size_<int>(15, 15), 3., 3.);
	cv::imshow("高斯滤波-全新图", imageBlur);

	cv::GaussianBlur(imageRoi, imageRoi, cv::Size_<int>(15, 15), 3., 3.);
	cv::imshow("高斯滤波-局部新图", image);

	return true;
}

