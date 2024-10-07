#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

int main() {
    // 1. HOGDescriptor 객체 생성
    cv::HOGDescriptor hog;
    
    // 2. 사전 훈련된 보행자 검출 SVM 계수 등록
    hog.setSVMDetector(cv::HOGDescriptor::getDefaultPeopleDetector());

    // 3. 입력 이미지 로드
    cv::Mat img = cv::imread("../../useImage/people.png");

    if (img.empty()) {
        std::cerr << "Image load failed!" << std::endl;
        return -1;
    }

    // 4. 사람 검출
    std::vector<cv::Rect> found;
    hog.detectMultiScale(img, found);

    // 5. 검출된 사람들을 이미지에 표시
    for (size_t i = 0; i < found.size(); i++) {
        cv::Rect r = found[i];

        // 사각형의 크기를 약간 확장 (option)
        r.x += cvRound(r.width * 0.1);
        r.width = cvRound(r.width * 0.8);
        r.y += cvRound(r.height * 0.06);
        r.height = cvRound(r.height * 0.9);

        // 검출된 사람을 빨간 사각형으로 표시
        cv::rectangle(img, r.tl(), r.br(), cv::Scalar(0, 0, 255), 2);
    }

    // 6. 결과 출력
    cv::imshow("People Detection", img);
    cv::waitKey(0);

    return 0;
}

