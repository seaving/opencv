#include "includes.h"

/*
* 函数: example_erode
* 功能: 形态学滤波-腐蚀后再开运算
* 参数: img_file 		原图文件
* 返回: bool
*		- false		失败
* 说明: 
*/
bool example_erode(const std::string& img_file)
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

	cv::imshow("形态学滤波-腐蚀-原图", image);

	kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size_<int>(5, 9), cv::Point_<int>(-1, -1));
	cv::erode(image, dstImage, kernel, cv::Point_<int>(-1, -1));

	cv::imshow("形态学滤波-腐蚀-新图", dstImage);

	kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size_<int>(5, 9), cv::Point_<int>(-1, -1));
	cv::morphologyEx(image, dstImage, cv::MORPH_OPEN, kernel, cv::Point_<int>(-1, -1));

	cv::imshow("形态学滤波-开运算-新图", dstImage);

	return true;
}

