# Lane Detection System with Real-World Coordinate Mapping

## Overview

This project develops a lane detection system that overlays a 3D track model (curves or straight lines) onto a camera feed. By leveraging a 3D engine for visualization, the system not only detects lanes but also calculates real-world coordinates for the detected features. This capability allows for precise alignment of the 3D track model with the live camera feed, making it possible to map lane positions in real-world spatial dimensions.

The system works as follows:
1. Extract 2D lane features from the camera image.
2. Convert 2D points into 3D space.
3. Visualize the extracted 3D points alongside the track model in the 3D engine, which uses camera parameters identical to those of the real-world camera.
4. Overlay the aligned track model onto the camera feed, enabling real-world spatial mapping.

## Project Structure

### 1. Engine 3D
This is the core module that handles 3D visualization and spatial alignment. The 3D engine ensures that:
- Extracted 3D points from the camera feed are rendered in a virtual environment.
- Track models (curves and straight lines) are displayed in 3D.
- The camera parameters in the 3D engine match those of the real-world camera, enabling precise alignment between the real-world and virtual coordinates.

[Related Project Reference: Link to 3D-Engine CPP](https://github.com/race-against-ai/3dengine_cpp)

### 2. Converter  
Converts 2D points extracted from the camera image into 3D points. These points represent real-world coordinates when visualized in the 3D engine.

### 3. Core  
Manages core functionalities, including:
- Receiving and processing the camera stream.
- Handling communication between the UI and the Engine 3D by passing relevant parameters.

### 4. Curve Calculator  
Generates mathematical models for curved lanes, which are visualized in the 3D engine and overlaid onto the camera feed.

### 5. Straight Calculator  
Generates mathematical models for straight lanes, integrated similarly to the curve models.

### 6. Image Filter  
Applies basic filtering to the camera image to extract prominent lane lines.  
[Related Project Reference: Link to Image Filtering Project](https://github.com/race-against-ai/road_line_filter)

### 7. UI  
The graphical interface is built using QML and displays:
- The live camera feed.
- The overlaid 3D track model.
- Tools for adjusting parameters to fine-tune system performance.

## Workflow

1. Initialize System Components  
   - Set the frame dimensions to `640x480`.  
   - Initialize `cv::Mat` objects for handling:
     - The camera frame.
     - The engine frame (for rendering).
     - A BGR-filtered frame.
   - Establish the video stream connection using `cv::VideoCapture` (e.g., `http://192.168.30.123:8443/normal.py`).
   - Create instances for:
     - CameraProcessor for image filtering.
     - Engine for 3D visualization.
     - Trackmodel to calculate and position the track.

2. Parameter Updates  
   - Dynamically fetch the latest curve, straight-line, and engine parameters via the parameter model:
     - `getCurveParameters()`
     - `getEngineParameters()`
     - `getStraightParameters()`

3. Track Model Selection  
   - Depending on user settings in the parameter model:
     - Generate a straight track using `generateStraightTrack(straight_parameter)` if straight-line detection is enabled.
     - Generate a curve track using `generateTrack(curve_parameter)` if curve detection is enabled.
     - Clear the track model if no detection type is selected.

4. Process Camera Feed  
   - Capture a frame from the video stream (`cap >> camera_frame`).
   - Use the CameraProcessor to process the image and extract prominent lane features for defined rows (`processor.process_Image(camera_frame, rows)`).
   - Retrieve the filtered frame from the processor (`processor.getResultFrame()`).

5. Convert 2D Points to 3D  
   - Convert the detected 2D lane points into 3D space using the Converter module in the engine.

6. 3D Engine Execution  
   - Run the 3D engine to render the processed frame, track model, and engine parameters (`engine.run(filtered_frame, mesh, engine_parameter)`).

7. Track Model Positioning  
   - Use the Trackmodel module to align the detected track features with the processed lane points (`trackmodel.trackmodel_position(mesh, detected_pairs)`).

8. UI Update  
   - Convert the engine-rendered frame to a format compatible with the UI:
     - Convert the frame (`cv::Mat`) to a `QImage` object.
     - Update the displayed image in the UI using `mImageModel.setImage(QPixmap::fromImage(img))`.

9. Loop Execution  
   - Run the above steps continuously within the main loop, maintaining a frame rate of 60 FPS (`msleep(1000 / 60.0)`).

## Dependencies

- C++
- OpenCV (Image Processing)
- QML (UI)
- [3D-Engine CPP](https://github.com/race-against-ai/3dengine_cpp)
- [Image Filter](https://github.com/race-against-ai/road_line_filter)
