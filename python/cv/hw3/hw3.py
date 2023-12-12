import cv2 as cv
import numpy as np

def main():
    # sobel()
    # canny_edge()
    # harris()
    equalize()

def sobel():
    img = cv.imread("pp.jpg", 0)
    Gx = [[1,0,-1],[2,0,-2],[1,0,-1]]
    Gy = [[1,2,1],[0,0,0],[-1,-2,-1]]
    height, width = img.shape
    print(height,width)
    x = np.zeros((height - 2, width - 2), dtype=np.uint8)
    y = np.zeros((height - 2, width - 2), dtype=np.uint8)
    sum = np.zeros((height - 2, width - 2), dtype=np.uint8)
    for i in range(0, height - 2):
        for j in range(0, width - 2):
            x[i,j] = np.sum(np.multiply(img[i:i + 3, j:j + 3], Gx))
            y[i,j] = np.sum(np.multiply(img[i:i + 3, j:j + 3], Gy))
    sum = cv.convertScaleAbs(np.abs(x) + np.abs(y))
    sum = sum * (sum < 200)
    cv.imwrite("sobel.jpg", sum)

def canny_edge():
    img = cv.imread("pp.jpg", 0)
    
    img_gaus = cv.GaussianBlur(img, (7,7), 3)
    sobelx = cv.Sobel(img_gaus, cv.CV_64F, 1, 0, ksize=3)
    sobely = cv.Sobel(img_gaus, cv.CV_64F, 0, 1, ksize=3)
    grad_magnitude = cv.convertScaleAbs(np.abs(sobelx) + np.abs(sobely))
    grad_direction = np.arctan2(sobely, sobelx) * (180 / np.pi)
    cv.imwrite("canny_grad_magnitude.jpg", grad_magnitude)
    img_nms = NMS(grad_magnitude, grad_direction)
    cv.imwrite("canny_img_nms.jpg", img_nms)
    img_link = link(img_nms)
    cv.imwrite("img_link.jpg", img_link)

    img_canny = cv.Canny(img_gaus, 10, 50)
    cv.imwrite("canny.jpg", img_canny)

def NMS(img_mag, img_direc):
    r, c = img_mag.shape
    ans = np.zeros((r, c), dtype=np.uint8)

    for i in range(1, r - 1):
        for j in range(1, c - 1):
            angle = img_direc[i,j]
            if (-157.5 <= angle <= -112.5) or (-67.5 <= angle <= -22.5) or (22.5 <= angle <= 67.5) or (112.5 <= angle <= 157.5):
                num = np.max(img_mag[i-1:i+2,j-1:j+2])
            elif (-112.5 < angle< -67.5) or (67.5 < angle < 112.5):
                num = np.max(img_mag[i,j-1:j+2])
            else:
                num = np.max(img_mag[i-1:i+2,j])
            if img_mag[i,j] >= num:
                ans[i,j] = img_mag[i,j]
    
    return ans

def link(img):
    high = np.uint8(40)
    low = np.uint8(10)
    strong = np.uint8(img > high)
    weak = np.uint8((img >= low) & (img <= high))
    r, c = img.shape
    ans = strong
    for i in range(0,r):
        for j in range(0,c):
            if (weak[i,j]) & (np.sum(strong[i-1:i+2,j-1:j+2])):
                ans[i,j] = 1
    return ans*255


def harris():
    img_gray = cv.imread("hw3.jpeg", 0)
    img_bgr = cv.imread("hw3.jpeg", 1)
    block_size = [3,5,7,9,11]
    ksize = 9
    for bs in block_size:
        dst = cv.cornerHarris(img_gray, bs, ksize, k = 0.04)
        img_out = img_bgr
        img_out[dst > 0.01 * dst.max()] = [0,0,255]
        cv.imwrite(f"harris{bs // 2}.jpg",img_out)

def equalize():
    img = cv.imread("cell.png",0)
    hist, bins = np.histogram(img.flatten(), 256)
    cdf = hist.cumsum()
    cdf = cdf / cdf[-1] * 255
    img_equ = np.uint8(np.interp(img.flatten(), bins[:256], cdf))
    img_equ = img_equ.reshape(img.shape)
    cv.imwrite("img_cell.jpg",img)
    cv.imwrite("img_equ.jpg",img_equ)

if __name__ == "__main__":
    main()