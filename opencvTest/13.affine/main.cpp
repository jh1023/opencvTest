#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
int main() {
	// read image
	cv::Mat image = cv::imread("Lenna.png", cv::IMREAD_GRAYSCALE);
	if (image.empty()){
		std::cout << "Could not read image" << std::endl;
	}

	std::vector<cv::Point2f> imagePts = {cv::Point2f(0, 0), 
		cv::Point2f(0, image.rows-1), cv::Point2f(image.cols-1, image.rows-1)};

	std::vector<cv::Point2f> dstPts = {cv::Point2f(0, 0), 
		cv::Point2f(0, image.rows-1), cv::Point2f(image.cols/2, image.rows/2)};

	cv::Mat affineTrans = cv::getAffineTransform(imagePts, dstPts);

	cv::Mat warpAffineTrans;
	cv::warpAffine(image, warpAffineTrans, affineTrans, cv::Size());

	cv::imshow("image", image);
	cv::imshow("warpAffineTrans", warpAffineTrans);
	//save
	cv::imwrite("warpAffineTrans.jpg", warpAffineTrans);

	cv::waitKey(0);
	cv::destroyAllWindows();

	return 0;
}
