#include "includes.h"

/*
* 函数: example_roi_add_img
* 功能: 把图像2掩膜叠加到图像1中
* 参数: img1_file 	原图文件
*		img2_file	原图文件
* 返回: bool
*		- false		失败
* 说明: 
*/
bool example_roi_add_img(const char *img1_file, const char *img2_file)
{
	cv::Mat image1, image2;
	cv::Mat imageRoi/*, mask*/;

	double start_time = 0.0;

	image1 = cv::imread(img1_file);
	if (image1.empty())
	{
		LOG_TRACE_ERROR("cv::imread %s error !\n", img1_file);
		return false;
	}

	image2 = cv::imread(img2_file);
	if (image2.empty())
	{
		LOG_TRACE_ERROR("cv::imread %s error !\n", img2_file);
		return false;
	}

	cv::imshow("example roi 1", image1);
	//cv::imshow("example roi 2", image2);

	start_time = static_cast<double>(cv::getTickCount());

	imageRoi = image1(cv::Rect_<int>(0, 0, image2.cols, image2.rows));
	if (imageRoi.empty())
	{
		LOG_TRACE_ERROR("imageRoi is empty !\n");
		return false;
	}

	/*mask = cv::imread(img2_file, cv::IMREAD_GRAYSCALE);
	if (mask.empty())
	{
		LOG_TRACE_ERROR("cv::imread %s error !\n", img2_file);
		return false;
	}*/

	image2.copyTo(imageRoi/*, mask*/);

	cv::imshow("example roi 3", image1);
	LOG_TRACE_NORMAL("spend time: %lf sec\n", 
		(cv::getTickCount() - start_time) / cv::getTickFrequency());

	return true;
}

/*
* 函数: example_roi_linearBlending
* 功能: 把图像2线性混合到图像1中
* 参数: img1_file 	原图文件
*		img2_file	原图文件
* 返回: bool
*		- false		失败
* 说明: 
*/
bool example_roi_linearBlending(const char *img1_file, const char *img2_file)
{
	cv::Mat image1, image2;
	cv::Mat imageRoi/*, mask*/;

	double start_time = 0.0;

	image1 = cv::imread(img1_file);
	if (image1.empty())
	{
		LOG_TRACE_ERROR("cv::imread %s error !\n", img1_file);
		return false;
	}

	image2 = cv::imread(img2_file);
	if (image2.empty())
	{
		LOG_TRACE_ERROR("cv::imread %s error !\n", img2_file);
		return false;
	}

	cv::imshow("example roi linear 1", image1);
	//cv::imshow("example roi linear 2", image2);

	start_time = static_cast<double>(cv::getTickCount());

	imageRoi = image1(cv::Rect_<int>(0, 0, image2.cols, image2.rows));
	if (imageRoi.empty())
	{
		LOG_TRACE_ERROR("imageRoi is empty !\n");
		return false;
	}

	/*mask = cv::imread(img2_file, cv::IMREAD_GRAYSCALE);
	if (mask.empty())
	{
		LOG_TRACE_ERROR("cv::imread %s error !\n", img2_file);
		return false;
	}*/

	cv::addWeighted(imageRoi, 0.5, image2, 0.5, 0., imageRoi);

	cv::imshow("example roi linear 3", imageRoi);
	LOG_TRACE_NORMAL("spend time: %lf sec\n", 
		(cv::getTickCount() - start_time) / cv::getTickFrequency());

	return true;
}

