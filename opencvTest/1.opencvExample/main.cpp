#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
	// read image
	cv::Mat image = cv::imread("../../useImage/Lenna.png");
	if (image.empty()){
		std::cout << "Could not read image" << std::endl;
	}

	// Apply identity filter using kernel
	cv::Mat kernel1 = (cv::Mat_<double>(3,3) << 0, 0, 0, 0, 1, 0, 0, 0, 0);
	cv::Mat identity; 
	cv::filter2D(image, identity, -1 , kernel1, cv::Point(-1, -1), 0, 4);

	// Blurred using kernel
	// Initialize matrix with all ones
	cv::Mat kernel2 = cv::Mat::ones(5,5, CV_64F);
	// Normalize the elements
	kernel2 = kernel2 / 25;
	cv::Mat kernelBlur;
	cv::filter2D(image, kernelBlur, -1 , kernel2, cv::Point(-1, -1), 0, 4);

	// Blurred using OpenCV C++ blur() function
	cv::Mat img_blur;
	cv::blur(image, img_blur, cv::Size(5,5));

	// Performing Gaussian Blur
	cv::Mat gaussian_blur;
	cv::GaussianBlur(image, gaussian_blur, cv::Size(5,5), 0);

	// Apply Median Blur
	cv::Mat median_blurred;
	cv::medianBlur(image, median_blurred, (5,5));


	// Apply sharpening using kernel
	cv::Mat sharp_img;
	cv::Mat kernel3 = (cv::Mat_<double>(3,3) << 0, -1,  0, 
                                   -1,  5, -1, 
                                    0, -1, 0);
	cv::filter2D(image, sharp_img, -1 , kernel3, cv::Point(-1, -1), 0, cv::BORDER_DEFAULT);

	// Apply bilateral filtering
	cv::Mat bilateral_filter;
	cv::bilateralFilter(image, bilateral_filter, 9, 75, 75);
	
	// Display Image
	cv::imshow("Original", image);
	cv::imshow("Identity", identity);
	cv::imshow("Kernel blur", kernelBlur);
	cv::imshow("Blurred", img_blur);
	cv::imshow("Gaussian Blurred", gaussian_blur);
	cv::imwrite("median_blur.jpg", median_blurred);
	cv::imwrite("sharp_image.jpg", sharp_img);
	cv::imshow("Bilateral filtering", bilateral_filter);

	cv::waitKey(0);
	cv::destroyAllWindows();

	return 0;
}

