#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // 이미지 읽기
    cv::Mat image = cv::imread("Lenna.png");

    if (image.empty()) {
        std::cerr << "Image load failed" << std::endl;
        return -1;
    }

    // 이미지를 YCrCb 색상 공간으로 변환
    cv::Mat src_ycrcb;
    cv::cvtColor(image, src_ycrcb, cv::COLOR_BGR2YCrCb);

    // ROI 선택
    cv::Rect rect = cv::selectROI(image);
    cv::Mat roi = src_ycrcb(rect);

    // 히스토그램 계산
    cv::Mat hist;
    int channels[] = {1, 2}; // Cr, Cb 채널
    int cr_bins = 128; // Cr 채널의 히스토그램 빈 수
    int cb_bins = 128; // Cb 채널의 히스토그램 빈 수
    int histSize[] = {cr_bins, cb_bins};
    float cr_range[] = {0, 256};
    float cb_range[] = {0, 256};
    const float* ranges[] = {cr_range, cb_range};

    cv::calcHist(&roi, 1, channels, cv::Mat(), hist, 2, histSize, ranges);

    // 역투영 수행
    cv::Mat backproj;
    cv::calcBackProject(&src_ycrcb, 1, channels, hist, backproj, ranges);

    // 역투영 결과에 임계값 적용
    cv::Mat thresh;
    cv::threshold(backproj, thresh, 50, 255, cv::THRESH_BINARY);

    // 결과 이미지 생성
    cv::Mat dst;
    image.copyTo(dst, thresh);

    // 결과 출력
    cv::imshow("Original Image", image);
    cv::imshow("Mask", thresh);
    cv::imshow("Detected Face", dst);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}
//마우스로 범위 지정한뒤 엔터 누르기
