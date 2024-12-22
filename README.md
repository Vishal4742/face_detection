# Face Detection using OpenCV

This project uses OpenCV to perform real-time face detection via a webcam. It uses a pre-trained Haar Cascade classifier to detect faces in video frames.

## Requirements

- **C++ compiler** (e.g., GCC or MSVC)
- **OpenCV** (installed and configured for your platform)
- **Haar Cascade Classifier** for face detection

## Setup Instructions

### 1. Install OpenCV

To run this project, you need to install OpenCV on your system. You can follow the instructions for your platform:

- **Windows**: [Install OpenCV on Windows](https://docs.opencv.org/master/d3/d52/tutorial_windows_install.html)
- **Linux**: [Install OpenCV on Ubuntu](https://docs.opencv.org/master/d7/d9f/tutorial_linux_install.html)
- **Mac**: [Install OpenCV on macOS](https://docs.opencv.org/master/d7/d9f/tutorial_linux_install.html)

Make sure OpenCV is correctly configured with your C++ compiler and that you can link OpenCV with your project.

### 2. Download Haar Cascade Classifier

You will need the `haarcascade_frontalface_default.xml` file to detect faces. Download it from [here](https://github.com/opencv/opencv/tree/master/data/haarcascades) or from the OpenCV GitHub repository.

### 3. Compile and Run the Code

1. Open a terminal (or Command Prompt) and navigate to the project folder.
   
2. Compile the C++ source code:
   ```bash
   g++ face_detection.cpp -o face_detection `pkg-config --cflags --libs opencv4`
