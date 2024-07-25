#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
	// read image
	cv::Mat image = cv::imread("Lenna.png");
	if (image.empty()){
		std::cout << "Could not read image" << std::endl;
	}

	// Draw line on image
	cv::Mat imageLine = image.clone();
	cv::Point pointA(200,80);
	cv::Point pointB(450,80);
	cv::line(imageLine, pointA, pointB, cv::Scalar(255, 255, 0), 3, 8, 0);

	// Draw circle
	cv::Mat circle_image = image.clone();
	// define the center of circle
	cv::Point circle_center(300,280);
	// define the radius of circle
	int radius = 100;
	// Draw a circle using the circle() Function
	cv::circle(circle_image, circle_center, radius, cv::Scalar(0, 0, 255), 3, 8, 0);

	// Draw Filled Circle
	cv::Mat Filled_circle_image = image.clone();
	// Draw a Filled Circle using the circle() Function
	cv::circle(Filled_circle_image, circle_center, radius, cv::Scalar(255, 0, 0), -1, 8, 0);

	// Draw Rectangle
	cv::Mat rect_image = image.clone();
	// Define the starting and end points for the rectangle
	cv::Point start_point(120,100);
	cv::Point end_point(430,405);
	// Draw a rectangle using the rectangle() function
	cv::rectangle(rect_image, start_point, end_point, cv::Scalar(0,0,255), 3, 8, 0);

	//Draw an Ellipse
	cv::Mat imageEllipse = image.clone();
	// define the center point of ellipse
	cv::Point ellipse_center(300,280);
	// define the major and minor axes of the ellipse
	cv::Point axis1(100, 50);
	cv::Point axis2(125, 50);
	// Draw an ellipse using the ellipse() function
	//Horizontal
	cv::ellipse(imageEllipse, ellipse_center, axis1, 0, 0, 360, cv::Scalar(255, 0, 0), 3, 8, 0);
	// Vertical
	cv::ellipse(imageEllipse, ellipse_center, axis2, 90, 0, 360, cv::Scalar(0, 0, 255), 3, 8, 0);


	//Draw a Half-Ellipse
	cv::Mat halfEllipse = image.clone();
	// define the center of half ellipse
	cv::Point ellipse_center2(300,280);
	//define the axis point
	cv::Point axis1_half(100, 50);
	// draw the Half Ellipse, just the outline
	cv::ellipse(halfEllipse, ellipse_center2, axis1_half, 0, 180, 360, cv::Scalar(255, 0, 0), 3, 8, 0);
	// if you want to draw a Filled ellipse, use this line of code
	cv::ellipse(halfEllipse, ellipse_center2, axis1_half, 0, 0, 180, cv::Scalar(0, 0, 255), -2, 8, 0);

	// Adding Text
	cv::Mat imageText = image.clone();
	//cv::putText (InputOutputArray img, const String &text, Point org, int fontFace, double fontScale, Scalar color, int thickness=1, int lineType=LINE_8, bool bottomLeftOrigin=false)
	// Write text using putText() function
	cv::putText(imageText, "I am Lenna!", cv::Point(120,400), cv::FONT_HERSHEY_SIMPLEX, 1.5, cv::Scalar(255,255,0), 2);

	// Display Image
	cv::imshow("Original Image", image);
	cv::imshow("Lined Image", imageLine);
	cv::imshow("Circle on Image", circle_image);
	cv::imshow("Filled Circle on Image", Filled_circle_image);
	cv::imshow("Rectangle on Image", rect_image);
	cv::imshow("Ellipses on Image", imageEllipse);
	cv::imshow("Half-Ellipses on Image", halfEllipse);
	cv::imshow("Text on Image", imageText);

	// wait indefinitely, press any key on keyboard to exit
	cv::waitKey(0);
	cv::destroyAllWindows();

	return 0;
}
