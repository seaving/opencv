#include "includes.h"

/*
* 函数: _example_colorReduce
* 功能: 颜色空间缩减算法
* 参数: src_img 		原图Mat对象
*		dst_img		目标Mat对象
*		level		缩减程度
* 返回: bool
*		- false		失败
* 说明: 
*/
static inline bool _example_colorReduce(cv::Mat& src_img, cv::Mat& dst_img, unsigned int level)
{
	int i = 0;
	unsigned char reduce_table[256] = {0};
	if (src_img.empty())
	{
		LOG_TRACE_ERROR("src image is empty !\n");
		return false;
	}

	for (i = 0; i < 256; i ++)
	{
		reduce_table[i] = cv::saturate_cast<uchar>((i / level) * level + level / 2);
	}

	dst_img = src_img.clone();
#if 0
	//指针遍历
	int rows = dst_img.rows;
	int cols = dst_img.cols * src_img.channels();
	for (int row = 0; row < rows; row ++)
	{
		uchar *outdata = dst_img.ptr<uchar>(row);
		for (int col = 0; col < cols; col ++)
		{
			outdata[col] = reduce_table[cv::saturate_cast<uchar>(outdata[col])];
		}
	}
#endif
#if 0
	//迭代器遍历
	cv::Mat_<cv::Vec3b>::iterator it = dst_img.begin<cv::Vec3b>();
	cv::Mat_<cv::Vec3b>::iterator end = dst_img.end<cv::Vec3b>();
	for ( ; it != end; it ++)
	{
		(*it)[0] = reduce_table[cv::saturate_cast<uchar>((*it)[0])];
		(*it)[1] = reduce_table[cv::saturate_cast<uchar>((*it)[1])];
		(*it)[2] = reduce_table[cv::saturate_cast<uchar>((*it)[2])];
	}
#endif
#if 1
	//动态地址计算
	int rows = dst_img.rows;
	int cols = dst_img.cols;
	for (int row = 0; row < rows; row ++)
	{
		for (int col = 0; col < cols; col ++)
		{
			cv::Vec3b& vec = dst_img.at<cv::Vec3b>(row, col);
			vec[0] = reduce_table[cv::saturate_cast<uchar>(vec[0])];
			vec[1] = reduce_table[cv::saturate_cast<uchar>(vec[1])];
			vec[2] = reduce_table[cv::saturate_cast<uchar>(vec[2])];
		}
	}
#endif
	return true;
}

/*
* 函数: example_colorReduce
* 功能: 颜色空间缩减
* 参数: img_file 		原图文件
*		level		缩减程度
* 返回: bool
*		- false		失败
* 说明: 
*/
bool example_colorReduce(const char *img_file, unsigned int level)
{
	cv::Mat image;

	double start_time = 0.0;

	image = cv::imread(img_file);
	if (image.empty())
	{
		LOG_TRACE_ERROR("cv::imread %s error !\n", img_file);
		return false;
	}

	cv::imshow("example color reduce 1", image);

	start_time = static_cast<double>(cv::getTickCount());

	_example_colorReduce(image, image, level);

	cv::imshow("example color reduce 2", image);
	LOG_TRACE_NORMAL("spend time: %lf sec\n", 
		(cv::getTickCount() - start_time) / cv::getTickFrequency());

	return true;
}


