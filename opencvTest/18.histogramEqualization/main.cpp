#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
int main() {
	// read image
	cv::Mat image = cv::imread("candies.png");
	if (image.empty()){
		std::cout << "Could not read image" << std::endl;
	}


	cv::Mat src_ycrcb;
	cv::cvtColor(image, src_ycrcb, cv::COLOR_BGR2YCrCb);

	std::vector<cv::Mat> planes;
	cv::split(src_ycrcb, planes);

	cv::equalizeHist(planes[0], planes[0]);

	cv::Mat dst_ycrcb;
	cv::merge(planes, dst_ycrcb);

	cv::Mat histogramEqualization;
	cv::cvtColor(dst_ycrcb, histogramEqualization, cv::COLOR_YCrCb2BGR);

	cv::imshow("image", image);
	cv::imshow("histogramEqualization", histogramEqualization);


	cv::imwrite("histogramEqualization.jpg", histogramEqualization);
	cv::waitKey(0);
	cv::destroyAllWindows();

	return 0;
}


