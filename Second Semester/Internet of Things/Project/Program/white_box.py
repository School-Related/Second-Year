import tkinter as tk
import cv2
from PIL import ImageTk, Image

# Define the function that will be called when the slider is moved
def update_threshold(value):
    global threshold
    threshold = int(value)

# Define the function that will be called when the "Process" button is clicked
def process_image():
    global threshold
    
    # Convert the image to grayscale
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

    # Threshold the image to isolate white regions using the current threshold value
    thresh = cv2.threshold(gray, threshold, 255, cv2.THRESH_BINARY)[1]

    # Find contours in the thresholded image
    contours, hierarchy = cv2.findContours(thresh, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

    # Iterate through each contour and filter by area and aspect ratio
    for contour in contours:
        x, y, w, h = cv2.boundingRect(contour)
        area = cv2.contourArea(contour)
        aspect_ratio = w / float(h)
        
        if area > 1000 and aspect_ratio > 0.5 and aspect_ratio < 2:
            cv2.rectangle(image, (x, y), (x+w, y+h), (0, 255, 0), 2)

    # Update the image in the GUI window
    img = Image.fromarray(cv2.cvtColor(image, cv2.COLOR_BGR2RGB))
    img_tk = ImageTk.PhotoImage(img)
    canvas.itemconfig(canvas_image, image=img_tk)
    canvas.image = img_tk  # Keep a reference to prevent garbage collection

# Load the image
image = cv2.imread("../Program/8080_images0/img.jpg")

# Set the initial threshold value
threshold = 220

# Create the Tkinter GUI window
root = tk.Tk()
root.title("Threshold Slider")

# Create a canvas for displaying the image
canvas = tk.Canvas(root, width=image.shape[1], height=image.shape[0])
canvas.pack()
img = Image.fromarray(cv2.cvtColor(image, cv2.COLOR_BGR2RGB))
img_tk = ImageTk.PhotoImage(img)
canvas_image = canvas.create_image(0, 0, anchor=tk.NW, image=img_tk)

# Create a slider for changing the threshold value
slider = tk.Scale(root, from_=0, to=255, orient=tk.HORIZONTAL, command=update_threshold)
slider.pack()

# Create a button for processing the image
button = tk.Button(root, text="Process", command=process_image)
button.pack()

# Start the Tkinter event loop
root.mainloop()
