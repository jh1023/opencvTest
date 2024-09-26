#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // Cascade Classifier 로드
	//OpenCV/data/haarcascades 안에 있음
    cv::CascadeClassifier face_cascade;
    if (!face_cascade.load("./haarcascade_frontalface_default.xml")) {
        std::cerr << "Error loading face cascade" << std::endl;
        return -1;
    }

    // 이미지 로드
    cv::Mat img = cv::imread("../../useImage/Lenna.png");
    if (img.empty()) {
        std::cerr << "Error loading image" << std::endl;
        return -1;
    }

    // 이미지 그레이스케일로 변환
    cv::Mat gray;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);

    // 얼굴 검출
    std::vector<cv::Rect> faces;
    face_cascade.detectMultiScale(gray, faces, 1.1, 2, 0 | cv::CASCADE_SCALE_IMAGE, cv::Size(30, 30));

    // 검출된 얼굴에 사각형 그리기
    for (const auto& face : faces) {
        cv::rectangle(img, face, cv::Scalar(255, 0, 0), 2);
    }

    // 결과 이미지 표시
    cv::imshow("Detected Faces", img);
    cv::waitKey(0);

    return 0;
}

