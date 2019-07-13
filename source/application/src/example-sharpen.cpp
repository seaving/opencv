#include "includes.h"

/*
* 函数: example_sharpen
* 功能: 图片锐化，提高对比度例子
* 参数: img_file 		原图文件
*		level		锐化程度
* 返回: bool
*		- false		失败
* 说明: 
*/
bool example_sharpen(const char *img_file, unsigned int level)
{
	cv::Mat image;
	cv::Mat kernel = (cv::Mat_<char>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);

	double start_time = 0.0;

	unsigned int i = 0;

	image = cv::imread(img_file);
	if (image.empty())
	{
		LOG_TRACE_ERROR("cv::imread %s error !\n", img_file);
		return false;
	}

	cv::imshow("example sharpen 1", image);

	start_time = static_cast<double>(cv::getTickCount());

	for (i = 0; i < level; i ++)
	{
		cv::filter2D(image, image, image.depth(), kernel);
	}

	cv::imshow("example sharpen 2", image);
	LOG_TRACE_NORMAL("spend time: %lf sec\n", 
		(cv::getTickCount() - start_time) / cv::getTickFrequency());

	return true;
}

