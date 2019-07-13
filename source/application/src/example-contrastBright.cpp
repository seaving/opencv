#include "includes.h"

typedef struct __contrast_bright__
{
	int contrast;
	int bright;
	cv::Mat srcImage;
	cv::Mat dstImage;
} contrast_bright_t;

static contrast_bright_t _param = {0};

/*
* 函数: _adjust_contrast_bright
* 功能: 亮度对比度调节
* 参数: img_file 		原图文件
*		level		锐化程度
* 返回: bool
*		- false		失败
* 说明: 
*/
static inline bool _adjust_contrast_bright(contrast_bright_t& param)
{
	int row = 0;
	int col = 0;
	int rows = param.srcImage.rows;
	int cols = param.srcImage.cols;

	uchar table[256] = {0};
	for (col = 0; col < 256; col ++)
	{
		table[col] = cv::saturate_cast<uchar>(
				param.contrast * 0.01 * col + param.bright);
	}

	for (row = 0; row < rows; row ++)
	{
		for (col = 0; col < cols; col ++)
		{
			cv::Vec3b& srcVec = param.srcImage.at<cv::Vec3b>(row, col);
			cv::Vec3b& dstVec = param.dstImage.at<cv::Vec3b>(row, col);
			dstVec[0] = table[srcVec[0]];
			dstVec[1] = table[srcVec[1]];
			dstVec[2] = table[srcVec[2]];
		}
	}

	return true;
}

/*
* 函数: _trackbar_cb
* 功能: 滚动条回调
* 参数: pos 			滚动条的滚动值
*		user		用户参数
* 返回: 无
* 说明: 
*/
static void _trackbar_cb(int pos, void *user)
{
	contrast_bright_t *param = (contrast_bright_t *) user;
	if (param == NULL 
		|| param->srcImage.empty())
	{
		return;
	}

	_adjust_contrast_bright(*param);

	cv::imshow("效果图窗口", param->dstImage);
}

/*
* 函数: example_contrast_and_bright
* 功能: 亮度对比度调节
* 参数: img_file 		原图文件
*		level		锐化程度
* 返回: bool
*		- false		失败
* 说明: 
*/
bool example_contrast_and_bright(const char *img_file)
{
	_param.srcImage = cv::imread(img_file);
	if (_param.srcImage.empty())
	{
		LOG_TRACE_ERROR("cv::imread %s error !\n", img_file);
		return false;
	}

	_param.bright = 80;
	_param.contrast = 80;

	_param.dstImage = cv::Mat::zeros(_param.srcImage.size(), _param.srcImage.type());

	cv::namedWindow("效果图窗口", cv::WINDOW_AUTOSIZE);

	cv::createTrackbar("对比度: ", "效果图窗口", &_param.contrast, 300, _trackbar_cb, &_param);
	cv::createTrackbar("亮度: ", "效果图窗口", &_param.bright, 200, _trackbar_cb, &_param);

	cv::imshow("example contrast and bright 1", _param.srcImage);

	_trackbar_cb(_param.contrast, &_param);
	_trackbar_cb(_param.bright, &_param);

	return true;
}

