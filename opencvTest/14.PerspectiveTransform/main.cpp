#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
int main() {
	// read image
	cv::Mat image = cv::imread("dog.jpg");
	if (image.empty()){
		std::cout << "Could not read image" << std::endl;
	}

	std::vector<cv::Point2f> imagePts(4), perspectivePts(4);
	int w = 300, h = 300;

	imagePts[0] = cv::Point2f(0, 76);
	imagePts[1] = cv::Point2f(500, 76);
	imagePts[2] = cv::Point2f(288, 371);
	imagePts[3] = cv::Point2f(500, 371);

	perspectivePts[0] = cv::Point2f(0, 0);
	perspectivePts[1] = cv::Point2f(200, 0);
	perspectivePts[2] = cv::Point2f(0, 200);
	perspectivePts[3] = cv::Point2f(200, 200);
	cv::Mat temp = cv::getPerspectiveTransform(imagePts, perspectivePts);
	cv::Mat perspective;
	cv::warpPerspective(image, perspective, temp, cv::Size(w, h));

	cv::imshow("image", image);
	cv::imshow("perspective", perspective);
	//save
	cv::imwrite("perspective.jpg", perspective);

	cv::waitKey(0);
	cv::destroyAllWindows();

	return 0;
}
