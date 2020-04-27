#include "opencv2/core/utility.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/video.hpp"

using namespace std;
using namespace cv;

int main(int argc, char **argv)
{
    VideoCapture cap("test.264", CAP_INTEL_MFX);
    Mat frame, gray;

    while(true)
    {
        cap >> frame;
        if (frame.empty())
            break;
        cvtColor(frame, gray, COLOR_BGR2GRAY);

        imwrite("out.bmp", gray);
    }
    return 0;
}