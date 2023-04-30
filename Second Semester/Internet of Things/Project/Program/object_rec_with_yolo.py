import cv2
import numpy as np

# Load YOLOv3-tiny model
net = cv2.dnn.readNet('/run/media/krishnaraj/Classes/University/Second Year/Second Semester/Python Programming/Programs/yolov3.weights', '/run/media/krishnaraj/Classes/University/Second Year/Second Semester/Python Programming/Programs/yolov3.cfg')

# Load class names
with open('coco.names', 'r') as f:
    classes = [line.strip() for line in f.readlines()]

# Set input/output names
input_name = 'data'
output_names = ['yolo_82', 'yolo_94', 'yolo_106']

# Set target confidence level
confidence_threshold = 0.5

# Set input size and scale factor
input_size = (416, 416)
scale_factor = 1/255.0

# Open video capture device
cap = cv2.VideoCapture(0)

# Loop over frames from the video stream
while True:
    # Read frame from video stream
    ret, frame = cap.read()

    if not ret:
        break

    # Resize frame and convert to blob
    blob = cv2.dnn.blobFromImage(frame, scale_factor, input_size, swapRB=True)

    # Set input blob and perform object detection
    net.setInput(blob, input_name)
    outputs = net.forward(output_names)

    # Initialize lists for detected objects
    boxes = []
    confidences = []
    class_ids = []

    # Loop over all outputs and detect objects
    for output in outputs:
        for detection in output:
            scores = detection[5:]
            class_id = np.argmax(scores)
            confidence = scores[class_id]

            if confidence > confidence_threshold:
                center_x = int(detection[0] * frame.shape[1])
                center_y = int(detection[1] * frame.shape[0])
                width = int(detection[2] * frame.shape[1])
                height = int(detection[3] * frame.shape[0])
                left = int(center_x - width / 2)
                top = int(center_y - height / 2)

                boxes.append([left, top, width, height])
                confidences.append(float(confidence))
                class_ids.append(class_id)

    # Apply non-max suppression to remove duplicate detections
    indices = cv2.dnn.NMSBoxes(boxes, confidences, confidence_threshold, 0.4)

    # Draw boxes around detected objects
    if len(indices) > 0:
        for i in indices.flatten():
            left, top, width, height = boxes[i]
            label = f'{classes[class_ids[i]]}: {confidences[i]:.2f}'
            cv2.rectangle(frame, (left, top), (left + width, top + height), (0, 255, 0), 2)
            cv2.putText(frame, label, (left, top - 5), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)

    # Display frame with detected objects
    cv2.imshow('Object Detection', frame)

    # Wait for key press and check if 'q' was pressed
    if cv2.waitKey(1) == ord('q'):
        break

# Release video capture device and close all windows
cap.release()
cv2.destroyAllWindows()
