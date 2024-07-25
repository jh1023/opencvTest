#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
	// 이미지 읽기
	cv::Mat img_color = cv::imread("Lenna.png", cv::IMREAD_COLOR);
	cv::Mat img_grayscale = cv::imread("Lenna.png", cv::IMREAD_GRAYSCALE);
	cv::Mat img_unchanged = cv::imread("Lenna.png", cv::IMREAD_UNCHANGED);

	// 이미지 표시
	// Create a window.
	cv::namedWindow( "color image", cv::WINDOW_AUTOSIZE );
	cv::namedWindow( "grayscale image", cv::WINDOW_AUTOSIZE );
	cv::namedWindow( "unchanged image", cv::WINDOW_AUTOSIZE );

	// Show the image inside it.
	cv::imshow( "color image", img_color ); 
	cv::imshow( "grayscale image", img_grayscale );
	cv::imshow( "unchanged image", img_unchanged ); 

	// Wait for a keystroke.   
	cv::waitKey(0);  

	// Destroys all the windows created                         
	cv::destroyAllWindows();
	
	// 이미지 쓰기
	imwrite("save.png", img_grayscale);

    return 0;
}
