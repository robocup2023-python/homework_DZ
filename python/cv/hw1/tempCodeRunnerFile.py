t, width, channels = img.shape
    # pad_size = size // 2
    # result = np.zeros((height - pad_size * 2, width - pad_size * 2, 3), dtype = float)
    # for c in range(0, 3):
    #     for i in range(pad_size, height - pad_size):
    #         for j in range(pad_size, width - pad_size):
    #             result[i - pad_size, j - pad_size, c] = np.sum(np.dot(img[i - pad_size:i + pad_size + 1, j - pad_size:j + pad_size + 1, c], kernel))
    #             print(result[i - pad_size, j - pad_size, c])
    # return