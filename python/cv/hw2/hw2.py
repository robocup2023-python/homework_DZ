import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt

def main():
    img_gray = cv.imread("hw2.jpg", 0)
    img_dft = cv.dft(np.float32(img_gray), flags=cv.DFT_COMPLEX_OUTPUT)
    img_dft_shift = np.fft.fftshift(img_dft)
    img_AM_spectrum, img_phase_specture = cv.cartToPolar(img_dft_shift[:,:,0],img_dft_shift[:,:,1], angleInDegrees=True)
    cv.imwrite("img_AM_spectrum.png", img_AM_spectrum)
    cv.imwrite("img_phase_specture.png", img_phase_specture)

    r, c = img_gray.shape
    mask = np.ones((r, c, 2), np.uint8)
    mask[r // 2 - 10:r // 2 + 10, c // 2 - 10:c // 2 + 10,:] = 0
    img_dft_shift = img_dft_shift * mask
    img_ishift = np.fft.ifftshift(img_dft_shift)
    img_idft = cv.idft(img_ishift)
    img_out = cv.magnitude(img_idft[:,:,0],img_idft[:,:,1])
    cv.imwrite("img_out.jpg",img_out) 

    plt.subplot(221), plt.imshow(img_gray, 'gray'), plt.title('Original Image')
    plt.axis('off')
    plt.subplot(222), plt.imshow(img_AM_spectrum, 'gray'), plt.title('img_AM_spectrum')
    plt.axis('off')
    plt.subplot(223), plt.imshow(img_phase_specture, 'gray'), plt.title('Inverse img_phase_specture Image')
    plt.axis('off')
    plt.subplot(224), plt.imshow(img_out, 'gray'), plt.title('Inverse Fourier Image')
    plt.axis('off')
    plt.show()

if __name__ == "__main__":
    main()