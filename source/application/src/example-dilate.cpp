#include "includes.h"

/*
* 函数: example_dilate
* 功能: 形态学滤波-膨胀后再闭运算
* 参数: img_file 		原图文件
* 返回: bool
*		- false		失败
* 说明: 
*/
bool example_dilate(const std::string& img_file)
{
	cv::Mat image;
	cv::Mat dstImage;
	cv::Mat kernel;
	image = cv::imread(img_file, cv::IMREAD_COLOR);
	if (image.empty())
	{
		LOG_TRACE_ERROR("imread %s error !\n", img_file.c_str());
		return false;
	}

	cv::imshow("形态学滤波-膨胀-原图", image);

	kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size_<int>(7, 9), cv::Point_<int>(-1, -1));
	cv::dilate(image, dstImage, kernel, cv::Point_<int>(-1, -1));

	cv::imshow("形态学滤波-膨胀-新图", dstImage);

	kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size_<int>(7, 9), cv::Point_<int>(-1, -1));
	cv::morphologyEx(image, dstImage, cv::MORPH_CLOSE, kernel, cv::Point_<int>(-1, -1));

	cv::imshow("形态学滤波-闭运算-新图", dstImage);

	return true;
}

