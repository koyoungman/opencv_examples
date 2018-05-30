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
	const string filename1 = "../image/read_16.tif";
	const string filename2 = "../image/read_32.tif";
	Mat color2unchanged1 = imread(filename1, IMREAD_UNCHANGED);
	Mat color2unchanged2 = imread(filename2, IMREAD_UNCHANGED);
	CV_Assert(color2unchanged1.data && color2unchanged2.data);

	Rect roi(100, 100, 1, 1);
	cout << "16/32비트 영상 행렬 좌표(100, 100) 화소값 " << endl;
	cout << "color2unchanged1 " << color2unchanged1(roi) << endl;
	cout << "color2unchanged2 " << color2unchanged2(roi) << endl << endl;

	print_matInfo("color2unchanged1", color2unchanged1);
	print_matInfo("color2unchanged2", color2unchanged2);
	imshow("color2unchanged1", color2unchanged1);
	imshow("color2unchanged2", color2unchanged2);
	waitKey(0);

	return 0;
}
