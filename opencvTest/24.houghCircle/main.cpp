#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
	// 이미지 읽기
	cv::Mat image = cv::imread("../../useImage/BlobTest.jpg", cv::IMREAD_GRAYSCALE);

	if (image.empty()) {
		std::cerr << "Image load failed" << std::endl;
		return -1;
	}

	cv::Mat houghCircleImg;
	cv::cvtColor(image, houghCircleImg, cv::COLOR_GRAY2BGR);

	std::vector<cv::Vec3f> circles;
	cv::HoughCircles(image, circles, cv::HOUGH_GRADIENT_ALT, 1.5, 10, 300, 0.9, 20, 50);

	for(const cv::Vec3f& circle : circles)
	{
		cv::Vec3i c = circle;
		cv::circle(houghCircleImg, cv::Point(c[0], c[1]), c[2], cv::Scalar(0, 0, 255), 2, cv::LINE_AA);
	}

	cv::imshow("image", image);
	cv::imshow("houghCircleImg", houghCircleImg);

	cv::imwrite("houghCircleImg.jpg", houghCircleImg);

	cv::waitKey(0);
	cv::destroyAllWindows();

	return 0;
}

