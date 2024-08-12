#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
	// read image
	cv::Mat image = cv::imread("Lenna.png", cv::IMREAD_GRAYSCALE);
	if (image.empty()){
		std::cout << "Could not read image" << std::endl;
	}
	cv::Mat BnInterpolation;
	BnInterpolation.create(image.rows * 3 / 2, image.cols * 3 / 2, CV_8U);
	int x1, y1, x2, y2;
	double rx, ry, p, q, value;

	// scaling factor
	double sx = static_cast<double>(image.cols - 1) / (BnInterpolation.cols - 1);
	double sy = static_cast<double>(image.rows - 1) / (BnInterpolation.rows - 1);


	for (int y = 0; y < BnInterpolation.rows; y++) {
		for(int x = 0; x < BnInterpolation.cols; x++) {
			rx = sx * x;
			ry = sy * y;
			x1 = cvFloor(rx);
			y1 = cvFloor(ry);
			x2 = x1 + 1; if(x2 == image.cols) x2 = image.cols - 1;
			y2 = y1 + 1; if(y2 == image.rows) y2 = image.rows - 1;
			p  = rx - x1;
			q  = ry - y1;

			value = (1. - p) * (1. - q) * image.at<uchar>(y1, x1)
				+ p * (1. - q) * image.at<uchar>(y1, x2)
				+ (1. - p) * q * image.at<uchar>(y2, x1)
				+ p * q * image.at<uchar>(y2, x2);

			BnInterpolation.at<uchar>(y, x) = static_cast<uchar>(value + .5); 
		}
	}

	cv::imshow("image", image);
	cv::imshow("BnInterpolation", BnInterpolation);
	cv::imwrite("Bilinear Interpolation.jpg", BnInterpolation);
	cv::waitKey(0);
	cv::destroyAllWindows();

	return 0;
}
