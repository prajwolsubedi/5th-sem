ori_img = imread('img\redrose.jpg');
noisy_img = imnoise(ori_img,'salt & pepper', 0.05); %adding salt and pepper noise
medf = @(x)median(x(:));
filtered_img = nlfilter(noisy_img,[3,3],medf);
subplot(3,2,1); imshow(ori_img); title('Original Image');
subplot(3,2,2); imshow(noisy_img); title('Noisy Image');
subplot(3,2,3); imshow(filtered_img); title('Filtered Image');