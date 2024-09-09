#include <opencv2/opencv.hpp>
#include <iostream>


int main() {
	// 이미지 읽기
	cv::Mat image = cv::imread("../../useImage/Lenna.png", cv::IMREAD_GRAYSCALE);

	if (image.empty()) {
		std::cerr << "Image load failed" << std::endl;
		return -1;
	}

    int w = image.cols / 4;
    int h = image.rows / 4;

    cv::Mat dst = cv::Mat::zeros(image.rows, image.cols, CV_8UC1);
    double threshold = cv::threshold(image, dst, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);

    for(int y = 0; y < 4; y++) {
        for(int x = 0; x < 4; x++) {
            cv::Mat image_ = image(cv::Rect(x * w, y * h, w, h));
            cv::Mat dst_ = dst(cv::Rect(x * w, y * h, w, h));
            cv::threshold(image_, dst_, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);
        }
    }

    cv::imshow("image", image);
    cv::imshow("dst", dst);
	cv::waitKey(0);
	cv::destroyAllWindows();

	return 0;
}

