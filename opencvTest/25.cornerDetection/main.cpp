#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
	// 이미지 읽기
	cv::Mat image = cv::imread("../../useImage/building.png", cv::IMREAD_GRAYSCALE);

	if (image.empty()) {
		std::cerr << "Image load failed" << std::endl;
		return -1;
	}

	// GFTT
	std::vector<cv::Point2f> corners;
	cv::goodFeaturesToTrack(image, corners, 400, 0.01, 10);

	cv::Mat gfttImg;
	cv::cvtColor(image, gfttImg, cv::COLOR_GRAY2BGR);

	for(const auto& corner : corners) {
		cv::circle(gfttImg, corner, 5, cv::Scalar(0, 0, 255), 2, cv::LINE_AA);
	}

	// FAST
	std::vector<cv::KeyPoint> kps;
	cv::FAST(image, kps, 60);

	cv::Mat fastImg;
	cv::cvtColor(image, fastImg, cv::COLOR_GRAY2BGR);

	for(const auto& kp : kps) {
		cv::circle(fastImg, cv::Point(kp.pt.x, kp.pt.y), 5, cv::Scalar(0, 0, 255), 2, cv::LINE_AA);
	}
	cv::imshow("image", image);
	cv::imshow("GFTT", gfttImg);
	cv::imshow("FAST", fastImg);

	cv::imwrite("GFTT.jpg", gfttImg);
	cv::imwrite("FAST.jpg", fastImg);
	cv::waitKey(0);
	cv::destroyAllWindows();

	return 0;
}

