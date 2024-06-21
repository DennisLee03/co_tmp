void conv2d(int *input, int *kernel, int w, int h,
            int ksize, int s) {
    for (int i = 0; i <= h - ksize; i++) {  // 先處理高度 (i 迴圈)
        for (int j = 0; j <= w - ksize; j++) {  // 再處理寬度 (j 迴圈)
            int sum = 0;
            for (int n = 0; n < ksize; n += s) {
                for (int m = 0; m < ksize; m += s) {
                    sum += input[(i + m) * w + j + n] * kernel[m * ksize + n];
                }
            }
            input[i * w + j] = sum;
        }
    }
}

