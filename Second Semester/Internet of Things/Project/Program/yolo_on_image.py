import cv2
import numpy as np
import os

# Load YOLOv3-tiny model
net = cv2.dnn.readNet('yolov3.weights', 'yolov3.cfg')

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

# Read input image file
image_path = '../Program/8080_images0/img.jpg'
if not os.path.isfile(image_path):
    print(f'Error: {image_path} not found')
    exit()
image = cv2.imread(image_path)

# Resize image and convert to blob
blob = cv2.dnn.blobFromImage(image, scale_factor, input_size, swapRB=True)

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
            center_x = int(detection[0] * image.shape[1])
            center_y = int(detection[1] * image.shape[0])
            width = int(detection[2] * image.shape[1])
            height = int(detection[3] * image.shape[0])
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
        cv2.rectangle(image, (left, top), (left + width, top + height), (0, 255, 0), 2)
        cv2.putText(image, label, (left, top - 5), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)

# Save output image with detections
output_path = 'output_image.jpg'
cv2.imwrite(output_path, image)
print(f'Image saved to {output_path}')
