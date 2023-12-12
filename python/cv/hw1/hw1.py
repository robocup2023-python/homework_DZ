import cv2 as cv
import numpy as np
import math
import matplotlib.pyplot as plt

def gaus_kernel(size, sigma):
    kernel = np.zeros((size, size), dtype = np.float32)
    center = size // 2
    for i in range(0, size):
        for j in range(0, size):
            x = i - center
            y = j - center
            kernel[i, j] = 1/(2*math.pi*sigma*sigma)*math.exp((-x*x-y*y)/(2*sigma*sigma))
    kernel /= np.sum(np.sum(kernel))
    visualize(kernel, size)
    return kernel

def my_gaus(img, size, sigma):
    kernel = gaus_kernel(size, sigma)
    height, width, _ = img.shape
    print(height,width)
    pad_size = size // 2
    result = np.zeros((height - pad_size * 2, width - pad_size * 2, 3), dtype = np.float32)
    for c in range(0, 3):
        for i in range(pad_size, height - pad_size):
            for j in range(pad_size, width - pad_size):
                result[i - pad_size, j - pad_size, c] = np.sum(np.sum(np.multiply(img[i - pad_size:i + pad_size + 1, j - pad_size:j + pad_size + 1, c], kernel)))
    return np.uint8(result)

def Func_gaus(img_bgr):
    img_func1 =cv.GaussianBlur(img_bgr,(7,7),1)
    img_func2 =cv.GaussianBlur(img_bgr,(7,7),3)
    img_func3 =cv.GaussianBlur(img_bgr,(7,7),5)
    img_func4 =cv.GaussianBlur(img_bgr,(7,7),7)
    cv.imwrite("hjt_func1.jpg",img_func1)
    cv.imwrite("hjt_func2.jpg",img_func2)
    cv.imwrite("hjt_func3.jpg",img_func3)
    cv.imwrite("hjt_func4.jpg",img_func4)

def mannual_gaus(img_bgr):
    img_mannual1 = my_gaus(img_bgr, 7, 1)
    img_mannual2 = my_gaus(img_bgr, 7, 3)
    img_mannual3 = my_gaus(img_bgr, 7, 5)
    img_mannual4 = my_gaus(img_bgr, 7, 7)
    cv.imwrite("hjt_mannual1.jpg",img_mannual1)
    cv.imwrite("hjt_mannual2.jpg",img_mannual2)
    cv.imwrite("hjt_mannual3.jpg",img_mannual3)
    cv.imwrite("hjt_mannual4.jpg",img_mannual4)

def visualize(kernel,size):
    x, y = np.meshgrid(range(size), range(size))
    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')  
    x = np.arange(size)
    y = np.arange(size)
    x, y = np.meshgrid(x, y)
    ax.plot_surface(x, y, kernel, cmap='viridis')
    ax.set_title('2D Filter Kernel Visualization in 3D')
    ax.set_xlabel('Columns')
    ax.set_ylabel('Rows')
    ax.set_zlabel('Filter Values')
    plt.show()

def padding(img,size):
    height, width, _ = img.shape
    pad_size = size // 2

    img_zero_padding = np.zeros((height + pad_size * 2, width + pad_size * 2, 3), dtype = np.uint8)
    img_reflect = np.zeros((height + pad_size * 2, width + pad_size * 2, 3), dtype = np.uint8)
    for c in range(0, 3):
        for i in range(pad_size, height + pad_size):
            for j in range(pad_size, width + pad_size):
                img_zero_padding[i, j, c] = img[i - pad_size, j - pad_size, c]
                img_reflect[i, j, c] = img[i - pad_size, j - pad_size, c]
    cv.imwrite("hjt_zero_padding.jpg",img_zero_padding)

    for c in range(0, 3):
        for i in range(0, pad_size):
            for j in range(pad_size, width + pad_size):
                img_reflect[i, j, c] = img_reflect[2 * pad_size - i - 1, j, c]
            for j in range(0, pad_size):
                img_reflect[i, j, c] = img_reflect[i, 2 * pad_size - j - 1, c]
            for j in range(width + pad_size, width + pad_size * 2):
                img_reflect[i, j, c] = img_reflect[i, 2 * width + 2 * pad_size - j - 1, c]
        for i in range(pad_size, height + pad_size):
            for j in range(0, pad_size):
                img_reflect[i, j, c] = img_reflect[i, 2 * pad_size - j - 1, c]
            for j in range(width + pad_size, width + pad_size * 2):
                img_reflect[i, j, c] = img_reflect[i, 2 * width + 2 * pad_size - j - 1, c]
        for i in range(height + pad_size, height + pad_size * 2):
            for j in range(pad_size, width + pad_size):
                img_reflect[i, j, c] = img_reflect[2 * height + 2 * pad_size - i - 1, j, c]
            for j in range(0, pad_size):
                img_reflect[i, j, c] = img_reflect[i, 2 * pad_size - j - 1, c]
            for j in range(width + pad_size, width + pad_size * 2):
                img_reflect[i, j, c] = img_reflect[i, 2 * width + 2 * pad_size - j - 1, c]
    cv.imwrite("hjt_reflect.jpg",img_reflect)

def main():
    img_bgr = cv.imread("hjt.jpg", 1)
    Func_gaus(img_bgr)
    mannual_gaus(img_bgr)
    padding(img_bgr,135)
    
if __name__ == "__main__":
    main()