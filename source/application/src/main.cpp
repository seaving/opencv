#include "includes.h"

/*
* 函数: _main_loop
* 功能: 主流程
* 参数: 无
* 返回: int
* 说明: 
*/
static inline int _main_loop()
{
	/*for ( ; ; )
	{
		sleep(1);
	}*/

	cv::waitKey();
	return 0;
}

/*
* 函数: main
* 功能: 主函数
* 参数: argc		参数列表个数
*		argv	参数列表
* 返回: int
* 说明: 
*/
int main(int argc, char **argv)
{
	const char *img1_file = IMAGE_DIR"/lena.jpg";
	//const char *img2_file = IMAGE_DIR"/timg.jpg";

	//example_sharpen(img1_file, 1);
	//example_colorReduce(img1_file, 32);
	//example_roi_add_img(img1_file, img2_file);
	//example_roi_linearBlending(img1_file, img2_file);
	//example_chennel_split(img1_file);
	//example_chennel_split_and_merge(img1_file, img2_file);
	//example_contrast_and_bright(img1_file);

	//example_blur(img1_file);
	example_gaussian_blur(img1_file);

	return _main_loop();
}

