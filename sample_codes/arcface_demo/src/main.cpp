#include <iostream>
#include <opencv2/opencv.hpp>

#include "arcface.h"

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		std::cout << "Usage : " << argv[0] <<  " <test image1> <test image2>.\n";
		return -1;
	}

	ArcFace arcFace;
	std::string model_path = "../models/arcface.wk";
	int ret = arcFace.init((char*)model_path.c_str());

	cv::Mat image1 = cv::imread(argv[1]);
	cv::Mat image2 = cv::imread(argv[2]);

	if(image1.empty() || image2.empty())
	{
		std::cout << "input image is empty!!!\n";
		return -1;
	}

	cv::Mat feature1, feature2;
	arcFace.extract(image1, feature1);
	arcFace.extract(image2, feature2);
	
	float sim = arcFace.similarity(feature1, feature2);

	std::cout << "similarity : " << sim << std::endl;

	arcFace.destroy();
	return 0;
}
