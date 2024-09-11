#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
	// 이미지 읽기
	cv::Mat image = cv::imread("../../useImage/Lenna.png", cv::IMREAD_GRAYSCALE);

	if (image.empty()) {
		std::cerr << "Image load failed" << std::endl;
		return -1;
	}

	cv::Mat dst;
	cv::erode(image, dst, cv::Mat()); //침식
	//cv::dilate(image, dst, cv::Mat()); //팽창
	cv::Mat dst2;
	cv::morphologyEx(dst, dst2, cv::MORPH_OPEN, cv::Mat()); // MORPH_CLOSE ...

	cv::imshow("image", image);
	cv::imshow("erode or dilate", dst);
	cv::imshow("morphologyEx", dst2);
	
	cv::waitKey(0);
	cv::destroyAllWindows();

	return 0;
}

