#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
	// read image
	cv::Mat image = cv::imread("Lenna.png", cv::IMREAD_GRAYSCALE);
	if (image.empty()){
		std::cout << "Could not read image" << std::endl;
	}

	cv::Mat moveConv = cv::Mat::zeros(image.rows, image.cols, CV_8UC1);

	for (int y = 0; y < image.rows; y++)
	{
		for(int x = 0; x < image.cols; x++)
		{
			int x_ = x - 200;
			int y_ = y + 100;
			if(x_ < 0 || x_ >= moveConv.cols) continue;
			if(y_ < 0 || y_ >= moveConv.rows) continue;
			moveConv.at<uchar>(y_, x_) = image.at<uchar>(y, x);
		}
	}

	cv::imshow("image", image);
	cv::imshow("moveConv", moveConv);
	cv::imwrite("movement_conversion.jpg", moveConv);
	cv::waitKey(0);
	cv::destroyAllWindows();

	return 0;
}
