#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
	// 이미지 읽기
	cv::Mat image = cv::imread("../../useImage/building.png", cv::IMREAD_GRAYSCALE);

	if (image.empty()) {
		std::cerr << "Image load failed" << std::endl;
		return -1;
	}

	cv::Mat edge;
	cv::Canny(image, edge, 50, 150);

	std::vector<cv::Vec2f> lines1;
	cv::HoughLines(edge, lines1, 1, CV_PI / 180, 250);

	// draw hough lines
	cv::Mat houghlineImg;
	cv::cvtColor(edge, houghlineImg, cv::COLOR_GRAY2BGR);

	for(const cv::Vec2f& line : lines1) {
		float r = line[0], t = line[1];
		double cos = std::cos(t), sin = std::sin(t);
		double x = r * cos, y = r * sin;
		double alpha = 1000;

		cv::Point pt1(cvRound(x + alpha * (-sin)), cvRound(y + alpha * cos));
		cv::Point pt2(cvRound(x - alpha * (-sin)), cvRound(y - alpha * cos));
		cv::line(houghlineImg, pt1, pt2, cv::Scalar(0, 0, 255), 1, cv::LINE_AA);
	}

	std::vector<cv::Vec4i> lines2;
	cv::HoughLinesP(edge, lines2, 1, CV_PI / 180, 160, 50, 5);

	cv::Mat houghlinesPImg;
	cv::cvtColor(edge, houghlinesPImg, cv::COLOR_GRAY2BGR);

	for(const cv::Vec4i& line : lines2) {
		cv::line(houghlinesPImg, cv::Point(line[0], line[1]), cv::Point(line[2], line[3]), cv::Scalar(0, 0, 255), 2, cv::LINE_AA);
	}


	cv::imshow("image", image);
	cv::imshow("houghline", houghlineImg);
	cv::imshow("houghlinesP", houghlinesPImg);

	cv::imwrite("houghline.jpg", houghlineImg);
	cv::imwrite("houghlinesP.jpg", houghlinesPImg);
	cv::waitKey(0);
	cv::destroyAllWindows();

	return 0;
}

