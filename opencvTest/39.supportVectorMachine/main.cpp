#include <opencv2/opencv.hpp>
#include <opencv2/ml.hpp>
#include <iostream>

int main() {
	// 1. 데이터 생성
	cv::Mat trainData, labels;

	// 첫 번째 클래스 (점: (1, 1), (1, 2))
	cv::Mat class1 = (cv::Mat_<float>(2, 2) << 1, 1, 1, 2);
	cv::Mat class1_labels = (cv::Mat_<int>(2, 1) << 1, 1);

	// 두 번째 클래스 (점: (3, 3), (4, 4))
	cv::Mat class2 = (cv::Mat_<float>(2, 2) << 3, 3, 4, 4);
	cv::Mat class2_labels = (cv::Mat_<int>(2, 1) << -1, -1);

	// 데이터와 레이블 결합
	trainData.push_back(class1);
	trainData.push_back(class2);
	labels.push_back(class1_labels);
	labels.push_back(class2_labels);

	// 2. SVM 모델 생성 및 학습
	cv::Ptr<cv::ml::SVM> svm = cv::ml::SVM::create();

	svm->setKernel(cv::ml::SVM::LINEAR);  // 선형 커널
	svm->setType(cv::ml::SVM::C_SVC);     // C-Support Vector Classification
	svm->setC(1);                         // Regularization parameter
	svm->setGamma(0.5);                   // Gamma parameter for kernel
	svm->setTermCriteria(cv::TermCriteria(cv::TermCriteria::MAX_ITER, 100, 1e-6));

	svm->train(trainData, cv::ml::ROW_SAMPLE, labels);
	svm->save("svm_model.xml");  // 모델 저장

	// 3. 예측 및 결과 시각화
	cv::Mat testData = (cv::Mat_<float>(4, 2) << 1, 1, 2, 2, 3, 3, 4, 4);  // 테스트 데이터

	cv::Mat results;
	svm->predict(testData, results);

	// 출력 결과
	std::cout << "Test data predictions: " << std::endl;
	for (int i = 0; i < results.rows; ++i) {
		std::cout << "Point " << i + 1 << ": " << results.at<float>(i, 0) << std::endl;
	}

	return 0;
}

