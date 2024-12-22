#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    // Load the pre-trained Haar Cascade Classifier for face detection
    String face_cascade_name = "haarcascade_frontalface_default.xml";
    CascadeClassifier face_cascade;
    if (!face_cascade.load(face_cascade_name)) {
        cout << "Error loading face cascade" << endl;
        return -1;
    }

    // Open a video stream (can be a webcam or a video file)
    VideoCapture capture(0);  // 0 for webcam
    if (!capture.isOpened()) {
        cout << "Error opening video stream" << endl;
        return -1;
    }

    while (true) {
        Mat frame;
        capture >> frame;  // Capture frame-by-frame

        if (frame.empty()) {
            break;  // Exit if there is no frame
        }

        // Convert the frame to grayscale (Haar cascades work on grayscale images)
        Mat gray;
        cvtColor(frame, gray, COLOR_BGR2GRAY);

        // Detect faces in the image
        vector<Rect> faces;
        face_cascade.detectMultiScale(gray, faces);

        // Draw rectangle around each face detected
        for (size_t i = 0; i < faces.size(); i++) {
            rectangle(frame, faces[i], Scalar(255, 0, 0), 2);  // Draw rectangle
        }

        // Show the resulting frame
        imshow("Face Detection", frame);

        // Break the loop if the user presses 'q'
        if (waitKey(1) == 'q') {
            break;
        }
    }

    // Release the video capture object and close all OpenCV windows
    capture.release();
    destroyAllWindows();

    return 0;
}
