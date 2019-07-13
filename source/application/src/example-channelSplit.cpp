#include "includes.h"

/*
* 函数: example_chennel_split
* 功能: 分离通道
* 参数: img_file 		原图文件
* 返回: bool
*		- false		失败
* 说明: 
*/
bool example_chennel_split(const char *img_file)
{
	cv::Mat image;
	cv::Mat channel;
	std::vector<cv::Mat> channels;

	unsigned int i = 0;
	char windowsId[64] = {0};

	double start_time = 0.0;

	image = cv::imread(img_file);
	if (image.empty())
	{
		LOG_TRACE_ERROR("cv::imread %s error !\n", img_file);
		return false;
	}

	cv::imshow("example chennel split 1", image);

	start_time = static_cast<double>(cv::getTickCount());

	//分离出来的通道变成了单通道灰度图了
	cv::split(image, channels);
	for (i = 0; i < channels.size(); i ++)
	{
		channel = channels.at(0);
		snprintf(windowsId, sizeof(windowsId), "example chennel %d", i);
		cv::imshow(windowsId, channel);
	}
	LOG_TRACE_NORMAL("spend time: %lf sec\n", 
		(cv::getTickCount() - start_time) / cv::getTickFrequency());

	return true;
}

/*
* 函数: example_chennel_split_and_merge
* 功能: 分离通道以及通道合并
* 参数: img1_file 	原图1文件
*		img2_file	原图2文件
* 返回: bool
*		- false		失败
* 说明: 
*/
bool example_chennel_split_and_merge(const char *img1_file, const char *img2_file)
{
	cv::Mat image1, image2;
	cv::Mat channel;
	cv::Mat imageRoi;
	std::vector<cv::Mat> channels;

	unsigned int i = 0;
	char windowsId[64] = {0};

	double start_time = 0.0;

	image1 = cv::imread(img1_file);
	if (image1.empty())
	{
		LOG_TRACE_ERROR("cv::imread %s error !\n", img1_file);
		return false;
	}

	//按照单通道读取，因为后面image1会通道分离成单通道
	image2 = cv::imread(img2_file, cv::IMREAD_GRAYSCALE);
	if (image2.empty())
	{
		LOG_TRACE_ERROR("cv::imread %s error !\n", img2_file);
		return false;
	}

	cv::imshow("example chennel split merge 1", image1);

	start_time = static_cast<double>(cv::getTickCount());

	//分离出来的通道变成了单通道灰度图了
	cv::split(image1, channels);
	//for (i = 0; i < channels.size(); i ++)
	{
		channel = channels.at(i);
		imageRoi = channel(cv::Rect_<int>(0, 0, image2.cols, image2.rows));
		cv::addWeighted(imageRoi, 1., image2, 0.5, 0., imageRoi, imageRoi.depth());
	}

	cv::merge(channels, image1);
	snprintf(windowsId, sizeof(windowsId), "example chennel merge %d", i);
	cv::imshow(windowsId, image1);

	LOG_TRACE_NORMAL("spend time: %lf sec\n", 
		(cv::getTickCount() - start_time) / cv::getTickFrequency());

	return true;
}

