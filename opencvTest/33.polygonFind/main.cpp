#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // 이미지 읽기
    cv::Mat src = cv::imread("../../useImage/polygon.png");
    if (src.empty()) {
        std::cerr << "Image load failed!" << std::endl;
        return -1;
    }

    // 그레이스케일로 변환
    cv::Mat gray;
    cv::cvtColor(src, gray, cv::COLOR_BGR2GRAY);

    // 이진화 (Binary Thresholding)
    cv::Mat binary;
    cv::threshold(gray, binary, 127, 255, cv::THRESH_BINARY_INV);

    // 외곽선 찾기 (Find contours)
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(binary, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    // 외곽선 근사화 및 다각형 판별
    for (size_t i = 0; i < contours.size(); i++) {
        std::vector<cv::Point> approx;
        double epsilon = 0.04 * cv::arcLength(contours[i], true); // 근사화 정확도 조정
        cv::approxPolyDP(contours[i], approx, epsilon, true);

        // 작은 객체 또는 비볼록 객체 제외
        if (std::fabs(cv::contourArea(contours[i])) < 100 || !cv::isContourConvex(approx)) {
            continue;
        }

        // 다각형 판별
        if (approx.size() == 3) {
            cv::putText(src, "Triangle", approx[0], cv::FONT_HERSHEY_SIMPLEX, 0.6, cv::Scalar(0, 255, 0), 2);
        }
        else if (approx.size() == 4) {
            // 사각형 판별: 사각형은 직사각형 또는 정사각형일 수 있음
            double aspectRatio = std::fabs(cv::boundingRect(approx).width / (double)cv::boundingRect(approx).height);
            if (aspectRatio > 0.9 && aspectRatio < 1.1) {
                cv::putText(src, "Square", approx[0], cv::FONT_HERSHEY_SIMPLEX, 0.6, cv::Scalar(255, 0, 0), 2);
            }
            else {
                cv::putText(src, "Rectangle", approx[0], cv::FONT_HERSHEY_SIMPLEX, 0.6, cv::Scalar(255, 0, 0), 2);
            }
        }
        else {
            // 원 판별: 근사화 후의 다각형이 6개 이상의 꼭지점을 가지면 원에 가까움
            double area = cv::contourArea(contours[i]);
            cv::Rect boundingRect = cv::boundingRect(contours[i]);
            int radius = boundingRect.width / 2;

            if (std::fabs(1 - ((double)boundingRect.width / boundingRect.height)) <= 0.2 && 
                std::fabs(1 - (area / (CV_PI * std::pow(radius, 2)))) <= 0.2) {
                cv::putText(src, "Circle", approx[0], cv::FONT_HERSHEY_SIMPLEX, 0.6, cv::Scalar(0, 0, 255), 2);
            }
        }

        // 외곽선 그리기
        cv::drawContours(src, std::vector<std::vector<cv::Point>>{approx}, -1, cv::Scalar(0, 255, 255), 2);
    }

    // 결과 이미지 출력
    cv::imshow("Result", src);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}

