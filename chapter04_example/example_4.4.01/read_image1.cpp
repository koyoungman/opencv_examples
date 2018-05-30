#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

void print_matInfo(string name, Mat img)
{
	string mat_type;
	auto img_depth = img.depth();
	
	switch (img_depth)
	{
	case CV_8U:
		mat_type = "CV_8U";
		break;
	case CV_8S:
		mat_type = "CV_8S";
		break;
	case CV_16U:
		mat_type = "CV_16U";
		break;
	case CV_16S:
		mat_type = "CV_16S";
		break;
	case CV_32S:
		mat_type = "CV_32S";
		break;
	case CV_32F:
		mat_type = "CV_32F";
		break;
	case CV_64F:
		mat_type = "CV_64F";
		break;
	}

	cout << name;
	cout << format(": depth(%d) channels(%d) -> 자료형 : ", img_depth, img.channels());
	cout << mat_type << "C" << img.channels() << endl;
}

int main(int argc, char** argv)
{
	const string filename = "../image/read_gray.jpg";
	Mat gray2gray = imread(filename, IMREAD_GRAYSCALE);
	Mat gray2color = imread(filename, IMREAD_COLOR);
	CV_Assert(gray2gray.data && gray2color.data);

	Rect roi(100, 100, 1, 1);
	cout << "행렬 좌표(100, 100) 화소값 " << endl;
	cout << "gray2gray " << gray2gray(roi) << endl;
	cout << "gray2color " << gray2color(roi) << endl << endl;

	print_matInfo("gray2gray", gray2gray);
	print_matInfo("gray2color", gray2color);
	imshow("gray2gray", gray2gray);
	imshow("gray2color", gray2color);
	waitKey(0);

	return 0;
}
